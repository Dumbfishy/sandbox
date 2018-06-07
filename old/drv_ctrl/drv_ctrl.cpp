/*
 * CONFIDENTIAL - FORD MOTOR COMPANY
 *
 * This is an unpublished work, which is a trade secret, created in
 * 2017.  Ford Motor Company owns all rights to this work and intends
 * to maintain it in confidence to preserve its trade secret status.
 * Ford Motor Company reserves the right to protect this work as an
 * unpublished copyrighted work in the event of an inadvertent or
 * deliberate unauthorized publication.  Ford Motor Company also
 * reserves its rights under the copyright laws to protect this work
 * as a published work.  Those having access to this work may not copy
 * it, use it, or disclose the information contained in it without
 * the written authorization of Ford Motor Company.
 */

/* INCLUDES *******************************************************************/
#include <sys/param.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "wlan_srv-logger.hpp"
#include "main.hpp"
/******************************************************************************/

/* NAMESPACE ******************************************************************/
namespace wlan {
/******************************************************************************/

/* DEFINES ********************************************************************/
static const char* TAG = "drv_ctrl";

#define DRV_LOAD_CMD "insmod"
#define DRV_REMOVE_CMD "rmmod"
#define DRV "wlan_sdio.ko"
#define DRV_PATH "/lib/modules/3.18.66/extra"

/* 4k reply size is what wpa_cli is using */
#define MAX_LEN_CMD 2048
#define MAX_LEN_REPLY 4096
/******************************************************************************/

/* GLOBALS ********************************************************************/
/* Comment for compile right now, add back in for error prints
static const char *drvCtrlOk = "OK";
static const char *drvCtrlFail = "FAIL";
static const char *drvCtrlUnknown = "UNKNOWN COMMAND";
*/

/******************************************************************************/

/* PROTOTYPES *****************************************************************/
/******************************************************************************/

/* FUNCTIONS/CLASSES **********************************************************/
DrvCtrl::DrvCtrl(void *ctx)
{
    ENTER();
    m_globalCtx = ctx;
    m_requested = 0;
    m_starting = false;
    m_stopping = false;
    m_running = false;
    EXIT();
}

// TODO: add doxygen
DrvCtrl::~DrvCtrl()
{
    ENTER();

    /* if the driver is running, shut it down */
    if (m_starting || m_running) {
        decline();
    }

    EXIT();
}

// TODO: add doxygen
int DrvCtrl::request()
{
    int rc = 0;

    ENTER();

    /* increment our count of people starting the wlan driver */
    m_requested++;
    INFO("wlan driver has been requested\n");

    /* check if we need to start the wlan driver */
    if ((m_starting) || (m_running)) {
        INFO("wlan driver is already starting/running\n");
        rc = 0;
    } else {
        INFO("wlan driver is not running already, starting\n");
        rc = startWlanDriver();
    }

    EXIT();
    return(rc);
}


// TODO: add doxygen
int DrvCtrl::decline()
{
    int rc = 0;

    ENTER();

    /* decrement our count of people that have started the wlan driver */
    m_requested--;
    INFO("wlan driver has been declined\n");

    /* check if we need to stop the wlan driver */
    if (m_requested > 0) {
        INFO("wlan driver is still in use, not stopping for now\n");
        rc = 0;
    } else {
        INFO("wlan driver is not needed anymore, stopping\n");
        //* stop the wpa_supplicant
        rc = stopWlanDriver();
    }
    EXIT();
    return(rc);
}

// TODO: add doxygen
int DrvCtrl::startWlanDriver()
{
//    WlanContext_t *ctx = NULL;
    const char wlanDriverStartCmd[MAX_LEN_START_CMD] = {'\0'};
    int rc = 0;
    ENTER();

//    ctx = (WlanContext_t *)m_globalCtx;

    m_starting = true;

    INFO("Starting wlan driver...\n");

    /* build up the start command */
    rc = snprintf((char *)wlanDriverStartCmd, MAX_LEN_START_CMD,
                    "%s %s/%s", DRV_LOAD_CMD, DRV_PATH, DRV);

    //TODO: handle if there is an error with snprintf
    DEBUG("wlan driver start command = \"%s\"\n", wlanDriverStartCmd);

    /* run start command */
    rc = system(wlanDriverStartCmd);
    if (rc) {
        ERROR("Failed to start wlan driver - rc = %d\n", rc);
        rc = -1;
        goto LEAVE;
    } else {
        DEBUG("wlan driver started successfully\n");
    }

    INFO("Successfully requested wlan driver to start\n");

    m_starting = false;
    m_stopping = false;
    m_running = true;

LEAVE:
    EXIT();
    return(rc);
}


// TODO: add doxygen
int DrvCtrl::stopWlanDriver()
{
   // WlanContext_t *ctx = NULL;
    const char wlanDriverStopCmd[MAX_LEN_STOP_CMD] = {'\0'};
    int rc = 0;

    ENTER();

    m_stopping = true;
 //   ctx = (WlanContext_t *)m_globalCtx;

    INFO("Stopping wpa_supplicant...\n");

    /* build up the stop command */
    rc = snprintf((char *)wlanDriverStopCmd, MAX_LEN_STOP_CMD,
                    "%s %s", DRV_REMOVE_CMD, DRV);

    /* run stop command */
    rc = system(wlanDriverStopCmd);
    if (rc) {
        ERROR("Failed to stop the wlan driver - rc = %d\n", rc);
        rc = -1;
        goto LEAVE;
    } else {
        DEBUG("wlan driver stopped successfully\n");
    }

    m_stopping = false;
    m_starting = false;
    m_running = false;

    INFO("Successfully requested stopped the wlan driver\n");

LEAVE:
    EXIT();
    return(rc);
}
/******************************************************************************/
} /* wlan*/
/******************************************************************************/
/* EOF */

