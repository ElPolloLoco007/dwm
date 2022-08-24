/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int showborder         = 1;        /* 0 means no border */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "3270Medium Nerd Font:size=14" };
static const char dmenufont[]       = "3270Medium Nerd Font:size=14";
static const char col_black[]       = "#242424";
static const char col_yellow[]      = "#ffff7a";
static const char col_cyan[]        = "#00d1d1";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_yellow, col_black, col_black },
	[SchemeSel]  = { col_cyan, col_black,  col_yellow  },
};


/* icons */
static const char *tags[] = {"", "ﬥ", "爵", "璉", "ﳲ", "", "", "", "ﴠ"};

/* first element is for all-tag view */
static int defaultlayouts[1 + LENGTH(tags)]  = { 0, 0, 0, 0, 0, 0, 0, 3, 4, 2};

//use: xprop
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class             instance    			title       tags mask     switchtotag     isfloating   monitor */
	{ "firefox",         NULL,       			NULL,       1 << 2,       1,              0,           -1 },
	{ "Code",            "code",     			NULL,       1 << 1,       1,		      0,           -1 },
	{ "DBeaver",         NULL,       			NULL,       1 << 3,       1,		      0,           -1 },
	{ "vncviewer",       NULL,       			NULL,       1 << 4,       1,	   	 	  0,           -1 },
	{ "Spotify", 		 "spotify",				NULL,       1 << 4,       1, 			  0,           -1 },
	{ "mpv",             NULL,       			NULL,       1 << 4,       1,  			  0,           -1 },
	{ "Steam",           NULL,       			NULL,       1 << 5,       1, 			  0,           -1 },
	{ "Dwarf_Fortress",  "Dwarf_Fortress",      NULL,       1 << 5,       1, 			  0,            1 },
	{ "dwarftherapist",  "dwarftherapist",      NULL,       1 << 5,       1, 			  0,            2 },
    { "Alacritty",       "games",           	NULL,       1 << 5,       1, 			  0,           -1 },
	{ "calendar",        NULL,       			NULL,       1 << 7,       1,  			  0,           -1 },
	{ "Alacritty",       "news",  				NULL,       1 << 8,       0,  			  0,           -1 },
	{ "Alacritty",       "radio",       		NULL,       1 << 4,       1,  			  0,           -1 },
	{ "Alacritty", 		 "newsboat-player",   	NULL,       1 << 4,       1,  			  0,           -1 },
	{ "Alacritty",       "pi",   				NULL,       1 << 6,       1,  			  0,           -1 },
	{ "Alacritty",       "investment",   		NULL,       1 << 7,       0,  			  0,           -1 },
};

/* layout(s) */
static const float mfact     	= 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster    	= 1;    /* number of clients in master area */
static const int resizehints 	= 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "侀",      tile },    /* first entry is default */
	{ "恵",      monocle },
	{ "﩯",      grid },
	{ "充",      bstack },
	{ "",      NULL },    /* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,            	KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* dwmblocks definitions */
#define STATUSBAR "dwmblocks"

/* shiftview patch */
#include "shiftview.c"

/* commands */
static char dmenumon[2] 				= "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]			= { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_yellow, "-sb", col_black, "-sf", col_cyan, NULL };
static const char *dmenukillcmd[]		= { "dmenu_kill",NULL };
static const char *termcmd[]  			= { "alacritty", NULL };

/* scripts commands */
static const char *volup[]  			= { "dwm_vol","up", NULL };
static const char *voldown[]  			= { "dwm_vol","down", NULL };
static const char *volvol[]  			= { "dwm_vol","vol", NULL };
static const char *volmic[]  			= { "dwm_vol","mic", NULL };
static const char *brightnessup[]  		= { "dwm_brightness","+10", NULL };
static const char *brightnessdown[]  	= { "dwm_brightness","-10", NULL };
static const char *powershutdown[]  	= { "dwm_power","shutdown", NULL };
static const char *powerreboot[]  		= { "dwm_power","reboot", NULL };
static const char *screens[]  			= { "dwm_screens", NULL };
static const char *media[]  			= { "dmenu_media", NULL };
static const char *games[]  			= { "dmenu_games", NULL };
static const char *togglelanguage[]  	= { "dwm_toggle_language", NULL };

