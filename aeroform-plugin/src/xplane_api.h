// Generated by generate_xplane_api.py
#ifndef XPLANE_API_H
#define XPLANE_API_H

#include "aeroform_common.h"

#include <XPLMDataAccess.h>
#include <XPLMUtilities.h>
#include <XPLMPlanes.h>
#include <XPLMGraphics.h>
#include <XPLMCamera.h>
#include <XPLMDataAccess.h>
#include <XPLMDisplay.h>
#include <XPLMGraphics.h>
#include <XPLMInstance.h>
#include <XPLMMap.h>
#include <XPLMMenus.h>
#include <XPLMNavigation.h>
#include <XPLMPlanes.h>
#include <XPLMPlugin.h>
#include <XPLMProcessing.h>
#include <XPLMScenery.h>
#include <XPLMSound.h>
#include <XPLMUtilities.h>
#include <XPLMWeather.h>
#include <XPWidgetDefs.h>
#include <XPUIGraphics.h>
#include <XPWidgetUtils.h>
#include <XPWidgets.h>

typedef XPLMDataRef (*XPLMFindDataRefFunc)(const char *);
typedef void (*XPLMSetUsersAircraftFunc)(const char *);
typedef void (*XPLMPlaceUserAtAirportFunc)(const char *);
typedef void (*XPLMCountAircraftFunc)(int *, int *, XPLMPluginID *);
typedef void (*XPLMGetNthAircraftModelFunc)(int, char *, char *);
typedef int (*XPLMAcquirePlanesFunc)(char **, XPLMPlanesAvailable_f, void *);
typedef void (*XPLMReleasePlanesFunc)();
typedef void (*XPLMSetActiveAircraftCountFunc)(int);
typedef void (*XPLMSetAircraftModelFunc)(int, const char *);
typedef void (*XPLMDisableAIForPlaneFunc)(int);
typedef int (*XPLMCanWriteDataRefFunc)(XPLMDataRef);
typedef int (*XPLMIsDataRefGoodFunc)(XPLMDataRef);
typedef int (*XPLMGetDataiFunc)(XPLMDataRef);
typedef void (*XPLMSetDataiFunc)(XPLMDataRef, int);
typedef float (*XPLMGetDatafFunc)(XPLMDataRef);
typedef void (*XPLMSetDatafFunc)(XPLMDataRef, float);
typedef double (*XPLMGetDatadFunc)(XPLMDataRef);
typedef void (*XPLMSetDatadFunc)(XPLMDataRef, double);
typedef int (*XPLMGetDataviFunc)(XPLMDataRef, int *, int, int);
typedef void (*XPLMSetDataviFunc)(XPLMDataRef, int *, int, int);
typedef int (*XPLMGetDatavfFunc)(XPLMDataRef, float *, int, int);
typedef void (*XPLMSetDatavfFunc)(XPLMDataRef, float *, int, int);
typedef int (*XPLMGetDatabFunc)(XPLMDataRef, void *, int, int);
typedef void (*XPLMSetDatabFunc)(XPLMDataRef, void *, int, int);
typedef void (*XPLMUnregisterDataAccessorFunc)(XPLMDataRef);
typedef int (*XPLMShareDataFunc)(const char *, XPLMDataTypeID, XPLMDataChanged_f, void *);
typedef int (*XPLMUnshareDataFunc)(const char *, XPLMDataTypeID, XPLMDataChanged_f, void *);
typedef void (*XPLMGetNavAidInfoFunc)(XPLMNavRef, XPLMNavType *, float *, float *, float *, int *, float *, char *, char *, char *);
typedef int (*XPLMCountFMSEntriesFunc)();
typedef int (*XPLMGetDisplayedFMSEntryFunc)();
typedef int (*XPLMGetDestinationFMSEntryFunc)();
typedef void (*XPLMSetDisplayedFMSEntryFunc)(int);
typedef void (*XPLMSetDestinationFMSEntryFunc)(int);
typedef void (*XPLMGetFMSEntryInfoFunc)(int, XPLMNavType *, char *, XPLMNavRef *, int *, float *, float *);
typedef void (*XPLMSetFMSEntryInfoFunc)(int, XPLMNavRef, int);
typedef void (*XPLMSetFMSEntryLatLonFunc)(int, float, float, int);
typedef void (*XPLMClearFMSEntryFunc)(int);
typedef void (*XPLMSetGraphicsStateFunc)(int, int, int, int, int, int, int);
typedef void (*XPLMBindTexture2dFunc)(int, int);
typedef void (*XPLMGenerateTextureNumbersFunc)(int *, int);
typedef void (*XPLMWorldToLocalFunc)(double, double, double, double *, double *, double *);
typedef void (*XPLMLocalToWorldFunc)(double, double, double, double *, double *, double *);
typedef void (*XPLMDrawTranslucentDarkBoxFunc)(int, int, int, int);
typedef void (*XPLMDrawStringFunc)(float *, int, int, const char *, int *, XPLMFontID);
typedef void (*XPLMDrawNumberFunc)(float *, int, int, double, int, int, int, XPLMFontID);
typedef void (*XPLMGetFontDimensionsFunc)(XPLMFontID, int *, int *, int *);
typedef void (*XPLMDestroyInstanceFunc)(XPLMInstanceRef);
typedef void (*XPLMInstanceSetPositionFunc)(XPLMInstanceRef, const XPLMDrawInfo_t *, const float *);
typedef int (*XPLMCountPluginsFunc)();
typedef void (*XPLMGetPluginInfoFunc)(XPLMPluginID, char *, char *, char *, char *);
typedef int (*XPLMIsPluginEnabledFunc)(XPLMPluginID);
typedef int (*XPLMEnablePluginFunc)(XPLMPluginID);
typedef void (*XPLMDisablePluginFunc)(XPLMPluginID inPluginID);
typedef void (*XPLMReloadPluginsFunc)();
typedef void (*XPLMSendMessageToPluginFunc)(XPLMPluginID, int, void *);
typedef int (*XPLMRegisterDrawCallbackFunc)(XPLMDrawCallback_f, XPLMDrawingPhase, int, void *);
typedef int (*XPLMUnregisterDrawCallbackFunc)(XPLMDrawCallback_f, XPLMDrawingPhase, int, void *);
typedef void (*XPLMDestroyWindowFunc)(XPLMWindowID);
typedef void (*XPLMGetScreenSizeFunc)(int *, int *);
typedef void (*XPLMGetMouseLocationFunc)(int *, int *);
typedef void (*XPLMGetWindowGeometryFunc)(XPLMWindowID, int *, int *, int *, int *);
typedef void (*XPLMSetWindowGeometryFunc)(XPLMWindowID, int, int, int, int);
typedef int (*XPLMGetWindowIsVisibleFunc)(XPLMWindowID);
typedef void (*XPLMSetWindowIsVisibleFunc)(XPLMWindowID, int);
typedef void *(*XPLMGetWindowRefConFunc)(XPLMWindowID);
typedef void (*XPLMSetWindowRefConFunc)(XPLMWindowID, void *);
typedef void (*XPLMTakeKeyboardFocusFunc)(XPLMWindowID);
typedef int (*XPLMHasKeyboardFocusFunc)(XPLMWindowID);
typedef void (*XPLMBringWindowToFrontFunc)(XPLMWindowID);
typedef int (*XPLMIsWindowInFrontFunc)(XPLMWindowID);
typedef int (*XPLMRegisterKeySnifferFunc)(XPLMKeySniffer_f, int, void *);
typedef int (*XPLMUnregisterKeySnifferFunc)(XPLMKeySniffer_f, int, void *);
typedef void (*XPLMUnregisterHotKeyFunc)(XPLMHotKeyID);
typedef int (*XPLMCountHotKeysFunc)();
typedef void (*XPLMGetHotKeyInfoFunc)(XPLMHotKeyID, char *, XPLMKeyFlags *, char *, XPLMPluginID *);
typedef void (*XPLMSetHotKeyCombinationFunc)(XPLMHotKeyID, char, XPLMKeyFlags);
typedef float (*XPLMGetElapsedTimeFunc)();
typedef int (*XPLMGetCycleNumberFunc)();
typedef void (*XPLMRegisterFlightLoopCallbackFunc)(XPLMFlightLoop_f, float, void *);
typedef void (*XPLMUnregisterFlightLoopCallbackFunc)(XPLMFlightLoop_f, void *);
typedef void (*XPLMSetFlightLoopCallbackIntervalFunc)(XPLMFlightLoop_f, float, int, void *);
typedef void (*XPLMGetSystemPathFunc)(char *);
typedef void (*XPLMGetPrefsPathFunc)(char *);
typedef const char *(*XPLMGetDirectorySeparatorFunc)();
typedef char *(*XPLMExtractFileAndPathFunc)(char *);
typedef int (*XPLMGetDirectoryContentsFunc)(const char *, int, char *, int, char **, int, int *, int *);
typedef void (*XPLMGetVersionsFunc)(int *, int *, XPLMHostApplicationID *);
typedef void (*XPLMDebugStringFunc)(const char *);
typedef void (*XPLMSpeakStringFunc)(const char *);
typedef const char *(*XPLMGetVirtualKeyDescriptionFunc)(char);
typedef void (*XPLMReloadSceneryFunc)();
typedef void (*XPLMDestroyMenuFunc)(XPLMMenuID);
typedef void (*XPLMClearAllMenuItemsFunc)(XPLMMenuID);
typedef int (*XPLMAppendMenuItemFunc)(XPLMMenuID, const char *, void *, int);
typedef void (*XPLMAppendMenuSeparatorFunc)(XPLMMenuID);
typedef void (*XPLMSetMenuItemNameFunc)(XPLMMenuID, int, const char *, int);
typedef void (*XPLMCheckMenuItemFunc)(XPLMMenuID, int, XPLMMenuCheck);
typedef void (*XPLMCheckMenuItemStateFunc)(XPLMMenuID, int, XPLMMenuCheck *);
typedef void (*XPLMEnableMenuItemFunc)(XPLMMenuID, int, int);
typedef void (*XPLMControlCameraFunc)(XPLMCameraControlDuration, XPLMCameraControl_f, void *);
typedef void (*XPLMDontControlCameraFunc)();
typedef int (*XPLMIsCameraBeingControlledFunc)(XPLMCameraControlDuration *);
typedef void (*XPLMReadCameraPositionFunc)(XPLMCameraPosition_t *);
typedef void (*XPUCreateWidgetsFunc)(const XPWidgetCreate_t *, int, XPWidgetID, XPWidgetID *);
typedef void (*XPUMoveWidgetByFunc)(XPWidgetID, int, int);
typedef int (*XPUFixedLayoutFunc)(XPWidgetMessage, XPWidgetID, intptr_t, intptr_t);
typedef int (*XPUSelectIfNeededFunc)(XPWidgetMessage, XPWidgetID, intptr_t, intptr_t, int);
typedef int (*XPUDefocusKeyboardFunc)(XPWidgetMessage, XPWidgetID, intptr_t, intptr_t, int);
typedef int (*XPUDragWidgetFunc)(XPWidgetMessage, XPWidgetID, intptr_t, intptr_t, int, int, int, int);
typedef void (*XPDestroyWidgetFunc)(XPWidgetID, int);
typedef int (*XPSendMessageToWidgetFunc)(XPWidgetID, XPWidgetMessage, XPDispatchMode, intptr_t, intptr_t);
typedef void (*XPPlaceWidgetWithinFunc)(XPWidgetID, XPWidgetID);
typedef int (*XPCountChildWidgetsFunc)(XPWidgetID);
typedef void (*XPShowWidgetFunc)(XPWidgetID);
typedef void (*XPHideWidgetFunc)(XPWidgetID);
typedef int (*XPIsWidgetVisibleFunc)(XPWidgetID);
typedef void (*XPBringRootWidgetToFrontFunc)(XPWidgetID);
typedef int (*XPIsWidgetInFrontFunc)(XPWidgetID);
typedef void (*XPGetWidgetGeometryFunc)(XPWidgetID, int *, int *, int *, int *);
typedef void (*XPSetWidgetGeometryFunc)(XPWidgetID, int, int, int, int);
typedef void (*XPGetWidgetExposedGeometryFunc)(XPWidgetID, int *, int *, int *, int *);
typedef void (*XPSetWidgetDescriptorFunc)(XPWidgetID, const char *);
typedef int (*XPGetWidgetDescriptorFunc)(XPWidgetID, char *, int);
typedef void (*XPSetWidgetPropertyFunc)(XPWidgetID, XPWidgetPropertyID, intptr_t);
typedef void (*XPLoseKeyboardFocusFunc)(XPWidgetID);
typedef void (*XPAddWidgetCallbackFunc)(XPWidgetID, XPWidgetFunc_t);
typedef void (*XPDrawWindowFunc)(int, int, int, int, XPWindowStyle);
typedef void (*XPGetWindowDefaultDimensionsFunc)(XPWindowStyle, int *, int *);
typedef void (*XPDrawElementFunc)(int, int, int, int, XPElementStyle, int);
typedef void (*XPGetElementDefaultDimensionsFunc)(XPElementStyle, int *, int *, int *);
typedef void (*XPDrawTrackFunc)(int, int, int, int, int, int, int, XPTrackStyle, int);
typedef void (*XPGetTrackDefaultDimensionsFunc)(XPTrackStyle, int *, int *);
typedef void (*XPGetTrackMetricsFunc)(int, int, int, int, int, int, int, XPTrackStyle, int *, int *, int *, int *, int *, int *);
typedef int (*XPLMGetMyIDFunc)();

