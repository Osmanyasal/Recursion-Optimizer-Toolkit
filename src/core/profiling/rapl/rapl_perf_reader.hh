#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PERF_READER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PERF_READER_HH

#include <ostream>
#include <map>
#include <vector>

#include <rapl.hh>
#include <utils.hh>
#include <sys/ioctl.h>
#include <base_profiler.hh>
#include <query.hh>
namespace optkit::core
{
    struct RaplPerfReaderConfig
    {
        // Constructor
        RaplPerfReaderConfig(
            const std::map<int32_t, std::vector<int32_t>> &packages,
            const std::vector<RaplDomainInfo> &avail_domains,
            const RaplConfig &rapl_config,
            const bool dump_results_to_file = true) : packages(packages),
                                                      avail_domains(avail_domains),
                                                      rapl_config(rapl_config)
        {
            
        }

        const std::map<int32_t, std::vector<int32_t>> packages;
        const std::vector<RaplDomainInfo> avail_domains;
        const RaplConfig rapl_config; 
    };

    class RaplPerfReader
    {
    public:
        RaplPerfReader(const RaplPerfReaderConfig &rapl_perf_config);
        virtual ~RaplPerfReader();

        /**
         * @brief Returns sockect - domain - value relation
         *
         * @return std::map<int32_t, std::map<RaplDomain, int32_t>>
         */
        virtual std::map<int32_t, std::map<RaplDomain, double>> read_val();

    protected:
        RaplPerfReaderConfig rapl_perf_config;
        std::vector<std::vector<int32_t>> fd_package_domain;
    };

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplPerfReaderConfig &config);
std::ostream &operator<<(std::ostream &os, const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &map);

#endif