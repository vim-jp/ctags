# $Id$
#
# Makefile for Exuberant Ctags under Win32 with MinGW compiler
#

include source.mak

REGEX_DEFINES = -DHAVE_REGCOMP -D__USE_GNU -Dbool=int -Dfalse=0 -Dtrue=1 -Dstrcasecmp=stricmp

CFLAGS = -Wall
DEFINES = -DWIN32 $(REGEX_DEFINES) -DHAVE_ICONV
INCLUDES = -I. -Ignu_regex
CC = gcc
OBJEXT = o
LDFLAGS = -liconv
OBJECTS += $(REGEX_SOURCES:%.c=%.o)

ctags.exe: OPT = -O4
dctags.exe: OPT = -g
dctags.exe: DEBUG = -DDEBUG
dctags.exe: SOURCES += debug.c

.SUFFIXES: .c.o

.c.o:
	$(CC) -c $(OPT) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $<

ctags: ctags.exe

ctags.exe dctags.exe: $(OBJECTS) $(HEADERS) $(REGEX_HEADERS)
	$(CC) $(OPT) $(CFLAGS) $(DEFINES) $(INCLUDES) -o $@ $(OBJECTS) $(LDFLAGS)

readtags.exe: readtags.c
	$(CC) $(OPT) $(CFLAGS) -DREADTAGS_MAIN $(DEFINES) $(INCLUDES) -o $@ $<

clean:
	- rm -f ctags.exe
	- rm -f dctags.exe
	- rm -f tags
	- rm -f *.o
