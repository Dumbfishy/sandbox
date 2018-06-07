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

#ifndef WLAN_SRV_DRV_CTRL_HPP
#define WLAN_SRV_DRV_CTRL_HPP

/* INCLUDES *******************************************************************/
/******************************************************************************/

/* NAMESPACE ******************************************************************/
namespace wlan {
/******************************************************************************/

/* DEFINES ********************************************************************/
#define MAX_LEN_START_CMD 1024
#define MAX_LEN_STOP_CMD 1024
/* ****************************************************************************/

/* GLOBALS ********************************************************************/
/******************************************************************************/

/* PROTOTYPES *****************************************************************/
class DrvCtrl
{
    public:
        DrvCtrl(void *ctx);
        virtual ~DrvCtrl();

        void mainLoop();

        int request();
        int decline();

        void processEvent();
    private:
        DrvCtrl(const DrvCtrl &) = delete;
        DrvCtrl & operator=(const DrvCtrl &) = delete;

        void *m_globalCtx;

        unsigned int m_requested;
        bool m_starting;
        bool m_stopping;
        bool m_running;

        int startWlanDriver();
        int stopWlanDriver();
};

/******************************************************************************/
} /* wlan */
#endif /* WLAN_SRV_DRV_CTRL_HPP */
/******************************************************************************/
/* EOF */

