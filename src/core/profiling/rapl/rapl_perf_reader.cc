#include <rapl_perf_reader.hh>

namespace optkit::core
{

    RaplPerfReader::RaplPerfReader(const char *block_name, const char *event_name, const RaplPerfReaderConfig &rapl_perf_config) : BaseProfiler{block_name, event_name}, rapl_perf_config{rapl_perf_config}
    {
        // std::cout << rapl_perf_config << std::endl;
        static std::string s_type = read_file("/sys/bus/event_source/devices/power/type");
        static int32_t type = std::atoi(s_type.c_str());

        struct perf_event_attr attr;

        fd_package_domain.resize(rapl_perf_config.packages.size());

        for (size_t package = 0; package < rapl_perf_config.packages.size(); package++)
        {
            fd_package_domain[package].resize(rapl_perf_config.avail_domains.size());

            for (int domain = 0; domain < rapl_perf_config.avail_domains.size(); domain++)
            {
                auto selected_domain = rapl_perf_config.avail_domains[domain];
                fd_package_domain[package][domain] = -1;

                if (!((int32_t)selected_domain.domain & rapl_perf_config.rapl_config.monitor_domain))
                {
                    std::cout << selected_domain.domain << " is being skipped!\n";
                    continue;
                }

                ::memset(&attr, 0x0, sizeof(attr));
                attr.type = type;
                attr.config = selected_domain.config;

                if (attr.config == 0)
                    continue;

                fd_package_domain[package][domain] = ::syscall(__NR_perf_event_open, &attr, -1, package, -1, 0);

                if (fd_package_domain[package][domain] < 0)
                {
                    OPTKIT_CORE_ERROR("RAPL PERF: SOMETHING WENT WRONG!! {}", fd_package_domain[package][domain]);
                }
            }
        }
    }
    RaplPerfReader::~RaplPerfReader()
    {
        if (OPT_LIKELY(this->rapl_perf_config.dump_results_to_file))
        {
            std::cout << read();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;
            OPTKIT_CORE_INFO("Duration: {}", duration_ms);
            this->save();
        }
        else
        {
            std::cout << read_val();
            auto end = std::chrono::high_resolution_clock::now();
            auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;
            OPTKIT_CORE_INFO("Duration: {}", duration_ms);
        }
    }
    void RaplPerfReader::disable()
    {
        OPTKIT_CORE_WARN("Rapl cannot be disabled");
    }
    void RaplPerfReader::enable()
    {
        OPTKIT_CORE_WARN("Rapl is always enabled");
    }

    std::map<int32_t, std::map<RaplDomain, double>> RaplPerfReader::read_val()
    {
        std::map<int32_t, std::map<RaplDomain, double>> result;

        long long value;
        for (int package = 0; package < rapl_perf_config.packages.size(); package++)
        {
            for (int domain = 0; domain < rapl_perf_config.avail_domains.size(); domain++)
            {
                auto selected_domain = rapl_perf_config.avail_domains[domain];
                if (!((int32_t)selected_domain.domain & rapl_perf_config.rapl_config.monitor_domain))
                {
                    OPTKIT_CORE_DEBUG("%d is being skipped", selected_domain.domain);
                    continue;
                }
                if (fd_package_domain[package][domain] != -1)
                {
                    value = 0;
                    ::read(fd_package_domain[package][domain], &value, 8);

                    if (OPT_LIKELY(rapl_perf_config.rapl_config.is_reset_after_read))
                        ::ioctl(fd_package_domain[package][domain], PERF_EVENT_IOC_RESET, 0); // reset counter after read!

                    result[package][selected_domain.domain] = (double)value * selected_domain.scale;
                }
            }
        }

        return result;
    }

    std::string RaplPerfReader::convert_buffer_to_json()
    {
        std::stringstream ss;
        ss << "[\n";
        // based on the insertion order.
        for (const auto &val : this->read_buffer)
        {
            ss << core::to_json(val);
        }
        ss << "]\n";
        return ss.str();
    }

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &map)
{
    const std::vector<optkit::core::RaplDomainInfo> &avail_domains = optkit::core::Query::rapl_domain_info();
    for (const auto &pair : map)
    {
        os << "\tPackage " << pair.first << "\n";
        for (const auto &innerpair : pair.second)
        {
            for (const auto &info : avail_domains)
            {
                if (info.domain == innerpair.first)
                {
                    os << "\t\t" << info.event << ": " << innerpair.second << " " << info.units << " Consumed.\n";
                }
            }
        }
    }
    return os;
}
std::ostream &operator<<(std::ostream &os, const optkit::core::RaplPerfReaderConfig &config)
{
    os << "\nRaplPerfReaderConfig:\n";
    os << "---------------------:\n";
    os << "Packages(socket_ids - core_ids):\n";
    for (const auto &package : config.packages)
    {
        os << "  Package " << package.first << ": ";
        for (const auto &value : package.second)
        {
            os << value << " ";
        }
        os << "\n";
    }
    os << "Available Domains:\n";
    for (const auto &domain : config.avail_domains)
    {
        os << "  " << domain << "\n";
    }

    os << config.rapl_config << "\n";

    return os;
}
