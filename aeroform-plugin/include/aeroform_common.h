#ifndef AEROFORM_COMMON_H
#define AEROFORM_COMMON_H

#define __APPLE__ 1

// X-Plane SDK версии
#define XPLM200 1
#define XPLM210 1
#define XPLM300 1
#define XPLM301 1
#define XPLM302 1
#define XPLM303 1
#define XPLM400 1
#define XPLM410 1

#define WIDGET_API

#define AEROFORM_PLUGIN_NAME    "Aeroform Bridge"
#define AEROFORM_PLUGIN_SIG     "aeroform.plugin.bridge"
#define AEROFORM_PLUGIN_DESC    "Aeroform Bridge for X-Plane"

#define AEROFORM_VERSION        "0.0.1"
#define AEROFORM_AUTHOR         "@traumaflakke"

#define AEROFORM_BRIDGE_LIB_FILENAME "Aeroform.Core.dll"
#define AEROFORM_LOADER_CONFIG_FILENAME "Aeroform.Core.runtimeconfig.json"

#if defined(_WIN32) || defined(_WIN64)
    #define APL 0
    #define IBM 1
    #define LIN 0
    #include <windows.h>
    #define AEROFORM_LOAD_LIBRARY(name)  LoadLibraryA(name)
    #define AEROFORM_GET_PROC_ADDRESS    GetProcAddress
    #define AEROFORM_FREE_LIBRARY        FreeLibrary
    #define AEROFORM_PLUGIN_FILENAME     "win.xpl"
#elif defined(__APPLE__) || defined(__MACH__)
    #define APL 1
    #define IBM 0
    #define LIN 0
    #include <dlfcn.h>
    #define AEROFORM_LOAD_LIBRARY(name)  dlopen(name, RTLD_LAZY)
    #define AEROFORM_LIBRARY_ERROR       dlerror()
    #define AEROFORM_GET_PROC_ADDRESS    dlsym
    #define AEROFORM_FREE_LIBRARY        dlclose
    #define AEROFORM_PLUGIN_FILENAME     "mac.xpl"
#elif defined(__linux__) || defined(__unix__)
    #define APL 0
    #define IBM 0
    #define LIN 1
    #include <dlfcn.h>
    #define AEROFORM_LOAD_LIBRARY(name)  dlopen(name, RTLD_LAZY)
    #define AEROFORM_LIBRARY_ERROR       dlerror()
    #define AEROFORM_GET_PROC_ADDRESS    dlsym
    #define AEROFORM_FREE_LIBRARY        dlclose
    #define AEROFORM_PLUGIN_FILENAME     "lin.xpl"
#else
    #error "Unsupported platform"
#endif

#endif // AEROFORM_COMMON_H