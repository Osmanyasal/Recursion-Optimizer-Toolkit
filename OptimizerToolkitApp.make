# GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild prelink

ifeq ($(config),debug)
  RESCOMP = windres
  TARGETDIR = bin/Debug
  TARGET = $(TARGETDIR)/OptimizerToolkitApp
  OBJDIR = bin/obj/Debug/OptimizerToolkitApp
  DEFINES += -DOPTKIT_MODE_DEBUG
  INCLUDES += -Isrc
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -g -Wall -O0 -g -fopenmp -msse -march=native -mavx2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -g -std=c++11 -Wall -O0 -g -fopenmp -msse -march=native -mavx2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += -lpthread -ldl -ltensorflow -lspdlog
  LDDEPS +=
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64 -fopenmp -lpfm
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
  define PREBUILDCMDS
	@echo Running prebuild commands
	@echo [CHECK MSR-SAFE]
	if [ ! -f ./lib/msr-safe/all_set ]; then \
	    cd ./lib/msr-safe && make clean && make && make install && (sudo rmmod msr-safe || true) && \
	    (sudo insmod ./msr-safe.ko || true) && sudo chmod g+rw /dev/cpu/*/msr_safe /dev/cpu/msr_* && \
	    sudo chgrp rt7 /dev/cpu/*/msr_safe /dev/cpu/msr_batch /dev/cpu/msr_safe_version && \
	    sudo chgrp rt7 /dev/cpu/msr_allowlist && \
	    echo "0x00000620 0xFFFFFFFFFFFFFFFF" > /dev/cpu/msr_allowlist && \
	    touch all_set; \
	fi
	@echo [CHECK SPDLOG]
	if [ ! -f ./lib/spdlog/build/libspdlog.a ]; then \
	    cd ./lib/spdlog && ./install.sh; \
	fi
	@echo [CHECK LIBPFM]
	if [ ! -f ./lib/libpfm4/all_set ]; then \
	    cd ./lib/libpfm4 && ./install.sh; \
	fi
	@echo [CHECK EVENTS]
	if [ ! -f ./src/core/events/all_set ]; then \
	    echo "⛏️ Exporting events from libpfm4" && \
	    mkdir -p ./src/core/events && \
	    cd ./src/utils && \
	    python3 pmu_parser.py $(shell find ./lib/libpfm4/lib/events -type f \( -name "intel*.h" -or -name "amd*.h" -or -name "arm*.h" -or -name "power*.h" \) -exec echo "../../{}" \;) && \
	    touch ../.././src/core/events/all_set; \
	fi
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: prebuild prelink $(TARGET)
	@:

endif

ifeq ($(config),release)
  RESCOMP = windres
  TARGETDIR = bin/Release
  TARGET = $(TARGETDIR)/OptimizerToolkitApp
  OBJDIR = bin/obj/Release/OptimizerToolkitApp
  DEFINES += -DOPTKIT_MODE_NDEBUG
  INCLUDES += -Isrc
  FORCE_INCLUDE +=
  ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -Wall -O2 -fopenmp -msse -march=native -mavx2
  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -O2 -std=c++11 -Wall -O2 -fopenmp -msse -march=native -mavx2
  ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
  LIBS += -lpthread -ldl -ltensorflow -lspdlog
  LDDEPS +=
  ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -m64 -s -fopenmp -lpfm
  LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
  define PREBUILDCMDS
	@echo Running prebuild commands
	@echo [CHECK MSR-SAFE]
	if [ ! -f ./lib/msr-safe/all_set ]; then \
	    cd ./lib/msr-safe && make clean && make && make install && (sudo rmmod msr-safe || true) && \
	    (sudo insmod ./msr-safe.ko || true) && sudo chmod g+rw /dev/cpu/*/msr_safe /dev/cpu/msr_* && \
	    sudo chgrp rt7 /dev/cpu/*/msr_safe /dev/cpu/msr_batch /dev/cpu/msr_safe_version && \
	    sudo chgrp rt7 /dev/cpu/msr_allowlist && \
	    echo "0x00000620 0xFFFFFFFFFFFFFFFF" > /dev/cpu/msr_allowlist && \
	    touch all_set; \
	fi
	@echo [CHECK SPDLOG]
	if [ ! -f ./lib/spdlog/build/libspdlog.a ]; then \
	    cd ./lib/spdlog && ./install.sh; \
	fi
	@echo [CHECK LIBPFM]
	if [ ! -f ./lib/libpfm4/all_set ]; then \
	    cd ./lib/libpfm4 && ./install.sh; \
	fi
	@echo [CHECK EVENTS]
	if [ ! -f ./src/core/events/all_set ]; then \
	    echo "⛏️ Exporting events from libpfm4" && \
	    mkdir -p ./src/core/events && \
	    cd ./src/utils && \
	    python3 pmu_parser.py $(shell find ./lib/libpfm4/lib/events -type f \( -name "intel*.h" -or -name "amd*.h" -or -name "arm*.h" -or -name "power*.h" \) -exec echo "../../{}" \;) && \
	    touch ../.././src/core/events/all_set; \
	fi
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
all: prebuild prelink $(TARGET)
	@:

