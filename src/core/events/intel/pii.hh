#include <cstdint>
#include <intel_priv.hh>
namespace optkit::intel{
	enum class pii : uint64_t {
		CPU_CLK_UNHALTED = 0x79, // Number cycles during which the processor is not halted
		INST_RETIRED = 0xc0, // Number of instructions retired
		DATA_MEM_REFS = 0x43, // All loads from any memory type. All stores to any memory typeEach part of a split is counted separately. The internal logic counts not only memory loads and stores but also internal retries. 80-bit floating point accesses are double counted
		DCU_LINES_IN = 0x45, // Total lines allocated in the DCU
		DCU_M_LINES_IN = 0x46, // Number of M state lines allocated in the DCU
		DCU_M_LINES_OUT = 0x47, // Number of M state lines evicted from the DCU. This includes evictions via snoop HITM
		DCU_MISS_OUTSTANDING = 0x48, // Weighted number of cycle while a DCU miss is outstanding
		IFU_IFETCH = 0x80, // Number of instruction fetches
		IFU_IFETCH_MISS = 0x81, // Number of instruction fetch misses. All instructions fetches that do not hit the IFU (i.e.
		ITLB_MISS = 0x85, // Number of ITLB misses
		IFU_MEM_STALL = 0x86, // Number of cycles instruction fetch is stalled for any reason. Includes IFU cache misses
		ILD_STALL = 0x87, // Number of cycles that the instruction length decoder is stalled
		L2_IFETCH = 0x28, // Number of L2 instruction fetches. This event indicates that a normal instruction fetch was received by the L2. The count includes only L2 cacheable instruction fetches: it does not include UC instruction fetches It does not include ITLB miss accesses
		L2_IFETCH__MASK__PII_L2_IFETCH__I = 0x100, // Invalid state
		L2_IFETCH__MASK__PII_L2_IFETCH__S = 0x200, // Shared state
		L2_IFETCH__MASK__PII_L2_IFETCH__E = 0x400, // Exclusive state
		L2_IFETCH__MASK__PII_L2_IFETCH__M = 0x800, // Modified state
		L2_ST = 0x2a, // Number of L2 data stores. This event indicates that a normal
		L2_ST__MASK__PII_L2_IFETCH__I = 0x100, // Invalid state
		L2_ST__MASK__PII_L2_IFETCH__S = 0x200, // Shared state
		L2_ST__MASK__PII_L2_IFETCH__E = 0x400, // Exclusive state
		L2_ST__MASK__PII_L2_IFETCH__M = 0x800, // Modified state
		L2_M_LINES_INM = 0x25, // Number of modified lines allocated in the L2
		L2_RQSTS = 0x2e, // Total number of L2 requests
		L2_RQSTS__MASK__PII_L2_IFETCH__I = 0x100, // Invalid state
		L2_RQSTS__MASK__PII_L2_IFETCH__S = 0x200, // Shared state
		L2_RQSTS__MASK__PII_L2_IFETCH__E = 0x400, // Exclusive state
		L2_RQSTS__MASK__PII_L2_IFETCH__M = 0x800, // Modified state
		L2_ADS = 0x21, // Number of L2 address strobes
		L2_DBUS_BUSY = 0x22, // Number of cycles during which the L2 cache data bus was busy
		L2_DBUS_BUSY_RD = 0x23, // Number of cycles during which the data bus was busy transferring read data from L2 to the processor
		BUS_DRDY_CLOCKS = 0x62, // Number of clocks during which DRDY# is asserted. Utilization of the external system data bus during data transfers
		BUS_DRDY_CLOCKS__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_DRDY_CLOCKS__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_LOCK_CLOCKS = 0x63, // Number of clocks during which LOCK# is asserted on the external system bus
		BUS_LOCK_CLOCKS__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_LOCK_CLOCKS__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_REQ_OUTSTANDING = 0x60, // Number of bus requests outstanding. This counter is incremented by the number of cacheable read bus requests outstanding in any given cycle
		BUS_TRANS_BRD = 0x65, // Number of burst read transactions
		BUS_TRANS_BRD__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRANS_BRD__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRANS_RFO = 0x66, // Number of completed read for ownership transactions
		BUS_TRANS_RFO__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRANS_RFO__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRANS_WB = 0x67, // Number of completed write back transactions
		BUS_TRANS_WB__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRANS_WB__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_IFETCH = 0x68, // Number of completed instruction fetch transactions
		BUS_TRAN_IFETCH__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_IFETCH__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_INVAL = 0x69, // Number of completed invalidate transactions
		BUS_TRAN_INVAL__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_INVAL__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_PWR = 0x6a, // Number of completed partial write transactions
		BUS_TRAN_PWR__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_PWR__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRANS_P = 0x6b, // Number of completed partial transactions
		BUS_TRANS_P__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRANS_P__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRANS_IO = 0x6c, // Number of completed I/O transactions
		BUS_TRANS_IO__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRANS_IO__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_DEF = 0x6d, // Number of completed deferred transactions
		BUS_TRAN_DEF__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_DEF__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_BURST = 0x6e, // Number of completed burst transactions
		BUS_TRAN_BURST__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_BURST__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_ANY = 0x70, // Number of all completed bus transactions. Address bus utilization can be calculated knowing the minimum address bus occupancy. Includes special cycles
		BUS_TRAN_ANY__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_ANY__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_TRAN_MEM = 0x6f, // Number of completed memory transactions
		BUS_TRAN_MEM__MASK__PII_BUS_DRDY_CLOCKS__SELF = 0x0, // Clocks when processor is driving bus
		BUS_TRAN_MEM__MASK__PII_BUS_DRDY_CLOCKS__ANY = 0x2000, // Clocks when any agent is driving bus
		BUS_DATA_RECV = 0x64, // Number of bus clock cycles during which this processor is receiving data
		BUS_BNR_DRV = 0x61, // Number of bus clock cycles during which this processor is driving the BNR# pin
		BUS_HIT_DRV = 0x7a, // Number of bus clock cycles during which this processor is driving the HIT# pin
		BUS_HITM_DRV = 0x7b, // Number of bus clock cycles during which this processor is driving the HITM# pin
		BUS_SNOOP_STALL = 0x7e, // Number of clock cycles during which the bus is snoop stalled
		FLOPS = 0xc1, // Number of computational floating-point operations retired. Excludes floating-point computational operations that cause traps or assists. Includes internal sub-operations for complex floating-point instructions like transcendentals. Excludes floating point loads and stores
		FP_COMP_OPS_EXE = 0x10, // Number of computational floating-point operations executed. The number of FADD
		FP_ASSIST = 0x11, // Number of floating-point exception cases handled by microcode.
		MUL = 0x12, // Number of multiplies.This count includes integer as well as FP multiplies and is speculative
		DIV = 0x13, // Number of divides.This count includes integer as well as FP divides and is speculative
		CYCLES_DIV_BUSY = 0x14, // Number of cycles during which the divider is busy
		LD_BLOCKS = 0x3, // Number of load operations delayed due to store buffer blocks. Includes counts caused by preceding stores whose addresses are unknown
		SB_DRAINS = 0x4, // Number of store buffer drain cycles. Incremented every cycle the store buffer is draining. Draining is caused by serializing operations like CPUID
		MISALIGN_MEM_REF = 0x5, // Number of misaligned data memory references. Incremented by 1 every cycle during which
		UOPS_RETIRED = 0xc2, // Number of micro-ops retired
		INST_DECODED = 0xd0, // Number of instructions decoded
		HW_INT_RX = 0xc8, // Number of hardware interrupts received
		CYCLES_INT_MASKED = 0xc6, // Number of processor cycles for which interrupts are disabled
		CYCLES_INT_PENDING_AND_MASKED = 0xc7, // Number of processor cycles for which interrupts are disabled and interrupts are pending.
		BR_INST_RETIRED = 0xc4, // Number of branch instructions retired
		BR_MISS_PRED_RETIRED = 0xc5, // Number of mispredicted branches retired
		BR_TAKEN_RETIRED = 0xc9, // Number of taken branches retired
		BR_MISS_PRED_TAKEN_RET = 0xca, // Number of taken mispredicted branches retired
		BR_INST_DECODED = 0xe0, // Number of branch instructions decoded
		BTB_MISSES = 0xe2, // Number of branches for which the BTB did not produce a prediction
		BR_BOGUS = 0xe4, // Number of bogus branches
		BACLEARS = 0xe6, // 
		RESOURCE_STALLS = 0xa2, // Incremented by 1 during every cycle for which there is a resource related stall. Includes register renaming buffer entries
		PARTIAL_RAT_STALLS = 0xd2, // Number of cycles or events for partial stalls. This includes flag partial stalls
		SEGMENT_REG_LOADS = 0x6, // Number of segment register loads.
		MMX_INSTR_EXEC = 0xb0, // Number of MMX instructions executed
		MMX_INSTR_RET = 0xce, // Number of MMX instructions retired
		MMX_SAT_INSTR_EXEC = 0xb1, // Number of MMX saturating instructions executed
		MMX_UOPS_EXEC = 0xb2, // Number of MMX micro-ops executed
		MMX_INSTR_TYPE_EXEC = 0xb3, // Number of MMX instructions executed by type
		MMX_INSTR_TYPE_EXEC__MASK__PII_MMX_INSTR_TYPE_EXEC__MUL = 0x100, // MMX packed multiply instructions executed
		MMX_INSTR_TYPE_EXEC__MASK__PII_MMX_INSTR_TYPE_EXEC__SHIFT = 0x200, // MMX packed shift instructions executed
		MMX_INSTR_TYPE_EXEC__MASK__PII_MMX_INSTR_TYPE_EXEC__PACK = 0x400, // MMX pack operation instructions executed
		MMX_INSTR_TYPE_EXEC__MASK__PII_MMX_INSTR_TYPE_EXEC__UNPACK = 0x800, // MMX unpack operation instructions executed
		MMX_INSTR_TYPE_EXEC__MASK__PII_MMX_INSTR_TYPE_EXEC__LOGICAL = 0x1000, // MMX packed logical instructions executed
		MMX_INSTR_TYPE_EXEC__MASK__PII_MMX_INSTR_TYPE_EXEC__ARITH = 0x2000, // MMX packed arithmetic instructions executed
		FP_MMX_TRANS = 0xcc, // Number of MMX transitions
		FP_MMX_TRANS__MASK__PII_FP_MMX_TRANS__TO_FP = 0x0, // From MMX instructions to floating-point instructions
		FP_MMX_TRANS__MASK__PII_FP_MMX_TRANS__TO_MMX = 0x100, // From floating-point instructions to MMX instructions
		MMX_ASSIST = 0xcd, // Number of MMX micro-ops executed
		SEG_RENAME_STALLS = 0xd4, // Number of Segment Register Renaming Stalls
		SEG_RENAME_STALLS__MASK__PII_SEG_RENAME_STALLS__ES = 0x100, // Segment register ES
		SEG_RENAME_STALLS__MASK__PII_SEG_RENAME_STALLS__DS = 0x200, // Segment register DS
		SEG_RENAME_STALLS__MASK__PII_SEG_RENAME_STALLS__FS = 0x400, // Segment register FS
		SEG_RENAME_STALLS__MASK__PII_SEG_RENAME_STALLS__GS = 0x800, // Segment register GS
		SEG_REG_RENAMES = 0xd5, // Number of Segment Register Renames
		SEG_REG_RENAMES__MASK__PII_SEG_RENAME_STALLS__ES = 0x100, // Segment register ES
		SEG_REG_RENAMES__MASK__PII_SEG_RENAME_STALLS__DS = 0x200, // Segment register DS
		SEG_REG_RENAMES__MASK__PII_SEG_RENAME_STALLS__FS = 0x400, // Segment register FS
		SEG_REG_RENAMES__MASK__PII_SEG_RENAME_STALLS__GS = 0x800, // Segment register GS
		RET_SEG_RENAMES = 0xd6, // Number of segment register rename events retired
		L2_LD = 0x29, // Number of L2 data loads. This event indicates that a normal
		L2_LD__MASK__PII_L2_IFETCH__I = 0x100, // Invalid state
		L2_LD__MASK__PII_L2_IFETCH__S = 0x200, // Shared state
		L2_LD__MASK__PII_L2_IFETCH__E = 0x400, // Exclusive state
		L2_LD__MASK__PII_L2_IFETCH__M = 0x800, // Modified state
		L2_LINES_IN = 0x24, // Number of lines allocated in the L2
		L2_LINES_OUT = 0x26, // Number of lines removed from the L2 for any reason
		L2_M_LINES_OUTM = 0x27, // Number of modified lines removed from the L2 for any reason
		
	};
};