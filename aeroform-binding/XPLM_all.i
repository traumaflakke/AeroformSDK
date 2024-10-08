%module XPlaneWrappers

%{
#include <stdexcept>
%}

%include <exception.i>

%exception {
    try {
        $action
    } catch (const std::exception& e) {
        SWIG_exception(SWIG_RuntimeError, e.what());
    } catch (...) {
        SWIG_exception(SWIG_UnknownError, "Unknown exception occurred");
    }
}

%{
#include "XPLM/XPLMDefs.h"
#include "XPLM/XPLMPlugin.h"
#include "XPLM/XPLMPlanes.h"
#include "XPLM/XPLMSound.h"
#include "XPLM/XPLMDataAccess.h"
#include "XPLM/XPLMNavigation.h"
#include "XPLM/XPLMGraphics.h"
#include "XPLM/XPLMInstance.h"
#include "XPLM/XPLMDisplay.h"
#include "XPLM/XPLMProcessing.h"
#include "XPLM/XPLMUtilities.h"
#include "XPLM/XPLMMenus.h"
#include "XPLM/XPLMWeather.h"
#include "XPLM/XPLMCamera.h"
#include "XPLM/XPLMMap.h"
#include "XPLM/XPLMScenery.h"
#include "Widgets/XPWidgetDefs.h"
#include "Widgets/XPStandardWidgets.h"
#include "Widgets/XPWidgetUtils.h"
#include "Widgets/XPWidgets.h"
#include "Widgets/XPUIGraphics.h"
#include "Wrappers/XPCWidgetAttachments.h"
#include "Wrappers/XPCListener.h"
#include "Wrappers/XPCWidget.h"
#include "Wrappers/XPCProcessing.h"
#include "Wrappers/XPCBroadcaster.h"
#include "Wrappers/XPCDisplay.h"
%}

%include "aeroform_common.h"
%include "XPLM/XPLMDefs.h"
%include "XPLM/XPLMPlugin.h"
%include "XPLM/XPLMPlanes.h"
%include "XPLM/XPLMSound.h"
%include "XPLM/XPLMDataAccess.h"
%include "XPLM/XPLMNavigation.h"
%include "XPLM/XPLMGraphics.h"
%include "XPLM/XPLMInstance.h"
%include "XPLM/XPLMDisplay.h"
%include "XPLM/XPLMProcessing.h"
%include "XPLM/XPLMUtilities.h"
%include "XPLM/XPLMMenus.h"
%include "XPLM/XPLMWeather.h"
%include "XPLM/XPLMCamera.h"
%include "XPLM/XPLMMap.h"
%include "XPLM/XPLMScenery.h"
%include "Widgets/XPWidgetDefs.h"
%include "Widgets/XPStandardWidgets.h"
%include "Widgets/XPWidgetUtils.h"
%include "Widgets/XPWidgets.h"
%include "Widgets/XPUIGraphics.h"
%include "Wrappers/XPCWidgetAttachments.h"
%include "Wrappers/XPCListener.h"
%include "Wrappers/XPCWidget.h"
%include "Wrappers/XPCProcessing.h"
%include "Wrappers/XPCBroadcaster.h"
%include "Wrappers/XPCDisplay.h"