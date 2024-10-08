#include "aeroform_common.h"

#include "PluginManager.h"
#include "XPLMPlugin.h"

// Удалите глобальную переменную g_pluginManager

PLUGIN_API int XPluginStart(char* outName, char* outSig, char* outDesc) {
    return PluginManager::getInstance().start(outName, outSig, outDesc);
}

PLUGIN_API void XPluginStop(void) {
    PluginManager::getInstance().stop();
}

PLUGIN_API void XPluginDisable(void) {
    PluginManager::getInstance().disable();
}

PLUGIN_API int XPluginEnable(void) {
    PluginManager::getInstance().enable();
    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void* inParam) {
    PluginManager::getInstance().receiveMessage(inMsg, inParam);
}