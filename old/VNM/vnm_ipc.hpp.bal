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

#ifndef WLAN_SRV_VNM_IPC_HPP
#define WLAN_SRV_VNM_IPC_HPP

/* INCLUDES *******************************************************************/
#include "wlan_data_types.hpp"
#include "vnm/vnmipcif.hpp"
/******************************************************************************/

/* NAMESPACE ******************************************************************/
namespace wlan {
/******************************************************************************/

/* DEFINES ********************************************************************/
typedef struct VnmIpcIntf {
    std::string     intf;
    bool hasIpAddr = false;
    std::string   ipAddr;
} VnmIpcIntf_t;


enum class VnmIpcReqType
{
    Min = 0,
    Add,
    ClearIpv4,
    RequestStaticIpv4,
    RequestDhcpServer,
    RequestDhcpClient,
    Max
};


typedef struct VnmIpcReq {
    std::string     intf;
    VnmIpcReqType   type = {VnmIpcReqType::Add};
    Ipv4AddrType    ipv4Type = {Ipv4AddrType::None};
   union ipv4 {
        ipv4Addr_t  staticAddr;
        ipv4() {memset(this, 0, sizeof(ipv4));};
    } ipv4;
    Ipv6AddrType    ipv6Type = {Ipv6AddrType::None};
    union ipv6 {
        ipv6Addr_t  staticAddr;
        ipv6() {memset(this, 0, sizeof(ipv6));};
    } ipv6;
} VnmIpcReq_t;
/* ****************************************************************************/

/* GLOBALS ********************************************************************/
/******************************************************************************/

/* PROTOTYPES *****************************************************************/
class VnmIpc
{
    public:
        VnmIpc(void *ctx);
        virtual ~VnmIpc();

        bool start();
        bool stop();

        /* IPv4 stuff */
        bool clearIpv4(const char *intf);
        bool requestStaticIpv4(const char *intf, ipv4Addr_t &addr);
        bool requestDhcpClient(const char *intf);
        bool requestDhcpServer(const char *intf /*, server config */);

        /* IPv6 stuff */

    private:
        VnmIpc(const VnmIpc &) = delete;
        VnmIpc & operator=(const VnmIpc &) = delete;

        void *m_globalCtx;

        bool m_running;
        std::thread *m_thread;

        std::string m_vnmIpcId = "wlanSrv";

        fnv::vnm::VnmIpc m_vnmIpcInstance;
        fnv::vnm::VnmIpcRet_t m_vnmIpcRetCode;

        /*
         * the list of interfaces that have requests on them and that we should
         * be monitoring for IP addressing changes
         */
        std::list<VnmIpcIntf_t> m_intfs;

        /*
         * a queue for incoming requests
         */
        std::deque<VnmIpcReq_t> m_reqsQ;

        /* mutex for queue */
        std::mutex m_qMutex;

        /* pipe for signalling when we put something in the queue */
        int m_signalPipeRead;
        int m_signalPipeWrite;
        int m_signalIntfUpdate;

        /* stuff for select loop */
        fd_set m_rfds;
        int m_maxFd;

        /*
         * main processing loop for thread
         */
        void waitForData(void);

        /*
         * helper function to setup m_rfds and m_highestFd
         */
        void setupRfds();

        /*
         * determines which fd has something for us to do
         */
        void handleFdsReady(void);

        /*
         * helper function that abstracts signalling the vnm_ipc thread via
         * the pipe.
         */
        bool signalVnmIpc(void);

        /*
         * helper function that check whether an interface is already being monitored
         * and adds it to the list if not, keep track of the fd associated with that 
         * interface.
         */
        bool checkIntfList(std::string intf);

        /*
         * function that checks the type of VNM request we have received and call the
         * approtiate handleVNM() function
         */
        bool selectVnmCall(void);

        bool handleClearIpv4(VnmIpcReq_t vnmRequest);
        bool handleRequestStaticIpv4(VnmIpcReq_t vnmRequest);
        bool handleRequestDhcpClient(VnmIpcReq_t vnmRequest);
        bool handleRequestDhcpServer(VnmIpcReq_t vnmRequest);

        int getIntfUpdateFd(void);
        bool checkIntfIpAddress(void);


};
/******************************************************************************/
} /* wlan */
#endif /* WLAN_SRV_VNM_IPC_HPP */
/******************************************************************************/
/* EOF */

