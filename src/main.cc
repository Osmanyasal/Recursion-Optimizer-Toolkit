#include <omp.h>
#include <optkit.hh>
#include <test.hh>


int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    // optkit::core::recepies::amd64::zen3::ComputationalIntensity ci;
    // recepies::amd64::zen3::Recepies::computational_intensity();

    // std::cout << "num sockets: " << Query::num_sockets << " num cores:" << Query::num_cores << "\n";

    // return 0;

    // optkit::test::freq::run();

    // std::cout << "reset frequency !!\n";

    // CPUFrequency::reset_core_frequency(0);
    // CPUFrequency::reset_uncore_frequency(0);

    {
        double aa = 0;
        OPTKIT_PERFORMANCE_BLOCK_EVENTS("for_loop", "Computational Intensity", pp, recepies::amd64::zen3::Recepies::computational_intensity());

        for (int i = 0; i < 1000000; i++)
            aa = aa + i * 0.052; // 2M

        std::cout << aa << "\n";
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("file_read", "Computational Intensity", pp, recepies::amd64::zen3::Recepies::computational_intensity());

        std::cout << QueryFreq::get_bios_limit();
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("multiple_file_read", "Computational Intensity", pp, recepies::amd64::zen3::Recepies::computational_intensity());

        std::cout << QueryFreq::get_bios_limit() << QueryFreq::get_cpuinfo_max_freq() << QueryFreq::get_cpuinfo_min_freq() << QueryFreq::get_scaling_driver() << QueryFreq::get_scaling_max_limit();
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("multiple_file_write", "Computational Intensity", pp, recepies::amd64::zen3::Recepies::computational_intensity());

        for (int i = 0; i < 1; i++)
        {
            CPUFrequency::set_core_frequency(1200000, 0);
            CPUFrequency::set_core_frequency(1300000, 0);
            CPUFrequency::set_core_frequency(3300000, 0);
        }
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("combined", "Computational Intensity", pp, recepies::amd64::zen3::Recepies::computational_intensity());
        
        // file write
        CPUFrequency::set_core_frequency(1200000, 0);
        CPUFrequency::set_core_frequency(1300000, 0);
        CPUFrequency::set_core_frequency(3300000, 0);

        // compute
        float aa;
        for (int i = 0; i < 1000000; i++)
            aa = aa + i * 0.052; // 2M

        // file read
        std::cout << QueryFreq::get_bios_limit() << QueryFreq::get_cpuinfo_max_freq() << QueryFreq::get_cpuinfo_min_freq() << QueryFreq::get_scaling_driver() << QueryFreq::get_scaling_max_limit();
    }

    CPUFrequency::reset_core_frequency(0);

    return 0;
}
