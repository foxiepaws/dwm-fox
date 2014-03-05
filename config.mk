# dwm version
VERSION = 6.0

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

#X11INC = /usr/X11R6/include
#X11LIB = /usr/X11R6/lib

X11INC = /usr/local/include
X11LIB = /usr/local/lib

# Xinerama
XINERAMALIBS = -L${X11LIB} -lXinerama
XINERAMAFLAGS = -DXINERAMA


# enable transparency.
DEFINES =  -DWITH_OPACITY
DEFINES += -DVERSION=\"${VERSION}\"

# Xft
 XFTINCS = -I${X11INC}/freetype2
 XFTLIBS = -L${X11LIB} -lXft


#includes and libs
INCS = -I. -I/usr/include -I${X11INC} ${XFTINCS}
LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} ${XFTLIBS}

# flags
CPPFLAGS = ${DEFINES} ${XINERAMAFLAGS}
#CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
#LDFLAGS = -g ${LIBS}
LDFLAGS = -s ${LIBS}

# Solaris
#CFLAGS = -fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS = ${LIBS}

# compiler and linker
CC = cc -E

