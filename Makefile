CXX = clang++ -std=c++20
XPLANE_PATH = $(HOME)/XPlane11
XPLANE12_PATH = $(HOME)/X-Plane\ 12
PLUGINS = $(XPLANE_PATH)/Resources/plugins/aeroform/64
PLUGINS12 = $(XPLANE12_PATH)/Resources/plugins/aeroform/64
TARGET = mac.xpl
SOURCES = $(wildcard aeroform-plugin/src/*.cpp) $(wildcard /opt/xplane/SDK/CHeaders/Wrappers/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

SDK_ROOT = /opt/xplane/SDK

ARCHS = -arch arm64
OSXC = $(ARCHS) -mmacosx-version-min=11.0

DEFS = -DAPL=1 -DIBM=0 -DLIN=0 -DXPLM200=1 -DXPLM210=1 -DXPLM300=1 -DXPLM301=1 -DXPLM302=1 -DXPLM303=1 -DXPLM400=1 -DXPLM410=1 -DWIDGET_API=1

CXXFLAGS = -Wall -fPIC -fvisibility=hidden -fno-rtti -lc++fs \
           -O3 -mtune=generic \
					 -I$(CURDIR)/aeroform-plugin/include/XPLSDK \
           -I$(SDK_ROOT)/CHeaders/XPLM -I$(SDK_ROOT)/CHeaders/Widgets \
					 -I$(SDK_ROOT)/CHeaders/Wrappers \
           -I$(CURDIR)/aeroform-plugin/include \
           $(DEFS) $(OSXC)

LDFLAGS = -dynamiclib -shared \
					-L$(CURDIR)/aeroform-plugin/lib -lhostfxr -lnethost \
          -F$(SDK_ROOT)/Libraries/Mac -framework XPLM -framework XPWidgets \
					-Wl,-rpath,@loader_path \
					-Wl,-rpath,@executable_path/../../../Resources/plugins/aeroform \
					-Wl,-rpath,@executable_path/../../../Resources/plugins/aeroform/64/dotnet \
					-Wl,-rpath,@executable_path/../../../Resources/plugins/aeroform/64/dotnet/host/fxr/8.0.8 \
					-Wl,-rpath,@executable_path/../../../Resources/plugins/aeroform/64/dotnet/shared/Microsoft.NETCore.App/8.0.8 \
					-Wl,-rpath,@executable_path/../../../Resources/plugins \
          -Wl,-rpath,@executable_path/../Frameworks \
          -Wl,-map,$(TARGET).map \
          $(OSXC)

# Добавляем XPLM_all_wrap.cxx в список объектных файлов
WRAP_OBJ = aeroform-plugin/src/XPLM_all_wrap.o
OBJECTS += $(WRAP_OBJ)

all: $(TARGET) install clean_after

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Специальное правило для компиляции XPLM_all_wrap.cxx
$(WRAP_OBJ): aeroform-plugin/src/XPLM_all_wrap.cxx
	$(CXX) $(CXXFLAGS) -fvisibility=default -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(LDFLAGS) $^
	chmod a+x $@

clean_after:
	rm -f $(OBJECTS) $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -f $(PLUGINS)/$(TARGET)
	rm -f $(PLUGINS12)/$(TARGET)

install: $(TARGET)
	mkdir -p $(PLUGINS12)
	cp -f $(TARGET) $(PLUGINS12)
	cp -f aeroform.json $(PLUGINS12)
	dotnet publish -c Release

.PHONY: all clean install