/* application commands */
static const char *firefox[]  			= { "firefox", NULL };
static const char *firefoxtab[]  		= { "firefox","--new-tab", "duckduckgo.com", NULL };
static const char *flameshot[]  		= { "flameshot","gui", NULL };
static const char *slock[]  			= { "sudo","slock", NULL };


static Key keys[] = {
	/* modifier                         key               function        argument */
	{ MODKEY,                       XK_p,           spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_k,           spawn,          {.v = dmenukillcmd } },
	{ MODKEY|ShiftMask,      		XK_Return, 		spawn,          {.v = termcmd } },
    { MODKEY,                       XK_s,           rotatestack,   	{.i = +1 } },
	{ MODKEY,                       XK_a,           rotatestack,  	{.i = -1 } },
	{ MODKEY,                       XK_period,  	shiftview,      {.i = +1 } },
	{ MODKEY,                       XK_comma, 		shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_b,           togglebar,      {0} },
	{ MODKEY|ShiftMask,         	XK_b,   		toggleborder,   {0} },
    { MODKEY,                       XK_e,           focusstack,     {.i = +1 } },
    { MODKEY,                       XK_w,           focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,      		XK_e,           incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,      		XK_w,           incnmaster,     {.i = -1 } },	
	{ MODKEY|ShiftMask,    			XK_comma,  		setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,     		XK_period, 	    setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,     		XK_c,           killclient,     {0} },
	{ MODKEY,  					    XK_q,           cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,  			XK_q,           resetlayout,    {0} },
	{ MODKEY,                       XK_minus,     	focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_plus,        focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,      		XK_minus,     	tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,      		XK_plus,        tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_l,           quit,           {0} },
	{ MODKEY,             			XK_l,           spawn,          {.v = slock }},
	{ MODKEY,                       XK_Tab,         view,           {0} },
	{ MODKEY,                       XK_0,           view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,    		  	XK_0,           tag,            {.ui = ~0 } },	
	{ MODKEY,                       XK_Return,      zoom,           {0} },
	{ MODKEY,                       XK_space,     	spawn,          {.v = togglelanguage }},
	{ MODKEY,                       XK_f,           spawn,          {.v = firefoxtab }},
	{ MODKEY|ShiftMask,             XK_f,           spawn,          {.v = firefox }},
	{ MODKEY,			      		XK_m,           spawn,          {.v = media }},
	{ MODKEY,			      		XK_g,           spawn,          {.v = games }},
	{ MODKEY,                       XK_F3,          spawn,          {.v = screens }},
	{ MODKEY|ShiftMask,      		XK_z,           spawn,          {.v = powerreboot }},
	{ MODKEY|ShiftMask,      		XK_x,           spawn,          {.v = powershutdown }},
	{ MODKEY,                       XK_F7,          spawn,          {.v = brightnessdown }},
	{ MODKEY,                       XK_F8,          spawn,          {.v = brightnessup }},
	{ MODKEY,                       XK_F10,         spawn,          {.v = volvol }},
	{ MODKEY|ShiftMask,     		XK_F10,         spawn,          {.v = volmic }},
	{ MODKEY,                       XK_F11,         spawn, 		    {.v = voldown }},
	{ MODKEY,                       XK_F12,         spawn, 		    {.v = volup }},
	{ NULL,                         XK_Print,       spawn,          {.v = flameshot }},
	TAGKEYS(                        XK_1,           0)
	TAGKEYS(                        XK_2,           1)
	TAGKEYS(                        XK_3,           2)
	TAGKEYS(                        XK_4,           3)
	TAGKEYS(                        XK_5,           4)
	TAGKEYS(                        XK_6,           5)
	TAGKEYS(                        XK_7,           6)
	TAGKEYS(                        XK_8,           7)
	TAGKEYS(                        XK_9,           8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkClientWin,         MODKEY,			Button1,        movemouse,   	{0} },
	{ ClkClientWin,         MODKEY, 		Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY, 		Button3,        resizemouse,  	{0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,       		Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY, 		Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY, 		Button3,        toggletag,      {0} },
};
