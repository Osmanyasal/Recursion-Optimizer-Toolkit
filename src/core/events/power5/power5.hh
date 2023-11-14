#pragma once
#include <cstdint>
namespace optkit::ibm::power5{
	enum power5 : uint64_t {
		PM_LSU_REJECT_RELOAD_CDF = 0x2c6090, // LSU reject due to reload CDF or tag update collision
		PM_FPU1_SINGLE = 0x20e7, // FPU1 executed single precision instruction
		PM_L3SB_REF = 0x701c4, // L3 slice B references
		PM_THRD_PRIO_DIFF_3or4_CYC = 0x430e5, // Cycles thread priority difference is 3 or 4
		PM_INST_FROM_L275_SHR = 0x322096, // Instruction fetched from L2.75 shared
		PM_MRK_DATA_FROM_L375_MOD = 0x1c70a7, // Marked data loaded from L3.75 modified
		PM_DTLB_MISS_4K = 0xc40c0, // Data TLB miss for 4K page
		PM_CLB_FULL_CYC = 0x220e5, // Cycles CLB full
		PM_MRK_ST_CMPL = 0x100003, // Marked store instruction completed
		PM_LSU_FLUSH_LRQ_FULL = 0x320e7, // Flush caused by LRQ full
		PM_MRK_DATA_FROM_L275_SHR = 0x3c7097, // Marked data loaded from L2.75 shared
		PM_1INST_CLB_CYC = 0x400c1, // Cycles 1 instruction in CLB
		PM_MEM_SPEC_RD_CANCEL = 0x721e6, // Speculative memory read cancelled
		PM_MRK_DTLB_MISS_16M = 0xc40c5, // Marked Data TLB misses for 16M page
		PM_FPU_FDIV = 0x100088, // FPU executed FDIV instruction
		PM_FPU_SINGLE = 0x102090, // FPU executed single precision instruction
		PM_FPU0_FMA = 0xc1, // FPU0 executed multiply-add instruction
		PM_SLB_MISS = 0x280088, // SLB misses
		PM_LSU1_FLUSH_LRQ = 0xc00c6, // LSU1 LRQ flushes
		PM_L2SA_ST_HIT = 0x733e0, // L2 slice A store hits
		PM_DTLB_MISS = 0x800c4, // Data TLB misses
		PM_BR_PRED_TA = 0x230e3, // A conditional branch was predicted
		PM_MRK_DATA_FROM_L375_MOD_CYC = 0x4c70a7, // Marked load latency from L3.75 modified
		PM_CMPLU_STALL_FXU = 0x211099, // Completion stall caused by FXU instruction
		PM_EXT_INT = 0x400003, // External interrupts
		PM_MRK_LSU1_FLUSH_LRQ = 0x810c6, // LSU1 marked LRQ flushes
		PM_LSU1_LDF = 0xc50c4, // LSU1 executed Floating Point load instruction
		PM_MRK_ST_GPS = 0x200003, // Marked store sent to GPS
		PM_FAB_CMD_ISSUED = 0x700c7, // Fabric command issued
		PM_LSU0_SRQ_STFWD = 0xc20e0, // LSU0 SRQ store forwarded
		PM_CR_MAP_FULL_CYC = 0x100c4, // Cycles CR logical operation mapper full
		PM_L2SA_RCST_DISP_FAIL_RC_FULL = 0x722e0, // L2 slice A RC store dispatch attempt failed due to all RC full
		PM_MRK_LSU0_FLUSH_ULD = 0x810c0, // LSU0 marked unaligned load flushes
		PM_LSU_FLUSH_SRQ_FULL = 0x330e0, // Flush caused by SRQ full
		PM_FLUSH_IMBAL = 0x330e3, // Flush caused by thread GCT imbalance
		PM_MEM_RQ_DISP_Q16to19 = 0x727e6, // Memory read queue dispatched to queues 16-19
		PM_THRD_PRIO_DIFF_minus3or4_CYC = 0x430e1, // Cycles thread priority difference is -3 or -4
		PM_DATA_FROM_L35_MOD = 0x2c309e, // Data loaded from L3.5 modified
		PM_MEM_HI_PRIO_WR_CMPL = 0x726e6, // High priority write completed
		PM_FPU1_FDIV = 0xc4, // FPU1 executed FDIV instruction
		PM_FPU0_FRSP_FCONV = 0x10c1, // FPU0 executed FRSP or FCONV instructions
		PM_MEM_RQ_DISP = 0x701c6, // Memory read queue dispatched
		PM_LWSYNC_HELD = 0x130e0, // LWSYNC held at dispatch
		PM_FXU_FIN = 0x313088, // FXU produced a result
		PM_DSLB_MISS = 0x800c5, // Data SLB misses
		PM_FXLS1_FULL_CYC = 0x110c4, // Cycles FXU1/LS1 queue full
		PM_DATA_FROM_L275_SHR = 0x3c3097, // Data loaded from L2.75 shared
		PM_THRD_SEL_T0 = 0x410c0, // Decode selected thread 0
		PM_PTEG_RELOAD_VALID = 0x830e4, // PTEG reload valid
		PM_LSU_LMQ_LHR_MERGE = 0xc70e5, // LMQ LHR merges
		PM_MRK_STCX_FAIL = 0x820e6, // Marked STCX failed
		PM_2INST_CLB_CYC = 0x400c2, // Cycles 2 instructions in CLB
		PM_FAB_PNtoVN_DIRECT = 0x723e7, // PN to VN beat went straight to its destination
		PM_PTEG_FROM_L2MISS = 0x38309b, // PTEG loaded from L2 miss
		PM_CMPLU_STALL_LSU = 0x211098, // Completion stall caused by LSU instruction
		PM_MRK_DSLB_MISS = 0xc50c7, // Marked Data SLB misses
		PM_LSU_FLUSH_ULD = 0x1c0088, // LRQ unaligned load flushes
		PM_PTEG_FROM_LMEM = 0x283087, // PTEG loaded from local memory
		PM_MRK_BRU_FIN = 0x200005, // Marked instruction BRU processing finished
		PM_MEM_WQ_DISP_WRITE = 0x703c6, // Memory write queue dispatched due to write
		PM_MRK_DATA_FROM_L275_MOD_CYC = 0x4c70a3, // Marked load latency from L2.75 modified
		PM_LSU1_NCLD = 0xc50c5, // LSU1 non-cacheable loads
		PM_L2SA_RCLD_DISP_FAIL_OTHER = 0x731e0, // L2 slice A RC load dispatch attempt failed due to other reasons
		PM_SNOOP_PW_RETRY_WQ_PWQ = 0x717c6, // Snoop partial-write retry due to collision with active write or partial-write queue
		PM_FPR_MAP_FULL_CYC = 0x100c1, // Cycles FPR mapper full
		PM_FPU1_FULL_CYC = 0x100c7, // Cycles FPU1 issue queue full
		PM_L3SA_ALL_BUSY = 0x721e3, // L3 slice A active for every cycle all CI/CO machines busy
		PM_3INST_CLB_CYC = 0x400c3, // Cycles 3 instructions in CLB
		PM_MEM_PWQ_DISP_Q2or3 = 0x734e6, // Memory partial-write queue dispatched to Write Queue 2 or 3
		PM_L2SA_SHR_INV = 0x710c0, // L2 slice A transition from shared to invalid
		PM_THRESH_TIMEO = 0x30000b, // Threshold timeout
		PM_L2SA_RC_DISP_FAIL_CO_BUSY_ALL = 0x713c0, // L2 slice A RC dispatch attempt failed due to all CO busy
		PM_THRD_SEL_OVER_GCT_IMBAL = 0x410c4, // Thread selection overrides caused by GCT imbalance
		PM_FPU_FSQRT = 0x200090, // FPU executed FSQRT instruction
		PM_MRK_LSU0_FLUSH_LRQ = 0x810c2, // LSU0 marked LRQ flushes
		PM_PMC1_OVERFLOW = 0x20000a, // PMC1 Overflow
		PM_L3SC_SNOOP_RETRY = 0x731e5, // L3 slice C snoop retries
		PM_DATA_TABLEWALK_CYC = 0x800c7, // Cycles doing data tablewalks
		PM_THRD_PRIO_6_CYC = 0x420e5, // Cycles thread running at priority level 6
		PM_FPU_FEST = 0x401090, // FPU executed FEST instruction
		PM_FAB_M1toP1_SIDECAR_EMPTY = 0x702c7, // M1 to P1 sidecar empty
		PM_MRK_DATA_FROM_RMEM = 0x1c70a1, // Marked data loaded from remote memory
		PM_MRK_DATA_FROM_L35_MOD_CYC = 0x4c70a6, // Marked load latency from L3.5 modified
		PM_MEM_PWQ_DISP = 0x704c6, // Memory partial-write queue dispatched
		PM_FAB_P1toM1_SIDECAR_EMPTY = 0x701c7, // P1 to M1 sidecar empty
		PM_LD_MISS_L1_LSU0 = 0xc10c2, // LSU0 L1 D cache load misses
		PM_SNOOP_PARTIAL_RTRY_QFULL = 0x730e6, // Snoop partial write retry due to partial-write queues full
		PM_FPU1_STALL3 = 0x20e5, // FPU1 stalled in pipe3
		PM_GCT_USAGE_80to99_CYC = 0x30001f, // Cycles GCT 80-99% full
		PM_WORK_HELD = 0x40000c, // Work held
		PM_INST_CMPL = 0x100009, // Instructions completed
		PM_LSU1_FLUSH_UST = 0xc00c5, // LSU1 unaligned store flushes
		PM_FXU_IDLE = 0x100012, // FXU idle
		PM_LSU0_FLUSH_ULD = 0xc00c0, // LSU0 unaligned load flushes
		PM_LSU1_REJECT_LMQ_FULL = 0xc60e5, // LSU1 reject due to LMQ full or missed data coming
		PM_GRP_DISP_REJECT = 0x120e4, // Group dispatch rejected
		PM_L2SA_MOD_INV = 0x730e0, // L2 slice A transition from modified to invalid
		PM_PTEG_FROM_L25_SHR = 0x183097, // PTEG loaded from L2.5 shared
		PM_FAB_CMD_RETRIED = 0x710c7, // Fabric command retried
		PM_L3SA_SHR_INV = 0x710c3, // L3 slice A transition from shared to invalid
		PM_L2SB_RC_DISP_FAIL_CO_BUSY_ALL = 0x713c1, // L2 slice B RC dispatch attempt failed due to all CO busy
		PM_L2SA_RCST_DISP_FAIL_ADDR = 0x712c0, // L2 slice A RC store dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_L2SA_RCLD_DISP_FAIL_RC_FULL = 0x721e0, // L2 slice A RC load dispatch attempt failed due to all RC full
		PM_PTEG_FROM_L375_MOD = 0x1830a7, // PTEG loaded from L3.75 modified
		PM_MRK_LSU1_FLUSH_UST = 0x810c5, // LSU1 marked unaligned store flushes
		PM_BR_ISSUED = 0x230e4, // Branches issued
		PM_MRK_GRP_BR_REDIR = 0x212091, // Group experienced marked branch redirect
		PM_EE_OFF = 0x130e3, // Cycles MSR(EE) bit off
		PM_MEM_RQ_DISP_Q4to7 = 0x712c6, // Memory read queue dispatched to queues 4-7
		PM_MEM_FAST_PATH_RD_DISP = 0x713e6, // Fast path memory read dispatched
		PM_INST_FROM_L3 = 0x12208d, // Instruction fetched from L3
		PM_ITLB_MISS = 0x800c0, // Instruction TLB misses
		PM_FXU1_BUSY_FXU0_IDLE = 0x400012, // FXU1 busy FXU0 idle
		PM_FXLS_FULL_CYC = 0x411090, // Cycles FXLS queue is full
		PM_DTLB_REF_4K = 0xc40c2, // Data TLB reference for 4K page
		PM_GRP_DISP_VALID = 0x120e3, // Group dispatch valid
		PM_LSU_FLUSH_UST = 0x2c0088, // SRQ unaligned store flushes
		PM_FXU1_FIN = 0x130e6, // FXU1 produced a result
		PM_THRD_PRIO_4_CYC = 0x420e3, // Cycles thread running at priority level 4
		PM_MRK_DATA_FROM_L35_MOD = 0x2c709e, // Marked data loaded from L3.5 modified
		PM_4INST_CLB_CYC = 0x400c4, // Cycles 4 instructions in CLB
		PM_MRK_DTLB_REF_16M = 0xc40c7, // Marked Data TLB reference for 16M page
		PM_INST_FROM_L375_MOD = 0x42209d, // Instruction fetched from L3.75 modified
		PM_L2SC_RCST_DISP_FAIL_ADDR = 0x712c2, // L2 slice C RC store dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_GRP_CMPL = 0x300013, // Group completed
		PM_FPU1_1FLOP = 0xc7, // FPU1 executed add
		PM_FPU_FRSP_FCONV = 0x301090, // FPU executed FRSP or FCONV instructions
		PM_5INST_CLB_CYC = 0x400c5, // Cycles 5 instructions in CLB
		PM_L3SC_REF = 0x701c5, // L3 slice C references
		PM_THRD_L2MISS_BOTH_CYC = 0x410c7, // Cycles both threads in L2 misses
		PM_MEM_PW_GATH = 0x714c6, // Memory partial-write gathered
		PM_FAB_PNtoNN_SIDECAR = 0x713c7, // PN to NN beat went to sidecar first
		PM_FAB_DCLAIM_ISSUED = 0x720e7, // dclaim issued
		PM_GRP_IC_MISS = 0x120e7, // Group experienced I cache miss
		PM_INST_FROM_L35_SHR = 0x12209d, // Instruction fetched from L3.5 shared
		PM_LSU_LMQ_FULL_CYC = 0xc30e7, // Cycles LMQ full
		PM_MRK_DATA_FROM_L2_CYC = 0x2c70a0, // Marked load latency from L2
		PM_LSU_SRQ_SYNC_CYC = 0x830e5, // SRQ sync duration
		PM_LSU0_BUSY_REJECT = 0xc20e3, // LSU0 busy due to reject
		PM_LSU_REJECT_ERAT_MISS = 0x1c6090, // LSU reject due to ERAT miss
		PM_MRK_DATA_FROM_RMEM_CYC = 0x4c70a1, // Marked load latency from remote memory
		PM_DATA_FROM_L375_SHR = 0x3c309e, // Data loaded from L3.75 shared
		PM_FPU0_FMOV_FEST = 0x10c0, // FPU0 executed FMOV or FEST instructions
		PM_PTEG_FROM_L25_MOD = 0x283097, // PTEG loaded from L2.5 modified
		PM_LD_REF_L1_LSU0 = 0xc10c0, // LSU0 L1 D cache load references
		PM_THRD_PRIO_7_CYC = 0x420e6, // Cycles thread running at priority level 7
		PM_LSU1_FLUSH_SRQ = 0xc00c7, // LSU1 SRQ lhs flushes
		PM_L2SC_RCST_DISP = 0x702c2, // L2 slice C RC store dispatch attempt
		PM_CMPLU_STALL_DIV = 0x411099, // Completion stall caused by DIV instruction
		PM_MEM_RQ_DISP_Q12to15 = 0x732e6, // Memory read queue dispatched to queues 12-15
		PM_INST_FROM_L375_SHR = 0x32209d, // Instruction fetched from L3.75 shared
		PM_ST_REF_L1 = 0x3c1090, // L1 D cache store references
		PM_L3SB_ALL_BUSY = 0x721e4, // L3 slice B active for every cycle all CI/CO machines busy
		PM_FAB_P1toVNorNN_SIDECAR_EMPTY = 0x711c7, // P1 to VN/NN sidecar empty
		PM_MRK_DATA_FROM_L275_SHR_CYC = 0x2c70a3, // Marked load latency from L2.75 shared
		PM_FAB_HOLDtoNN_EMPTY = 0x722e7, // Hold buffer to NN empty
		PM_DATA_FROM_LMEM = 0x2c3087, // Data loaded from local memory
		PM_RUN_CYC = 0x100005, // Run cycles
		PM_PTEG_FROM_RMEM = 0x1830a1, // PTEG loaded from remote memory
		PM_L2SC_RCLD_DISP = 0x701c2, // L2 slice C RC load dispatch attempt
		PM_LSU0_LDF = 0xc50c0, // LSU0 executed Floating Point load instruction
		PM_LSU_LRQ_S0_VALID = 0xc20e2, // LRQ slot 0 valid
		PM_PMC3_OVERFLOW = 0x40000a, // PMC3 Overflow
		PM_MRK_IMR_RELOAD = 0x820e2, // Marked IMR reloaded
		PM_MRK_GRP_TIMEO = 0x40000b, // Marked group completion timeout
		PM_ST_MISS_L1 = 0xc10c3, // L1 D cache store misses
		PM_STOP_COMPLETION = 0x300018, // Completion stopped
		PM_LSU_BUSY_REJECT = 0x1c2090, // LSU busy due to reject
		PM_ISLB_MISS = 0x800c1, // Instruction SLB misses
		PM_CYC = 0xf, // Processor cycles
		PM_THRD_ONE_RUN_CYC = 0x10000b, // One of the threads in run cycles
		PM_GRP_BR_REDIR_NONSPEC = 0x112091, // Group experienced non-speculative branch redirect
		PM_LSU1_SRQ_STFWD = 0xc20e4, // LSU1 SRQ store forwarded
		PM_L3SC_MOD_INV = 0x730e5, // L3 slice C transition from modified to invalid
		PM_L2_PREF = 0xc50c3, // L2 cache prefetches
		PM_GCT_NOSLOT_BR_MPRED = 0x41009c, // No slot in GCT caused by branch mispredict
		PM_MRK_DATA_FROM_L25_MOD = 0x2c7097, // Marked data loaded from L2.5 modified
		PM_L2SB_MOD_INV = 0x730e1, // L2 slice B transition from modified to invalid
		PM_L2SB_ST_REQ = 0x723e1, // L2 slice B store requests
		PM_MRK_L1_RELOAD_VALID = 0xc70e4, // Marked L1 reload data source valid
		PM_L3SB_HIT = 0x711c4, // L3 slice B hits
		PM_L2SB_SHR_MOD = 0x700c1, // L2 slice B transition from shared to modified
		PM_EE_OFF_EXT_INT = 0x130e7, // Cycles MSR(EE) bit off and external interrupt pending
		PM_1PLUS_PPC_CMPL = 0x100013, // One or more PPC instruction completed
		PM_L2SC_SHR_MOD = 0x700c2, // L2 slice C transition from shared to modified
		PM_PMC6_OVERFLOW = 0x30001a, // PMC6 Overflow
		PM_LSU_LRQ_FULL_CYC = 0x110c2, // Cycles LRQ full
		PM_IC_PREF_INSTALL = 0x210c7, // Instruction prefetched installed in prefetch buffer
		PM_TLB_MISS = 0x180088, // TLB misses
		PM_GCT_FULL_CYC = 0x100c0, // Cycles GCT full
		PM_FXU_BUSY = 0x200012, // FXU busy
		PM_MRK_DATA_FROM_L3_CYC = 0x2c70a4, // Marked load latency from L3
		PM_LSU_REJECT_LMQ_FULL = 0x2c6088, // LSU reject due to LMQ full or missed data coming
		PM_LSU_SRQ_S0_ALLOC = 0xc20e5, // SRQ slot 0 allocated
		PM_GRP_MRK = 0x100014, // Group marked in IDU
		PM_INST_FROM_L25_SHR = 0x122096, // Instruction fetched from L2.5 shared
		PM_FPU1_FIN = 0x10c7, // FPU1 produced a result
		PM_DC_PREF_STREAM_ALLOC = 0x830e7, // D cache new prefetch stream allocated
		PM_BR_MPRED_TA = 0x230e6, // Branch mispredictions due to target address
		PM_CRQ_FULL_CYC = 0x110c1, // Cycles CR issue queue full
		PM_L2SA_RCLD_DISP = 0x701c0, // L2 slice A RC load dispatch attempt
		PM_SNOOP_WR_RETRY_QFULL = 0x710c6, // Snoop read retry due to read queue full
		PM_MRK_DTLB_REF_4K = 0xc40c3, // Marked Data TLB reference for 4K page
		PM_LSU_SRQ_S0_VALID = 0xc20e1, // SRQ slot 0 valid
		PM_LSU0_FLUSH_LRQ = 0xc00c2, // LSU0 LRQ flushes
		PM_INST_FROM_L275_MOD = 0x422096, // Instruction fetched from L2.75 modified
		PM_GCT_EMPTY_CYC = 0x200004, // Cycles GCT empty
		PM_LARX_LSU0 = 0x820e7, // Larx executed on LSU0
		PM_THRD_PRIO_DIFF_5or6_CYC = 0x430e6, // Cycles thread priority difference is 5 or 6
		PM_SNOOP_RETRY_1AHEAD = 0x725e6, // Snoop retry due to one ahead collision
		PM_FPU1_FSQRT = 0xc6, // FPU1 executed FSQRT instruction
		PM_MRK_LD_MISS_L1_LSU1 = 0x820e4, // LSU1 marked L1 D cache load misses
		PM_MRK_FPU_FIN = 0x300014, // Marked instruction FPU processing finished
		PM_THRD_PRIO_5_CYC = 0x420e4, // Cycles thread running at priority level 5
		PM_MRK_DATA_FROM_LMEM = 0x2c7087, // Marked data loaded from local memory
		PM_FPU1_FRSP_FCONV = 0x10c5, // FPU1 executed FRSP or FCONV instructions
		PM_SNOOP_TLBIE = 0x800c3, // Snoop TLBIE
		PM_L3SB_SNOOP_RETRY = 0x731e4, // L3 slice B snoop retries
		PM_FAB_VBYPASS_EMPTY = 0x731e7, // Vertical bypass buffer empty
		PM_MRK_DATA_FROM_L275_MOD = 0x1c70a3, // Marked data loaded from L2.75 modified
		PM_6INST_CLB_CYC = 0x400c6, // Cycles 6 instructions in CLB
		PM_L2SB_RCST_DISP = 0x702c1, // L2 slice B RC store dispatch attempt
		PM_FLUSH = 0x110c7, // Flushes
		PM_L2SC_MOD_INV = 0x730e2, // L2 slice C transition from modified to invalid
		PM_FPU_DENORM = 0x102088, // FPU received denormalized data
		PM_L3SC_HIT = 0x711c5, // L3 slice C hits
		PM_SNOOP_WR_RETRY_RQ = 0x706c6, // Snoop write/dclaim retry due to collision with active read queue
		PM_LSU1_REJECT_SRQ = 0xc60e4, // LSU1 SRQ lhs rejects
		PM_IC_PREF_REQ = 0x220e6, // Instruction prefetch requests
		PM_L3SC_ALL_BUSY = 0x721e5, // L3 slice C active for every cycle all CI/CO machines busy
		PM_MRK_GRP_IC_MISS = 0x412091, // Group experienced marked I cache miss
		PM_GCT_NOSLOT_IC_MISS = 0x21009c, // No slot in GCT caused by I cache miss
		PM_MRK_DATA_FROM_L3 = 0x1c708e, // Marked data loaded from L3
		PM_GCT_NOSLOT_SRQ_FULL = 0x310084, // No slot in GCT caused by SRQ full
		PM_THRD_SEL_OVER_ISU_HOLD = 0x410c5, // Thread selection overrides caused by ISU holds
		PM_CMPLU_STALL_DCACHE_MISS = 0x21109a, // Completion stall caused by D cache miss
		PM_L3SA_MOD_INV = 0x730e3, // L3 slice A transition from modified to invalid
		PM_LSU_FLUSH_LRQ = 0x2c0090, // LRQ flushes
		PM_THRD_PRIO_2_CYC = 0x420e1, // Cycles thread running at priority level 2
		PM_LSU_FLUSH_SRQ = 0x1c0090, // SRQ flushes
		PM_MRK_LSU_SRQ_INST_VALID = 0xc70e6, // Marked instruction valid in SRQ
		PM_L3SA_REF = 0x701c3, // L3 slice A references
		PM_L2SC_RC_DISP_FAIL_CO_BUSY_ALL = 0x713c2, // L2 slice C RC dispatch attempt failed due to all CO busy
		PM_FPU0_STALL3 = 0x20e1, // FPU0 stalled in pipe3
		PM_GPR_MAP_FULL_CYC = 0x130e5, // Cycles GPR mapper full
		PM_TB_BIT_TRANS = 0x100018, // Time Base bit transition
		PM_MRK_LSU_FLUSH_LRQ = 0x381088, // Marked LRQ flushes
		PM_FPU0_STF = 0x20e2, // FPU0 executed store instruction
		PM_MRK_DTLB_MISS = 0xc50c6, // Marked Data TLB misses
		PM_FPU1_FMA = 0xc5, // FPU1 executed multiply-add instruction
		PM_L2SA_MOD_TAG = 0x720e0, // L2 slice A transition from modified to tagged
		PM_LSU1_FLUSH_ULD = 0xc00c4, // LSU1 unaligned load flushes
		PM_MRK_LSU0_FLUSH_UST = 0x810c1, // LSU0 marked unaligned store flushes
		PM_MRK_INST_FIN = 0x300005, // Marked instruction finished
		PM_FPU0_FULL_CYC = 0x100c3, // Cycles FPU0 issue queue full
		PM_LSU_LRQ_S0_ALLOC = 0xc20e6, // LRQ slot 0 allocated
		PM_MRK_LSU1_FLUSH_ULD = 0x810c4, // LSU1 marked unaligned load flushes
		PM_MRK_DTLB_REF = 0x1c4090, // Marked Data TLB reference
		PM_BR_UNCOND = 0x123087, // Unconditional branch
		PM_THRD_SEL_OVER_L2MISS = 0x410c3, // Thread selection overrides caused by L2 misses
		PM_L2SB_SHR_INV = 0x710c1, // L2 slice B transition from shared to invalid
		PM_MEM_LO_PRIO_WR_CMPL = 0x736e6, // Low priority write completed
		PM_L3SC_MOD_TAG = 0x720e5, // L3 slice C transition from modified to TAG
		PM_MRK_ST_MISS_L1 = 0x820e3, // Marked L1 D cache store misses
		PM_GRP_DISP_SUCCESS = 0x300002, // Group dispatch success
		PM_THRD_PRIO_DIFF_1or2_CYC = 0x430e4, // Cycles thread priority difference is 1 or 2
		PM_IC_DEMAND_L2_BHT_REDIRECT = 0x230e0, // L2 I cache demand request due to BHT redirect
		PM_MEM_WQ_DISP_Q8to15 = 0x733e6, // Memory write queue dispatched to queues 8-15
		PM_FPU0_SINGLE = 0x20e3, // FPU0 executed single precision instruction
		PM_LSU_DERAT_MISS = 0x280090, // DERAT misses
		PM_THRD_PRIO_1_CYC = 0x420e0, // Cycles thread running at priority level 1
		PM_L2SC_RCST_DISP_FAIL_OTHER = 0x732e2, // L2 slice C RC store dispatch attempt failed due to other reasons
		PM_FPU1_FEST = 0x10c6, // FPU1 executed FEST instruction
		PM_FAB_HOLDtoVN_EMPTY = 0x721e7, // Hold buffer to VN empty
		PM_SNOOP_RD_RETRY_RQ = 0x705c6, // Snoop read retry due to collision with active read queue
		PM_SNOOP_DCLAIM_RETRY_QFULL = 0x720e6, // Snoop dclaim/flush retry due to write/dclaim queues full
		PM_MRK_DATA_FROM_L25_SHR_CYC = 0x2c70a2, // Marked load latency from L2.5 shared
		PM_MRK_ST_CMPL_INT = 0x300003, // Marked store completed with intervention
		PM_FLUSH_BR_MPRED = 0x110c6, // Flush caused by branch mispredict
		PM_L2SB_RCLD_DISP_FAIL_ADDR = 0x711c1, // L2 slice B RC load dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_FPU_STF = 0x202090, // FPU executed store instruction
		PM_CMPLU_STALL_FPU = 0x411098, // Completion stall caused by FPU instruction
		PM_THRD_PRIO_DIFF_minus1or2_CYC = 0x430e2, // Cycles thread priority difference is -1 or -2
		PM_GCT_NOSLOT_CYC = 0x100004, // Cycles no GCT slot allocated
		PM_FXU0_BUSY_FXU1_IDLE = 0x300012, // FXU0 busy FXU1 idle
		PM_PTEG_FROM_L35_SHR = 0x18309e, // PTEG loaded from L3.5 shared
		PM_MRK_LSU_FLUSH_UST = 0x381090, // Marked unaligned store flushes
		PM_L3SA_HIT = 0x711c3, // L3 slice A hits
		PM_MRK_DATA_FROM_L25_SHR = 0x1c7097, // Marked data loaded from L2.5 shared
		PM_L2SB_RCST_DISP_FAIL_ADDR = 0x712c1, // L2 slice B RC store dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_MRK_DATA_FROM_L35_SHR = 0x1c709e, // Marked data loaded from L3.5 shared
		PM_IERAT_XLATE_WR = 0x220e7, // Translation written to ierat
		PM_L2SA_ST_REQ = 0x723e0, // L2 slice A store requests
		PM_THRD_SEL_T1 = 0x410c1, // Decode selected thread 1
		PM_IC_DEMAND_L2_BR_REDIRECT = 0x230e1, // L2 I cache demand request due to branch redirect
		PM_INST_FROM_LMEM = 0x222086, // Instruction fetched from local memory
		PM_FPU0_1FLOP = 0xc3, // FPU0 executed add
		PM_MRK_DATA_FROM_L35_SHR_CYC = 0x2c70a6, // Marked load latency from L3.5 shared
		PM_PTEG_FROM_L2 = 0x183087, // PTEG loaded from L2
		PM_MEM_PW_CMPL = 0x724e6, // Memory partial-write completed
		PM_THRD_PRIO_DIFF_minus5or6_CYC = 0x430e0, // Cycles thread priority difference is -5 or -6
		PM_L2SB_RCLD_DISP_FAIL_OTHER = 0x731e1, // L2 slice B RC load dispatch attempt failed due to other reasons
		PM_FPU0_FIN = 0x10c3, // FPU0 produced a result
		PM_MRK_DTLB_MISS_4K = 0xc40c1, // Marked Data TLB misses for 4K page
		PM_L3SC_SHR_INV = 0x710c5, // L3 slice C transition from shared to invalid
		PM_GRP_BR_REDIR = 0x120e6, // Group experienced branch redirect
		PM_L2SC_RCLD_DISP_FAIL_RC_FULL = 0x721e2, // L2 slice C RC load dispatch attempt failed due to all RC full
		PM_MRK_LSU_FLUSH_SRQ = 0x481088, // Marked SRQ lhs flushes
		PM_PTEG_FROM_L275_SHR = 0x383097, // PTEG loaded from L2.75 shared
		PM_L2SB_RCLD_DISP_FAIL_RC_FULL = 0x721e1, // L2 slice B RC load dispatch attempt failed due to all RC full
		PM_SNOOP_RD_RETRY_WQ = 0x715c6, // Snoop read retry due to collision with active write queue
		PM_LSU0_NCLD = 0xc50c1, // LSU0 non-cacheable loads
		PM_FAB_DCLAIM_RETRIED = 0x730e7, // dclaim retried
		PM_LSU1_BUSY_REJECT = 0xc20e7, // LSU1 busy due to reject
		PM_FXLS0_FULL_CYC = 0x110c0, // Cycles FXU0/LS0 queue full
		PM_FPU0_FEST = 0x10c2, // FPU0 executed FEST instruction
		PM_DTLB_REF_16M = 0xc40c6, // Data TLB reference for 16M page
		PM_L2SC_RCLD_DISP_FAIL_ADDR = 0x711c2, // L2 slice C RC load dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_LSU0_REJECT_ERAT_MISS = 0xc60e3, // LSU0 reject due to ERAT miss
		PM_DATA_FROM_L25_MOD = 0x2c3097, // Data loaded from L2.5 modified
		PM_GCT_USAGE_60to79_CYC = 0x20001f, // Cycles GCT 60-79% full
		PM_DATA_FROM_L375_MOD = 0x1c30a7, // Data loaded from L3.75 modified
		PM_LSU_LMQ_SRQ_EMPTY_CYC = 0x200015, // Cycles LMQ and SRQ empty
		PM_LSU0_REJECT_RELOAD_CDF = 0xc60e2, // LSU0 reject due to reload CDF or tag update collision
		PM_0INST_FETCH = 0x42208d, // No instructions fetched
		PM_LSU1_REJECT_RELOAD_CDF = 0xc60e6, // LSU1 reject due to reload CDF or tag update collision
		PM_L1_PREF = 0xc70e7, // L1 cache data prefetches
		PM_MEM_WQ_DISP_Q0to7 = 0x723e6, // Memory write queue dispatched to queues 0-7
		PM_MRK_DATA_FROM_LMEM_CYC = 0x4c70a0, // Marked load latency from local memory
		PM_BRQ_FULL_CYC = 0x100c5, // Cycles branch queue full
		PM_GRP_IC_MISS_NONSPEC = 0x112099, // Group experienced non-speculative I cache miss
		PM_PTEG_FROM_L275_MOD = 0x1830a3, // PTEG loaded from L2.75 modified
		PM_MRK_LD_MISS_L1_LSU0 = 0x820e0, // LSU0 marked L1 D cache load misses
		PM_MRK_DATA_FROM_L375_SHR_CYC = 0x2c70a7, // Marked load latency from L3.75 shared
		PM_LSU_FLUSH = 0x110c5, // Flush initiated by LSU
		PM_DATA_FROM_L3 = 0x1c308e, // Data loaded from L3
		PM_INST_FROM_L2 = 0x122086, // Instruction fetched from L2
		PM_PMC2_OVERFLOW = 0x30000a, // PMC2 Overflow
		PM_FPU0_DENORM = 0x20e0, // FPU0 received denormalized data
		PM_FPU1_FMOV_FEST = 0x10c4, // FPU1 executed FMOV or FEST instructions
		PM_INST_FETCH_CYC = 0x220e4, // Cycles at least 1 instruction fetched
		PM_LSU_LDF = 0x4c5090, // LSU executed Floating Point load instruction
		PM_INST_DISP = 0x300009, // Instructions dispatched
		PM_DATA_FROM_L25_SHR = 0x1c3097, // Data loaded from L2.5 shared
		PM_L1_DCACHE_RELOAD_VALID = 0xc30e4, // L1 reload data source valid
		PM_MEM_WQ_DISP_DCLAIM = 0x713c6, // Memory write queue dispatched due to dclaim/flush
		PM_FPU_FULL_CYC = 0x110090, // Cycles FPU issue queue full
		PM_MRK_GRP_ISSUED = 0x100015, // Marked group issued
		PM_THRD_PRIO_3_CYC = 0x420e2, // Cycles thread running at priority level 3
		PM_FPU_FMA = 0x200088, // FPU executed multiply-add instruction
		PM_INST_FROM_L35_MOD = 0x22209d, // Instruction fetched from L3.5 modified
		PM_MRK_CRU_FIN = 0x400005, // Marked instruction CRU processing finished
		PM_SNOOP_WR_RETRY_WQ = 0x716c6, // Snoop write/dclaim retry due to collision with active write queue
		PM_CMPLU_STALL_REJECT = 0x41109a, // Completion stall caused by reject
		PM_LSU1_REJECT_ERAT_MISS = 0xc60e7, // LSU1 reject due to ERAT miss
		PM_MRK_FXU_FIN = 0x200014, // Marked instruction FXU processing finished
		PM_L2SB_RCST_DISP_FAIL_OTHER = 0x732e1, // L2 slice B RC store dispatch attempt failed due to other reasons
		PM_L2SC_RC_DISP_FAIL_CO_BUSY = 0x703c2, // L2 slice C RC dispatch attempt failed due to RC/CO pair chosen was miss and CO already busy
		PM_PMC4_OVERFLOW = 0x10000a, // PMC4 Overflow
		PM_L3SA_SNOOP_RETRY = 0x731e3, // L3 slice A snoop retries
		PM_PTEG_FROM_L35_MOD = 0x28309e, // PTEG loaded from L3.5 modified
		PM_INST_FROM_L25_MOD = 0x222096, // Instruction fetched from L2.5 modified
		PM_THRD_SMT_HANG = 0x330e7, // SMT hang detected
		PM_CMPLU_STALL_ERAT_MISS = 0x41109b, // Completion stall caused by ERAT miss
		PM_L3SA_MOD_TAG = 0x720e3, // L3 slice A transition from modified to TAG
		PM_FLUSH_SYNC = 0x330e1, // Flush caused by sync
		PM_INST_FROM_L2MISS = 0x12209b, // Instruction fetched missed L2
		PM_L2SC_ST_HIT = 0x733e2, // L2 slice C store hits
		PM_MEM_RQ_DISP_Q8to11 = 0x722e6, // Memory read queue dispatched to queues 8-11
		PM_MRK_GRP_DISP = 0x100002, // Marked group dispatched
		PM_L2SB_MOD_TAG = 0x720e1, // L2 slice B transition from modified to tagged
		PM_CLB_EMPTY_CYC = 0x410c6, // Cycles CLB empty
		PM_L2SB_ST_HIT = 0x733e1, // L2 slice B store hits
		PM_MEM_NONSPEC_RD_CANCEL = 0x711c6, // Non speculative memory read cancelled
		PM_BR_PRED_CR_TA = 0x423087, // A conditional branch was predicted
		PM_MRK_LSU0_FLUSH_SRQ = 0x810c3, // LSU0 marked SRQ lhs flushes
		PM_MRK_LSU_FLUSH_ULD = 0x481090, // Marked unaligned load flushes
		PM_INST_DISP_ATTEMPT = 0x120e1, // Instructions dispatch attempted
		PM_INST_FROM_RMEM = 0x422086, // Instruction fetched from remote memory
		PM_ST_REF_L1_LSU0 = 0xc10c1, // LSU0 L1 D cache store references
		PM_LSU0_DERAT_MISS = 0x800c2, // LSU0 DERAT misses
		PM_L2SB_RCLD_DISP = 0x701c1, // L2 slice B RC load dispatch attempt
		PM_FPU_STALL3 = 0x202088, // FPU stalled in pipe3
		PM_BR_PRED_CR = 0x230e2, // A conditional branch was predicted
		PM_MRK_DATA_FROM_L2 = 0x1c7087, // Marked data loaded from L2
		PM_LSU0_FLUSH_SRQ = 0xc00c3, // LSU0 SRQ lhs flushes
		PM_FAB_PNtoNN_DIRECT = 0x703c7, // PN to NN beat went straight to its destination
		PM_IOPS_CMPL = 0x1, // Internal operations completed
		PM_L2SC_SHR_INV = 0x710c2, // L2 slice C transition from shared to invalid
		PM_L2SA_RCST_DISP_FAIL_OTHER = 0x732e0, // L2 slice A RC store dispatch attempt failed due to other reasons
		PM_L2SA_RCST_DISP = 0x702c0, // L2 slice A RC store dispatch attempt
		PM_SNOOP_RETRY_AB_COLLISION = 0x735e6, // Snoop retry due to a b collision
		PM_FAB_PNtoVN_SIDECAR = 0x733e7, // PN to VN beat went to sidecar first
		PM_LSU_LMQ_S0_ALLOC = 0xc30e6, // LMQ slot 0 allocated
		PM_LSU0_REJECT_LMQ_FULL = 0xc60e1, // LSU0 reject due to LMQ full or missed data coming
		PM_SNOOP_PW_RETRY_RQ = 0x707c6, // Snoop partial-write retry due to collision with active read queue
		PM_DTLB_REF = 0x2c4090, // Data TLB references
		PM_PTEG_FROM_L3 = 0x18308e, // PTEG loaded from L3
		PM_FAB_M1toVNorNN_SIDECAR_EMPTY = 0x712c7, // M1 to VN/NN sidecar empty
		PM_LSU_SRQ_EMPTY_CYC = 0x400015, // Cycles SRQ empty
		PM_FPU1_STF = 0x20e6, // FPU1 executed store instruction
		PM_LSU_LMQ_S0_VALID = 0xc30e5, // LMQ slot 0 valid
		PM_GCT_USAGE_00to59_CYC = 0x10001f, // Cycles GCT less than 60% full
		PM_DATA_FROM_L2MISS = 0x3c309b, // Data loaded missed L2
		PM_GRP_DISP_BLK_SB_CYC = 0x130e1, // Cycles group dispatch blocked by scoreboard
		PM_FPU_FMOV_FEST = 0x301088, // FPU executed FMOV or FEST instructions
		PM_XER_MAP_FULL_CYC = 0x100c2, // Cycles XER mapper full
		PM_FLUSH_SB = 0x330e2, // Flush caused by scoreboard operation
		PM_MRK_DATA_FROM_L375_SHR = 0x3c709e, // Marked data loaded from L3.75 shared
		PM_MRK_GRP_CMPL = 0x400013, // Marked group completed
		PM_SUSPENDED = 0x0, // Suspended
		PM_GRP_IC_MISS_BR_REDIR_NONSPEC = 0x120e5, // Group experienced non-speculative I cache miss or branch redirect
		PM_SNOOP_RD_RETRY_QFULL = 0x700c6, // Snoop read retry due to read queue full
		PM_L3SB_MOD_INV = 0x730e4, // L3 slice B transition from modified to invalid
		PM_DATA_FROM_L35_SHR = 0x1c309e, // Data loaded from L3.5 shared
		PM_LD_MISS_L1_LSU1 = 0xc10c6, // LSU1 L1 D cache load misses
		PM_STCX_FAIL = 0x820e1, // STCX failed
		PM_DC_PREF_DST = 0x830e6, // DST (Data Stream Touch) stream start
		PM_GRP_DISP = 0x200002, // Group dispatches
		PM_L2SA_RCLD_DISP_FAIL_ADDR = 0x711c0, // L2 slice A RC load dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_FPU0_FPSCR = 0x30e0, // FPU0 executed FPSCR instruction
		PM_DATA_FROM_L2 = 0x1c3087, // Data loaded from L2
		PM_FPU1_DENORM = 0x20e4, // FPU1 received denormalized data
		PM_FPU_1FLOP = 0x100090, // FPU executed one flop instruction
		PM_L2SC_RCLD_DISP_FAIL_OTHER = 0x731e2, // L2 slice C RC load dispatch attempt failed due to other reasons
		PM_L2SC_RCST_DISP_FAIL_RC_FULL = 0x722e2, // L2 slice C RC store dispatch attempt failed due to all RC full
		PM_FPU0_FSQRT = 0xc2, // FPU0 executed FSQRT instruction
		PM_LD_REF_L1 = 0x4c1090, // L1 D cache load references
		PM_INST_FROM_L1 = 0x22208d, // Instruction fetched from L1
		PM_TLBIE_HELD = 0x130e4, // TLBIE held at dispatch
		PM_DC_PREF_OUT_OF_STREAMS = 0xc50c2, // D cache out of prefetch streams
		PM_MRK_DATA_FROM_L25_MOD_CYC = 0x4c70a2, // Marked load latency from L2.5 modified
		PM_MRK_LSU1_FLUSH_SRQ = 0x810c7, // LSU1 marked SRQ lhs flushes
		PM_MEM_RQ_DISP_Q0to3 = 0x702c6, // Memory read queue dispatched to queues 0-3
		PM_ST_REF_L1_LSU1 = 0xc10c5, // LSU1 L1 D cache store references
		PM_MRK_LD_MISS_L1 = 0x182088, // Marked L1 D cache load misses
		PM_L1_WRITE_CYC = 0x230e7, // Cycles writing to instruction L1
		PM_L2SC_ST_REQ = 0x723e2, // L2 slice C store requests
		PM_CMPLU_STALL_FDIV = 0x21109b, // Completion stall caused by FDIV or FQRT instruction
		PM_THRD_SEL_OVER_CLB_EMPTY = 0x410c2, // Thread selection overrides caused by CLB empty
		PM_BR_MPRED_CR = 0x230e5, // Branch mispredictions due to CR bit setting
		PM_L3SB_MOD_TAG = 0x720e4, // L3 slice B transition from modified to TAG
		PM_MRK_DATA_FROM_L2MISS = 0x3c709b, // Marked data loaded missed L2
		PM_LSU_REJECT_SRQ = 0x1c6088, // LSU SRQ lhs rejects
		PM_LD_MISS_L1 = 0x3c1088, // L1 D cache load misses
		PM_INST_FROM_PREF = 0x32208d, // Instruction fetched from prefetch
		PM_DC_INV_L2 = 0xc10c7, // L1 D cache entries invalidated from L2
		PM_STCX_PASS = 0x820e5, // Stcx passes
		PM_LSU_SRQ_FULL_CYC = 0x110c3, // Cycles SRQ full
		PM_FPU_FIN = 0x401088, // FPU produced a result
		PM_L2SA_SHR_MOD = 0x700c0, // L2 slice A transition from shared to modified
		PM_LSU_SRQ_STFWD = 0x1c2088, // SRQ store forwarded
		PM_0INST_CLB_CYC = 0x400c0, // Cycles no instructions in CLB
		PM_FXU0_FIN = 0x130e2, // FXU0 produced a result
		PM_L2SB_RCST_DISP_FAIL_RC_FULL = 0x722e1, // L2 slice B RC store dispatch attempt failed due to all RC full
		PM_THRD_GRP_CMPL_BOTH_CYC = 0x200013, // Cycles group completed by both threads
		PM_PMC5_OVERFLOW = 0x10001a, // PMC5 Overflow
		PM_FPU0_FDIV = 0xc0, // FPU0 executed FDIV instruction
		PM_PTEG_FROM_L375_SHR = 0x38309e, // PTEG loaded from L3.75 shared
		PM_LD_REF_L1_LSU1 = 0xc10c4, // LSU1 L1 D cache load references
		PM_L2SA_RC_DISP_FAIL_CO_BUSY = 0x703c0, // L2 slice A RC dispatch attempt failed due to RC/CO pair chosen was miss and CO already busy
		PM_HV_CYC = 0x20000b, // Hypervisor Cycles
		PM_THRD_PRIO_DIFF_0_CYC = 0x430e3, // Cycles no thread priority difference
		PM_LR_CTR_MAP_FULL_CYC = 0x100c6, // Cycles LR/CTR mapper full
		PM_L3SB_SHR_INV = 0x710c4, // L3 slice B transition from shared to invalid
		PM_DATA_FROM_RMEM = 0x1c30a1, // Data loaded from remote memory
		PM_DATA_FROM_L275_MOD = 0x1c30a3, // Data loaded from L2.75 modified
		PM_LSU0_REJECT_SRQ = 0xc60e0, // LSU0 SRQ lhs rejects
		PM_LSU1_DERAT_MISS = 0x800c6, // LSU1 DERAT misses
		PM_MRK_LSU_FIN = 0x400014, // Marked instruction LSU processing finished
		PM_DTLB_MISS_16M = 0xc40c4, // Data TLB miss for 16M page
		PM_LSU0_FLUSH_UST = 0xc00c1, // LSU0 unaligned store flushes
		PM_L2SC_MOD_TAG = 0x720e2, // L2 slice C transition from modified to tagged
		
	};
};

namespace power5 = optkit::ibm::power5;