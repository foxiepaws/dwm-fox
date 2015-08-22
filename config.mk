# dwm version
VERSION = 6.0

# Customize below to fit your system

# paths
PREFIX = /usr/home/allie
MANPREFIX = ${PREFIX}/.share/man


BINDIR=.bin


#X11INC = /usr/X11R6/include
#X11LIB = /usr/X11R6/lib
X11INC = /usr/local/include
X11LIB = /usr/local/lib

#X11INC = /usr/include/X11
#X11LIB = /usr/lib/X11

# Xinerama
XINERAMALIBS = -L${X11LIB} -lXinerama
XINERAMAFLAGS = -DXINERAMA

# enable transparency.
DEFINES =  -DWITH_OPACITY
DEFINES += -DVERSION=\"${VERSION}\"
DEFINES += -DWITH_PANGO

# Xft
#XFTINCS = -I${X11INC}/freetype2 -I/usr/include/freetype2
#XFTLIBS = -L${X11LIB} -lXft
XFTINCS = `pkg-config --cflags xft`
XFTLIBS = `pkg-config --libs xft`

# pango libs
PANGOINCS = `pkg-config --cflags pango pangoxft`
PANGOLIBS = `pkg-config --libs pango pangoxft`

#includes and libs
INCS = -I. -I/usr/include -I${X11INC} ${XFTINCS} ${PANGOINCS}
LIBS = -L/usr/lib -lc -L${X11LIB} -lX11 ${XINERAMALIBS} ${XFTLIBS} ${PANGOLIBS}

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
CC ?= cc 

