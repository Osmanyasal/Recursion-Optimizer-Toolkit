#pragma once
#include <cstdint>
#include "intel_priv.hh"
namespace optkit::intel::knl_unc_m2pcie{
	enum knl_unc_m2pcie : uint64_t {
		UNC_M2P_INGRESS_CYCLES_NE = 0x10, // Ingress Queue Cycles Not Empty. Counts the number of cycles when the M2PCIe Ingress is not empty
		UNC_M2P_INGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_INGRESS_CYCLES_NE__CBO_IDI = 0x0100, // CBO_IDI
		UNC_M2P_INGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_INGRESS_CYCLES_NE__CBO_NCB = 0x0200, // CBO_NCB
		UNC_M2P_INGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_INGRESS_CYCLES_NE__CBO_NCS = 0x0400, // CBO_NCS
		UNC_M2P_INGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_INGRESS_CYCLES_NE__ALL = 0x0800, // All
		UNC_M2P_EGRESS_CYCLES_NE = 0x23, // Egress (to CMS) Cycles Not Empty. Counts the number of cycles when the M2PCIe Egress is not empty
		UNC_M2P_EGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AD_0 = 0x0100, // AD_0
		UNC_M2P_EGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AK_0 = 0x0200, // AK_0
		UNC_M2P_EGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_EGRESS_CYCLES__BL_0 = 0x0400, // BL_0
		UNC_M2P_EGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AD_1 = 0x0800, // AD_1
		UNC_M2P_EGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AK_1 = 0x1000, // AK_1
		UNC_M2P_EGRESS_CYCLES_NE__MASK__KNL_UNC_M2P_EGRESS_CYCLES__BL_1 = 0x2000, // BL_1
		UNC_M2P_EGRESS_INSERTS = 0x24, // Egress (to CMS) Ingress. Counts the number of number of messages inserted into the  the M2PCIe Egress queue
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__AD_0 = 0x0100, // AD_0
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__AK_0 = 0x0200, // AK_0
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__BL_0 = 0x0400, // BL_0
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__AK_CRD_0 = 0x0800, // AK_CRD_0
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__AD_1 = 0x1000, // AD_1
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__AK_1 = 0x2000, // AK_1
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__BL_1 = 0x4000, // BL_1
		UNC_M2P_EGRESS_INSERTS__MASK__KNL_UNC_M2P_EGRESS_INSERTS__AK_CRD_1 = 0x8000, // AK_CRD_1
		UNC_M2P_EGRESS_CYCLES_FULL = 0x25, // Egress (to CMS) Cycles Full. Counts the number of cycles when the M2PCIe Egress is full
		UNC_M2P_EGRESS_CYCLES_FULL__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AD_0 = 0x0100, // AD_0
		UNC_M2P_EGRESS_CYCLES_FULL__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AK_0 = 0x0200, // AK_0
		UNC_M2P_EGRESS_CYCLES_FULL__MASK__KNL_UNC_M2P_EGRESS_CYCLES__BL_0 = 0x0400, // BL_0
		UNC_M2P_EGRESS_CYCLES_FULL__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AD_1 = 0x0800, // AD_1
		UNC_M2P_EGRESS_CYCLES_FULL__MASK__KNL_UNC_M2P_EGRESS_CYCLES__AK_1 = 0x1000, // AK_1
		UNC_M2P_EGRESS_CYCLES_FULL__MASK__KNL_UNC_M2P_EGRESS_CYCLES__BL_1 = 0x2000, // BL_1
		
	};
};

namespace knl_unc_m2pcie = optkit::intel::knl_unc_m2pcie;