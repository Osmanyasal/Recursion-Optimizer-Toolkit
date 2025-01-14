#pragma once
#include <cstdint>
#include "intel_priv.hh"
namespace optkit::intel::hswep_unc_h{
	enum hswep_unc_h : uint64_t {
		UNC_H_CLOCKTICKS = 0x00, // HA Uncore clockticks
		UNC_H_CONFLICT_CYCLES = 0xb, // Conflict Checks
		UNC_H_DIRECT2CORE_COUNT = 0x11, // Direct2Core Messages Sent
		UNC_H_DIRECT2CORE_CYCLES_DISABLED = 0x12, // Cycles when Direct2Core was Disabled
		UNC_H_DIRECT2CORE_TXN_OVERRIDE = 0x13, // Number of Reads that had Direct2Core Overridden
		UNC_H_DIRECTORY_LOOKUP = 0xc, // Directory Lookups
		UNC_H_DIRECTORY_LOOKUP__MASK__HSWEP_UNC_H_DIRECTORY_LOOKUP__NO_SNP = 0x200, // Snoop not needed
		UNC_H_DIRECTORY_LOOKUP__MASK__HSWEP_UNC_H_DIRECTORY_LOOKUP__SNOOP = 0x100, // SNooop needed
		UNC_H_DIRECTORY_UPDATE = 0xd, // Directory Updates
		UNC_H_DIRECTORY_UPDATE__MASK__HSWEP_UNC_H_DIRECTORY_UPDATE__ANY = 0x300, // Counts any directory update
		UNC_H_DIRECTORY_UPDATE__MASK__HSWEP_UNC_H_DIRECTORY_UPDATE__CLEAR = 0x200, // Directory clears
		UNC_H_DIRECTORY_UPDATE__MASK__HSWEP_UNC_H_DIRECTORY_UPDATE__SET = 0x100, // Directory set
		UNC_H_IGR_NO_CREDIT_CYCLES = 0x22, // Cycles without QPI Ingress Credits
		UNC_H_IGR_NO_CREDIT_CYCLES__MASK__HSWEP_UNC_H_IGR_NO_CREDIT_CYCLES__RSP = 0x8000, // Number of hits with opcode RspI
		UNC_H_IGR_NO_CREDIT_CYCLES__MASK__HSWEP_UNC_H_IGR_NO_CREDIT_CYCLES__AD_QPI1 = 0x200, // AD to QPI link 1
		UNC_H_IGR_NO_CREDIT_CYCLES__MASK__HSWEP_UNC_H_IGR_NO_CREDIT_CYCLES__BL_QPI0 = 0x400, // BL to QPI link 0
		UNC_H_IGR_NO_CREDIT_CYCLES__MASK__HSWEP_UNC_H_IGR_NO_CREDIT_CYCLES__BL_QPI1 = 0x800, // BL to QPI link 1
		UNC_H_IGR_NO_CREDIT_CYCLES__MASK__HSWEP_UNC_H_IGR_NO_CREDIT_CYCLES__AD_QPI2 = 0x1000, // AD to QPI link 2
		UNC_H_IGR_NO_CREDIT_CYCLES__MASK__HSWEP_UNC_H_IGR_NO_CREDIT_CYCLES__BL_QPI2 = 0x2000, // BL to QPI link 2
		UNC_H_IMC_RETRY = 0x1e, // Retry Events
		UNC_H_IMC_WRITES = 0x1a, // HA to IMC Full Line Writes Issued
		UNC_H_IMC_WRITES__MASK__HSWEP_UNC_H_IMC_WRITES__ALL = 0xf00, // Counts all writes
		UNC_H_IMC_WRITES__MASK__HSWEP_UNC_H_IMC_WRITES__FULL = 0x100, // Counts full line non ISOCH
		UNC_H_IMC_WRITES__MASK__HSWEP_UNC_H_IMC_WRITES__PARTIAL = 0x200, // Counts partial non-ISOCH
		UNC_H_IMC_WRITES__MASK__HSWEP_UNC_H_IMC_WRITES__FULL_ISOCH = 0x400, // Counts ISOCH full line
		UNC_H_IMC_WRITES__MASK__HSWEP_UNC_H_IMC_WRITES__PARTIAL_ISOCH = 0x800, // Counts ISOCH partial
		UNC_H_IMC_READS = 0x17, // HA to IMC normal priority reads issued
		UNC_H_IMC_READS__MASK__HSWEP_UNC_H_IMC_READS__NORMAL = 0x100, // Normal priority
		UNC_H_REQUESTS = 0x1, // Read and Write Requests
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__READS = 0x300, // Counts incoming read requests. Good proxy for LLC read misses
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__READS_LOCAL = 0x100, // Counts incoming read requests coming from local socket. Good proxy for LLC read misses
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__READS_REMOTE = 0x200, // Counts incoming read requests coming from remote socket. Good proxy for LLC read misses
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__WRITES = 0xc00, // Counts incoming writes
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__WRITES_LOCAL = 0x400, // Counts incoming writes from local socket
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__WRITES_REMOTE = 0x800, // Counts incoming writes from remote socket
		UNC_H_REQUESTS__MASK__HSWEP_UNC_H_REQUESTS__INVITOE_LOCAL = 0x1000, // Counts InvItoE coming from local socket
		UNC_H_RPQ_CYCLES_NO_REG_CREDITS = 0x15, // IMC RPQ Credits Empty
		UNC_H_RPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__INVITOE_REMOTE = 0x2000, // Counts InvItoE coming from remote socket
		UNC_H_RPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__CHN1 = 0x200, // Channel 1
		UNC_H_RPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__CHN2 = 0x400, // channel 2
		UNC_H_RPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__CHN3 = 0x800, // Chanel 3
		UNC_H_TAD_REQUESTS_G0 = 0x1b, // HA Requests to a TAD Region
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION0 = 0x100, // Counts for TAD Region 0
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION1 = 0x200, // Counts for TAD Region 1
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION2 = 0x400, // Counts for TAD Region 2
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION3 = 0x800, // Counts for TAD Region 3
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION4 = 0x1000, // Counts for TAD Region 4
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION5 = 0x2000, // Counts for TAD Region 5
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION6 = 0x4000, // Counts for TAD Region 6
		UNC_H_TAD_REQUESTS_G0__MASK__HSWEP_UNC_H_TAD_REQUESTS_G0__REGION7 = 0x8000, // Counts for TAD Region 7
		UNC_H_TAD_REQUESTS_G1 = 0x1c, // HA Requests to a TAD Region
		UNC_H_TAD_REQUESTS_G1__MASK__HSWEP_UNC_H_TAD_REQUESTS_G1__REGION8 = 0x100, // Counts for TAD Region 8
		UNC_H_TAD_REQUESTS_G1__MASK__HSWEP_UNC_H_TAD_REQUESTS_G1__REGION9 = 0x200, // Counts for TAD Region 9
		UNC_H_TAD_REQUESTS_G1__MASK__HSWEP_UNC_H_TAD_REQUESTS_G1__REGION10 = 0x400, // Counts for TAD Region 10
		UNC_H_TAD_REQUESTS_G1__MASK__HSWEP_UNC_H_TAD_REQUESTS_G1__REGION11 = 0x800, // Counts for TAD Region 11
		UNC_H_TXR_AD_CYCLES_FULL = 0x2a, // AD Egress Full
		UNC_H_TXR_AD_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AD_CYCLES_FULL__ALL = 0x300, // Counts cycles full from both schedulers
		UNC_H_TXR_AD_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AD_CYCLES_FULL__SCHED0 = 0x100, // Counts cycles full from scheduler bank 0
		UNC_H_TXR_AD_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AD_CYCLES_FULL__SCHED1 = 0x200, // Counts cycles full from scheduler bank 1
		UNC_H_TXR_AK_CYCLES_FULL = 0x32, // AK Egress Full
		UNC_H_TXR_AK_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AK_CYCLES_FULL__ALL = 0x300, // Counts cycles from both schedulers
		UNC_H_TXR_AK_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AK_CYCLES_FULL__SCHED0 = 0x100, // Counts cycles from scheduler bank 0
		UNC_H_TXR_AK_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AK_CYCLES_FULL__SCHED1 = 0x200, // Counts cycles from scheduler bank 1
		UNC_H_TXR_AK = 0xe, // Outbound Ring Transactions on AK
		UNC_H_TXR_AK__MASK__HSWEP_UNC_H_TXR_AK__NDR = 0x100, // Number of outbound NDR (non-data response) transactions send on the AK ring. AK NDR is used for messages to the local socket
		UNC_H_TXR_AK__MASK__HSWEP_UNC_H_TXR_AK__CRD_CBO = 0x200, // Number of outbound CDR transactions send on the AK ring to CBO
		UNC_H_TXR_AK__MASK__HSWEP_UNC_H_TXR_AK__CRD_QPI = 0x400, // Number of outbound CDR transactions send on the AK ring to QPI
		UNC_H_TXR_BL = 0x10, // Outbound DRS Ring Transactions to Cache
		UNC_H_TXR_BL__MASK__HSWEP_UNC_H_TXR_BL__DRS_CACHE = 0x100, // Counts data being sent to the cache
		UNC_H_TXR_BL__MASK__HSWEP_UNC_H_TXR_BL__DRS_CORE = 0x200, // Counts data being sent directly to the requesting core
		UNC_H_TXR_BL__MASK__HSWEP_UNC_H_TXR_BL__DRS_QPI = 0x400, // Counts data being sent to a remote socket over QPI
		UNC_H_TXR_BL_CYCLES_FULL = 0x36, // BL Egress Full
		UNC_H_TXR_BL_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AK_CYCLES_FULL__ALL = 0x300, // Counts cycles from both schedulers
		UNC_H_TXR_BL_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AK_CYCLES_FULL__SCHED0 = 0x100, // Counts cycles from scheduler bank 0
		UNC_H_TXR_BL_CYCLES_FULL__MASK__HSWEP_UNC_H_TXR_AK_CYCLES_FULL__SCHED1 = 0x200, // Counts cycles from scheduler bank 1
		UNC_H_WPQ_CYCLES_NO_REG_CREDITS = 0x18, // HA IMC CHN0 WPQ Credits Empty
		UNC_H_WPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__INVITOE_REMOTE = 0x2000, // Counts InvItoE coming from remote socket
		UNC_H_WPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__CHN1 = 0x200, // Channel 1
		UNC_H_WPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__CHN2 = 0x400, // channel 2
		UNC_H_WPQ_CYCLES_NO_REG_CREDITS__MASK__HSWEP_UNC_H_RPQ_CYCLES_NO_REG_CREDITS__CHN3 = 0x800, // Chanel 3
		UNC_H_BT_BYPASS = 0x52, // Backup Tracker bypass
		UNC_H_BYPASS_IMC = 0x14, // HA to IMC bypass
		UNC_H_BYPASS_IMC__MASK__HSWEP_UNC_H_BYPASS_IMC__TAKEN = 0x100, // Bypass taken
		UNC_H_BYPASS_IMC__MASK__HSWEP_UNC_H_BYPASS_IMC__NOT_TAKEN = 0x200, // Bypass not taken
		UNC_H_BT_CYCLES_NE = 0x42, // Backup Tracker cycles not empty
		UNC_H_BT_OCCUPANCY = 0x43, // Backup Tracker inserts
		UNC_H_OSB = 0x53, // OSB snoop broadcast
		UNC_H_OSB__MASK__HSWEP_UNC_H_OSB__REMOTE = 0x800, // Remote
		UNC_H_OSB__MASK__HSWEP_UNC_H_OSB__READS_LOCAL = 0x200, // Local reads
		UNC_H_OSB__MASK__HSWEP_UNC_H_OSB__INVITOE_LOCAL = 0x400, // Local InvItoE
		UNC_H_OSB__MASK__HSWEP_UNC_H_OSB__CANCELLED = 0x1000, // Cancelled due to D2C or Other
		UNC_H_OSB__MASK__HSWEP_UNC_H_OSB__READS_LOCAL_USEFUL = 0x2000, // Local reads - useful
		UNC_H_OSB_EDR = 0x54, // OSB early data return
		UNC_H_OSB_EDR__MASK__HSWEP_UNC_H_OSB_EDR__REMOTE_USEFUL = 0x4000, // Remote - useful
		UNC_H_OSB_EDR__MASK__HSWEP_UNC_H_OSB_EDR__READS_LOCAL_I = 0x200, // Reads to local I
		UNC_H_OSB_EDR__MASK__HSWEP_UNC_H_OSB_EDR__READS_REMOTE_I = 0x400, // Reads to remote I
		UNC_H_OSB_EDR__MASK__HSWEP_UNC_H_OSB_EDR__READS_LOCAL_S = 0x800, // Reads to local S
		UNC_H_RING_AD_USED = 0x3e, // AD ring in use
		UNC_H_RING_AD_USED__MASK__HSWEP_UNC_H_RING_AD_USED__READS_REMOTE_S = 0x1000, // Reads to remote S
		UNC_H_RING_AD_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CCW_ODD = 0x800, // Counter-clockwise and odd ring polarity
		UNC_H_RING_AD_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW_EVEN = 0x100, // Clockwise and even ring polarity
		UNC_H_RING_AD_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW_ODD = 0x200, // Clockwise and odd ring polarity
		UNC_H_RING_AD_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW = 0x3300, // Clockwise with any polarity
		UNC_H_RING_AD_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CCW = 0xcc00, // Counter-clockwise with any polarity
		UNC_H_RING_AK_USED = 0x3f, // AK ring in use
		UNC_H_RING_AK_USED__MASK__HSWEP_UNC_H_RING_AD_USED__READS_REMOTE_S = 0x1000, // Reads to remote S
		UNC_H_RING_AK_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CCW_ODD = 0x800, // Counter-clockwise and odd ring polarity
		UNC_H_RING_AK_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW_EVEN = 0x100, // Clockwise and even ring polarity
		UNC_H_RING_AK_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW_ODD = 0x200, // Clockwise and odd ring polarity
		UNC_H_RING_AK_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW = 0x3300, // Clockwise with any polarity
		UNC_H_RING_AK_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CCW = 0xcc00, // Counter-clockwise with any polarity
		UNC_H_RING_BL_USED = 0x40, // BL ring in use
		UNC_H_RING_BL_USED__MASK__HSWEP_UNC_H_RING_AD_USED__READS_REMOTE_S = 0x1000, // Reads to remote S
		UNC_H_RING_BL_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CCW_ODD = 0x800, // Counter-clockwise and odd ring polarity
		UNC_H_RING_BL_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW_EVEN = 0x100, // Clockwise and even ring polarity
		UNC_H_RING_BL_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW_ODD = 0x200, // Clockwise and odd ring polarity
		UNC_H_RING_BL_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CW = 0x3300, // Clockwise with any polarity
		UNC_H_RING_BL_USED__MASK__HSWEP_UNC_H_RING_AD_USED__CCW = 0xcc00, // Counter-clockwise with any polarity
		UNC_H_DIRECTORY_LAT_OPT = 0x41, // Directory latency optimization data return path taken
		UNC_H_SNOOP_RESP_RECV_LOCAL = 0x60, // Snoop responses received local
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPI = 0x100, // Filters for snoop responses of RspI. RspI is returned when the remote cache does not have the data or when the remote cache silently evicts data (e.g. RFO hit non-modified line)
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPS = 0x200, // Filters for snoop responses of RspS. RspS is returned when the remote cache has the data but is not forwarding it. It is a way to let the requesting socket know that it cannot allocate the data in E-state
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPIFWD = 0x400, // Filters for snoop responses of RspIFwd. RspIFwd is returned when the remote cache agent forwards data and the requesting agent is able to acquire the data in E or M state. This is commonly returned with RFO transacations. It can be either HitM or HitFE
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPSFWD = 0x800, // Filters for snoop responses of RspSFwd. RspSFwd is returned when the remote cache agent forwards data  but holds on to its current copy. This is common for data and code reads that hit in a remote socket in E or F state
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSP_WB = 0x1000, // Filters for snoop responses of RspIWB or RspSWB. This is returned when a non-RFO requests hits in M-state. Data and code reads can return either RspIWB or RspSWB depending on how the system has been configured. InvItoE transactions will also return RspIWB because they must acquire ownership
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSP_FWD_WB = 0x2000, // Filters for snoop responses of RspxFwdxWB. This snoop response is only used in 4s systems. It is used when a snoop HITM in a remote caching agent and it directly forwards data to a requester and simultaneously returns data to the home to be written back to memory
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPCNFLCT = 0x4000, // Filters for snoop responses of RspConflict. This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CMAs that caching agent. This triggers the conflict resolution hardware. This covers both RspConflct and RspCnflctWBI
		UNC_H_SNOOP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__OTHER = 0x8000, // Filters all other snoop responses
		UNC_H_SNP_RESP_RECV_LOCAL = 0x60, // Snoop responses received local
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPI = 0x100, // Filters for snoop responses of RspI. RspI is returned when the remote cache does not have the data or when the remote cache silently evicts data (e.g. RFO hit non-modified line)
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPS = 0x200, // Filters for snoop responses of RspS. RspS is returned when the remote cache has the data but is not forwarding it. It is a way to let the requesting socket know that it cannot allocate the data in E-state
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPIFWD = 0x400, // Filters for snoop responses of RspIFwd. RspIFwd is returned when the remote cache agent forwards data and the requesting agent is able to acquire the data in E or M state. This is commonly returned with RFO transacations. It can be either HitM or HitFE
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPSFWD = 0x800, // Filters for snoop responses of RspSFwd. RspSFwd is returned when the remote cache agent forwards data  but holds on to its current copy. This is common for data and code reads that hit in a remote socket in E or F state
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSP_WB = 0x1000, // Filters for snoop responses of RspIWB or RspSWB. This is returned when a non-RFO requests hits in M-state. Data and code reads can return either RspIWB or RspSWB depending on how the system has been configured. InvItoE transactions will also return RspIWB because they must acquire ownership
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSP_FWD_WB = 0x2000, // Filters for snoop responses of RspxFwdxWB. This snoop response is only used in 4s systems. It is used when a snoop HITM in a remote caching agent and it directly forwards data to a requester and simultaneously returns data to the home to be written back to memory
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__RSPCNFLCT = 0x4000, // Filters for snoop responses of RspConflict. This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CMAs that caching agent. This triggers the conflict resolution hardware. This covers both RspConflct and RspCnflctWBI
		UNC_H_SNP_RESP_RECV_LOCAL__MASK__HSWEP_UNC_H_SNP_RESP_RECV_LOCAL__OTHER = 0x8000, // Filters all other snoop responses
		UNC_H_TXR_BL_OCCUPANCY = 0x34, // BL Egress occupancy
		UNC_H_TXR_BL_OCCUPANCY__MASK__HSWEP_UNC_H_TXR_BL_OCCUPANCY__SCHED0 = 0x100, // Counts cycles full from scheduler bank 0
		UNC_H_TXR_BL_OCCUPANCY__MASK__HSWEP_UNC_H_TXR_BL_OCCUPANCY__SCHED1 = 0x200, // Counts cycles full from scheduler bank 1
		UNC_H_SNOOP_RESP = 0x21, // Snoop responses received
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSPI = 0x100, // Filters for snoop responses of RspI. RspI is returned when the remote cache does not have the data or when the remote cache silently evicts data (e.g. RFO hit non-modified line)
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSPS = 0x200, // Filters for snoop responses of RspS. RspS is returned when the remote cache has the data but is not forwarding it. It is a way to let the requesting socket know that it cannot allocate the data in E-state
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSPIFWD = 0x400, // Filters for snoop responses of RspIFwd. RspIFwd is returned when the remote cache agent forwards data and the requesting agent is able to acquire the data in E or M state. This is commonly returned with RFO transacations. It can be either HitM or HitFE
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSPSFWD = 0x800, // Filters for snoop responses of RspSFwd. RspSFwd is returned when the remote cache agent forwards data  but holds on to its current copy. This is common for data and code reads that hit in a remote socket in E or F state
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSP_WB = 0x1000, // Filters for snoop responses of RspIWB or RspSWB. This is returned when a non-RFO requests hits in M-state. Data and code reads can return either RspIWB or RspSWB depending on how the system has been configured. InvItoE transactions will also return RspIWB because they must acquire ownership
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSP_FWD_WB = 0x2000, // Filters for snoop responses of RspxFwdxWB. This snoop response is only used in 4s systems. It is used when a snoop HITM in a remote caching agent and it directly forwards data to a requester and simultaneously returns data to the home to be written back to memory
		UNC_H_SNOOP_RESP__MASK__HSWEP_UNC_H_SNOOP_RESP__RSPCNFLCT = 0x4000, // Filters for snoop responses of RspConflict. This is returned when a snoop finds an existing outstanding transaction in a remote caching agent when it CMAs that caching agent. This triggers the conflict resolution hardware. This covers both RspConflct and RspCnflctWBI
		UNC_H_HITME_HIT = 0x71, // Hits in the HitMe cache
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__ALL = 0xff00, // All requests
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__READ_OR_INVITOE = 0x100, // Number of hits with opcode RdCode
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__WBMTOI = 0x200, // Number of hits with opcode WbToMtoI
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__ACKCNFLTWBI = 0x400, // Number of hits with opcode AckCnfltWbI
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__WBMTOE_OR_S = 0x800, // Number of hits with opcode WbMtoE or WbMtoS
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__HOM = 0xf00, // Number of hits with HOM requests
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__RSPFWDI_REMOTE = 0x1000, // Number of hits with opcode RspIFwd
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__RSPFWDI_LOCAL = 0x2000, // Number of hits with opcode RspIFwd
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__INVALS = 0x2600, // Number of hits for invalidations
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__RSPFWDS = 0x4000, // Number of hits with opcode RsSFwd
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__EVICTS = 0x4200, // Number of hits for allocations
		UNC_H_HITME_HIT__MASK__HSWEP_UNC_H_HITME_HIT__ALLOCS = 0x7000, // Number of hits for allocations
		UNC_H_HITME_HIT_PV_BITS_SET = 0x72, // Number of PV bits set on HitMe cache hits
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__RSP = 0x8000, // Number of hits with opcode RspI
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__READ_OR_INVITOE = 0x100, // Number of hits with opcode RdCode
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__WBMTOI = 0x200, // Number of hits with opcode WbToMtoI
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__ACKCNFLTWBI = 0x400, // Number of hits with opcode AckCnfltWbI
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__WBMTOE_OR_S = 0x800, // Number of hits with opcode WbMtoE or WbMtoS
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__HOM = 0xf00, // Number of hits with HOM requests
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__RSPFWDI_REMOTE = 0x1000, // Number of hits with opcode RspIFwd
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__RSPFWDI_LOCAL = 0x2000, // Number of hits with opcode RspIFwd
		UNC_H_HITME_HIT_PV_BITS_SET__MASK__HSWEP_UNC_H_HITME_HIT_PV_BITS_SET__RSPFWDS = 0x4000, // Number of hits with opcode RsSFwd
		UNC_H_HITME_LOOKUP = 0x70, // Number of accesses to HitMe cache
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__ALL = 0xff00, // All requests
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__READ_OR_INVITOE = 0x100, // Number of hits with opcode RdCode
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__WBMTOI = 0x200, // Number of hits with opcode WbToMtoI
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__ACKCNFLTWBI = 0x400, // Number of hits with opcode AckCnfltWbI
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__WBMTOE_OR_S = 0x800, // Number of hits with opcode WbMtoE or WbMtoS
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__HOM = 0xf00, // Number of hits with HOM requests
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__RSPFWDI_REMOTE = 0x1000, // Number of hits with opcode RspIFwd
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__RSPFWDI_LOCAL = 0x2000, // Number of hits with opcode RspIFwd
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__INVALS = 0x2600, // Number of hits for invalidations
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__RSPFWDS = 0x4000, // Number of hits with opcode RsSFwd
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__EVICTS = 0x4200, // Number of hits for allocations
		UNC_H_HITME_LOOKUP__MASK__HSWEP_UNC_H_HITME_HIT__ALLOCS = 0x7000, // Number of hits for allocations
		UNC_H_SBO0_CREDIT_ACQUIRED = 0x68, // SBO0 credits acquired
		UNC_H_SBO0_CREDIT_ACQUIRED__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__AD = 0x100, // For AD ring
		UNC_H_SBO0_CREDIT_ACQUIRED__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__BL = 0x200, // For BL ring
		UNC_H_SBO0_CREDIT_OCCUPANCY = 0x6a, // SBO0 credits occupancy
		UNC_H_SBO0_CREDIT_OCCUPANCY__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__AD = 0x100, // For AD ring
		UNC_H_SBO0_CREDIT_OCCUPANCY__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__BL = 0x200, // For BL ring
		UNC_H_SBO1_CREDIT_ACQUIRED = 0x69, // SBO1 credits acquired
		UNC_H_SBO1_CREDIT_ACQUIRED__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__AD = 0x100, // For AD ring
		UNC_H_SBO1_CREDIT_ACQUIRED__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__BL = 0x200, // For BL ring
		UNC_H_SBO0_CREDIT_OCCUPANCY__REPEAT__1 = 0x6b, // SBO1 credits occupancy
		UNC_H_SBO0_CREDIT_OCCUPANCY__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__AD__REPEAT__1 = 0x100, // For AD ring
		UNC_H_SBO0_CREDIT_OCCUPANCY__MASK__HSWEP_UNC_H_SBO0_CREDITS_ACQUIRED__BL__REPEAT__1 = 0x200, // For BL ring
		UNC_H_SNOOPS_RSP_AFTER_DATA = 0xa, // Number of reads when the snoops was on the critical path to the data return
		UNC_H_SNOOPS_RSP_AFTER_DATA__MASK__HSWEP_UNC_H_SNOOPS_RSP_AFTER_DATA__LOCAL = 0x100, // Local
		UNC_H_SNOOPS_RSP_AFTER_DATA__MASK__HSWEP_UNC_H_SNOOPS_RSP_AFTER_DATA__REMOTE = 0x200, // Remote
		UNC_H_SNOOPS_CYCLES_NE = 0x8, // Number of cycles when one or more snoops are outstanding
		UNC_H_SNOOPS_CYCLES_NE__MASK__HSWEP_UNC_H_SNOOPS_CYCLES_NE__ALL = 0x300, // Local
		UNC_H_SNOOPS_CYCLES_NE__MASK__HSWEP_UNC_H_SNOOPS_CYCLES_NE__LOCAL = 0x100, // Local
		UNC_H_SNOOPS_CYCLES_NE__MASK__HSWEP_UNC_H_SNOOPS_CYCLES_NE__REMOTE = 0x200, // Remote
		UNC_H_SNOOPS_OCCUPANCY = 0x9, // Tracker snoops outstanding accumulator
		UNC_H_SNOOPS_OCCUPANCY__MASK__HSWEP_UNC_H_SNOOPS_RSP_AFTER_DATA__LOCAL = 0x100, // Local
		UNC_H_SNOOPS_OCCUPANCY__MASK__HSWEP_UNC_H_SNOOPS_RSP_AFTER_DATA__REMOTE = 0x200, // Remote
		UNC_H_STALL_NO_SBO_CREDIT = 0x6c, // Stalls on no SBO credits
		UNC_H_STALL_NO_SBO_CREDIT__MASK__HSWEP_UNC_H_STALL_NO_SBO_CREDIT__SBO0_AD = 0x100, // No credit for SBO0 AD Ring
		UNC_H_STALL_NO_SBO_CREDIT__MASK__HSWEP_UNC_H_STALL_NO_SBO_CREDIT__SBO1_AD = 0x200, // No credit for SBO1 AD Ring
		UNC_H_STALL_NO_SBO_CREDIT__MASK__HSWEP_UNC_H_STALL_NO_SBO_CREDIT__SBO0_BL = 0x400, // No credit for SBO0 BL Ring
		UNC_H_STALL_NO_SBO_CREDIT__MASK__HSWEP_UNC_H_STALL_NO_SBO_CREDIT__SBO1_BL = 0x800, // No credit for SBO1 BL Ring
		UNC_H_TRACKER_CYCLES_NE = 0x3, // Tracker cycles not empty
		UNC_H_TRACKER_CYCLES_NE__MASK__HSWEP_UNC_H_SNOOPS_CYCLES_NE__ALL = 0x300, // Local
		UNC_H_TRACKER_CYCLES_NE__MASK__HSWEP_UNC_H_SNOOPS_CYCLES_NE__LOCAL = 0x100, // Local
		UNC_H_TRACKER_CYCLES_NE__MASK__HSWEP_UNC_H_SNOOPS_CYCLES_NE__REMOTE = 0x200, // Remote
		UNC_H_TRACKER_OCCUPANCY = 0x4, // Tracker occupancy accumulator
		UNC_H_TRACKER_OCCUPANCY__MASK__HSWEP_UNC_H_TRACKER_OCCUPANCY__READS_LOCAL = 0x400, // Local read requests
		UNC_H_TRACKER_OCCUPANCY__MASK__HSWEP_UNC_H_TRACKER_OCCUPANCY__READS_REMOTE = 0x800, // Remote read requests
		UNC_H_TRACKER_OCCUPANCY__MASK__HSWEP_UNC_H_TRACKER_OCCUPANCY__WRITES_LOCAL = 0x1000, // Local write requests
		UNC_H_TRACKER_OCCUPANCY__MASK__HSWEP_UNC_H_TRACKER_OCCUPANCY__WRITES_REMOTE = 0x2000, // Remote write requests
		UNC_H_TRACKER_OCCUPANCY__MASK__HSWEP_UNC_H_TRACKER_OCCUPANCY__INVITOE_LOCAL = 0x4000, // Local InvItoE requests
		UNC_H_TRACKER_PENDING_OCCUPANCY = 0x5, // Data pending occupancy accumulator
		UNC_H_TRACKER_PENDING_OCCUPANCY__MASK__HSWEP_UNC_H_SNOOPS_RSP_AFTER_DATA__LOCAL = 0x100, // Local
		UNC_H_TRACKER_PENDING_OCCUPANCY__MASK__HSWEP_UNC_H_SNOOPS_RSP_AFTER_DATA__REMOTE = 0x200, // Remote
		UNC_H_TXR_STARVED = 0x6d, // Injection starvation
		UNC_H_TXR_STARVED__MASK__HSWEP_UNC_H_TXR_STARVED__INVITOE_REMOTE = 0x8000, // Remote InvItoE requests
		UNC_H_TXR_STARVED__MASK__HSWEP_UNC_H_TXR_STARVED__BL = 0x200, // For BL ring
		
	};
};

namespace hswep_unc_h = optkit::intel::hswep_unc_h;