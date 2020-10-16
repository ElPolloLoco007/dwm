/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "ubuntuMono-R:size=12","JoyPixels:12" };
static const char dmenufont[]       = "ubuntuMono-R:size=12";
static const char dmenuhp[]       = "brave,spotify,pcmanfm,dbeaver,thunderbird,steam,newsboat";
static const int focusonwheel       = 0;
static const char col_gray1[]       = "#440BD4"; //menu
static const char col_gray2[]       = "#3CB3FF";
static const char col_gray3[]       = "#FF2247"; //telstur
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#3CB371"; // millum menu
static const char col1[]            = "#FFD700";
static const char col2[]            = "#FF2223";
static const char col3[]            = "#EE1234";
static const char col4[]            = "#ffffff";
static const char col5[]            = "#ffffff";
static const char col6[]            = "#ffffff";
static const char col7[]            = "#ffffff";
static const char col8[]            = "#ffffff";
static const char col9[]            = "#ffffff";
static const char col10[]           = "#ffffff";
static const char col11[]           = "#ffffff";
static const char col12[]           = "#ffffff";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]  = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]   = { col_gray4, col_cyan,  col_cyan  },
	[SchemeCol1]  = { col1,      col2, col2 },
	[SchemeCol2]  = { col2,      col3, col2 },
	[SchemeCol3]  = { col3,      col_gray1, col_gray2 },
	[SchemeCol4]  = { col4,      col_gray1, col_gray2 },
	[SchemeCol5]  = { col5,      col_gray1, col_gray2 },
	[SchemeCol6]  = { col6,      col_gray1, col_gray2 },
	[SchemeCol7]  = { col7,      col_gray1, col_gray2 },
	[SchemeCol8]  = { col8,      col_gray1, col_gray2 },
	[SchemeCol9]  = { col8,      col_gray1, col_gray2 },
	[SchemeCol10] = { col10,     col_gray1, col_gray2 },
	[SchemeCol11] = { col11,     col_gray1, col_gray2 },
	[SchemeCol12] = { col12,     col_gray1, col_gray2 },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha }
	
};

/* tagging */
static const char *tags[] = { "🏠", "⚒", "🔧", "🎵🎥", "🐔", "📰", "📈", "🗓", "📧" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class             instance    title       tags mask     isfloating   monitor */
	{ "code",            NULL,       NULL,       1 << 1,       0,           -1 },
	{ "dbeaver",         NULL,       NULL,       1 << 2,       0,           -1 },
	{ "spotify", 		 NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Thunderbird",     NULL,       NULL,       1 << 8,       0,           -1 },
    { "Skype",   		 NULL,       NULL,       1 << 8,       0,           -1 },
	{ "mpv",             NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Steam",           NULL,       NULL,       1 << 4,       0,           -1 },
    { "newsboat",        NULL,       NULL,       1 << 5,       0,           -1 },
	{ "calendar",        NULL,       NULL,       1 << 7,       0,           -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4,"-hp",dmenuhp, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *termcmdNewsboat[]  = { "st","-c","newsboat","-e","newsboat", NULL };
static const char *termcmdCalendar[]  = { "st","-c","calendar","-e","calendar", NULL };

#include "shiftview.c"

static Key keys[] = {
	 //light-locker-command -l
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  focusmaster,    {0} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             			XK_n,      spawn,          {.v = termcmdNewsboat } },
	{ MODKEY,             			XK_n,      spawn,          {.v = termcmdCalendar } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,              			XK_Right,  shiftview,      { .i = +1 } },
	{ MODKEY,              			XK_Left,   shiftview,      { .i = -1 } },
	{ MODKEY,                       XK_m,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_Down,   rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Up,     rotatestack,    {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_comma,  setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_period,   setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,			XK_Down,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Up, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_q,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_w, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F11,  spawn, SHCMD("amixer -q sset Master 2%-") },
	{ MODKEY,                       XK_F12,  spawn, SHCMD("amixer -q sset Master 2%+") },
	{ MODKEY,                       XK_F10,  spawn, SHCMD("amixer -q sset Master toggle") },  //toggle sound
	{ MODKEY|ShiftMask,             XK_F10,  spawn, SHCMD("amixer set Capture toggle") },   //toggle microphone
	TAGKEYS(                        XK_h,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,             			XK_l,      spawn,          SHCMD("light-locker-command -l")},
	{ MODKEY, 						XK_Print, spawn, SHCMD("sleep .5; scrot -s ~/Pictures/screenshots/%Y-%m-%d-%s%w%h.jpg") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        shiftview,     { .i = -1 } },
	{ ClkTagBar,            0,              Button5,        shiftview,     { .i = +1 } },
};

