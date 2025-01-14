#pragma once
#include <cstdint>
#include "intel_priv.hh"
namespace optkit::intel::knc{
	enum knc : uint64_t {
		BANK_CONFLICTS = 0xa, // Number of actual bank conflicts
		BRANCHES = 0x12, // Number of taken and not taken branches
		BRANCHES_MISPREDICTED = 0x2b, // Number of branch mispredictions that occurred on BTB hits. BTB misses are not considered branch mispredicts because no prediction exists for them yet.
		CODE_CACHE_MISS = 0xe, // Number of instruction reads that miss the internal code cache; whether the read is cacheable or noncacheable
		CODE_PAGE_WALK = 0xd, // Number of code page walks
		CODE_READ = 0xc, // Number of instruction reads; whether the read is cacheable or noncacheable
		CPU_CLK_UNHALTED = 0x2a, // Number of cycles during which the processor is not halted.
		DATA_CACHE_LINES_WRITTEN_BACK = 0x6, // Number of dirty lines (all) that are written back
		DATA_PAGE_WALK = 0x2, // Number of data page walks
		DATA_READ = 0x0, // Number of successful memory data reads committed by the K-unit (L1). Cache accesses resulting from prefetch instructions are included for A0 stepping.
		DATA_READ_MISS = 0x3, // Number of memory read accesses that miss the internal data cache whether or not the access is cacheable or noncacheable. Cache accesses resulting from prefetch instructions are not included.
		DATA_READ_MISS_OR_WRITE_MISS = 0x29, // Number of memory read and/or write accesses that miss the internal data cache
		DATA_READ_OR_WRITE = 0x28, // Number of memory data reads and/or writes (internal data cache hit and miss combined). Read cache accesses resulting from prefetch instructions are included for A0 stepping.
		DATA_WRITE = 0x1, // Number of successful memory data writes committed by the K-unit (L1). Streaming stores (hit/miss L1)
		DATA_WRITE_MISS = 0x4, // Number of memory write accesses that miss the internal data cache whether or not the access is cacheable. Non-cacheable misses are not included.
		EXEC_STAGE_CYCLES = 0x2e, // Number of E-stage cycles that were successfully completed. Includes cycles generated by multi-cycle E-stage instructions. For instructions destined for the FPU or VPU pipelines
		FE_STALLED = 0x2d, // Number of cycles where the front-end could not advance. Any multi-cycle instructions which delay pipeline advance and apply backpressure to the front-end will be included
		INSTRUCTIONS_EXECUTED = 0x16, // Number of instructions executed (up to two per clock)
		INSTRUCTIONS_EXECUTED_V_PIPE = 0x17, // Number of instructions executed in the V_pipe. The event indicates the number of instructions that were paired.
		L1_DATA_HIT_INFLIGHT_PF1 = 0x20, // Number of data requests which hit an in-flight vprefetch0. The in-flight vprefetch0 was not necessarily issued from the same thread as the data request.
		L1_DATA_PF1 = 0x11, // Number of data vprefetch0 requests seen by the L1.
		L1_DATA_PF1_DROP = 0x1e, // Number of data vprefetch0 requests seen by the L1 which were dropped for any reason. A vprefetch0 can be dropped if the requested address matches another in-flight request or if it has a UC memtype.
		L1_DATA_PF1_MISS = 0x1c, // Number of data vprefetch0 requests seen by the L1 which missed L1. Does not include vprefetch1 requests which are counted in L1_DATA_PF1_DROP.
		L1_DATA_PF2 = 0x37, // Number of data vprefetch1 requests seen by the L1. This is not necessarily the same number as seen by the L2 because this count includes requests that are dropped by the core. A vprefetch1 can be dropped by the core if the requested address matches another in-flight request or if it has a UC memtype.
		L2_CODE_READ_MISS_CACHE_FILL = 0x10f0, // Number of code read accesses that missed the L2 cache and were satisfied by another L2 cache. Can include promoted read misses that started as DATA accesses.
		L2_CODE_READ_MISS_MEM_FILL = 0x10f5, // Number of code read accesses that missed the L2 cache and were satisfied by main memory. Can include promoted read misses that started as DATA accesses.
		L2_DATA_HIT_INFLIGHT_PF2 = 0x10ff, // Number of data requests which hit an in-flight vprefetch1. The in-flight vprefetch1 was not necessarily issued from the same thread as the data request.
		L2_DATA_PF1_MISS = 0x38, // Number of data vprefetch0 requests seen by the L2 which missed L2.
		L2_DATA_PF2 = 0x10fc, // Number of data vprefetch1 requests seen by the L2. Only counts vprefetch1 hits on A0 stepping.
		L2_DATA_PF2_DROP = 0x10fd, // Number of data vprefetch1 requests seen by the L2 which were dropped for any reason.
		L2_DATA_PF2_MISS = 0x10fe, // Number of data vprefetch1 requests seen by the L2 which missed L2. Does not include vprefetch2 requests which are counted in L2_DATA_PF2_DROP.
		L2_DATA_READ_MISS_CACHE_FILL = 0x10f1, // Number of data read accesses that missed the L2 cache and were satisfied by another L2 cache. Can include promoted read misses that started as CODE accesses.
		L2_DATA_READ_MISS_MEM_FILL = 0x10f6, // Number of data read accesses that missed the L2 cache and were satisfied by main memory. Can include promoted read misses that started as CODE accesses.
		L2_DATA_WRITE_MISS_CACHE_FILL = 0x10f2, // Number of data write (RFO) accesses that missed the L2 cache and were satisfied by another L2 cache.
		L2_DATA_WRITE_MISS_MEM_FILL = 0x10f7, // Number of data write (RFO) accesses that missed the L2 cache and were satisfied by main memory.
		L2_READ_HIT_E = 0x10c8, // L2 Read Hit E State
		L2_READ_HIT_M = 0x10c9, // L2 Read Hit M State
		L2_READ_HIT_S = 0x10ca, // L2 Read Hit S State
		L2_READ_MISS = 0x10cb, // L2 Read Misses. Prefetch and demand requests to the same address will produce double counting.
		L2_VICTIM_REQ_WITH_DATA = 0x10d7, // L2 received a victim request and responded with data
		L2_WRITE_HIT = 0x10cc, // L2 Write HIT
		LONG_CODE_PAGE_WALK = 0x3b, // Number of long code page walks
		LONG_DATA_PAGE_WALK = 0x3a, // Number of long data page walks
		MEMORY_ACCESSES_IN_BOTH_PIPES = 0x9, // Number of data memory reads or writes that are paired in both pipes of the pipeline
		MICROCODE_CYCLES = 0x2c, // The number of cycles microcode is executing. While microcode is executing
		PIPELINE_AGI_STALLS = 0x1f, // Number of address generation interlock (AGI) stalls. An AGI occurring in both the U- and V- pipelines in the same clock signals this event twice.
		PIPELINE_FLUSHES = 0x15, // Number of pipeline flushes that occur. Pipeline flushes are caused by BTB misses on taken branches
		PIPELINE_SG_AGI_STALLS = 0x21, // Number of address generation interlock (AGI) stalls due to vscatter* and vgather* instructions.
		SNP_HITM_BUNIT = 0x10e3, // Snoop HITM in BUNIT
		SNP_HITM_L2 = 0x10e7, // Snoop HITM in L2
		SNP_HIT_L2 = 0x10e6, // Snoop HIT in L2
		VPU_DATA_READ = 0x2000, // Number of read transactions that were issued. In general each read transaction will read 1 64B cacheline. If there are alignment issues
		VPU_DATA_READ_MISS = 0x2003, // VPU L1 data cache readmiss. Counts the number of occurrences.
		VPU_DATA_WRITE = 0x2001, // Number of write transactions that were issued. . In general each write transaction will write 1 64B cacheline. If there are alignment issues
		VPU_DATA_WRITE_MISS = 0x2004, // VPU L1 data cache write miss. Counts the number of occurrences.
		VPU_ELEMENTS_ACTIVE = 0x2018, // Counts the cumulative number of elements active (via mask) for VPU instructions issued.
		VPU_INSTRUCTIONS_EXECUTED = 0x2016, // Counts the number of VPU instructions executed in both u- and v-pipes.
		VPU_INSTRUCTIONS_EXECUTED_V_PIPE = 0x2017, // Counts the number of VPU instructions that paired and executed in the v-pipe.
		VPU_STALL_REG = 0x2005, // VPU stall on Register Dependency. Counts the number of occurrences. Dependencies will include RAW
		
	};
};

namespace knc = optkit::intel::knc;