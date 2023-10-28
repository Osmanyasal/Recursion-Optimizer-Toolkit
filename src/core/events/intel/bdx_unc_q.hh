#include <cstdint>
#include <intel_priv.hh>
namespace optkit::intel{
	enum class bdx_unc_q : uint64_t {
		UNC_Q_CLOCKTICKS = 0x14, // Counts the number of clocks in the QPI LL.  This clock runs at 1/4th the GT/s speed of the QPI link.  For example
		UNC_Q_CTO_COUNT = 0x38 | (1 << 21), // Counts the number of CTO (cluster trigger outs) events that were asserted across the two slots.  If both slots trigger in a given cycle
		UNC_Q_DIRECT2CORE = 0x13, // Counts the number of DRS packets that we attempted to do direct2core on.  There are 4 mutually exclusive filters.  Filter [0] can be used to get successful spawns
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_CREDITS = 0x200, // Direct 2 Core Spawning -- Spawn Failure - Egress Credits
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_CREDITS_MISS = 0x2000, // Direct 2 Core Spawning -- Spawn Failure - Egress and RBT Miss
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_CREDITS_RBT = 0x800, // Direct 2 Core Spawning -- Spawn Failure - Egress and RBT Invalid
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_CREDITS_RBT_MISS = 0x8000, // Direct 2 Core Spawning -- Spawn Failure - Egress and RBT Miss
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_MISS = 0x1000, // Direct 2 Core Spawning -- Spawn Failure - RBT Miss
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_RBT_HIT = 0x400, // Direct 2 Core Spawning -- Spawn Failure - RBT Invalid
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__FAILURE_RBT_MISS = 0x4000, // Direct 2 Core Spawning -- Spawn Failure - RBT Miss and Invalid
		UNC_Q_DIRECT2CORE__MASK__BDX_UNC_Q_DIRECT2CORE__SUCCESS_RBT_HIT = 0x100, // Direct 2 Core Spawning -- Spawn Success
		UNC_Q_L1_POWER_CYCLES = 0x12, // Number of QPI qfclk cycles spent in L1 power mode.  L1 is a mode that totally shuts down a QPI link.  Use edge detect to count the number of instances when the QPI link entered L1.  Link power states are per link and per direction
		UNC_Q_RXL0P_POWER_CYCLES = 0x10, // Number of QPI qfclk cycles spent in L0p power mode.  L0p is a mode where we disable 1/2 of the QPI lanes
		UNC_Q_RXL0_POWER_CYCLES = 0xf, // Number of QPI qfclk cycles spent in L0 power mode in the Link Layer.  L0 is the default mode which provides the highest performance with the most power.  Use edge detect to count the number of instances that the link entered L0.  Link power states are per link and per direction
		UNC_Q_RXL_BYPASSED = 0x9, // Counts the number of times that an incoming flit was able to bypass the flit buffer and pass directly across the BGF and into the Egress.  This is a latency optimization
		UNC_Q_RXL_CREDITS_CONSUMED_VN0 = 0x1e | (1 << 21), // Counts the number of times that an RxQ VN0 credit was consumed (i.e. message uses a VN0 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.
		UNC_Q_RXL_CREDITS_CONSUMED_VN0__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__DRS = 0x100, // VN0 Credit Consumed -- DRS
		UNC_Q_RXL_CREDITS_CONSUMED_VN0__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__HOM = 0x800, // VN0 Credit Consumed -- HOM
		UNC_Q_RXL_CREDITS_CONSUMED_VN0__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__NCB = 0x200, // VN0 Credit Consumed -- NCB
		UNC_Q_RXL_CREDITS_CONSUMED_VN0__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__NCS = 0x400, // VN0 Credit Consumed -- NCS
		UNC_Q_RXL_CREDITS_CONSUMED_VN0__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__NDR = 0x2000, // VN0 Credit Consumed -- NDR
		UNC_Q_RXL_CREDITS_CONSUMED_VN0__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__SNP = 0x1000, // VN0 Credit Consumed -- SNP
		UNC_Q_RXL_CREDITS_CONSUMED_VN1 = 0x39 | (1 << 21), // Counts the number of times that an RxQ VN1 credit was consumed (i.e. message uses a VN1 credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.
		UNC_Q_RXL_CREDITS_CONSUMED_VN1__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__DRS = 0x100, // VN0 Credit Consumed -- DRS
		UNC_Q_RXL_CREDITS_CONSUMED_VN1__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__HOM = 0x800, // VN0 Credit Consumed -- HOM
		UNC_Q_RXL_CREDITS_CONSUMED_VN1__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__NCB = 0x200, // VN0 Credit Consumed -- NCB
		UNC_Q_RXL_CREDITS_CONSUMED_VN1__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__NCS = 0x400, // VN0 Credit Consumed -- NCS
		UNC_Q_RXL_CREDITS_CONSUMED_VN1__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__NDR = 0x2000, // VN0 Credit Consumed -- NDR
		UNC_Q_RXL_CREDITS_CONSUMED_VN1__MASK__BDX_UNC_Q_RXL_CREDITS_CONSUMED_VN0__SNP = 0x1000, // VN0 Credit Consumed -- SNP
		UNC_Q_RXL_CREDITS_CONSUMED_VNA = 0x1d | (1 << 21), // Counts the number of times that an RxQ VNA credit was consumed (i.e. message uses a VNA credit for the Rx Buffer).  This includes packets that went through the RxQ and those that were bypasssed.
		UNC_Q_RXL_CYCLES_NE = 0xa, // Counts the number of cycles that the QPI RxQ was not empty.  Generally
		UNC_Q_RXL_FLITS_G0 = 0x1, // Counts the number of flits received from the QPI Link.
		UNC_Q_RXL_FLITS_G0__MASK__BDX_UNC_Q_RXL_FLITS_G0__IDLE = 0x200, // Number of data flits over QPI that do not hold payload. When QPI is not in a power saving state
		UNC_Q_RXL_FLITS_G0__MASK__BDX_UNC_Q_RXL_FLITS_G0__DATA = 0x200, // Number of data flits over QPI
		UNC_Q_RXL_FLITS_G0__MASK__BDX_UNC_Q_RXL_FLITS_G0__NON_DATA = 0x400, // Number of non-NULL non-data flits over QPI
		UNC_Q_RXL_FLITS_G1 = 0x2 | (1 << 21), // Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for SNP
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__DRS = 0x1800, // Flits Received - Group 1 -- DRS Flits (both Header and Data)
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__DRS_DATA = 0x800, // Flits Received - Group 1 -- DRS Data Flits
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__DRS_NONDATA = 0x1000, // Flits Received - Group 1 -- DRS Header Flits
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__HOM = 0x600, // Flits Received - Group 1 -- HOM Flits
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__HOM_NONREQ = 0x400, // Flits Received - Group 1 -- HOM Non-Request Flits
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__HOM_REQ = 0x200, // Flits Received - Group 1 -- HOM Request Flits
		UNC_Q_RXL_FLITS_G1__MASK__BDX_UNC_Q_RXL_FLITS_G1__SNP = 0x100, // Flits Received - Group 1 -- SNP Flits
		UNC_Q_RXL_FLITS_G2 = 0x3 | (1 << 21), // Counts the number of flits received from the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR
		UNC_Q_RXL_FLITS_G2__MASK__BDX_UNC_Q_RXL_FLITS_G2__NCB = 0xc00, // Flits Received - Group 2 -- Non-Coherent Rx Flits
		UNC_Q_RXL_FLITS_G2__MASK__BDX_UNC_Q_RXL_FLITS_G2__NCB_DATA = 0x400, // Flits Received - Group 2 -- Non-Coherent data Rx Flits
		UNC_Q_RXL_FLITS_G2__MASK__BDX_UNC_Q_RXL_FLITS_G2__NCB_NONDATA = 0x800, // Flits Received - Group 2 -- Non-Coherent non-data Rx Flits
		UNC_Q_RXL_FLITS_G2__MASK__BDX_UNC_Q_RXL_FLITS_G2__NCS = 0x1000, // Flits Received - Group 2 -- Non-Coherent standard Rx Flits
		UNC_Q_RXL_FLITS_G2__MASK__BDX_UNC_Q_RXL_FLITS_G2__NDR_AD = 0x100, // Flits Received - Group 2 -- Non-Data Response Rx Flits - AD
		UNC_Q_RXL_FLITS_G2__MASK__BDX_UNC_Q_RXL_FLITS_G2__NDR_AK = 0x200, // Flits Received - Group 2 -- Non-Data Response Rx Flits - AK
		UNC_Q_RXL_INSERTS = 0x8, // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_DRS = 0x9 | (1 << 21), // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_DRS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_INSERTS_DRS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_INSERTS_HOM = 0xc | (1 << 21), // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_HOM__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_INSERTS_HOM__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_INSERTS_NCB = 0xa | (1 << 21), // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_NCB__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_INSERTS_NCB__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_INSERTS_NCS = 0xb | (1 << 21), // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_NCS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_INSERTS_NCS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_INSERTS_NDR = 0xe | (1 << 21), // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_NDR__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_INSERTS_NDR__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_INSERTS_SNP = 0xd | (1 << 21), // Number of allocations into the QPI Rx Flit Buffer.  Generally
		UNC_Q_RXL_INSERTS_SNP__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_INSERTS_SNP__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_OCCUPANCY = 0xb, // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_DRS = 0x15 | (1 << 21), // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_DRS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_OCCUPANCY_DRS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_OCCUPANCY_HOM = 0x18 | (1 << 21), // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_HOM__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_OCCUPANCY_HOM__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_OCCUPANCY_NCB = 0x16 | (1 << 21), // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_NCB__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_OCCUPANCY_NCB__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_OCCUPANCY_NCS = 0x17 | (1 << 21), // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_NCS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_OCCUPANCY_NCS__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_OCCUPANCY_NDR = 0x1a | (1 << 21), // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_NDR__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_OCCUPANCY_NDR__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_RXL_OCCUPANCY_SNP = 0x19 | (1 << 21), // Accumulates the number of elements in the QPI RxQ in each cycle.  Generally
		UNC_Q_RXL_OCCUPANCY_SNP__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_RXL_OCCUPANCY_SNP__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXL0P_POWER_CYCLES = 0xd, // Number of QPI qfclk cycles spent in L0p power mode.  L0p is a mode where we disable 1/2 of the QPI lanes
		UNC_Q_TXL0_POWER_CYCLES = 0xc, // Number of QPI qfclk cycles spent in L0 power mode in the Link Layer.  L0 is the default mode which provides the highest performance with the most power.  Use edge detect to count the number of instances that the link entered L0.  Link power states are per link and per direction
		UNC_Q_TXL_BYPASSED = 0x5, // Counts the number of times that an incoming flit was able to bypass the Tx flit buffer and pass directly out the QPI Link. Generally
		UNC_Q_TXL_CYCLES_NE = 0x6, // Counts the number of cycles when the TxQ is not empty. Generally
		UNC_Q_TXL_FLITS_G0 = 0x0, // Counts the number of flits transmitted across the QPI Link.  It includes filters for Idle
		UNC_Q_TXL_FLITS_G0__MASK__BDX_UNC_Q_TXL_FLITS_G0__DATA = 0x200, // Flits Transferred - Group 0 -- Data Tx Flits
		UNC_Q_TXL_FLITS_G0__MASK__BDX_UNC_Q_TXL_FLITS_G0__NON_DATA = 0x400, // Flits Transferred - Group 0 -- Non-Data protocol Tx Flits
		UNC_Q_TXL_FLITS_G1 = 0x0 | (1 << 21), // Counts the number of flits transmitted across the QPI Link.  It includes filters for Idle
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__DRS = 0x1800, // Flits Transferred - Group 1 -- DRS Flits (both Header and Data)
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__DRS_DATA = 0x800, // Flits Transferred - Group 1 -- DRS Data Flits
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__DRS_NONDATA = 0x1000, // Flits Transferred - Group 1 -- DRS Header Flits
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__HOM = 0x600, // Flits Transferred - Group 1 -- HOM Flits
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__HOM_NONREQ = 0x400, // Flits Transferred - Group 1 -- HOM Non-Request Flits
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__HOM_REQ = 0x200, // Flits Transferred - Group 1 -- HOM Request Flits
		UNC_Q_TXL_FLITS_G1__MASK__BDX_UNC_Q_TXL_FLITS_G1__SNP = 0x100, // Flits Transferred - Group 1 -- SNP Flits
		UNC_Q_TXL_FLITS_G2 = 0x1 | (1 << 21), // Counts the number of flits trasmitted across the QPI Link.  This is one of three groups that allow us to track flits.  It includes filters for NDR
		UNC_Q_TXL_FLITS_G2__MASK__BDX_UNC_Q_TXL_FLITS_G2__NCB = 0xc00, // Flits Transferred - Group 2 -- Non-Coherent Bypass Tx Flits
		UNC_Q_TXL_FLITS_G2__MASK__BDX_UNC_Q_TXL_FLITS_G2__NCB_DATA = 0x400, // Flits Transferred - Group 2 -- Non-Coherent data Tx Flits
		UNC_Q_TXL_FLITS_G2__MASK__BDX_UNC_Q_TXL_FLITS_G2__NCB_NONDATA = 0x800, // Flits Transferred - Group 2 -- Non-Coherent non-data Tx Flits
		UNC_Q_TXL_FLITS_G2__MASK__BDX_UNC_Q_TXL_FLITS_G2__NCS = 0x1000, // Flits Transferred - Group 2 -- Non-Coherent standard Tx Flits
		UNC_Q_TXL_FLITS_G2__MASK__BDX_UNC_Q_TXL_FLITS_G2__NDR_AD = 0x100, // Flits Transferred - Group 2 -- Non-Data Response Tx Flits - AD
		UNC_Q_TXL_FLITS_G2__MASK__BDX_UNC_Q_TXL_FLITS_G2__NDR_AK = 0x200, // Flits Transferred - Group 2 -- Non-Data Response Tx Flits - AK
		UNC_Q_TXL_INSERTS = 0x4, // Number of allocations into the QPI Tx Flit Buffer.  Generally
		UNC_Q_TXL_OCCUPANCY = 0x7, // Accumulates the number of flits in the TxQ.  Generally
		UNC_Q_TXR_AD_HOM_CREDIT_ACQUIRED = 0x26 | (1 << 21), // Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle. Flow Control FIFO for Home messages on AD.
		UNC_Q_TXR_AD_HOM_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_AD_HOM_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_AD_HOM_CREDIT_OCCUPANCY = 0x22 | (1 << 21), // Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle.  Flow Control FIFO for HOM messages on AD.
		UNC_Q_TXR_AD_HOM_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_AD_HOM_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_AD_NDR_CREDIT_ACQUIRED = 0x28 | (1 << 21), // Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle.  Flow Control FIFO for NDR messages on AD.
		UNC_Q_TXR_AD_NDR_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_AD_NDR_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_AD_NDR_CREDIT_OCCUPANCY = 0x24 | (1 << 21), // Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle. Flow Control FIFO  for NDR messages on AD.
		UNC_Q_TXR_AD_NDR_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_AD_NDR_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_AD_SNP_CREDIT_ACQUIRED = 0x27 | (1 << 21), // Number of link layer credits into the R3 (for transactions across the BGF) acquired each cycle.  Flow Control FIFO for Snoop messages on AD.
		UNC_Q_TXR_AD_SNP_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_AD_SNP_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_AD_SNP_CREDIT_OCCUPANCY = 0x23 | (1 << 21), // Occupancy event that tracks the number of link layer credits into the R3 (for transactions across the BGF) available in each cycle.  Flow Control FIFO fro Snoop messages on AD.
		UNC_Q_TXR_AD_SNP_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_AD_SNP_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_AK_NDR_CREDIT_ACQUIRED = 0x29 | (1 << 21), // Number of credits into the R3 (for transactions across the BGF) acquired each cycle. Local NDR message class to AK Egress.
		UNC_Q_TXR_AK_NDR_CREDIT_OCCUPANCY = 0x25 | (1 << 21), // Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  Local NDR message class to AK Egress.
		UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED = 0x2a | (1 << 21), // Number of credits into the R3 (for transactions across the BGF) acquired each cycle. DRS message class to BL Egress.
		UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__VN0 = 0x100, // R3QPI Egress Credit Occupancy - DRS -- for VN0
		UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__VN1 = 0x200, // R3QPI Egress Credit Occupancy - DRS -- for VN1
		UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__VN_SHR = 0x400, // R3QPI Egress Credit Occupancy - DRS -- for Shared VN
		UNC_Q_TXR_BL_DRS_CREDIT_OCCUPANCY = 0x1f | (1 << 21), // Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  DRS message class to BL Egress.
		UNC_Q_TXR_BL_DRS_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__VN0 = 0x100, // R3QPI Egress Credit Occupancy - DRS -- for VN0
		UNC_Q_TXR_BL_DRS_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__VN1 = 0x200, // R3QPI Egress Credit Occupancy - DRS -- for VN1
		UNC_Q_TXR_BL_DRS_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_TXR_BL_DRS_CREDIT_ACQUIRED__VN_SHR = 0x400, // R3QPI Egress Credit Occupancy - DRS -- for Shared VN
		UNC_Q_TXR_BL_NCB_CREDIT_ACQUIRED = 0x2b | (1 << 21), // Number of credits into the R3 (for transactions across the BGF) acquired each cycle. NCB message class to BL Egress.
		UNC_Q_TXR_BL_NCB_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_BL_NCB_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_BL_NCB_CREDIT_OCCUPANCY = 0x20 | (1 << 21), // Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  NCB message class to BL Egress.
		UNC_Q_TXR_BL_NCB_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_BL_NCB_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_BL_NCS_CREDIT_ACQUIRED = 0x2c | (1 << 21), // Number of credits into the R3 (for transactions across the BGF) acquired each cycle. NCS message class to BL Egress.
		UNC_Q_TXR_BL_NCS_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_BL_NCS_CREDIT_ACQUIRED__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_TXR_BL_NCS_CREDIT_OCCUPANCY = 0x21 | (1 << 21), // Occupancy event that tracks the number of credits into the R3 (for transactions across the BGF) available in each cycle.  NCS message class to BL Egress.
		UNC_Q_TXR_BL_NCS_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN0 = 0x100, // for VN0
		UNC_Q_TXR_BL_NCS_CREDIT_OCCUPANCY__MASK__BDX_UNC_Q_RXL_INSERTS_DRS__VN1 = 0x200, // for VN1
		UNC_Q_VNA_CREDIT_RETURNS = 0x1c | (1 << 21), // Number of VNA credits returned.
		UNC_Q_VNA_CREDIT_RETURN_OCCUPANCY = 0x1b | (1 << 21), // Number of VNA credits in the Rx side that are waitng to be returned back across the link.
		
	};
};