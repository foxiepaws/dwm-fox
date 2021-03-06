/* See LICENSE file for copyright and license details. */

/*+++++++++++
 * appearance 
 */

/* Colours */
static const char normbordercolor[] = "#000000";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#aaaaaa";
static const char selbordercolor[]  = "#000000";
static const char selbgcolor[]      = "#535d6c";
static const char selfgcolor[]      = "#ffffff";

/* font */
static const char font[]            = "Dina 9";
#ifdef WITH_PANGO
static const Bool statusmarkup = True; /* True means use pango markup */
#endif
/* sizes */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 1;       /* snap pixel */

/* opacity settings */
#ifdef WITH_OPACITY
static const double shade           = 1.0;      /* opacity of unfocused clients */
static const double shadebar        = 0.8;      /* opacity of the bar */
#endif 

/* systray settings */
/* #ifdef WITH_SYSTRAY */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
/* #endif */

/* how to show the bar. */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = False;     /* False means bottom bar */

/*--------------
 * end apperance 
 */


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

#ifdef WITH_OPACITY
static const Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor   opacity */
    { "Gimp",     NULL,       NULL,       0,            True,        -1,       -1 },
    { "Firefox",  NULL,       NULL,       1 << 8,       False,       -1,       -1 },
};
#else
static const Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor*/
    { "Gimp",     NULL,       NULL,       0,            True,        -1  },
    { "Firefox",  NULL,       NULL,       1 << 8,       False,       -1  },
};
#endif

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

#include "bstack.c"
#include "bstackhoriz.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "|||",      col },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]
= { "dmenu_run", "-b", "-p", "run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "x-terminal", NULL };
static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[4]} },
    { MODKEY,                       XK_c,      setlayout,      {.v = &layouts[5]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    { MODKEY|Mod1Mask, XK_1 , setlayout, {.v = &layouts[0] } },
    { MODKEY|Mod1Mask, XK_2 , setlayout, {.v = &layouts[1] } },
    { MODKEY|Mod1Mask, XK_3 , setlayout, {.v = &layouts[2] } },
    { MODKEY|Mod1Mask, XK_4 , setlayout, {.v = &layouts[3] } },
    { MODKEY|Mod1Mask, XK_5 , setlayout, {.v = &layouts[4] } },
    { MODKEY|Mod1Mask, XK_6 , setlayout, {.v = &layouts[5] } },

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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
};

