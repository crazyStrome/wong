# Alternative GNU Make project makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
INCLUDES += -I../Wong/include -I../Wong/vendor/spdlog/include -I../Wong/vendor/glm -I../Wong/vendor/ImGui
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -m64 -g
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -m64 -g
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
ALL_LDFLAGS += $(LDFLAGS) -L/usr/lib64 -Wl,-rpath,'$$ORIGIN/../Wong' -m64
LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef
define POSTBUILDCMDS
endef

ifeq ($(config),debug)
TARGETDIR = ../bin/Debug-linux-x86_64/Sandbox
TARGET = $(TARGETDIR)/Sandbox
OBJDIR = ../bin-int/Debug-linux-x86_64/Sandbox
DEFINES += -DWG_ENABLE_ASSERTS -DWG_DEBUG -DWG_PLATFORM_LINUX
LIBS += ../bin/Debug-linux-x86_64/Wong/libWong.so
LDDEPS += ../bin/Debug-linux-x86_64/Wong/libWong.so

else ifeq ($(config),release)
TARGETDIR = ../bin/Release-linux-x86_64/Sandbox
TARGET = $(TARGETDIR)/Sandbox
OBJDIR = ../bin-int/Release-linux-x86_64/Sandbox
DEFINES += -DWG_RELEASE -DWG_PLATFORM_LINUX
LIBS += ../bin/Release-linux-x86_64/Wong/libWong.so
LDDEPS += ../bin/Release-linux-x86_64/Wong/libWong.so

else ifeq ($(config),dist)
TARGETDIR = ../bin/Dist-linux-x86_64/Sandbox
TARGET = $(TARGETDIR)/Sandbox
OBJDIR = ../bin-int/Dist-linux-x86_64/Sandbox
DEFINES += -DWG_DIST -DWG_PLATFORM_LINUX
LIBS += ../bin/Dist-linux-x86_64/Wong/libWong.so
LDDEPS += ../bin/Dist-linux-x86_64/Wong/libWong.so

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/Sandbox.o
OBJECTS += $(OBJDIR)/Sandbox.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking Sandbox
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

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
	@echo Cleaning Sandbox
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/Sandbox.o: src/Sandbox.cc
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif