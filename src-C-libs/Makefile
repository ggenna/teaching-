# default build type
TYPE = debug
#TYPE = release

# default OS
OS = cygwin
#OS = solaris

# OS peculiarities
ifeq ($(OS),solaris)
EXTRALIBS = -lsocket -lnsl -lresolv
endif
ifeq ($(OS),cygwin)
EXTRALIBS =
endif

# defs for production-quality binaries
ifeq ($(TYPE),release)
CFLAGS = -O -Wall -Werror
LDFLAGS = -s $(EXTRALIBS)
endif

# defs for test/debug binaries
ifeq ($(TYPE),debug)
CFLAGS =-Wall -Werror -DTRACE -g
LDFLAGS = $(EXTRALIBS)
endif

# general def's
CC = gcc
LIBS = libpad.a
SOURCES = addtcpc.c addtcpc2.c addtcpc3.c addtcpc4.c addtcps.c addtcps2.c avrfy.c avrfy2.c byteorder.c checkopts.c \
  copyfile.c datasize.c daytimetcpc.c daytimetcps.c daytimeudpc.c daytimeudps.c \
  info_from_a.c info_from_n.c myself.c prallenv.c printevar.c service.c sveglia.c va_test.c
PROGS := $(SOURCES:.c=)

# phony targets

.PHONY: all clean veryclean depend

# general rule (make without any parameter)

all: $(PROGS)

# specific program generation rules

addtcpc: addtcpc.o $(LIBS)
addtcpc2: addtcpc2.o $(LIBS)
addtcpc3: addtcpc3.o $(LIBS)
addtcps: addtcps.o $(LIBS)
avrfy: avrfy.o $(LIBS)
avrfy2: avrfy2.o $(LIBS)
avrfy46: avrfy46.o $(LIBS)
byteorder: byteorder.o
checkopts: checkopts.o $(LIBS)
copyfile: copyfile.o $(LIBS)
datasize: datasize.o
daytimetcpc: daytimetcpc.o $(LIBS)
daytimetcps: daytimetcps.o $(LIBS)
daytimeudpc: daytimeudpc.o $(LIBS)
daytimeudps: daytimeudps.o $(LIBS)
info_from_a: info_from_a.o $(LIBS)
info_from_n: info_from_n.o $(LIBS)
myself: myself.o $(LIBS)
prallenv: prallenv.o
printevar: printevar.o
service: service.o $(LIBS)
sveglia: sveglia.o $(LIBS)
va_test: va_test.o $(LIBS)

# library

libpad.a: libpad.a(errlib.o) libpad.a(sockwrap.o)
	ranlib libpad.a

# misc

clean:
	/bin/rm -f *.o

veryclean:
	/bin/rm -f *.o $(PROGS) *.exe *~

depend:
	rm -f depend.txt
	for f in $(SOURCES); do gcc -MM $$f >> depend.txt; done

# dependencies

-include depend.txt
