#include <block_profiler.hh>

namespace optkit::core
{

    BlockProfiler::BlockProfiler(const char *block_name, std::initializer_list<uint64_t> raw_event_list, ProfilerConfig config) : BaseProfiler{config}
    {

        PMUEventManager::disable_all_events();

        this->block_name = block_name;
        int32_t fd = -1;
        for (auto &raw_event : raw_event_list)
        {
            struct perf_event_attr attr; 
            attr = config.perf_event_config;
            attr.config = raw_event;
            // attr.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;

            fd  = syscall(__NR_perf_event_open, &attr, config.pid, config.cpu, config.is_grouped ? fd : -1, 0); // <-- first becomes -1 and later we use the group_leader's fd.
            if (fd == -1)
            {
                OPTKIT_CORE_ERROR("perf_event_open error");
                return;
            }
            else
            {
                PMUEventManager::register_event(fd, 1);
                fd_list.push_back(fd);
            }
            ioctl(fd, PERF_EVENT_IOC_RESET, 0);
        }
        // enable clock now!
        start = std::chrono::high_resolution_clock::now();

        PMUEventManager::enable_all_events();
    }
    BlockProfiler ::~BlockProfiler()
    {

        PMUEventManager::disable_all_events();

        // disable clock now!
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;

        uint64_t count;
        for (int32_t fd : fd_list)
        {
            ::read(fd, &count, sizeof(count));     // read last value
            PMUEventManager::unregister_event(fd); // unregister this event
            std::cout << "\033[1;35m"
                      << "Block: " << this->block_name << "\033[0m"
                      << " [" << duration_ms << "ms] "
                      << "Measured: " << count << std::endl;
        }

        PMUEventManager::enable_all_events();
    }

    void BlockProfiler::disable()
    {
        for (int32_t fd : fd_list)
        {
            ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
        }
    }
    void BlockProfiler::enable()
    {
        for (int32_t fd : fd_list)
        {
            ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
        }
    }

    std::vector<uint64_t> BlockProfiler::read()
    {

        PMUEventManager::disable_all_events();

        std::vector<uint64_t> result;
        uint64_t count;
        for (int32_t fd : fd_list)
        {
            ::read(fd, &count, sizeof(count));
            result.push_back(count);
        }

        PMUEventManager::enable_all_events();

        return result;
    }
} // namespace optkit::core