struct XPlaneAPI {
    XPLMFindDataRefFunc XPLMFindDataRef;
    XPLMGetMyIDFunc XPLMGetMyID;
    XPLMSetUsersAircraftFunc XPLMSetUsersAircraft;
    XPLMPlaceUserAtAirportFunc XPLMPlaceUserAtAirport;
    XPLMCountAircraftFunc XPLMCountAircraft;
    XPLMGetNthAircraftModelFunc XPLMGetNthAircraftModel;
    XPLMAcquirePlanesFunc XPLMAcquirePlanes;
    XPLMReleasePlanesFunc XPLMReleasePlanes;
    XPLMSetActiveAircraftCountFunc XPLMSetActiveAircraftCount;
    XPLMSetAircraftModelFunc XPLMSetAircraftModel;
    XPLMDisableAIForPlaneFunc XPLMDisableAIForPlane;
    XPLMCanWriteDataRefFunc XPLMCanWriteDataRef;
    XPLMIsDataRefGoodFunc XPLMIsDataRefGood;
    XPLMGetDataiFunc XPLMGetDatai;
    XPLMSetDataiFunc XPLMSetDatai;
    XPLMGetDatafFunc XPLMGetDataf;
    XPLMSetDatafFunc XPLMSetDataf;
    XPLMGetDatadFunc XPLMGetDatad;
    XPLMSetDatadFunc XPLMSetDatad;
    XPLMGetDataviFunc XPLMGetDatavi;
    XPLMSetDataviFunc XPLMSetDatavi;
    XPLMGetDatavfFunc XPLMGetDatavf;
    XPLMSetDatavfFunc XPLMSetDatavf;
    XPLMGetDatabFunc XPLMGetDatab;
    XPLMSetDatabFunc XPLMSetDatab;
    XPLMUnregisterDataAccessorFunc XPLMUnregisterDataAccessor;
    XPLMShareDataFunc XPLMShareData;
    XPLMUnshareDataFunc XPLMUnshareData;
    XPLMGetNavAidInfoFunc XPLMGetNavAidInfo;
    XPLMCountFMSEntriesFunc XPLMCountFMSEntries;
    XPLMGetDisplayedFMSEntryFunc XPLMGetDisplayedFMSEntry;
    XPLMGetDestinationFMSEntryFunc XPLMGetDestinationFMSEntry;
    XPLMSetDisplayedFMSEntryFunc XPLMSetDisplayedFMSEntry;
    XPLMSetDestinationFMSEntryFunc XPLMSetDestinationFMSEntry;
    XPLMGetFMSEntryInfoFunc XPLMGetFMSEntryInfo;
    XPLMSetFMSEntryInfoFunc XPLMSetFMSEntryInfo;
    XPLMSetFMSEntryLatLonFunc XPLMSetFMSEntryLatLon;
    XPLMClearFMSEntryFunc XPLMClearFMSEntry;
    XPLMSetGraphicsStateFunc XPLMSetGraphicsState;
    XPLMBindTexture2dFunc XPLMBindTexture2d;
    XPLMGenerateTextureNumbersFunc XPLMGenerateTextureNumbers;
    XPLMWorldToLocalFunc XPLMWorldToLocal;
    XPLMLocalToWorldFunc XPLMLocalToWorld;
    XPLMDrawTranslucentDarkBoxFunc XPLMDrawTranslucentDarkBox;
    XPLMDrawStringFunc XPLMDrawString;
    XPLMDrawNumberFunc XPLMDrawNumber;
    XPLMGetFontDimensionsFunc XPLMGetFontDimensions;
    XPLMDestroyInstanceFunc XPLMDestroyInstance;
    XPLMInstanceSetPositionFunc XPLMInstanceSetPosition;
    XPLMCountPluginsFunc XPLMCountPlugins;
    XPLMGetPluginInfoFunc XPLMGetPluginInfo;
    XPLMIsPluginEnabledFunc XPLMIsPluginEnabled;
    XPLMEnablePluginFunc XPLMEnablePlugin;
    XPLMDisablePluginFunc XPLMDisablePlugin;
    XPLMReloadPluginsFunc XPLMReloadPlugins;
    XPLMSendMessageToPluginFunc XPLMSendMessageToPlugin;
    XPLMRegisterDrawCallbackFunc XPLMRegisterDrawCallback;
    XPLMUnregisterDrawCallbackFunc XPLMUnregisterDrawCallback;
    XPLMDestroyWindowFunc XPLMDestroyWindow;
    XPLMGetScreenSizeFunc XPLMGetScreenSize;
    XPLMGetMouseLocationFunc XPLMGetMouseLocation;
    XPLMGetWindowGeometryFunc XPLMGetWindowGeometry;
    XPLMSetWindowGeometryFunc XPLMSetWindowGeometry;
    XPLMGetWindowIsVisibleFunc XPLMGetWindowIsVisible;
    XPLMSetWindowIsVisibleFunc XPLMSetWindowIsVisible;
    XPLMGetWindowRefConFunc XPLMGetWindowRefCon;
    XPLMSetWindowRefConFunc XPLMSetWindowRefCon;
    XPLMTakeKeyboardFocusFunc XPLMTakeKeyboardFocus;
    XPLMHasKeyboardFocusFunc XPLMHasKeyboardFocus;
    XPLMBringWindowToFrontFunc XPLMBringWindowToFront;
    XPLMIsWindowInFrontFunc XPLMIsWindowInFront;
    XPLMRegisterKeySnifferFunc XPLMRegisterKeySniffer;
    XPLMUnregisterKeySnifferFunc XPLMUnregisterKeySniffer;
    XPLMUnregisterHotKeyFunc XPLMUnregisterHotKey;
    XPLMCountHotKeysFunc XPLMCountHotKeys;
    XPLMGetHotKeyInfoFunc XPLMGetHotKeyInfo;
    XPLMSetHotKeyCombinationFunc XPLMSetHotKeyCombination;
    XPLMGetElapsedTimeFunc XPLMGetElapsedTime;
    XPLMGetCycleNumberFunc XPLMGetCycleNumber;
    XPLMRegisterFlightLoopCallbackFunc XPLMRegisterFlightLoopCallback;
    XPLMUnregisterFlightLoopCallbackFunc XPLMUnregisterFlightLoopCallback;
    XPLMSetFlightLoopCallbackIntervalFunc XPLMSetFlightLoopCallbackInterval;
    XPLMGetSystemPathFunc XPLMGetSystemPath;
    XPLMGetPrefsPathFunc XPLMGetPrefsPath;
    XPLMGetDirectorySeparatorFunc XPLMGetDirectorySeparator;
    XPLMExtractFileAndPathFunc XPLMExtractFileAndPath;
    XPLMGetDirectoryContentsFunc XPLMGetDirectoryContents;
    XPLMGetVersionsFunc XPLMGetVersions;
    XPLMDebugStringFunc XPLMDebugString;
    XPLMSpeakStringFunc XPLMSpeakString;
    XPLMGetVirtualKeyDescriptionFunc XPLMGetVirtualKeyDescription;
    XPLMReloadSceneryFunc XPLMReloadScenery;
    XPLMDestroyMenuFunc XPLMDestroyMenu;
    XPLMClearAllMenuItemsFunc XPLMClearAllMenuItems;
    XPLMAppendMenuItemFunc XPLMAppendMenuItem;
    XPLMAppendMenuSeparatorFunc XPLMAppendMenuSeparator;
    XPLMSetMenuItemNameFunc XPLMSetMenuItemName;
    XPLMCheckMenuItemFunc XPLMCheckMenuItem;
    XPLMCheckMenuItemStateFunc XPLMCheckMenuItemState;
    XPLMEnableMenuItemFunc XPLMEnableMenuItem;
    XPLMControlCameraFunc XPLMControlCamera;
    XPLMDontControlCameraFunc XPLMDontControlCamera;
    XPLMIsCameraBeingControlledFunc XPLMIsCameraBeingControlled;
    XPLMReadCameraPositionFunc XPLMReadCameraPosition;
    XPUCreateWidgetsFunc XPUCreateWidgets;
    XPUMoveWidgetByFunc XPUMoveWidgetBy;
    XPUFixedLayoutFunc XPUFixedLayout;
    XPUSelectIfNeededFunc XPUSelectIfNeeded;
    XPUDefocusKeyboardFunc XPUDefocusKeyboard;
    XPUDragWidgetFunc XPUDragWidget;
    XPDestroyWidgetFunc XPDestroyWidget;
    XPSendMessageToWidgetFunc XPSendMessageToWidget;
    XPPlaceWidgetWithinFunc XPPlaceWidgetWithin;
    XPCountChildWidgetsFunc XPCountChildWidgets;
    XPShowWidgetFunc XPShowWidget;
    XPHideWidgetFunc XPHideWidget;
    XPIsWidgetVisibleFunc XPIsWidgetVisible;
    XPBringRootWidgetToFrontFunc XPBringRootWidgetToFront;
    XPIsWidgetInFrontFunc XPIsWidgetInFront;
    XPGetWidgetGeometryFunc XPGetWidgetGeometry;
    XPSetWidgetGeometryFunc XPSetWidgetGeometry;
    XPGetWidgetExposedGeometryFunc XPGetWidgetExposedGeometry;
    XPSetWidgetDescriptorFunc XPSetWidgetDescriptor;
    XPGetWidgetDescriptorFunc XPGetWidgetDescriptor;
    XPSetWidgetPropertyFunc XPSetWidgetProperty;
    XPLoseKeyboardFocusFunc XPLoseKeyboardFocus;
    XPAddWidgetCallbackFunc XPAddWidgetCallback;
    XPDrawWindowFunc XPDrawWindow;
    XPGetWindowDefaultDimensionsFunc XPGetWindowDefaultDimensions;
    XPDrawElementFunc XPDrawElement;
    XPGetElementDefaultDimensionsFunc XPGetElementDefaultDimensions;
    XPDrawTrackFunc XPDrawTrack;
    XPGetTrackDefaultDimensionsFunc XPGetTrackDefaultDimensions;
    XPGetTrackMetricsFunc XPGetTrackMetrics;

