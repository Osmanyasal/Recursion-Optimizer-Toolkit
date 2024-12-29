#include "core/event_recepies/tmanalysis.hh"

namespace optkit::core::recepies
{
    TMAnalysis::TMAnalysis(const char *block_name, const char *event_name, bool verbose, const ProfilerConfig &config) : block_name{block_name}, event_name{event_name}, verbose{verbose}, profiler_config{config}
    {
        start_time = __rdtsc();
    }

    void TMAnalysis::begin_monitoring(L1Metric metric)
    {
        switch (metric)
        {
        case L1Metric::Default:
            this->recipie_to_monitor = L1__default__recipie();
            analise_method_L1 = &TMAnalysis::L1__analise;
            break;

        case L1Metric::IPC:
            this->recipie_to_monitor = L1__default__recipie();
            analise_method_L1 = &TMAnalysis::L1__analise;
            break;

        case L1Metric::BackendBound:
        {
            this->recipie_to_monitor = L2__backend__memory();
            auto temp = L2__backend__core();
            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), temp.begin(), temp.end());
            analise_method_L2 = &TMAnalysis::L1__backend__analise;
            break;
        }

        case L1Metric::BadSpeculation:
        {
            this->recipie_to_monitor = L2__bad_speculation__branch_mispredict();
            auto temp = L2__bad_speculation__machine_clears();
            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), temp.begin(), temp.end());
            analise_method_L2 = &TMAnalysis::L1__bad_speculation__analise;
            break;
        }
        case L1Metric::Retiring:
        {
            this->recipie_to_monitor = L2__retiring__base();
            auto temp = L2__retiring__micro_sequencer();
            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), temp.begin(), temp.end());
            break;
        }
        case L1Metric::FrontendBound:
        {
            this->recipie_to_monitor = L2__frontend__fetch_bandwidth();
            auto temp = L2__frontend__fetch_latency();
            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), temp.begin(), temp.end());
            break;
        }
        default:
        {
            this->recipie_to_monitor = L1__default__recipie();
            analise_method_L1 = &TMAnalysis::L1__analise;
            break;
        }
        }

        choose_profiler();
    }
    void TMAnalysis::begin_monitoring(L2Metric metric)
    {
        switch (metric)
        {
        case L2Metric::Default:
            this->recipie_to_monitor = L2__default__recipie();
            break;

        case L2Metric::MemoryBound:
        {
            this->recipie_to_monitor = L3__memory__ext_memory();
            auto l1 = L3__memory__l1();
            auto l2 = L3__memory__l2();
            auto l3 = L3__memory__l3();

            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), l1.begin(), l1.end());
            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), l2.begin(), l2.end());
            this->recipie_to_monitor.insert(this->recipie_to_monitor.end(), l3.begin(), l3.end());
            break;
        }

        case L2Metric::CoreBound:
            break;

        case L2Metric::Base:
            break;

        case L2Metric::FetchLatency:
            break;

        case L2Metric::FetchBandwidth:
            break;

        default:
            this->recipie_to_monitor = L2__default__recipie();
            break;
        }

        choose_profiler();
    }

    void TMAnalysis::begin_monitoring(L3Metric metric)
    {

        choose_profiler();
    }

    void TMAnalysis::choose_profiler()
    {
        int32_t num_cntrs = core::pmu::QueryPMU::default_pmu_info().num_cntrs;
        if (OPT_UNLIKELY(core::pmu::PMUEventManager::number_of_events_being_monitored() + this->recipie_to_monitor.size() > num_cntrs))
        {
            OPTKIT_CORE_INFO("TMA chose block profiler");
            this->profiler_config.setGrouped(false);
            profiler_ref = std::unique_ptr<core::pmu::BlockProfiler>(
                new core::pmu::BlockProfiler(this->block_name, this->event_name, this->recipie_to_monitor, false, this->profiler_config));
        }
        else
        {
            OPTKIT_CORE_INFO("TMA chose block group profiler");
            this->profiler_config.setGrouped(true);
            profiler_ref = std::unique_ptr<core::pmu::BlockGroupProfiler>(
                new core::pmu::BlockGroupProfiler(this->block_name, this->event_name, this->recipie_to_monitor, false, this->profiler_config));
        }
    }

    TMAnalysis::~TMAnalysis()
    {
        delta_time = __rdtsc() - start_time; // get delta time.
        if (analise_method_L1)
        {
            OPTKIT_CORE_INFO("EXECUTING ANALYSIS METHOD 1");
            std::cout << (this->*analise_method_L1)() << "\n";
        }
        if (analise_method_L2)
        {
            OPTKIT_CORE_INFO("EXECUTING ANALYSIS METHOD 2");
            std::cout << (this->*analise_method_L2)() << "\n";
        }
        if (analise_method_L3)
        {
            OPTKIT_CORE_INFO("EXECUTING ANALYSIS METHOD 3");
            std::cout << (this->*analise_method_L3)() << "\n";
        }
    }

    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L1__default__recipie()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                               // 0
            {(0x9c | 0x100), "IDQ_UOPS_NOT_DELIVERED"},                               // 1
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                       // 2
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                            // 3
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"}, // 4
            {0xc0, "INSTRUCTION_RETIRED"}};                                           // 5

        // be_bound = 1 - (fe_bound + bad_speculation + retiring)

        return default_mapping;
    }

    std::map<L1Metric, double> TMAnalysis::L1__analise()
    {
        const std::vector<uint64_t> &pmu_record = profiler_ref->read_val();
        std::map<L1Metric, double> result;

        double SLOTS = 4 * pmu_record[0];

        result[L1Metric::CPU_UTIL] = (double)pmu_record[0] / delta_time;
        result[L1Metric::IPC] = ((double)pmu_record[5] / pmu_record[0]);
        result[L1Metric::FrontendBound] = (pmu_record[1] / SLOTS);                                        // IDQ_UOPS_NOT_DELIVERED.CORE / Slots
        result[L1Metric::Retiring] = (pmu_record[3] / SLOTS);                                             // UOPS_RETIRED.RETIRE_SLOTS / Slots
        result[L1Metric::BadSpeculation] = ((pmu_record[2] - pmu_record[3] + 4 * pmu_record[4]) / SLOTS); // (UOPS_ISSUED.ANY - UOPS_RETIRED.RETIRE_SLOTS + 4* INT_MISC.RECOVERY_CYCLES) / Slots
        result[L1Metric::BackendBound] = (1.0 - (result[L1Metric::FrontendBound] +
                                                 result[L1Metric::BadSpeculation] +
                                                 result[L1Metric::Retiring])); // 1 – (Frontend Bound + Bad Speculation + Retiring)

        return result;
    }

    // TODO: Rephrase this for l2
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__default__recipie()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                               // 0
            {(0x9c | 0x100), "IDQ_UOPS_NOT_DELIVERED"},                               // 1
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                       // 2
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                            // 3
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"}, // 4
            {0xc0, "INSTRUCTION_RETIRED"}};                                           // 5

        // be_bound = 1 - (fe_bound + bad_speculation + retiring)

        return default_mapping;
    }

    std::map<L1Metric, double> TMAnalysis::L2__analise()
    {
        const std::vector<uint64_t> &pmu_record = profiler_ref->read_val();
        std::map<L1Metric, double> result;

        return result;
    }

    // these 2 returns l1 backend-bound
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__backend__core()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{}; // 1 - L2__backend__memory
        return default_mapping;
    };
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__backend__memory()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                          // 0
            {(0xa3 | 0x0c00 | (0xc << INTEL_X86_CMASK_BIT)), "STALLS_L1D_MISS"}, // 1
            {(0xa3 | 0x0500 | (0x5 << INTEL_X86_CMASK_BIT)), "STALLS_L2_MISS"},  // 2
            {(0xa3 | 0x0600 | (0x6 << INTEL_X86_CMASK_BIT)), "STALLS_L3_MISS"},  // 3
            {(0xa2 | 0x800), "RESOURCE_STALLS_SB"}                               // 4
        };
        return default_mapping;
    }

    std::map<L2Metric, double> TMAnalysis::L1__backend__analise()
    {
        std::map<L2Metric, double> result;
        const std::vector<uint64_t> &pmu_record = profiler_ref->read_val();

        double CLOCKS = pmu_record[0];
        result[L2Metric::MemoryBound] = (((pmu_record[1] + pmu_record[2] + pmu_record[3]) - pmu_record[4]) / CLOCKS);
        result[L2Metric::CoreBound] = 1.0 - result[L2Metric::MemoryBound];
        return result;
    }

    // following 2 returns l1 bad-specualtion
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__bad_speculation__branch_mispredict()
    {
        OPTKIT_CORE_WARN("This setting is vaild for intel {ivb, spr, snb, skl, icl, bdw , hsw} architectures check MACHINE_CLEARS_COUNT event for different u-arch.");
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                                                                    // 0
            {0x00c5, "BR_MISP_RETIRED"},                                                                                   // 1
            {(0x00c3 | (0x0100ull | (0x1 << INTEL_X86_CMASK_BIT) | (0x1 << INTEL_X86_EDGE_BIT))), "MACHINE_CLEARS_COUNT"}, // 2
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                                                            // 3
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                                                                 // 4
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"},                                      // 5

        };
        return default_mapping;
    };
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__bad_speculation__machine_clears()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping;
        return default_mapping; // BadSpeculation - BranchMispredicts
    };
    std::map<L2Metric, double> TMAnalysis::L1__bad_speculation__analise()
    {

        /**
         * @brief #BrMispredFraction BrMispredRetired / (BrMispredRetired + MachineClears)
                Branch Mispredicts #BrMispredFraction * Bad Speculation
                Machine Clears Bad Speculation – Branch Mispredicts
         *
         */
        std::map<L2Metric, double> result;
        const std::vector<uint64_t> &pmu_record = profiler_ref->read_val();

        double CLOCKS = pmu_record[0];
        double SLOTS = CLOCKS * 4;
        double BAD_SPEC = ((pmu_record[3] - pmu_record[4] + 4 * pmu_record[5]) / SLOTS); // (UOPS_ISSUED.ANY - UOPS_RETIRED.RETIRE_SLOTS + 4* INT_MISC.RECOVERY_CYCLES) / Slots
        std::cout << "BAD SPEC=" << BAD_SPEC << "\n";
        result[L2Metric::BranchMisprediction] = (((double)pmu_record[1] / (pmu_record[1] + pmu_record[2])) * BAD_SPEC);
        result[L2Metric::MachineClear] = (BAD_SPEC - result[L2Metric::BranchMisprediction]);
        return result;
    }

    // following 2 returns l1 frontend-bound
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__frontend__fetch_bandwidth() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__frontend__fetch_latency() {};
    std::map<L2Metric, double> TMAnalysis::L1__frontend_bound__analise() {}

    // following 2 returns l1 retiring
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__retiring__base() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__retiring__micro_sequencer() {};
    std::map<L2Metric, double> TMAnalysis::L1__retiring__analise() {}

    // followign returns l2 memory bound
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__ext_memory() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__l1() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__l2() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__l3() {};
    std::map<L3Metric, double> TMAnalysis::L2__memory_bound__analise() {}

} // namespace optkit::core::recepies
