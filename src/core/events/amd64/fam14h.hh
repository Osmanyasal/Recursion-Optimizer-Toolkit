#pragma once
#include <cstdint>
namespace optkit::amd64::fam14h{
	enum fam14h : uint64_t {
		DISPATCHED_FPU = 0x0, // Number of uops dispatched to FPU execution pipelines
		DISPATCHED_FPU__MASK__AMD64_FAM14H_DISPATCHED_FPU__PIPE0 = 0x1, // Pipe 0 (fadd
		DISPATCHED_FPU__MASK__AMD64_FAM14H_DISPATCHED_FPU__PIPE1 = 0x2, // Pipe 1 (fmul
		DISPATCHED_FPU__MASK__AMD64_FAM14H_DISPATCHED_FPU__ANY = 0x3, // Pipe 1 and Pipe 0 ops
		CYCLES_NO_FPU_OPS_RETIRED = 0x1, // Cycles in which the FPU is Empty
		DISPATCHED_FPU_OPS_FAST_FLAG = 0x2, // Dispatched Fast Flag FPU Operations
		RETIRED_SSE_OPERATIONS = 0x3, // Retired SSE Operations
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__SINGLE_ADD_SUB_OPS = 0x1, // Single precision add/subtract ops
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__SINGLE_MUL_OPS = 0x2, // Single precision multiply ops
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__SINGLE_DIV_OPS = 0x4, // Single precision divide/square root ops
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__DOUBLE_ADD_SUB_OPS = 0x8, // Double precision add/subtract ops
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__DOUBLE_MUL_OPS = 0x10, // Double precision multiply ops
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__DOUBLE_DIV_OPS = 0x20, // Double precision divide/square root ops
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__OP_TYPE = 0x40, // FLOPS
		RETIRED_SSE_OPERATIONS__MASK__AMD64_FAM14H_RETIRED_SSE_OPERATIONS__ALL = 0x7f, // All sub-events selected
		RETIRED_MOVE_OPS = 0x4, // Retired Move Ops
		RETIRED_MOVE_OPS__MASK__AMD64_FAM14H_RETIRED_MOVE_OPS__ALL_OTHER_MERGING_MOVE_UOPS = 0x4, // All other merging move uops
		RETIRED_MOVE_OPS__MASK__AMD64_FAM14H_RETIRED_MOVE_OPS__ALL_OTHER_MOVE_UOPS = 0x8, // All other move uops
		RETIRED_MOVE_OPS__MASK__AMD64_FAM14H_RETIRED_MOVE_OPS__ALL = 0xc, // All sub-events selected
		RETIRED_SERIALIZING_OPS = 0x5, // Retired Serializing Ops
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM14H_RETIRED_SERIALIZING_OPS__SSE_BOTTOM_EXECUTING_UOPS = 0x1, // SSE bottom-executing uops retired
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM14H_RETIRED_SERIALIZING_OPS__SSE_BOTTOM_SERIALIZING_UOPS = 0x2, // SSE bottom-serializing uops retired
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM14H_RETIRED_SERIALIZING_OPS__X87_BOTTOM_EXECUTING_UOPS = 0x4, // X87 bottom-executing uops retired
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM14H_RETIRED_SERIALIZING_OPS__X87_BOTTOM_SERIALIZING_UOPS = 0x8, // X87 bottom-serializing uops retired
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM14H_RETIRED_SERIALIZING_OPS__ALL = 0xf, // All sub-events selected
		RETIRED_X87_FPU_OPS = 0x11, // Number of x87 floating points ops that have retired
		RETIRED_X87_FPU_OPS__MASK__AMD64_FAM14H_RETIRED_X87_FPU_OPS__ADD_SUB_OPS = 0x1, // Add/subtract ops
		RETIRED_X87_FPU_OPS__MASK__AMD64_FAM14H_RETIRED_X87_FPU_OPS__MULT_OPS = 0x2, // Multiply ops
		RETIRED_X87_FPU_OPS__MASK__AMD64_FAM14H_RETIRED_X87_FPU_OPS__DIV_FSQRT_OPS = 0x4, // Divide and fqsrt ops
		RETIRED_X87_FPU_OPS__MASK__AMD64_FAM14H_RETIRED_X87_FPU_OPS__ALL = 0x7, // All sub-events selected
		SEGMENT_REGISTER_LOADS = 0x20, // Segment Register Loads
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__ES = 0x1, // ES
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__CS = 0x2, // CS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__SS = 0x4, // SS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__DS = 0x8, // DS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__FS = 0x10, // FS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__GS = 0x20, // GS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__HS = 0x40, // HS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM14H_SEGMENT_REGISTER_LOADS__ALL = 0x7f, // All sub-events selected
		PIPELINE_RESTART_DUE_TO_SELF_MODIFYING_CODE = 0x21, // Pipeline Restart Due to Self-Modifying Code
		PIPELINE_RESTART_DUE_TO_PROBE_HIT = 0x22, // Pipeline Restart Due to Probe Hit
		RSQ_FULL = 0x23, // Number of cycles that the RSQ holds retired stores. This buffer holds the stores waiting to retired as well as requests that missed the data cache and waiting on a refill
		LOCKED_OPS = 0x24, // Locked Operations
		LOCKED_OPS__MASK__AMD64_FAM14H_LOCKED_OPS__EXECUTED = 0x1, // Number of locked instructions executed
		LOCKED_OPS__MASK__AMD64_FAM14H_LOCKED_OPS__BUS_LOCK = 0x2, // Number of cycles to acquire bus lock
		LOCKED_OPS__MASK__AMD64_FAM14H_LOCKED_OPS__UNLOCK_LINE = 0x4, // Number of cycles to unlock line (not including cache miss)
		LOCKED_OPS__MASK__AMD64_FAM14H_LOCKED_OPS__ALL = 0x7, // All sub-events selected
		RETIRED_CLFLUSH_INSTRUCTIONS = 0x26, // Retired CLFLUSH Instructions
		RETIRED_CPUID_INSTRUCTIONS = 0x27, // Retired CPUID Instructions
		CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS = 0x2a, // Cancelled Store to Load Forward Operations
		CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__MASK__AMD64_FAM14H_CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__ADDRESS_MISMATCHES = 0x1, // Address mismatches (starting byte not the same).
		CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__MASK__AMD64_FAM14H_CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__STORE_IS_SMALLER_THAN_LOAD = 0x2, // Store is smaller than load.
		CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__MASK__AMD64_FAM14H_CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__MISALIGNED = 0x4, // Misaligned.
		CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__MASK__AMD64_FAM14H_CANCELLED_STORE_TO_LOAD_FORWARD_OPERATIONS__ALL = 0x7, // All sub-events selected
		DATA_CACHE_ACCESSES = 0x40, // Data Cache Accesses
		DATA_CACHE_MISSES = 0x41, // Data Cache Misses
		DATA_CACHE_REFILLS = 0x42, // Data Cache Refills from L2 or Northbridge
		DATA_CACHE_REFILLS__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS__UNCACHEABLE = 0x1, // From non-cacheable data
		DATA_CACHE_REFILLS__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS__SHARED = 0x2, // From shared lines
		DATA_CACHE_REFILLS__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS__EXCLUSIVE = 0x4, // From exclusive lines
		DATA_CACHE_REFILLS__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS__OWNED = 0x8, // From owned lines
		DATA_CACHE_REFILLS__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS__MODIFIED = 0x10, // From modified lines
		DATA_CACHE_REFILLS__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS__ALL = 0x1f, // All sub-events selected
		DATA_CACHE_REFILLS_FROM_NB = 0x43, // Data Cache Refills from the Northbridge
		DATA_CACHE_REFILLS_FROM_NB__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS_FROM_NB__UNCACHEABLE = 0x1, // Uncacheable data
		DATA_CACHE_REFILLS_FROM_NB__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS_FROM_NB__SHARED = 0x2, // Shared
		DATA_CACHE_REFILLS_FROM_NB__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS_FROM_NB__EXCLUSIVE = 0x4, // Exclusive
		DATA_CACHE_REFILLS_FROM_NB__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS_FROM_NB__OWNED = 0x8, // Owned
		DATA_CACHE_REFILLS_FROM_NB__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS_FROM_NB__MODIFIED = 0x10, // Modified
		DATA_CACHE_REFILLS_FROM_NB__MASK__AMD64_FAM14H_DATA_CACHE_REFILLS_FROM_NB__ALL = 0x1f, // All sub-events selected
		DATA_CACHE_LINES_EVICTED = 0x44, // Data Cache Lines Evicted
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_FAM14H_DATA_CACHE_LINES_EVICTED__PROBE = 0x1, // Eviction from probe
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_FAM14H_DATA_CACHE_LINES_EVICTED__SHARED = 0x2, // Shared eviction
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_FAM14H_DATA_CACHE_LINES_EVICTED__EXCLUSIVE = 0x4, // Exclusive eviction
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_FAM14H_DATA_CACHE_LINES_EVICTED__OWNED = 0x8, // Owned eviction
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_FAM14H_DATA_CACHE_LINES_EVICTED__MODIFIED = 0x10, // Modified eviction
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_FAM14H_DATA_CACHE_LINES_EVICTED__ALL = 0x1f, // All sub-events selected
		L1_DTLB_MISS_AND_L2_DTLB_HIT = 0x45, // Number of data cache accesses that miss in the L1 DTLB and hit the L2 DTLB. This is a speculative event
		DTLB_MISS = 0x46, // L1 DTLB and L2 DTLB Miss
		DTLB_MISS__MASK__AMD64_FAM14H_DTLB_MISS__STORES_L1TLB_MISS = 0x1, // Stores that miss L1TLB
		DTLB_MISS__MASK__AMD64_FAM14H_DTLB_MISS__LOADS_L1TLB_MISS = 0x2, // Loads that miss L1TLB
		DTLB_MISS__MASK__AMD64_FAM14H_DTLB_MISS__STORES_L2TLB_MISS = 0x4, // Stores that miss L2TLB
		DTLB_MISS__MASK__AMD64_FAM14H_DTLB_MISS__LOADS_L2TLB_MISS = 0x8, // Loads that miss L2TLB
		DTLB_MISS__MASK__AMD64_FAM14H_DTLB_MISS__ALL = 0xf, // All sub-events selected
		MISALIGNED_ACCESSES = 0x47, // Misaligned Accesses
		PREFETCH_INSTRUCTIONS_DISPATCHED = 0x4b, // Prefetch Instructions Dispatched
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM14H_PREFETCH_INSTRUCTIONS_DISPATCHED__LOAD = 0x1, // Load (Prefetch
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM14H_PREFETCH_INSTRUCTIONS_DISPATCHED__STORE = 0x2, // Store (PrefetchW)
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM14H_PREFETCH_INSTRUCTIONS_DISPATCHED__NTA = 0x4, // NTA (PrefetchNTA)
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM14H_PREFETCH_INSTRUCTIONS_DISPATCHED__ALL = 0x7, // All sub-events selected
		DCACHE_MISSES_BY_LOCKED_INSTRUCTIONS = 0x4c, // DCACHE Misses by Locked Instructions
		L1_DTLB_HIT = 0x4d, // L1 DTLB Hit
		L1_DTLB_HIT__MASK__AMD64_FAM14H_L1_DTLB_HIT__L1_4K_TLB_HIT = 0x1, // L1 4K TLB hit
		L1_DTLB_HIT__MASK__AMD64_FAM14H_L1_DTLB_HIT__L1_2M_TLB_HIT = 0x2, // L1 2M TLB hit
		L1_DTLB_HIT__MASK__AMD64_FAM14H_L1_DTLB_HIT__ALL = 0x3, // All sub-events selected
		DCACHE_SW_PREFETCHES = 0x52, // Number of software prefetches that do not cause an actual data cache refill
		DCACHE_SW_PREFETCHES__MASK__AMD64_FAM14H_DCACHE_SW_PREFETCHES__HIT = 0x1, // SW prefetch hit in the data cache
		DCACHE_SW_PREFETCHES__MASK__AMD64_FAM14H_DCACHE_SW_PREFETCHES__PENDING_FILL = 0x2, // SW prefetch hit a pending fill
		DCACHE_SW_PREFETCHES__MASK__AMD64_FAM14H_DCACHE_SW_PREFETCHES__NO_MAB = 0x4, // SW prefetch does not get a MAB
		DCACHE_SW_PREFETCHES__MASK__AMD64_FAM14H_DCACHE_SW_PREFETCHES__L2_HIT = 0x8, // SW prefetch hits L2
		DCACHE_SW_PREFETCHES__MASK__AMD64_FAM14H_DCACHE_SW_PREFETCHES__ALL = 0xf, // All sub-events selected
		GLOBAL_TLB_FLUSHES = 0x54, // Global TLB Flushes
		MEMORY_REQUESTS = 0x65, // Memory Requests by Type
		MEMORY_REQUESTS__MASK__AMD64_FAM14H_MEMORY_REQUESTS__NON_CACHEABLE = 0x1, // Requests to non-cacheable (UC) memory
		MEMORY_REQUESTS__MASK__AMD64_FAM14H_MEMORY_REQUESTS__WRITE_COMBINING = 0x2, // Requests to write-combining (WC) memory or WC buffer flushes to WB memory
		MEMORY_REQUESTS__MASK__AMD64_FAM14H_MEMORY_REQUESTS__STREAMING_STORE = 0x80, // Streaming store (SS) requests
		MEMORY_REQUESTS__MASK__AMD64_FAM14H_MEMORY_REQUESTS__ALL = 0x83, // All sub-events selected
		MAB_REQUESTS = 0x68, // Number of L1 I-cache and D-cache misses per buffer. Average latency by combining with MAB_WAIT_CYCLES.
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_0 = 0x0, // Data cache buffer 0
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_1 = 0x1, // Data cache buffer 1
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_2 = 0x2, // Data cache buffer 2
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_3 = 0x3, // Data cache buffer 3
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_4 = 0x4, // Data cache buffer 4
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_5 = 0x5, // Data cache buffer 5
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_6 = 0x6, // Data cache buffer 6
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_7 = 0x7, // Data cache buffer 7
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__IC_BUFFER_0 = 0x8, // Instruction cache Buffer 1
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__IC_BUFFER_1 = 0x9, // Instructions cache buffer 1
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__ANY_IC_BUFFER = 0xa, // Any instruction cache buffer
		MAB_REQUESTS__MASK__AMD64_FAM14H_MAB_REQUESTS__ANY_DC_BUFFER = 0xb, // Any data cache buffer
		MAB_WAIT_CYCLES = 0x69, // Latency of L1 I-cache and D-cache misses per buffer. Average latency by combining with MAB_REQUESTS.
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_0 = 0x0, // Data cache buffer 0
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_1 = 0x1, // Data cache buffer 1
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_2 = 0x2, // Data cache buffer 2
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_3 = 0x3, // Data cache buffer 3
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_4 = 0x4, // Data cache buffer 4
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_5 = 0x5, // Data cache buffer 5
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_6 = 0x6, // Data cache buffer 6
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__DC_BUFFER_7 = 0x7, // Data cache buffer 7
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__IC_BUFFER_0 = 0x8, // Instruction cache Buffer 1
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__IC_BUFFER_1 = 0x9, // Instructions cache buffer 1
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__ANY_IC_BUFFER = 0xa, // Any instruction cache buffer
		MAB_WAIT_CYCLES__MASK__AMD64_FAM14H_MAB_REQUESTS__ANY_DC_BUFFER = 0xb, // Any data cache buffer
		SYSTEM_READ_RESPONSES = 0x6c, // Northbridge Read Responses by Coherency State
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__EXCLUSIVE = 0x1, // Exclusive
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__MODIFIED = 0x2, // Modified
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__SHARED = 0x4, // Shared
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__OWNED = 0x8, // Owned
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__DATA_ERROR = 0x10, // Data Error
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__DIRTY_SUCCESS = 0x20, // Change-to-dirty success
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__UNCACHEABLE = 0x40, // Uncacheable
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM14H_SYSTEM_READ_RESPONSES__ALL = 0x7f, // All sub-events selected
		CPU_CLK_UNHALTED = 0x76, // CPU Clocks not Halted
		REQUESTS_TO_L2 = 0x7d, // Requests to L2 Cache
		REQUESTS_TO_L2__MASK__AMD64_FAM14H_REQUESTS_TO_L2__INSTRUCTIONS = 0x1, // IC fill
		REQUESTS_TO_L2__MASK__AMD64_FAM14H_REQUESTS_TO_L2__DATA = 0x2, // DC fill
		REQUESTS_TO_L2__MASK__AMD64_FAM14H_REQUESTS_TO_L2__SNOOP = 0x8, // Tag snoop request
		REQUESTS_TO_L2__MASK__AMD64_FAM14H_REQUESTS_TO_L2__ALL = 0xb, // All sub-events selected
		L2_CACHE_MISS = 0x7e, // L2 Cache Misses
		L2_CACHE_MISS__MASK__AMD64_FAM14H_L2_CACHE_MISS__INSTRUCTIONS = 0x1, // IC fill
		L2_CACHE_MISS__MASK__AMD64_FAM14H_L2_CACHE_MISS__DATA = 0x2, // DC fill (includes possible replays
		L2_CACHE_MISS__MASK__AMD64_FAM14H_L2_CACHE_MISS__ALL = 0x3, // All sub-events selected
		L2_FILL_WRITEBACK = 0x7f, // L2 Fill/Writeback
		L2_FILL_WRITEBACK__MASK__AMD64_FAM14H_L2_FILL_WRITEBACK__L2_FILLS = 0x1, // L2 fills (victims from L1 caches
		L2_FILL_WRITEBACK__MASK__AMD64_FAM14H_L2_FILL_WRITEBACK__L2_WRITEBACKS = 0x2, // L2 Writebacks to system.
		L2_FILL_WRITEBACK__MASK__AMD64_FAM14H_L2_FILL_WRITEBACK__IC_ATTR_WRITES_L2_ACCESS = 0x4, // Ic attribute writes which access the L2
		L2_FILL_WRITEBACK__MASK__AMD64_FAM14H_L2_FILL_WRITEBACK__IC_ATTR_WRITES_L2_WRITES = 0x8, // Ic attribute writes which store into the L2
		L2_FILL_WRITEBACK__MASK__AMD64_FAM14H_L2_FILL_WRITEBACK__ALL = 0xf, // All sub-events selected
		INSTRUCTION_CACHE_FETCHES = 0x80, // Instruction Cache Fetches
		INSTRUCTION_CACHE_MISSES = 0x81, // Instruction Cache Misses
		INSTRUCTION_CACHE_REFILLS_FROM_L2 = 0x82, // Instruction Cache Refills from L2
		INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM = 0x83, // Instruction Cache Refills from System
		L1_ITLB_MISS_AND_L2_ITLB_MISS = 0x85, // L1 ITLB Miss and L2 ITLB Miss
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM14H_L1_ITLB_MISS_AND_L2_ITLB_MISS__4K_PAGE_FETCHES = 0x1, // Instruction fetches to a 4K page.
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM14H_L1_ITLB_MISS_AND_L2_ITLB_MISS__2M_PAGE_FETCHES = 0x2, // Instruction fetches to a 2M page.
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM14H_L1_ITLB_MISS_AND_L2_ITLB_MISS__ALL = 0x3, // All sub-events selected
		INSTRUCTION_FETCH_STALL = 0x87, // Instruction Fetch Stall
		RETURN_STACK_HITS = 0x88, // Return Stack Hits
		RETURN_STACK_OVERFLOWS = 0x89, // Return Stack Overflows
		INSTRUCTION_CACHE_VICTIMS = 0x8b, // Instruction Cache Victims
		INSTRUCTION_CACHE_LINES_INVALIDATED = 0x8c, // Instruction Cache Lines Invalidated
		INSTRUCTION_CACHE_LINES_INVALIDATED__MASK__AMD64_FAM14H_INSTRUCTION_CACHE_LINES_INVALIDATED__INVALIDATING_LS_PROBE = 0x1, // IC invalidate due to an LS probe
		INSTRUCTION_CACHE_LINES_INVALIDATED__MASK__AMD64_FAM14H_INSTRUCTION_CACHE_LINES_INVALIDATED__INVALIDATING_BU_PROBE = 0x2, // IC invalidate due to a BU probe
		INSTRUCTION_CACHE_LINES_INVALIDATED__MASK__AMD64_FAM14H_INSTRUCTION_CACHE_LINES_INVALIDATED__ALL = 0x3, // All sub-events selected
		ITLB_RELOADS = 0x99, // ITLB Reloads
		ITLB_RELOADS_ABORTED = 0x9a, // ITLB Reloads Aborted
		RETIRED_INSTRUCTIONS = 0xc0, // Retired Instructions
		RETIRED_UOPS = 0xc1, // Retired uops
		RETIRED_BRANCH_INSTRUCTIONS = 0xc2, // Retired Branch Instructions
		RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS = 0xc3, // Retired Mispredicted Branch Instructions
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS = 0xc4, // Retired Taken Branch Instructions
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc5, // Retired Taken Branch Instructions Mispredicted
		RETIRED_FAR_CONTROL_TRANSFERS = 0xc6, // Retired Far Control Transfers
		RETIRED_BRANCH_RESYNCS = 0xc7, // Retired Branch Resyncs
		RETIRED_NEAR_RETURNS = 0xc8, // Retired Near Returns
		RETIRED_NEAR_RETURNS_MISPREDICTED = 0xc9, // Retired Near Returns Mispredicted
		RETIRED_INDIRECT_BRANCHES_MISPREDICTED = 0xca, // Retired Indirect Branches Mispredicted
		RETIRED_FLOATING_POINT_INSTRUCTIONS = 0xcb, // Retired SSE/MMX/FP Instructions
		RETIRED_FLOATING_POINT_INSTRUCTIONS__MASK__AMD64_FAM14H_RETIRED_FLOATING_POINT_INSTRUCTIONS__X87 = 0x1, // X87 or MMX instructions
		RETIRED_FLOATING_POINT_INSTRUCTIONS__MASK__AMD64_FAM14H_RETIRED_FLOATING_POINT_INSTRUCTIONS__SSE = 0x2, // SSE (SSE
		RETIRED_FLOATING_POINT_INSTRUCTIONS__MASK__AMD64_FAM14H_RETIRED_FLOATING_POINT_INSTRUCTIONS__ALL = 0x3, // All sub-events selected
		INTERRUPTS_MASKED_CYCLES = 0xcd, // Interrupts-Masked Cycles
		INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING = 0xce, // Interrupts-Masked Cycles with Interrupt Pending
		INTERRUPTS_TAKEN = 0xcf, // Interrupts Taken
		FPU_EXCEPTIONS = 0xdb, // FPU Exceptions
		FPU_EXCEPTIONS__MASK__AMD64_FAM14H_FPU_EXCEPTIONS__X87_RECLASS_MICROFAULTS = 0x1, // X87 reclass microfaults
		FPU_EXCEPTIONS__MASK__AMD64_FAM14H_FPU_EXCEPTIONS__SSE_RETYPE_MICROFAULTS = 0x2, // SSE retype microfaults
		FPU_EXCEPTIONS__MASK__AMD64_FAM14H_FPU_EXCEPTIONS__SSE_RECLASS_MICROFAULTS = 0x4, // SSE reclass microfaults
		FPU_EXCEPTIONS__MASK__AMD64_FAM14H_FPU_EXCEPTIONS__SSE_AND_X87_MICROTRAPS = 0x8, // SSE and x87 microtraps
		FPU_EXCEPTIONS__MASK__AMD64_FAM14H_FPU_EXCEPTIONS__ALL = 0xf, // All sub-events selected
		DR0_BREAKPOINT_MATCHES = 0xdc, // DR0 Breakpoint Matches
		DR1_BREAKPOINT_MATCHES = 0xdd, // DR1 Breakpoint Matches
		DR2_BREAKPOINT_MATCHES = 0xde, // DR2 Breakpoint Matches
		DR3_BREAKPOINT_MATCHES = 0xdf, // DR3 Breakpoint Matches
		DRAM_ACCESSES_PAGE = 0xe0, // DRAM Accesses
		DRAM_ACCESSES_PAGE__MASK__AMD64_FAM14H_DRAM_ACCESSES_PAGE__HIT = 0x1, // DCT0 Page hit
		DRAM_ACCESSES_PAGE__MASK__AMD64_FAM14H_DRAM_ACCESSES_PAGE__MISS = 0x2, // DCT0 Page Miss
		DRAM_ACCESSES_PAGE__MASK__AMD64_FAM14H_DRAM_ACCESSES_PAGE__CONFLICT = 0x4, // DCT0 Page Conflict
		DRAM_ACCESSES_PAGE__MASK__AMD64_FAM14H_DRAM_ACCESSES_PAGE__WRITE_REQUEST = 0x40, // Write request
		DRAM_ACCESSES_PAGE__MASK__AMD64_FAM14H_DRAM_ACCESSES_PAGE__ALL = 0x47, // All sub-events selected
		MEMORY_CONTROLLER_PAGE_TABLE = 0xe1, // Number of page table events in the local DRAM controller
		MEMORY_CONTROLLER_PAGE_TABLE__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_PAGE_TABLE__DCT0_PAGE_TABLE_OVERFLOW = 0x1, // DCT0 Page Table Overflow
		MEMORY_CONTROLLER_PAGE_TABLE__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_PAGE_TABLE__DCT0_PAGE_TABLE_STALE_HIT = 0x2, // DCT0 number of stale table entry hits (hit on a page closed too soon)
		MEMORY_CONTROLLER_PAGE_TABLE__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_PAGE_TABLE__DCT0_PAGE_TABLE_IDLE_INC = 0x4, // DCT0 page table idle cycle limit incremented
		MEMORY_CONTROLLER_PAGE_TABLE__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_PAGE_TABLE__DCT0_PAGE_TABLE_IDLE_DEC = 0x8, // DCT0 page table idle cycle limit decremented
		MEMORY_CONTROLLER_PAGE_TABLE__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_PAGE_TABLE__DCT0_PAGE_TABLE_CLOSED = 0x10, // DCT0 page table is closed due to row inactivity
		MEMORY_CONTROLLER_PAGE_TABLE__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_PAGE_TABLE__ALL = 0x1f, // All sub-events selected
		MEMORY_CONTROLLER_SLOT_MISSES = 0xe2, // Memory Controller DRAM Command Slots Missed
		MEMORY_CONTROLLER_SLOT_MISSES__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_SLOT_MISSES__DCT0_RBD = 0x10, // DCT0 RBD
		MEMORY_CONTROLLER_SLOT_MISSES__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_SLOT_MISSES__DCT0_PREFETCH = 0x40, // DCT0 prefetch
		MEMORY_CONTROLLER_SLOT_MISSES__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_SLOT_MISSES__ALL = 0x50, // All sub-events selected
		MEMORY_CONTROLLER_RBD_QUEUE_EVENTS = 0xe4, // Memory Controller Bypass Counter Saturation
		MEMORY_CONTROLLER_RBD_QUEUE_EVENTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_RBD_QUEUE_EVENTS__DCQ_BYPASS_MAX = 0x4, // DCQ_BYPASS_MAX counter reached
		MEMORY_CONTROLLER_RBD_QUEUE_EVENTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_RBD_QUEUE_EVENTS__BANK_CLOSED = 0x8, // Bank is closed due to bank conflict with an outstanding request in the RBD queue
		MEMORY_CONTROLLER_RBD_QUEUE_EVENTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_RBD_QUEUE_EVENTS__ALL = 0xc, // All sub-events selected
		THERMAL_STATUS = 0xe8, // Thermal Status
		THERMAL_STATUS__MASK__AMD64_FAM14H_THERMAL_STATUS__MEMHOT_L = 0x1, // MEMHOT_L assertions
		THERMAL_STATUS__MASK__AMD64_FAM14H_THERMAL_STATUS__HTC_TRANSITION = 0x4, // Number of times HTC transitions from inactive to active
		THERMAL_STATUS__MASK__AMD64_FAM14H_THERMAL_STATUS__CLOCKS_HTC_P_STATE_INACTIVE = 0x20, // Number of clocks HTC P-state is inactive.
		THERMAL_STATUS__MASK__AMD64_FAM14H_THERMAL_STATUS__CLOCKS_HTC_P_STATE_ACTIVE = 0x40, // Number of clocks HTC P-state is active
		THERMAL_STATUS__MASK__AMD64_FAM14H_THERMAL_STATUS__PROCHOT_L = 0x80, // PROCHOT_L asserted by an external source and the assertion causes a P-state change
		THERMAL_STATUS__MASK__AMD64_FAM14H_THERMAL_STATUS__ALL = 0xc5, // All sub-events selected
		CPU_IO_REQUESTS_TO_MEMORY_IO = 0xe9, // CPU/IO Requests to Memory/IO
		CPU_IO_REQUESTS_TO_MEMORY_IO__MASK__AMD64_FAM14H_CPU_IO_REQUESTS_TO_MEMORY_IO__I_O_TO_I_O = 0x1, // IO to IO
		CPU_IO_REQUESTS_TO_MEMORY_IO__MASK__AMD64_FAM14H_CPU_IO_REQUESTS_TO_MEMORY_IO__I_O_TO_MEM = 0x2, // IO to Mem
		CPU_IO_REQUESTS_TO_MEMORY_IO__MASK__AMD64_FAM14H_CPU_IO_REQUESTS_TO_MEMORY_IO__CPU_TO_I_O = 0x4, // CPU to IO
		CPU_IO_REQUESTS_TO_MEMORY_IO__MASK__AMD64_FAM14H_CPU_IO_REQUESTS_TO_MEMORY_IO__CPU_TO_MEM = 0x8, // CPU to Mem
		CPU_IO_REQUESTS_TO_MEMORY_IO__MASK__AMD64_FAM14H_CPU_IO_REQUESTS_TO_MEMORY_IO__ALL = 0xf, // All sub-events selected
		CACHE_BLOCK = 0xea, // Cache Block Commands
		CACHE_BLOCK__MASK__AMD64_FAM14H_CACHE_BLOCK__VICTIM_WRITEBACK = 0x1, // Victim Block (Writeback)
		CACHE_BLOCK__MASK__AMD64_FAM14H_CACHE_BLOCK__DCACHE_LOAD_MISS = 0x4, // Read Block (Dcache load miss refill)
		CACHE_BLOCK__MASK__AMD64_FAM14H_CACHE_BLOCK__SHARED_ICACHE_REFILL = 0x8, // Read Block Shared (Icache refill)
		CACHE_BLOCK__MASK__AMD64_FAM14H_CACHE_BLOCK__READ_BLOCK_MODIFIED = 0x10, // Read Block Modified (Dcache store miss refill)
		CACHE_BLOCK__MASK__AMD64_FAM14H_CACHE_BLOCK__CHANGE_TO_DIRTY = 0x20, // Change-to-Dirty (first store to clean block already in cache)
		CACHE_BLOCK__MASK__AMD64_FAM14H_CACHE_BLOCK__ALL = 0x3d, // All sub-events selected
		SIZED_COMMANDS = 0xeb, // Sized Commands
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__NON_POSTED_WRITE_BYTE = 0x1, // Non-Posted SzWr Byte (1-32 bytes) Legacy or mapped IO
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__NON_POSTED_WRITE_DWORD = 0x2, // Non-Posted SzWr DW (1-16 dwords) Legacy or mapped IO
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__POSTED_WRITE_BYTE = 0x4, // Posted SzWr Byte (1-32 bytes) Subcache-line DMA writes
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__POSTED_WRITE_DWORD = 0x8, // Posted SzWr DW (1-16 dwords) Block-oriented DMA writes
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__READ_BYTE_4_BYTES = 0x10, // SzRd Byte (4 bytes) Legacy or mapped IO
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__READ_DWORD_1_16_DWORDS = 0x20, // SzRd DW (1-16 dwords) Block-oriented DMA reads
		SIZED_COMMANDS__MASK__AMD64_FAM14H_SIZED_COMMANDS__ALL = 0x3f, // All sub-events selected
		PROBE = 0xec, // Probe Responses and Upstream Requests
		PROBE__MASK__AMD64_FAM14H_PROBE__MISS = 0x1, // Probe miss
		PROBE__MASK__AMD64_FAM14H_PROBE__HIT_CLEAN = 0x2, // Probe hit clean
		PROBE__MASK__AMD64_FAM14H_PROBE__HIT_DIRTY_NO_MEMORY_CANCEL = 0x4, // Probe hit dirty without memory cancel (probed by Sized Write or Change2Dirty)
		PROBE__MASK__AMD64_FAM14H_PROBE__HIT_DIRTY_WITH_MEMORY_CANCEL = 0x8, // Probe hit dirty with memory cancel (probed by DMA read or cache refill request)
		PROBE__MASK__AMD64_FAM14H_PROBE__UPSTREAM_HIGH_PRIO_READS = 0x10, // Upstream high priority reads
		PROBE__MASK__AMD64_FAM14H_PROBE__UPSTREAM_LOW_PRIO_READS = 0x20, // Upstream low priority reads
		PROBE__MASK__AMD64_FAM14H_PROBE__UPSTREAM_LOW_PRIO_WRITES = 0x80, // Upstream non-ISOC writes
		PROBE__MASK__AMD64_FAM14H_PROBE__ALL = 0xbf, // All sub-events selected
		DEV_EVENTS = 0xee, // DEV Events
		DEV_EVENTS__MASK__AMD64_FAM14H_DEV_EVENTS__HIT = 0x10, // DEV hit
		DEV_EVENTS__MASK__AMD64_FAM14H_DEV_EVENTS__MISS = 0x20, // DEV miss
		DEV_EVENTS__MASK__AMD64_FAM14H_DEV_EVENTS__ERROR = 0x40, // DEV error
		DEV_EVENTS__MASK__AMD64_FAM14H_DEV_EVENTS__ALL = 0x70, // All sub-events selected
		MEMORY_CONTROLLER_REQUESTS = 0x1f0, // Memory Controller Requests
		MEMORY_CONTROLLER_REQUESTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_REQUESTS__32_BYTES_WRITES = 0x8, // 32 Bytes Sized Writes
		MEMORY_CONTROLLER_REQUESTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_REQUESTS__64_BYTES_WRITES = 0x10, // 64 Bytes Sized Writes
		MEMORY_CONTROLLER_REQUESTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_REQUESTS__32_BYTES_READS = 0x20, // 32 Bytes Sized Reads
		MEMORY_CONTROLLER_REQUESTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_REQUESTS__64_BYTES_READS = 0x40, // 64 Byte Sized Reads
		MEMORY_CONTROLLER_REQUESTS__MASK__AMD64_FAM14H_MEMORY_CONTROLLER_REQUESTS__ALL = 0x78, // All sub-events selected
		SIDEBAND_SIGNALS_SPECIAL_SIGNALS = 0x1e9, // Sideband signals and special cycles
		SIDEBAND_SIGNALS_SPECIAL_SIGNALS__MASK__AMD64_FAM14H_SIDEBAND_SIGNALS_SPECIAL_SIGNALS__STOPGRANT = 0x2, // Stopgrant
		SIDEBAND_SIGNALS_SPECIAL_SIGNALS__MASK__AMD64_FAM14H_SIDEBAND_SIGNALS_SPECIAL_SIGNALS__SHUTDOWN = 0x4, // Shutdown
		SIDEBAND_SIGNALS_SPECIAL_SIGNALS__MASK__AMD64_FAM14H_SIDEBAND_SIGNALS_SPECIAL_SIGNALS__WBINVD = 0x8, // Wbinvd
		SIDEBAND_SIGNALS_SPECIAL_SIGNALS__MASK__AMD64_FAM14H_SIDEBAND_SIGNALS_SPECIAL_SIGNALS__INVD = 0x10, // Invd
		SIDEBAND_SIGNALS_SPECIAL_SIGNALS__MASK__AMD64_FAM14H_SIDEBAND_SIGNALS_SPECIAL_SIGNALS__ALL = 0x1c, // All sub-events selected
		INTERRUPT_EVENTS = 0x1ea, // Interrupt events
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__FIXED_AND_LPA = 0x1, // Fixed and LPA
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__LPA = 0x2, // LPA
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__SMI = 0x4, // SMI
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__NMI = 0x8, // NMI
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__INIT = 0x10, // INIT
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__STARTUP = 0x20, // STARTUP
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__INT = 0x40, // INT
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__EOI = 0x80, // EOI
		INTERRUPT_EVENTS__MASK__AMD64_FAM14H_INTERRUPT_EVENTS__ALL = 0xff, // All sub-events selected
		PDC_MISS = 0x162, // PDC miss
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__HOST_PDE_LEVEL = 0x1, // Host PDE level
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__HOST_PDPE_LEVEL = 0x2, // Host PDPE level
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__HOST_PML4E_LEVEL = 0x4, // Host PML4E level
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__GUEST_PDE_LEVEL = 0x10, // Guest PDE level
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__GUEST_PDPE_LEVEL = 0x20, // Guest PDPE level
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__GUEST_PML4E_LEVEL = 0x40, // Guest PML4E level
		PDC_MISS__MASK__AMD64_FAM14H_PDC_MISS__ALL = 0x67, // All sub-events selected
		
	};
};

namespace fam14h = optkit::amd64::fam14h;