    void (*logDebug)(const char* message);
    void (*logInfo)(const char* message);
    void (*logWarning)(const char* message);
    void (*logError)(const char* message);
    
    const char* (*getPluginPath)();
};

void FillXPlaneAPI(XPlaneAPI* api) {
    if (!api) return;
    api->XPLMFindDataRef = XPLMFindDataRef;
    api->XPLMGetMyID = XPLMGetMyID;
    api->XPLMSetUsersAircraft = XPLMSetUsersAircraft;
    api->XPLMPlaceUserAtAirport = XPLMPlaceUserAtAirport;
    api->XPLMCountAircraft = XPLMCountAircraft;
    api->XPLMGetNthAircraftModel = XPLMGetNthAircraftModel;
    api->XPLMAcquirePlanes = XPLMAcquirePlanes;
    api->XPLMReleasePlanes = XPLMReleasePlanes;
    api->XPLMSetActiveAircraftCount = XPLMSetActiveAircraftCount;
    api->XPLMSetAircraftModel = XPLMSetAircraftModel;
    api->XPLMDisableAIForPlane = XPLMDisableAIForPlane;
    api->XPLMCanWriteDataRef = XPLMCanWriteDataRef;
    api->XPLMIsDataRefGood = XPLMIsDataRefGood;
    api->XPLMGetDatai = XPLMGetDatai;
    api->XPLMSetDatai = XPLMSetDatai;
    api->XPLMGetDataf = XPLMGetDataf;
    api->XPLMSetDataf = XPLMSetDataf;
    api->XPLMGetDatad = XPLMGetDatad;
    api->XPLMSetDatad = XPLMSetDatad;
    api->XPLMGetDatavi = XPLMGetDatavi;
    api->XPLMSetDatavi = XPLMSetDatavi;
    api->XPLMGetDatavf = XPLMGetDatavf;
    api->XPLMSetDatavf = XPLMSetDatavf;
    api->XPLMGetDatab = XPLMGetDatab;
    api->XPLMSetDatab = XPLMSetDatab;
    api->XPLMUnregisterDataAccessor = XPLMUnregisterDataAccessor;
    api->XPLMShareData = XPLMShareData;
    api->XPLMUnshareData = XPLMUnshareData;
    api->XPLMGetNavAidInfo = XPLMGetNavAidInfo;
    api->XPLMCountFMSEntries = XPLMCountFMSEntries;
    api->XPLMGetDisplayedFMSEntry = XPLMGetDisplayedFMSEntry;
    api->XPLMGetDestinationFMSEntry = XPLMGetDestinationFMSEntry;
    api->XPLMSetDisplayedFMSEntry = XPLMSetDisplayedFMSEntry;
    api->XPLMSetDestinationFMSEntry = XPLMSetDestinationFMSEntry;
    api->XPLMGetFMSEntryInfo = XPLMGetFMSEntryInfo;
    api->XPLMSetFMSEntryInfo = XPLMSetFMSEntryInfo;
    api->XPLMSetFMSEntryLatLon = XPLMSetFMSEntryLatLon;
    api->XPLMClearFMSEntry = XPLMClearFMSEntry;
    api->XPLMSetGraphicsState = XPLMSetGraphicsState;
    api->XPLMBindTexture2d = XPLMBindTexture2d;
    api->XPLMGenerateTextureNumbers = XPLMGenerateTextureNumbers;
    api->XPLMWorldToLocal = XPLMWorldToLocal;
    api->XPLMLocalToWorld = XPLMLocalToWorld;
    api->XPLMDrawTranslucentDarkBox = XPLMDrawTranslucentDarkBox;
    api->XPLMDrawString = XPLMDrawString;
    api->XPLMDrawNumber = XPLMDrawNumber;
    api->XPLMGetFontDimensions = XPLMGetFontDimensions;
    api->XPLMDestroyInstance = XPLMDestroyInstance;
    api->XPLMInstanceSetPosition = XPLMInstanceSetPosition;
    api->XPLMCountPlugins = XPLMCountPlugins;
    api->XPLMGetPluginInfo = XPLMGetPluginInfo;
    api->XPLMIsPluginEnabled = XPLMIsPluginEnabled;
    api->XPLMEnablePlugin = XPLMEnablePlugin;
    api->XPLMDisablePlugin = XPLMDisablePlugin;
    api->XPLMReloadPlugins = XPLMReloadPlugins;
    api->XPLMSendMessageToPlugin = XPLMSendMessageToPlugin;
    api->XPLMRegisterDrawCallback = XPLMRegisterDrawCallback;
    api->XPLMUnregisterDrawCallback = XPLMUnregisterDrawCallback;
    api->XPLMDestroyWindow = XPLMDestroyWindow;
    api->XPLMGetScreenSize = XPLMGetScreenSize;
    api->XPLMGetMouseLocation = XPLMGetMouseLocation;
    api->XPLMGetWindowGeometry = XPLMGetWindowGeometry;
    api->XPLMSetWindowGeometry = XPLMSetWindowGeometry;
    api->XPLMGetWindowIsVisible = XPLMGetWindowIsVisible;
    api->XPLMSetWindowIsVisible = XPLMSetWindowIsVisible;
    api->XPLMGetWindowRefCon = XPLMGetWindowRefCon;
    api->XPLMSetWindowRefCon = XPLMSetWindowRefCon;
    api->XPLMTakeKeyboardFocus = XPLMTakeKeyboardFocus;
    api->XPLMHasKeyboardFocus = XPLMHasKeyboardFocus;
    api->XPLMBringWindowToFront = XPLMBringWindowToFront;
    api->XPLMIsWindowInFront = XPLMIsWindowInFront;
    api->XPLMRegisterKeySniffer = XPLMRegisterKeySniffer;
    api->XPLMUnregisterKeySniffer = XPLMUnregisterKeySniffer;
    api->XPLMUnregisterHotKey = XPLMUnregisterHotKey;
    api->XPLMCountHotKeys = XPLMCountHotKeys;
    api->XPLMGetHotKeyInfo = XPLMGetHotKeyInfo;
    api->XPLMSetHotKeyCombination = XPLMSetHotKeyCombination;
    api->XPLMGetElapsedTime = XPLMGetElapsedTime;
    api->XPLMGetCycleNumber = XPLMGetCycleNumber;
    api->XPLMRegisterFlightLoopCallback = XPLMRegisterFlightLoopCallback;
    api->XPLMUnregisterFlightLoopCallback = XPLMUnregisterFlightLoopCallback;
    api->XPLMSetFlightLoopCallbackInterval = XPLMSetFlightLoopCallbackInterval;
    api->XPLMGetSystemPath = XPLMGetSystemPath;
    api->XPLMGetPrefsPath = XPLMGetPrefsPath;
    api->XPLMGetDirectorySeparator = XPLMGetDirectorySeparator;
    api->XPLMExtractFileAndPath = XPLMExtractFileAndPath;
    api->XPLMGetDirectoryContents = XPLMGetDirectoryContents;
    api->XPLMGetVersions = XPLMGetVersions;
    api->XPLMDebugString = XPLMDebugString;
    api->XPLMSpeakString = XPLMSpeakString;
    api->XPLMGetVirtualKeyDescription = XPLMGetVirtualKeyDescription;
    api->XPLMReloadScenery = XPLMReloadScenery;
    api->XPLMGetSystemPath = XPLMGetSystemPath;
    api->XPLMGetPrefsPath = XPLMGetPrefsPath;
    api->XPLMGetDirectorySeparator = XPLMGetDirectorySeparator;
    api->XPLMExtractFileAndPath = XPLMExtractFileAndPath;
    api->XPLMGetDirectoryContents = XPLMGetDirectoryContents;
    api->XPLMGetVersions = XPLMGetVersions;
    api->XPLMDebugString = XPLMDebugString;
    api->XPLMSpeakString = XPLMSpeakString;
    api->XPLMGetVirtualKeyDescription = XPLMGetVirtualKeyDescription;
    api->XPLMReloadScenery = XPLMReloadScenery;
    api->XPLMDestroyMenu = XPLMDestroyMenu;
    api->XPLMClearAllMenuItems = XPLMClearAllMenuItems;
    api->XPLMAppendMenuItem = XPLMAppendMenuItem;
    api->XPLMAppendMenuSeparator = XPLMAppendMenuSeparator;
    api->XPLMSetMenuItemName = XPLMSetMenuItemName;
    api->XPLMCheckMenuItem = XPLMCheckMenuItem;
    api->XPLMCheckMenuItemState = XPLMCheckMenuItemState;
    api->XPLMEnableMenuItem = XPLMEnableMenuItem;
    api->XPLMControlCamera = XPLMControlCamera;
    api->XPLMDontControlCamera = XPLMDontControlCamera;
    api->XPLMIsCameraBeingControlled = XPLMIsCameraBeingControlled;
    api->XPLMReadCameraPosition = XPLMReadCameraPosition;
    api->XPUCreateWidgets = XPUCreateWidgets;
    api->XPUMoveWidgetBy = XPUMoveWidgetBy;
    api->XPUFixedLayout = XPUFixedLayout;
    api->XPUSelectIfNeeded = XPUSelectIfNeeded;
    api->XPUDefocusKeyboard = XPUDefocusKeyboard;
    api->XPUDragWidget = XPUDragWidget;
    api->XPDestroyWidget = XPDestroyWidget;
    api->XPSendMessageToWidget = XPSendMessageToWidget;
    api->XPPlaceWidgetWithin = XPPlaceWidgetWithin;
    api->XPCountChildWidgets = XPCountChildWidgets;
    api->XPShowWidget = XPShowWidget;
    api->XPHideWidget = XPHideWidget;
    api->XPIsWidgetVisible = XPIsWidgetVisible;
    api->XPBringRootWidgetToFront = XPBringRootWidgetToFront;
    api->XPIsWidgetInFront = XPIsWidgetInFront;
    api->XPGetWidgetGeometry = XPGetWidgetGeometry;
    api->XPSetWidgetGeometry = XPSetWidgetGeometry;
    api->XPGetWidgetExposedGeometry = XPGetWidgetExposedGeometry;
    api->XPSetWidgetDescriptor = XPSetWidgetDescriptor;
    api->XPGetWidgetDescriptor = XPGetWidgetDescriptor;
    api->XPSetWidgetProperty = XPSetWidgetProperty;
    api->XPLoseKeyboardFocus = XPLoseKeyboardFocus;
    api->XPAddWidgetCallback = XPAddWidgetCallback;
    api->XPDrawWindow = XPDrawWindow;
    api->XPGetWindowDefaultDimensions = XPGetWindowDefaultDimensions;
    api->XPDrawElement = XPDrawElement;
    api->XPGetElementDefaultDimensions = XPGetElementDefaultDimensions;
    api->XPDrawTrack = XPDrawTrack;
    api->XPGetTrackDefaultDimensions = XPGetTrackDefaultDimensions;
    api->XPGetTrackMetrics = XPGetTrackMetrics;
}

#endif // XPLANE_API_H