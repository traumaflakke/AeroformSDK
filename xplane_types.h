// Generated by parse_xplane_headers.py
#ifndef XPLANE_TYPES_H
#define XPLANE_TYPES_H

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMDefs.h:177:1) { xplm_ShiftFlag = 1, xplm_OptionAltFlag = 2, xplm_ControlFlag = 4, xplm_DownFlag = 8, xplm_UpFlag = 16 };

typedef struct XPLMFixedString150_t { char[150] buffer };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMDefs.h:557:1) { xplm_MouseDown = 1, xplm_MouseDrag = 2, xplm_MouseUp = 3 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMDataAccess.h:143:1) { xplmType_Unknown = 0, xplmType_Int = 1, xplmType_Float = 2, xplmType_Double = 4, xplmType_FloatArray = 8, xplmType_IntArray = 16, xplmType_Data = 32 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMNavigation.h:48:1) { xplm_Nav_Unknown = 0, xplm_Nav_Airport = 1, xplm_Nav_NDB = 2, xplm_Nav_VOR = 4, xplm_Nav_ILS = 8, xplm_Nav_Localizer = 16, xplm_Nav_GlideSlope = 32, xplm_Nav_OuterMarker = 64, xplm_Nav_MiddleMarker = 128, xplm_Nav_InnerMarker = 256, xplm_Nav_Fix = 512, xplm_Nav_DME = 1024, xplm_Nav_LatLon = 2048, xplm_Nav_TACAN = 4096 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMGraphics.h:71:1) { xplm_Tex_GeneralInterface = 0 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMGraphics.h:263:1) { xplmFont_Basic = 0 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMDisplay.h:143:1) { xplm_Phase_FirstCockpit = 35, xplm_Phase_Panel = 40, xplm_Phase_Gauges = 45, xplm_Phase_Window = 50, xplm_Phase_LastCockpit = 55 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMUtilities.h:232:1) { xplm_Host_Unknown = 0, xplm_Host_XPlane = 1 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMUtilities.h:290:1) { xplm_Language_Unknown = 0, xplm_Language_English = 1, xplm_Language_French = 2, xplm_Language_German = 3, xplm_Language_Italian = 4, xplm_Language_Spanish = 5, xplm_Language_Korean = 6 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMMenus.h:62:1) { xplm_Menu_NoCheck = 0, xplm_Menu_Unchecked = 1, xplm_Menu_Checked = 2 };

typedef struct XPLMWeatherInfoWinds_t { float alt_msl; float speed; float direction; float gust_speed; float shear; float turbulence };

typedef struct XPLMWeatherInfoClouds_t { float cloud_type; float coverage; float alt_top; float alt_base };

typedef struct XPLMWeatherInfo_t { int structSize; float temperature_alt; float dewpoint_alt; float pressure_alt; float precip_rate_alt; float wind_dir_alt; float wind_spd_alt; float turbulence_alt; float wave_height; float wave_length; int wave_dir; float wave_speed; float visibility; float precip_rate; float thermal_climb; float pressure_sl; XPLMWeatherInfoWinds_t[13] wind_layers; XPLMWeatherInfoClouds_t[3] cloud_layers };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/XPLM/XPLMCamera.h:65:1) { xplm_ControlCameraUntilViewChanges = 1, xplm_ControlCameraForever = 2 };

typedef struct XPLMCameraPosition_t { float x; float y; float z; float pitch; float heading; float roll; float zoom };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPWidgetDefs.h:90:1) { xpProperty_Refcon = 0, xpProperty_Dragging = 1, xpProperty_DragXOff = 2, xpProperty_DragYOff = 3, xpProperty_Hilited = 4, xpProperty_Object = 5, xpProperty_Clip = 6, xpProperty_Enabled = 7, xpProperty_UserStart = 10000 };

typedef struct XPMouseState_t { int x; int y; int button };

typedef struct (unnamed struct at /opt/xplane/SDK/CHeaders/Widgets/XPWidgetDefs.h:153:9) { char key; int flags; char vkey };