endif

OBJECTS := \
	$(OBJDIR)/zen3_recepies.o \
	$(OBJDIR)/bdw_recepies.o \
	$(OBJDIR)/icl_governor.o \
	$(OBJDIR)/icl_recepies.o \
	$(OBJDIR)/skl_governor.o \
	$(OBJDIR)/skl_recepies.o \
	$(OBJDIR)/base_governor.o \
	$(OBJDIR)/cpu_frequency.o \
	$(OBJDIR)/query_frequency.o \
	$(OBJDIR)/block_group_profiler.o \
	$(OBJDIR)/block_profiler.o \
	$(OBJDIR)/libpfm4_wrapper.o \
	$(OBJDIR)/pmu_event_manager.o \
	$(OBJDIR)/pmu_utils.o \
	$(OBJDIR)/query_pmu.o \
	$(OBJDIR)/profiler_config.o \
	$(OBJDIR)/query_rapl.o \
	$(OBJDIR)/rapl.o \
	$(OBJDIR)/rapl_perf_reader.o \
	$(OBJDIR)/rapl_profiler.o \
	$(OBJDIR)/rapl_utils.o \
	$(OBJDIR)/query.o \
	$(OBJDIR)/main.o \
	$(OBJDIR)/optkit.o \
	$(OBJDIR)/logger.o \
	$(OBJDIR)/block_timer.o \
	$(OBJDIR)/utils.o \

RESOURCES := \

CUSTOMFILES := \

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

$(TARGET): $(GCH) ${CUSTOMFILES} $(OBJECTS) $(LDDEPS) $(RESOURCES) | $(TARGETDIR)
	@echo Linking OptimizerToolkitApp
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(CUSTOMFILES): | $(OBJDIR)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning OptimizerToolkitApp
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) $(PCH) | $(OBJDIR)
$(GCH): $(PCH) | $(OBJDIR)
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
else
$(OBJECTS): | $(OBJDIR)
endif

$(OBJDIR)/zen3_recepies.o: src/core/event_recepies/amd/zen3/zen3_recepies.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/bdw_recepies.o: src/core/event_recepies/intel/bdw/bdw_recepies.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/icl_governor.o: src/core/event_recepies/intel/icl/icl_governor.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/icl_recepies.o: src/core/event_recepies/intel/icl/icl_recepies.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/skl_governor.o: src/core/event_recepies/intel/skl/skl_governor.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/skl_recepies.o: src/core/event_recepies/intel/skl/skl_recepies.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/base_governor.o: src/core/freq/base_governor.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/cpu_frequency.o: src/core/freq/cpu_frequency.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/query_frequency.o: src/core/freq/query_frequency.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/block_group_profiler.o: src/core/profiling/pmu/block_group_profiler.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/block_profiler.o: src/core/profiling/pmu/block_profiler.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/libpfm4_wrapper.o: src/core/profiling/pmu/libpfm4_wrapper.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/pmu_event_manager.o: src/core/profiling/pmu/pmu_event_manager.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/pmu_utils.o: src/core/profiling/pmu/pmu_utils.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/query_pmu.o: src/core/profiling/pmu/query_pmu.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/profiler_config.o: src/core/profiling/profiler_config.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/query_rapl.o: src/core/profiling/rapl/query_rapl.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/rapl.o: src/core/profiling/rapl/rapl.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/rapl_perf_reader.o: src/core/profiling/rapl/rapl_perf_reader.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/rapl_profiler.o: src/core/profiling/rapl/rapl_profiler.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/rapl_utils.o: src/core/profiling/rapl/rapl_utils.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/query.o: src/core/query.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/main.o: src/main.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/optkit.o: src/optkit.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/logger.o: src/utils/logging/logger.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/block_timer.o: src/utils/profiling/block_timer.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/utils.o: src/utils/utils.cc
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(OBJDIR)/$(notdir $(PCH)).d
endif