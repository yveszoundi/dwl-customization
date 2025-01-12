/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx         = 1;  /* border pixel of windows */
static const float rootcolor[]             = {0.3, 0.3, 0.3, 1.0};
static const float bordercolor[]           = {0.5, 0.5, 0.5, 1.0};
static const float focuscolor[]            = {1.0, 0.0, 0.0, 1.0};
/* To conform the xdg-protocol, set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.1, 0.1, 0.1, 1.0};

/* autostart */
static const char *const autostart[] = {
  "/home/vip/.local/share/dwl/autostart.sh",  NULL,
  NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* app_id     title       tags mask     isfloating   monitor */
	/* examples:
	{ "Gimp",     NULL,       0,            1,           -1 },
	*/
	{ "Firefox",  NULL,       1 << 1,       0,           -1 },
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* monitors */
static const MonitorRule monrules[] = {
	/* name       mfact nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor:
	{ "eDP-1",    0.5,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL    -1,  -1 },
	*/
	/* defaults */
	{ NULL,       0.55, 1,      1,    &layouts[2], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = NULL,
};

static const int repeat_rate = 25;
static const int repeat_delay = 600;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE       
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS       
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER 
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;
/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* Prefix key */
#define PREFIXKEY     XKB_KEY_t

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY      WLR_MODIFIER_CTRL
#define MOD_ALT     WLR_MODIFIER_ALT
#define MOD_CONTROL WLR_MODIFIER_CTRL
#define MOD_SHIFT   WLR_MODIFIER_SHIFT
#define MOD_NONE    0

#define TAGKEYS(KEY,SKEY,TAG) \
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, KEY}},                                view,       {.ui = 1 << TAG} }, \
  { 2, {{MODKEY, PREFIXKEY}, {MOD_CONTROL,KEY}},                              toggleview, {.ui = 1 << TAG} }, \
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_R}, {MOD_SHIFT, SKEY}}, tag,        {.ui = 1 << TAG} }, \
  { 3, {{MODKEY, PREFIXKEY}, {MOD_CONTROL, XKB_KEY_h}, {MOD_NONE, KEY}},      toggletag,  {.ui = 1 << TAG} }

/* commands */
#define RUN(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

static const Keychord keychords[] = {
  /* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
  /* count key_sequences                                                                    function          argument */
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Return}},                                   spawn,            RUN("bemenu-run", "-l", "10") },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_c}},                                        spawn,            RUN("foot") },
  { 2, {{MODKEY, PREFIXKEY}, {MODKEY,   XKB_KEY_l}},                                        spawn,            RUN("swaylock") },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_R}, {MOD_SHIFT, XKB_KEY_C}},          spawn,            RUN("rclip-copy") },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_R}, {MOD_SHIFT, XKB_KEY_V}},          spawn,            RUN("rclip-paste") },  
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_n}},                                        focusstack,       {.i = +1} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_p}},                                        focusstack,       {.i = -1} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_bracketright}},                             incnmaster,       {.i = +1} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_bracketleft}},                              incnmaster,       {.i = -1} },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_L}, {MOD_SHIFT, XKB_KEY_braceright}}, setmfact,         {.f = +0.05} },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_L}, {MOD_SHIFT, XKB_KEY_braceleft}},  setmfact,         {.f = -0.05} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_grave}},                                    zoom,             {0} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Tab}},                                      view,             {0} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_k}},                                        killclient,       {0} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_t}},                                        setlayout,        {.v = &layouts[0]} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_f}},                                        setlayout,        {.v = &layouts[1]} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_m}},                                        setlayout,        {.v = &layouts[2]} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_space}},                                    setlayout,        {0} },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_R}, {MOD_SHIFT, XKB_KEY_F}},          togglefloating,   {0} },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_R}, {MOD_SHIFT, XKB_KEY_E}},          togglefullscreen, {0} },
  { 2, {{MODKEY, PREFIXKEY}, {MODKEY, XKB_KEY_0}},                                          view,             {.ui = ~0} },
  { 2, {{MODKEY, PREFIXKEY}, {MODKEY|MOD_SHIFT, XKB_KEY_parenright}},                       tag,              {.ui = ~0} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_comma}},                                    focusmon,         {.i = WLR_DIRECTION_LEFT} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_period}},                                   focusmon,         {.i = WLR_DIRECTION_RIGHT} },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_L}, {MOD_SHIFT, XKB_KEY_less}},       tagmon,           {.i = WLR_DIRECTION_LEFT} },
  { 3, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_Shift_L}, {MOD_SHIFT, XKB_KEY_greater}},    tagmon,           {.i = WLR_DIRECTION_RIGHT} },
  { 2, {{MODKEY, PREFIXKEY}, {MOD_NONE, XKB_KEY_q}},                                        quit,             {0} },

  TAGKEYS(XKB_KEY_1, XKB_KEY_exclam,      0),
  TAGKEYS(XKB_KEY_2, XKB_KEY_at,          1),
  TAGKEYS(XKB_KEY_3, XKB_KEY_numbersign,  2),
  TAGKEYS(XKB_KEY_4, XKB_KEY_dollar,      3),
  TAGKEYS(XKB_KEY_5, XKB_KEY_percent,     4),
  TAGKEYS(XKB_KEY_6, XKB_KEY_asciicircum, 5),
  TAGKEYS(XKB_KEY_7, XKB_KEY_ampersand,   6),
  TAGKEYS(XKB_KEY_8, XKB_KEY_asterisk,    7),
  TAGKEYS(XKB_KEY_9, XKB_KEY_parenleft,   8),

/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ 1, {{WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_BackSpace}}, quit, {0} },
#define CHVT(n) { 1, {{WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n}}, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),  
};

static const Button buttons[] = {
  { MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
  { MODKEY, BTN_MIDDLE, togglefloating, {0} },
  { MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
