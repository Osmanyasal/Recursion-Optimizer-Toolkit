#pragma once
#include <cstdint>
#include "intel_priv.hh"
namespace optkit::intel::knl{
	enum knl : uint64_t {
		UNHALTED_CORE_CYCLES = 0x3c, // Unhalted core cycles
		UNHALTED_REFERENCE_CYCLES = 0x0300, // Unhalted reference cycle
		INSTRUCTION_RETIRED = 0xc0, // Instructions retired (any thread modifier supported in fixed counter)
		INSTRUCTIONS_RETIRED = 0xc0, // This is an alias for INSTRUCTION_RETIRED (any thread modifier supported in fixed counter)
		LLC_REFERENCES = 0x4f2e, // Last level of cache references
		LAST_LEVEL_CACHE_REFERENCES = 0x4f2e, // This is an alias for LLC_REFERENCES
		LLC_MISSES = 0x412e, // Last level of cache misses
		LAST_LEVEL_CACHE_MISSES = 0x412e, // This is an alias for LLC_MISSES
		BRANCH_INSTRUCTIONS_RETIRED = 0xc4, // Branch instructions retired
		MISPREDICTED_BRANCH_RETIRED = 0xc5, // Mispredicted branch instruction retired
		ICACHE = 0x80, // Instruction fetches
		ICACHE__MASK__KNL_ICACHE__HIT = 0x100, // Counts all instruction fetches that hit the instruction cache.
		ICACHE__MASK__KNL_ICACHE__MISSES = 0x200, // Counts all instruction fetches that miss the instruction cache or produce memory requests. An instruction fetch miss is counted only once and not once for every cycle it is outstanding.
		ICACHE__MASK__KNL_ICACHE__ACCESSES = 0x300, // Counts all instruction fetches
		UOPS_RETIRED = 0xc2, // Micro-ops retired
		UOPS_RETIRED__MASK__KNL_UOPS_RETIRED__ALL = 0x1000, // Counts the number of micro-ops retired.
		UOPS_RETIRED__MASK__KNL_UOPS_RETIRED__MS = 0x0100, // Counts the number of micro-ops retired that are from the complex flows issued by the micro-sequencer (MS).
		UOPS_RETIRED__MASK__KNL_UOPS_RETIRED__SCALAR_SIMD = 0x2000, // Counts the number of scalar SSE
		UOPS_RETIRED__MASK__KNL_UOPS_RETIRED__PACKED_SIMD = 0x4000, // Counts the number of vector SSE
		INST_RETIRED = 0xc0, // Instructions retired
		INST_RETIRED__MASK__KNL_INST_RETIRED__ANY_P = 0x0, // Instructions retired using generic counter (precise event)
		INST_RETIRED__MASK__KNL_INST_RETIRED__ANY = 0x0, // Instructions retired using generic counter (precise event)
		CYCLES_DIV_BUSY = 0xcd, // Counts the number of core cycles when divider is busy.
		CYCLES_DIV_BUSY__MASK__KNL_CYCLES_DIV_BUSY__ALL = 0x0100, // Counts the number of core cycles when divider is busy.  Does not imply a stall waiting for the divider.
		RS_FULL_STALL = 0xcb, // Counts the number of core cycles when allocation pipeline is stalled.
		RS_FULL_STALL__MASK__KNL_RS_FULL_STALL__MEC = 0x0100, // Counts the number of core cycles when allocation pipeline is stalled and is waiting for a free MEC reservation station entry.
		RS_FULL_STALL__MASK__KNL_RS_FULL_STALL__ANY = 0x1f00, // Counts the total number of core cycles the Alloc pipeline is stalled when any one of the reservation stations is full.
		L2_REQUESTS = 0x2e, // L2 cache requests
		L2_REQUESTS__MASK__KNL_L2_RQSTS__MISS = 0x4100, // Counts the number of L2 cache misses
		L2_REQUESTS__MASK__KNL_L2_RQSTS__REFERENCE = 0x4f00, // Counts the total number of L2 cache references.
		MACHINE_CLEARS = 0xc3, // Counts the number of times that the machine clears.
		MACHINE_CLEARS__MASK__KNL_MACHINE_CLEARS__SMC = 0x0100, // Counts the number of times that the machine clears due to program modifying data within 1K of a recently fetched code page.
		MACHINE_CLEARS__MASK__KNL_MACHINE_CLEARS__MEMORY_ORDERING = 0x0200, // Counts the number of times the machine clears due to memory ordering hazards
		MACHINE_CLEARS__MASK__KNL_MACHINE_CLEARS__FP_ASSIST = 0x0400, // Counts the number of floating operations retired that required microcode assists
		MACHINE_CLEARS__MASK__KNL_MACHINE_CLEARS__ALL = 0x0800, // Counts all nukes
		MACHINE_CLEARS__MASK__KNL_MACHINE_CLEARS__ANY = 0x0800, // Counts all nukes
		BR_INST_RETIRED = 0xc4, // Retired branch instructions
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__ANY = 0x0, // Counts the number of branch instructions retired (Precise Event)
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__ALL_BRANCHES = 0x0, // Counts the number of branch instructions retired
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__JCC = 0x7e00, // Counts the number of branch instructions retired that were conditional jumps.
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__TAKEN_JCC = 0xfe00, // Counts the number of branch instructions retired that were conditional jumps and predicted taken.
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__CALL = 0xf900, // Counts the number of near CALL branch instructions retired.
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__REL_CALL = 0xfd00, // Counts the number of near relative CALL branch instructions retired.
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__IND_CALL = 0xfb00, // Counts the number of near indirect CALL branch instructions retired. (Precise Event)
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__RETURN = 0xf700, // Counts the number of near RET branch instructions retired. (Precise Event)
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__NON_RETURN_IND = 0xeb00, // Counts the number of branch instructions retired that were near indirect CALL or near indirect JMP. (Precise Event)
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__FAR_BRANCH = 0xbf00, // Counts the number of far branch instructions retired. (Precise Event)
		BR_INST_RETIRED__MASK__KNL_BR_INST_RETIRED__FAR = 0xbf00, // Counts the number of far branch instructions retired. (Precise Event)
		BR_MISP_RETIRED = 0xc5, // Counts the number of mispredicted branch instructions retired.
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__ALL_BRANCHES = 0x0000, // All mispredicted branches (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__ANY = 0x0000, // All mispredicted branches (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__JCC = 0x7e00, // Number of mispredicted conditional branch instructions retired (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__NON_RETURN_IND = 0xeb00, // Number of mispredicted non-return branch instructions retired (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__RETURN = 0xf700, // Number of mispredicted return branch instructions retired (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__IND_CALL = 0xfb00, // Number of mispredicted indirect call branch instructions retired (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__TAKEN_JCC = 0xfe00, // Number of mispredicted taken conditional branch instructions retired (Precise Event)
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__CALL = 0xf900, // Counts the number of mispredicted near CALL branch instructions retired.
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__REL_CALL = 0xfd00, // Counts the number of mispredicted near relative CALL branch instructions retired.
		BR_MISP_RETIRED__MASK__KNL_BR_MISP_RETIRED__FAR_BRANCH = 0xbf00, // Counts the number of mispredicted far branch instructions retired.
		MS_DECODED = 0xe7, // Number of times the MSROM starts a flow of uops.
		MS_DECODED__MASK__KNL_MS_DECODED__ENTRY = 0x0100, // Counts the number of times the MSROM starts a flow of uops.
		FETCH_STALL = 0x86, // Counts the number of core cycles the fetch stalls.
		FETCH_STALL__MASK__KNL_FETCH_STALL__ICACHE_FILL_PENDING_CYCLES = 0x0400, // Counts the number of core cycles the fetch stalls because of an icache miss. This is a cumulative count of core cycles the fetch stalled for all icache misses
		BACLEARS = 0xe6, // Branch address calculator
		BACLEARS__MASK__KNL_BACLEARS__ALL = 0x100, // Counts the number of times the front end resteers for any branch as a result of another branch handling mechanism in the front end.
		BACLEARS__MASK__KNL_BACLEARS__ANY = 0x100, // Counts the number of times the front end resteers for any branch as a result of another branch handling mechanism in the front end.
		BACLEARS__MASK__KNL_BACLEARS__RETURN = 0x800, // Counts the number of times the front end resteers for RET branches as a result of another branch handling mechanism in the front end.
		BACLEARS__MASK__KNL_BACLEARS__COND = 0x1000, // Counts the number of times the front end resteers for conditional branches as a result of another branch handling mechanism in the front end.
		NO_ALLOC_CYCLES = 0xca, // Front-end allocation
		NO_ALLOC_CYCLES__MASK__KNL_NO_ALLOC_CYCLES__ROB_FULL = 0x0100, // Counts the number of core cycles when no micro-ops are allocated and the ROB is full
		NO_ALLOC_CYCLES__MASK__KNL_NO_ALLOC_CYCLES__MISPREDICTS = 0x0400, // Counts the number of core cycles when no micro-ops are allocated and the alloc pipe is stalled waiting for a mispredicted branch to retire.
		NO_ALLOC_CYCLES__MASK__KNL_NO_ALLOC_CYCLES__RAT_STALL = 0x2000, // Counts the number of core cycles when no micro-ops are allocated and a RATstall (caused by reservation station full) is asserted.
		NO_ALLOC_CYCLES__MASK__KNL_NO_ALLOC_CYCLES__NOT_DELIVERED = 0x9000, // Counts the number of core cycles when no micro-ops are allocated
		NO_ALLOC_CYCLES__MASK__KNL_NO_ALLOC_CYCLES__ALL = 0x7f00, // Counts the total number of core cycles when no micro-ops are allocated for any reason.
		NO_ALLOC_CYCLES__MASK__KNL_NO_ALLOC_CYCLES__ANY = 0x7f00, // Counts the total number of core cycles when no micro-ops are allocated for any reason.
		CPU_CLK_UNHALTED = 0x3c, // Core cycles when core is not halted
		CPU_CLK_UNHALTED__MASK__KNL_CPU_CLK_UNHALTED__THREAD_P = 0x0, // thread cycles when core is not halted
		CPU_CLK_UNHALTED__MASK__KNL_CPU_CLK_UNHALTED__BUS = 0x100, // Bus cycles when core is not halted. This event can give a measurement of the elapsed time. This events has a constant ratio with CPU_CLK_UNHALTED:REF event
		CPU_CLK_UNHALTED__MASK__KNL_CPU_CLK_UNHALTED__REF_P = 0x200, // Number of reference cycles that the cpu is not in a halted state. The core enters the halted state when it is running the HLT instruction. In mobile systems
		MEM_UOPS_RETIRED = 0x4, // Counts the number of load micro-ops retired.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__L1_MISS_LOADS = 0x100, // Counts the number of load micro-ops retired that miss in L1 D cache.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__LD_DCU_MISS = 0x100, // Counts the number of load micro-ops retired that miss in L1 D cache.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__L2_HIT_LOADS = 0x200, // Counts the number of load micro-ops retired that hit in the L2.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__L2_MISS_LOADS = 0x400, // Counts the number of load micro-ops retired that miss in the L2.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__LD_L2_MISS = 0x400, // Counts the number of load micro-ops retired that miss in the L2.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__DTLB_MISS_LOADS = 0x800, // Counts the number of load micro-ops retired that cause a DTLB miss.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__UTLB_MISS_LOADS = 0x1000, // Counts the number of load micro-ops retired that caused micro TLB miss.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__LD_UTLB_MISS = 0x1000, // Counts the number of load micro-ops retired that caused micro TLB miss.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__HITM = 0x2000, // Counts the loads retired that get the data from the other core in the same tile in M state.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__ALL_LOADS = 0x4000, // Counts all the load micro-ops retired.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__ANY_LD = 0x4000, // Counts all the load micro-ops retired.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__ALL_STORES = 0x8000, // Counts all the store micro-ops retired.
		MEM_UOPS_RETIRED__MASK__KNL_MEM_UOPS_RETIRED__ANY_ST = 0x8000, // Counts all the store micro-ops retired.
		PAGE_WALKS = 0x5, // Number of page-walks executed
		PAGE_WALKS__MASK__KNL_PAGE_WALKS__D_SIDE_CYCLES = 0x100, // Counts the total D-side page walks that are completed or started. The page walks started in the speculative path will also be counted.
		PAGE_WALKS__MASK__KNL_PAGE_WALKS__D_SIDE_WALKS = 0x100 | INTEL_X86_MOD_EDGE | (1ULL << INTEL_X86_CMASK_BIT), // Counts the total number of core cycles for all the D-side page walks. The cycles for page walks started in speculative path will also be included.
		PAGE_WALKS__MASK__KNL_PAGE_WALKS__I_SIDE_CYCLES = 0x200, // Counts the total I-side page walks that are completed.
		PAGE_WALKS__MASK__KNL_PAGE_WALKS__I_SIDE_WALKS = 0x200 | INTEL_X86_MOD_EDGE | (1ULL << INTEL_X86_CMASK_BIT), // Counts the total number of core cycles for all the I-side page walks. The cycles for page walks started in speculative path will also be included.
		PAGE_WALKS__MASK__KNL_PAGE_WALKS__CYCLES = 0x300, // Counts the total page walks completed (I-side and D-side)
		PAGE_WALKS__MASK__KNL_PAGE_WALKS__WALKS = 0x300 | INTEL_X86_MOD_EDGE | (1ULL << INTEL_X86_CMASK_BIT), // Counts the total number of core cycles for all the page walks. The cycles for page walks started in speculative path will also be included.
		L2_REQUESTS_REJECT = 0x30, // Counts the number of MEC requests from the L2Q that reference a cache line were rejected.
		L2_REQUESTS_REJECT__MASK__KNL_L2_REQUESTS_REJECT__ALL = 0x000, // Counts the number of MEC requests from the L2Q that reference a cache line excluding SW prefetches filling only to L2 cache and L1 evictions (automatically exlcudes L2HWP
		CORE_REJECT_L2Q = 0x31, // Number of requests not accepted into the L2Q because of any L2 queue reject condition.
		CORE_REJECT_L2Q__MASK__KNL_CORE_REJECT__ALL = 0x000, // Counts the number of MEC requests that were not accepted into the L2Q because of any L2  queue reject condition. There is no concept of at-ret here. It might include requests due to instructions in the speculative path
		RECYCLEQ = 0x03, // Counts the number of occurrences a retired load gets blocked.
		RECYCLEQ__MASK__KNL_RECYCLEQ__LD_BLOCK_ST_FORWARD = 0x0100, // Counts the number of occurrences a retired load gets blocked because its address partially overlaps with a store (Precise Event).
		RECYCLEQ__MASK__KNL_RECYCLEQ__LD_BLOCK_STD_NOTREADY = 0x0200, // Counts the number of occurrences a retired load gets blocked because its address overlaps with a store whose data is not ready.
		RECYCLEQ__MASK__KNL_RECYCLEQ__ST_SPLITS = 0x0400, // Counts the number of occurrences a retired store that is a cache line split. Each split should be counted only once.
		RECYCLEQ__MASK__KNL_RECYCLEQ__LD_SPLITS = 0x0800, // Counts the number of occurrences a retired load that is a cache line split. Each split should be counted only once (Precise Event).
		RECYCLEQ__MASK__KNL_RECYCLEQ__LOCK = 0x1000, // Counts all the retired locked loads. It does not include stores because we would double count if we count stores.
		RECYCLEQ__MASK__KNL_RECYCLEQ__STA_FULL = 0x2000, // Counts the store micro-ops retired that were pushed in the rehad queue because the store address buffer is full.
		RECYCLEQ__MASK__KNL_RECYCLEQ__ANY_LD = 0x4000, // Counts any retired load that was pushed into the recycle queue for any reason.
		RECYCLEQ__MASK__KNL_RECYCLEQ__ANY_ST = 0x8000, // Counts any retired store that was pushed into the recycle queue for any reason.
		OFFCORE_RESPONSE_0 = 0x01b7, // Offcore response event (must provide at least one request type and either any_response or any combination of supplier + snoop)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__DMND_DATA_RD = 1ULL << (0 + 8), // Counts demand cacheable data and L1 prefetch data reads
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__DMND_RFO = 1ULL << (1 + 8), // Counts Demand cacheable data writes
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__DMND_CODE_RD = 1ULL << (2 + 8), // Counts demand code reads and prefetch code reads
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PF_L2_RFO = 1ULL << (5 + 8), // Counts L2 data RFO prefetches (includes PREFETCHW instruction)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PF_L2_CODE_RD = 1ULL << (6 + 8), // Request: number of code reads generated by L2 prefetchers
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PARTIAL_READS = 1ULL << (7 + 8), // Counts Partial reads (UC or WC and is valid only for Outstanding response type).
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PARTIAL_WRITES = 1ULL << (8 + 8), // Counts Partial writes (UC or WT or WP and should be programmed on PMC1)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__UC_CODE_READS = 1ULL << (9 + 8), // Counts UC code reads (valid only for Outstanding response type)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__BUS_LOCKS = 1ULL << (10 + 8), // Counts Bus locks and split lock requests
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__FULL_STREAMING_STORES = 1ULL << (11 + 8), // Counts Full streaming stores (WC and should be programmed on PMC1)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PF_SOFTWARE = 1ULL << (12 + 8), // Counts Software prefetches
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PF_L1_DATA_RD = 1ULL << (13 + 8), // Counts L1 data HW prefetches
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__PARTIAL_STREAMING_STORES = 1ULL << (14 + 8), // Counts Partial streaming stores (WC and should be programmed on PMC1)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__STREAMING_STORES = (1ULL << 14 | 1ULL << 11) << 8, // Counts all streaming stores (WC and should be programmed on PMC1)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_REQUEST = 1ULL << (15 + 8), // Counts any request
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_DATA_RD = (1ULL << 0 | 1ULL << 7 | 1ULL << 12 | 1ULL << 13) << 8, // Counts Demand cacheable data and L1 prefetch data read requests
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_RFO = (1ULL << 1 | 1ULL << 5) << 8, // Counts Demand cacheable data write requests
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_CODE_RD = (1ULL << 2 | 1ULL << 6) << 8, // Counts Demand code reads and prefetch code read requests
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_READ = (1ULL << 0 | 1ULL << 1 | 1ULL << 2 | 1ULL << 5 | 1ULL << 6 | 1ULL << 7 | 1ULL << 9 | 1ULL << 12 | 1ULL << 13 ) << 8, // Counts any Read request
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_PF_L2 = (1ULL << 5 | 1ULL << 6) << 8, // Counts any Prefetch requests
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__ANY_RESPONSE = (1ULL << 16) << 8, // Accounts for any response
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__DDR_NEAR = (1ULL << 31 | 1ULL << 23 ) << 8, // Accounts for data responses from DRAM Local.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__DDR_FAR = (1ULL << 31 | 1ULL << 24 ) << 8, // Accounts for data responses from DRAM Far.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__MCDRAM_NEAR = (1ULL << 31 | 1ULL << 21 ) << 8, // Accounts for data responses from MCDRAM Local.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__MCDRAM_FAR = (1ULL << 32 | 1ULL << 22 ) << 8, // Accounts for data responses from MCDRAM Far or Other tile L2 hit far.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__L2_HIT_NEAR_TILE_E_F = (1ULL << 35 | 1ULL << 19 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__L2_HIT_NEAR_TILE_M = (1ULL << 36 | 1ULL << 19 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__L2_HIT_FAR_TILE_E_F = (1ULL << 35 | 1ULL << 22 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__L2_HIT_FAR_TILE_M = (1ULL << 36 | 1ULL << 22 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__NON_DRAM = (1ULL << 37 | 1ULL << 17 ) << 8, // accounts for responses from any NON_DRAM system address. This includes MMIO transactions
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__MCDRAM = (1ULL << 32 | 1ULL << 31 | 1ULL << 22 | 1ULL << 21 ) << 8, // accounts for responses from MCDRAM (local and far)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__DDR = (1ULL << 32 | 1ULL << 31 | 1ULL << 24 | 1ULL << 23 ) << 8, // accounts for responses from DDR (local and far)
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__L2_HIT_NEAR_TILE = (1ULL << 36 | 1ULL << 35 | 1ULL << 20 | 1ULL << 19 ) << 8, // accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__L2_HIT_FAR_TILE = (1ULL << 36 | 1ULL << 35 | 1ULL << 22 ) << 8, // accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.
		OFFCORE_RESPONSE_0__MASK__KNL_OFFCORE_RESPONSE_0__OUTSTANDING = (1ULL << 38) << 8, // outstanding
		OFFCORE_RESPONSE_1 = 0x02b7, // Offcore response event (must provide at least one request type and either any_response or any combination of supplier + snoop)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__DMND_DATA_RD = 1ULL << (0 + 8), // Counts demand cacheable data and L1 prefetch data reads
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__DMND_RFO = 1ULL << (1 + 8), // Counts Demand cacheable data writes
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__DMND_CODE_RD = 1ULL << (2 + 8), // Counts demand code reads and prefetch code reads
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PF_L2_RFO = 1ULL << (5 + 8), // Counts L2 data RFO prefetches (includes PREFETCHW instruction)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PF_L2_CODE_RD = 1ULL << (6 + 8), // Request: number of code reads generated by L2 prefetchers
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PARTIAL_READS = 1ULL << (7 + 8), // Counts Partial reads (UC or WC and is valid only for Outstanding response type).
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PARTIAL_WRITES = 1ULL << (8 + 8), // Counts Partial writes (UC or WT or WP and should be programmed on PMC1)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__UC_CODE_READS = 1ULL << (9 + 8), // Counts UC code reads (valid only for Outstanding response type)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__BUS_LOCKS = 1ULL << (10 + 8), // Counts Bus locks and split lock requests
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__FULL_STREAMING_STORES = 1ULL << (11 + 8), // Counts Full streaming stores (WC and should be programmed on PMC1)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PF_SOFTWARE = 1ULL << (12 + 8), // Counts Software prefetches
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PF_L1_DATA_RD = 1ULL << (13 + 8), // Counts L1 data HW prefetches
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__PARTIAL_STREAMING_STORES = 1ULL << (14 + 8), // Counts Partial streaming stores (WC and should be programmed on PMC1)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__STREAMING_STORES = (1ULL << 14 | 1ULL << 11) << 8, // Counts all streaming stores (WC and should be programmed on PMC1)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_REQUEST = 1ULL << (15 + 8), // Counts any request
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_DATA_RD = (1ULL << 0 | 1ULL << 7 | 1ULL << 12 | 1ULL << 13) << 8, // Counts Demand cacheable data and L1 prefetch data read requests
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_RFO = (1ULL << 1 | 1ULL << 5) << 8, // Counts Demand cacheable data write requests
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_CODE_RD = (1ULL << 2 | 1ULL << 6) << 8, // Counts Demand code reads and prefetch code read requests
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_READ = (1ULL << 0 | 1ULL << 1 | 1ULL << 2 | 1ULL << 5 | 1ULL << 6 | 1ULL << 7 | 1ULL << 9 | 1ULL << 12 | 1ULL << 13 ) << 8, // Counts any Read request
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_PF_L2 = (1ULL << 5 | 1ULL << 6) << 8, // Counts any Prefetch requests
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__ANY_RESPONSE = (1ULL << 16) << 8, // Accounts for any response
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__DDR_NEAR = (1ULL << 31 | 1ULL << 23 ) << 8, // Accounts for data responses from DRAM Local.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__DDR_FAR = (1ULL << 31 | 1ULL << 24 ) << 8, // Accounts for data responses from DRAM Far.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__MCDRAM_NEAR = (1ULL << 31 | 1ULL << 21 ) << 8, // Accounts for data responses from MCDRAM Local.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__MCDRAM_FAR = (1ULL << 32 | 1ULL << 22 ) << 8, // Accounts for data responses from MCDRAM Far or Other tile L2 hit far.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__L2_HIT_NEAR_TILE_E_F = (1ULL << 35 | 1ULL << 19 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in E/F state.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__L2_HIT_NEAR_TILE_M = (1ULL << 36 | 1ULL << 19 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Near-other tile's L2 in M state.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__L2_HIT_FAR_TILE_E_F = (1ULL << 35 | 1ULL << 22 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in E/F state. Valid only for SNC4 cluster mode.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__L2_HIT_FAR_TILE_M = (1ULL << 36 | 1ULL << 22 ) << 8, // Accounts for responses from a snoop request hit with data forwarded from its Far(not in the same quadrant as the request)-other tile's L2 in M state.
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__NON_DRAM = (1ULL << 37 | 1ULL << 17 ) << 8, // accounts for responses from any NON_DRAM system address. This includes MMIO transactions
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__MCDRAM = (1ULL << 32 | 1ULL << 31 | 1ULL << 22 | 1ULL << 21 ) << 8, // accounts for responses from MCDRAM (local and far)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__DDR = (1ULL << 32 | 1ULL << 31 | 1ULL << 24 | 1ULL << 23 ) << 8, // accounts for responses from DDR (local and far)
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__L2_HIT_NEAR_TILE = (1ULL << 36 | 1ULL << 35 | 1ULL << 20 | 1ULL << 19 ) << 8, // accounts for responses from snoop request hit with data forwarded from its Near-other tile L2 in E/F/M state
		OFFCORE_RESPONSE_1__MASK__KNL_OFFCORE_RESPONSE_1__L2_HIT_FAR_TILE = (1ULL << 36 | 1ULL << 35 | 1ULL << 22 ) << 8, // accounts for responses from snoop request hit with data forwarded from it Far(not in the same quadrant as the request)-other tile L2 in E/F/M state. Valid only in SNC4 Cluster mode.
		
	};
};

namespace knl = optkit::intel::knl;