typedef struct XPWidgetGeometryChange_t { int dx; int dy; int dwidth; int dheight };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPWidgetDefs.h:185:1) { xpMode_Direct = 0, xpMode_UpChain = 1, xpMode_Recursive = 2, xpMode_DirectAllCallbacks = 3, xpMode_Once = 4 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPWidgetDefs.h:235:1) { xpMsg_None = 0, xpMsg_Create = 1, xpMsg_Destroy = 2, xpMsg_Paint = 3, xpMsg_Draw = 4, xpMsg_KeyPress = 5, xpMsg_KeyTakeFocus = 6, xpMsg_KeyLoseFocus = 7, xpMsg_MouseDown = 8, xpMsg_MouseDrag = 9, xpMsg_MouseUp = 10, xpMsg_Reshape = 11, xpMsg_ExposedChanged = 12, xpMsg_AcceptChild = 13, xpMsg_LoseChild = 14, xpMsg_AcceptParent = 15, xpMsg_Shown = 16, xpMsg_Hidden = 17, xpMsg_DescriptorChanged = 18, xpMsg_PropertyChanged = 19, xpMsg_UserStart = 10000 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:56:1) { xpMainWindowStyle_MainWindow = 0, xpMainWindowStyle_Translucent = 1 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:70:1) { xpProperty_MainWindowType = 1100, xpProperty_MainWindowHasCloseBoxes = 1200 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:86:1) { xpMessage_CloseButtonPushed = 1200 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:112:1) { xpSubWindowStyle_SubWindow = 0, xpSubWindowStyle_Screen = 2, xpSubWindowStyle_ListView = 3 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:129:1) { xpProperty_SubWindowType = 1200 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:170:1) { xpPushButton = 0, xpRadioButton = 1, xpWindowCloseBox = 3, xpLittleDownArrow = 5, xpLittleUpArrow = 6 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:197:1) { xpButtonBehaviorPushButton = 0, xpButtonBehaviorCheckBox = 1, xpButtonBehaviorRadioButton = 2 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:220:1) { xpProperty_ButtonType = 1300, xpProperty_ButtonBehavior = 1301, xpProperty_ButtonState = 1302 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:245:1) { xpMsg_PushButtonPressed = 1300, xpMsg_ButtonStateChanged = 1301 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:293:1) { xpTextEntryField = 0, xpTextTransparent = 3, xpTextTranslucent = 4 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:312:1) { xpProperty_EditFieldSelStart = 1400, xpProperty_EditFieldSelEnd = 1401, xpProperty_EditFieldSelDragStart = 1402, xpProperty_TextFieldType = 1403, xpProperty_PasswordMode = 1404, xpProperty_MaxCharacters = 1405, xpProperty_ScrollPosition = 1406, xpProperty_Font = 1407, xpProperty_ActiveEditSide = 1408 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:353:1) { xpMsg_TextFieldChanged = 1400 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:380:1) { xpScrollBarTypeScrollBar = 0, xpScrollBarTypeSlider = 1 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:394:1) { xpProperty_ScrollBarSliderPosition = 1500, xpProperty_ScrollBarMin = 1501, xpProperty_ScrollBarMax = 1502, xpProperty_ScrollBarPageAmount = 1503, xpProperty_ScrollBarType = 1504, xpProperty_ScrollBarSlop = 1505 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:421:1) { xpMsg_ScrollBarSliderPositionChanged = 1500 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:446:1) { xpProperty_CaptionLit = 1600 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:472:1) { xpShip = 4, xpILSGlideScope = 5, xpMarkerLeft = 6, xp_Airport = 7, xpNDB = 8, xpVOR = 9, xpRadioTower = 10, xpAircraftCarrier = 11, xpFire = 12, xpMarkerRight = 13, xpCustomObject = 14, xpCoolingTower = 15, xpSmokeStack = 16, xpBuilding = 17, xpPowerLine = 18, xpVORWithCompassRose = 19, xpOilPlatform = 21, xpOilPlatformSmall = 22, xpWayPoint = 23 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:518:1) { xpProperty_GeneralGraphicsType = 1700 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPStandardWidgets.h:539:1) { xpProperty_ProgressPosition = 1800, xpProperty_ProgressMin = 1801, xpProperty_ProgressMax = 1802 };

typedef struct XPWidgetCreate_t { int left; int top; int right; int bottom; int visible; const char * descriptor; int isRoot; int containerIndex; XPWidgetClass widgetClass };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPUIGraphics.h:45:1) { xpWindow_Help = 0, xpWindow_MainWindow = 1, xpWindow_SubWindow = 2, xpWindow_Screen = 4, xpWindow_ListView = 5 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPUIGraphics.h:107:1) { xpElement_TextField = 6, xpElement_CheckBox = 9, xpElement_CheckBoxLit = 10, xpElement_WindowCloseBox = 14, xpElement_WindowCloseBoxPressed = 15, xpElement_PushButton = 16, xpElement_PushButtonLit = 17, xpElement_OilPlatform = 24, xpElement_OilPlatformSmall = 25, xpElement_Ship = 26, xpElement_ILSGlideScope = 27, xpElement_MarkerLeft = 28, xpElement_Airport = 29, xpElement_Waypoint = 30, xpElement_NDB = 31, xpElement_VOR = 32, xpElement_RadioTower = 33, xpElement_AircraftCarrier = 34, xpElement_Fire = 35, xpElement_MarkerRight = 36, xpElement_CustomObject = 37, xpElement_CoolingTower = 38, xpElement_SmokeStack = 39, xpElement_Building = 40, xpElement_PowerLine = 41, xpElement_CopyButtons = 45, xpElement_CopyButtonsWithEditingGrid = 46, xpElement_EditingGrid = 47, xpElement_ScrollBar = 48, xpElement_VORWithCompassRose = 49, xpElement_Zoomer = 51, xpElement_TextFieldMiddle = 52, xpElement_LittleDownArrow = 53, xpElement_LittleUpArrow = 54, xpElement_WindowDragBar = 61, xpElement_WindowDragBarSmooth = 62 };

typedef enum (unnamed enum at /opt/xplane/SDK/CHeaders/Widgets/XPUIGraphics.h:268:1) { xpTrack_ScrollBar = 0, xpTrack_Slider = 1, xpTrack_Progress = 2 };

#endif // XPLANE_TYPES_H
