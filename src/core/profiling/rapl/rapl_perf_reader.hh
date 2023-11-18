#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PERF_READER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PERF_READER_HH

#include <ostream>
#include <map>
#include <rapl.hh>
#include <utils.hh> 
#include <vector>
#include <sys/ioctl.h>
#include <base_profiler.hh>
namespace optkit::core
{
    struct RaplPerfReaderConfig
    {
        const std::map<int32_t, std::vector<int32_t>> &packages;
        const std::vector<RaplDomainInfo> &avail_domains;
        const RaplConfig& rapl_config;
    };

    class RaplPerfReader : public BaseProfiler<std::unordered_map<int32_t, std::unordered_map<RaplDomain, double>>>
    {
    public:
        RaplPerfReader(const RaplPerfReaderConfig& rapl_perf_config);
        virtual ~RaplPerfReader();

        /**
         * @brief Rapl's is always enabled
         * 
         */
        virtual void disable() override;

        /**
         * @brief Rapl's always enabled.
         * 
         */
        virtual void enable() override;

        /**
         * @brief Returns sockect - domain - value relation
         * 
         * @return std::unordered_map<int32_t, std::unordered_map<RaplDomain, int32_t>> 
         */
        virtual std::unordered_map<int32_t, std::unordered_map<RaplDomain, double>> read() override;

    private:
        RaplPerfReaderConfig rapl_perf_config;
        std::vector<std::vector<int32_t>> fd_package_domain;
    };

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplPerfReaderConfig &config);
 
#endif