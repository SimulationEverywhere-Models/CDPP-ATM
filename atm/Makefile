.SUFFIXES : .cpp .o .c .y

CPP=g++
CC=gcc
AR=ar
YACPP=yacc

DEFINES_CPP=
# Optimized Code - Requires more virtual memory.
OPTCPPFLAGS=-O3

# Not optimized
#OPTCPPFLAGS=

# gcc < 2.8.x 
#DEFINES_CPP=-D_G_NO_EXTERN_TEMPLATES
#CPPFLAGS=-fhandle-exceptions 

# gcc 2.8.x (y superiores):

# Ver warnings:
#CPPFLAGS += -Wall
# Ignorar warnings:
CPPFLAGS += -w

# Include information for GDB:
#CPPFLAGS += -g

# The next flag must be actived ONLY if we are compiling under Windows 95 !!!!
#CPPFLAGS += -D__WINDOWS__

DEFINES_C=

# If we are compiling for Unix
INCLUDES_CPP=-I/usr/include
# or if we are compiling for Windows 95
#INCLUDES_CPP=

INCLUDES_C=
CFLAGS=
DEBUGFLAGS=
LDFLAGS+=-L. -g
#^|
EXAMPLESOBJS=  Balanceverifier.o CardReader.o UserInterface.o cashdispenser.o pinverifier.o register.o queue.o main.o generat.o cpu.o transduc.o distri.o com.o linpack.o debug.o trafico.o
#

LIBNAME=simu
LIBS=-lsimu
ALLOBJS= ${EXAMPLESOBJS} ${SIMOBJS} 
INIOBJS=initest.o ini.o
ALLSRCS=${ALLOBJS:.o=.cpp} gram.y 

all: simu libs

libs: libsimu.a

simu: ${ALLOBJS} 
	g++ ${LDFLAGS} -o $@ ${EXAMPLESOBJS} ${LIBS}

initest: ${INIOBJS} 
	${CPP} ${LDFLAGS} -o $@ ${INIOBJS} 

drawlog: drawlog.o libsimu.a
	g++ ${LDFLAGS} -o $@ drawlog.o ${LIBS}

makerand: makerand.o libsimu.a
	g++ ${LDFLAGS} -o $@ makerand.o ${LIBS}

toMap: toMap.o libsimu.a
	g++ ${LDFLAGS} -o $@ toMap.o ${LIBS}

toCDPP: toCDPP.o libsimu.a
	g++ ${LDFLAGS} -o $@ toCDPP.o ${LIBS}

randEvent: randEvent.o libsimu.a
	g++ ${LDFLAGS} -o $@ randEvent.o ${EXAMPLESOBJS} ${LIBS}

exptest: synnode.o
	g++ ${LDFLAGS} -o $@ synnode.o
	
parser: parser.o gram.o
	g++ ${LDFLAGS} -o $@ parser.o gram.o

libsimu.a: ${SIMOBJS}
	${AR} crs lib${LIBNAME}.a ${SIMOBJS}

clean:
	- rm -f *.o *.a simu core drawlog initest exptest parser makerand toMap

depend:
	makedepend -Y ${ALLSRCS}

backup:
	tar -cvf simu.tar *.cpp *.h *.c *.y makefile* *.ma *.ev *.vpj *.bat *.txt *.val *.inc *.map; gzip simu.tar; mv simu.tar.gz simu.tgz

# Without Optimization
.cpp.o:
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<
#^|
Balanceverifier.o: /cygdrive/C/eclipse/workspace/a/atm/Balanceverifier.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $< 
CardReader.o: /cygdrive/C/eclipse/workspace/a/atm/CardReader.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $< 
UserInterface.o: /cygdrive/C/eclipse/workspace/a/atm/UserInterface.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $< 
cashdispenser.o: /cygdrive/C/eclipse/workspace/a/atm/cashdispenser.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $< 
pinverifier.o: /cygdrive/C/eclipse/workspace/a/atm/pinverifier.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $< 
register.o: /cygdrive/C/eclipse/workspace/a/atm/register.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $< 
#
generat.o: generat.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

queue.o: queue.cpp
	${CPP} -c ${LDFLAGS} ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

cpu.o: cpu.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

transduc.o: transduc.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

trafico.o: trafico.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

#register.o: register.cpp
#	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

msgadm.o: msgadm.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

root.o: root.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

parser.o: parser.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

main.o: main.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

drawlog.o: drawlog.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

toMap.o: toMap.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

toCDPP.o: toCDPP.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

makerand.o: makerand.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

mainsimu.o: mainsimu.cpp
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<

# Uncomment these lines only for Windows
#macroexp.o: macroexp.cpp
#	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<
#
#flatcoup.o: flatcoup.cpp
#	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} $<
#

.cpp.o:
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} ${OPTCPPFLAGS} $<

.c.o:
	${CC} -c ${INCLUDES_C} ${DEFINES_C}  ${DEBUGFLAGS} ${CFLAGS} ${OPTCPPFLAGS} $<

.y.o:
	bison -d -v -o gram.c gram.y
	${CPP} -c ${INCLUDES_CPP} ${DEFINES_CPP} ${DEBUGFLAGS} ${CPPFLAGS} ${OPTCPPFLAGS} ${@:.o=.c} 
	rm $*.c
	
# DO NOT DELETE
#^|
Balanceverifier.o: \
 /cygdrive/C/eclipse/workspace/a/atm/Balanceverifier.cpp \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/randlib.h \
 /cygdrive/C/eclipse/workspace/a/atm/Balanceverifier.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/atomic.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/model.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/port.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modelid.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/time.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/portlist.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/real.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/undefd.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/impresion.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/tbool.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/except.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/stringp.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/value.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/evaldeb.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cellpos.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ntupla.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/procadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/process.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/message.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/strutil.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/distri.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/mainsimu.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/root.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/event.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ini.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/loader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ltranadm.h
CardReader.o: /cygdrive/C/eclipse/workspace/a/atm/CardReader.cpp \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/randlib.h \
 /cygdrive/C/eclipse/workspace/a/atm/CardReader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/atomic.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/model.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/port.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modelid.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/time.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/portlist.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/real.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/undefd.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/impresion.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/tbool.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/except.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/stringp.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/value.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/evaldeb.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cellpos.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ntupla.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/procadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/process.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/message.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/strutil.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/distri.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/mainsimu.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/root.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/event.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ini.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/loader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ltranadm.h
UserInterface.o: /cygdrive/C/eclipse/workspace/a/atm/UserInterface.cpp \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/randlib.h \
 /cygdrive/C/eclipse/workspace/a/atm/UserInterface.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/atomic.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/model.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/port.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modelid.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/time.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/portlist.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/real.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/undefd.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/impresion.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/tbool.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/except.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/stringp.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/value.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/evaldeb.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cellpos.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ntupla.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/procadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/process.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/message.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/strutil.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/distri.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/mainsimu.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/root.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/event.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ini.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/loader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ltranadm.h
cashdispenser.o: /cygdrive/C/eclipse/workspace/a/atm/cashdispenser.cpp \
 /cygdrive/C/eclipse/workspace/a/atm/cashdispenser.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/atomic.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/model.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/port.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modelid.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/time.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/portlist.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/real.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/undefd.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/impresion.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/tbool.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/except.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/stringp.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/value.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/evaldeb.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cellpos.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ntupla.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/procadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/process.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/message.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/strutil.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/distri.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/mainsimu.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/root.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/event.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ini.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/loader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ltranadm.h
pinverifier.o: /cygdrive/C/eclipse/workspace/a/atm/pinverifier.cpp \
 /cygdrive/C/eclipse/workspace/a/atm/PINverifier.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/atomic.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/model.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/port.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modelid.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/time.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/portlist.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/real.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/undefd.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/impresion.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/tbool.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/except.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/stringp.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/value.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/evaldeb.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cellpos.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ntupla.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/procadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/process.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/message.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/strutil.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/distri.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/mainsimu.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/root.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/event.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ini.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/loader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ltranadm.h
register.o: /cygdrive/C/eclipse/workspace/a/atm/register.cpp \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modeladm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/mainsimu.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/root.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/event.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/time.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/real.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/undefd.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/impresion.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/tbool.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/except.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/stringp.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/value.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/evaldeb.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/port.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/modelid.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/process.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/procadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ini.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/loader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ltranadm.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cellpos.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/ntupla.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/portlist.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/model.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/queue.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/atomic.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/generat.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/cpu.h \
 /cygdrive/C/eclipse/workspace/a/atm/Cashdispenser.h \
 /cygdrive/C/eclipse/workspace/a/atm/Balanceverifier.h \
 /cygdrive/C/eclipse/workspace/a/atm/pinverifier.h \
 /cygdrive/C/eclipse/workspace/a/atm/UserInterface.h \
 /cygdrive/C/eclipse/workspace/a/atm/CardReader.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/transduc.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/message.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/strutil.h \
 /cygdrive/C/eclipse/plugins/CD++Builder_1.1.0/internal/trafico.h
#
#include $(OBJS:.cpp=.d)
queue.o: queue.h atomic.h model.h port.h modelid.h time.h portlist.h real.h
queue.o: undefd.h impresion.h tbool.h except.h stringp.h value.h evaldeb.h
queue.o: cellpos.h ntupla.h procadm.h process.h message.h strutil.h
queue.o: mainsimu.h root.h event.h ini.h loader.h ltranadm.h
main.o: stdaload.h loader.h time.h evaldeb.h macroexp.h except.h stringp.h
main.o: netload.h mainsimu.h root.h event.h real.h undefd.h impresion.h
main.o: tbool.h value.h port.h modelid.h process.h procadm.h ini.h ltranadm.h
main.o: cellpos.h ntupla.h portlist.h model.h
generat.o: generat.h atomic.h model.h port.h modelid.h time.h portlist.h
generat.o: real.h undefd.h impresion.h tbool.h except.h stringp.h value.h
generat.o: evaldeb.h cellpos.h ntupla.h procadm.h process.h message.h
generat.o: strutil.h mainsimu.h root.h event.h ini.h loader.h ltranadm.h
generat.o: distri.h
cpu.o: cpu.h atomic.h model.h port.h modelid.h time.h portlist.h real.h
cpu.o: undefd.h impresion.h tbool.h except.h stringp.h value.h evaldeb.h
cpu.o: cellpos.h ntupla.h procadm.h process.h message.h strutil.h distri.h
cpu.o: mainsimu.h root.h event.h ini.h loader.h ltranadm.h
transduc.o: transduc.h atomic.h model.h port.h modelid.h time.h portlist.h
transduc.o: real.h undefd.h impresion.h tbool.h except.h stringp.h value.h
transduc.o: evaldeb.h cellpos.h ntupla.h procadm.h process.h message.h
transduc.o: strutil.h mainsimu.h root.h event.h ini.h loader.h ltranadm.h
trafico.o: time.h trafico.h atomic.h model.h port.h modelid.h portlist.h
trafico.o: real.h undefd.h impresion.h tbool.h except.h stringp.h value.h
trafico.o: evaldeb.h cellpos.h ntupla.h procadm.h process.h message.h
trafico.o: strutil.h
distri.o: time.h distri.h except.h stringp.h strutil.h real.h undefd.h
distri.o: impresion.h tbool.h value.h evaldeb.h
debug.o: debug.h tdcell.h atomcell.h portlist.h real.h undefd.h impresion.h
debug.o: tbool.h except.h stringp.h value.h evaldeb.h port.h modelid.h
debug.o: cellpos.h ntupla.h atomic.h model.h time.h procadm.h process.h
debug.o: neighval.h mylist.h coupcell.h coupled.h ltranadm.h cellstate.h
#register.o: modeladm.h mainsimu.h root.h event.h time.h real.h undefd.h
#register.o: impresion.h tbool.h except.h stringp.h value.h evaldeb.h port.h
#register.o: modelid.h process.h procadm.h ini.h loader.h ltranadm.h cellpos.h
#register.o: ntupla.h portlist.h model.h queue.h atomic.h generat.h cpu.h
#register.o: transduc.h message.h strutil.h trafico.h
neighval.o: neighval.h mylist.h real.h undefd.h impresion.h tbool.h except.h
neighval.o: stringp.h value.h evaldeb.h cellpos.h ntupla.h coupcell.h
neighval.o: coupled.h model.h port.h modelid.h time.h portlist.h procadm.h
neighval.o: process.h ltranadm.h cellstate.h
macroexp.o: macroexp.h except.h stringp.h strutil.h real.h undefd.h
macroexp.o: impresion.h tbool.h value.h evaldeb.h
evaldeb.o: evaldeb.h
zone.o: zone.h cellpos.h ntupla.h except.h stringp.h
except.o: except.h stringp.h macroexp.h
strutil.o: strutil.h real.h undefd.h impresion.h tbool.h except.h stringp.h
strutil.o: value.h evaldeb.h
flatcoup.o: flatcoup.h coupcell.h coupled.h model.h port.h modelid.h time.h
flatcoup.o: portlist.h real.h undefd.h impresion.h tbool.h except.h stringp.h
flatcoup.o: value.h evaldeb.h cellpos.h ntupla.h procadm.h process.h
flatcoup.o: ltranadm.h cellstate.h neighval.h mylist.h strutil.h realfunc.h
flatcoor.o: flatcoor.h coordin.h process.h modelid.h time.h except.h
flatcoor.o: stringp.h value.h flatcoup.h coupcell.h coupled.h model.h port.h
flatcoor.o: portlist.h real.h undefd.h impresion.h tbool.h evaldeb.h
flatcoor.o: cellpos.h ntupla.h procadm.h ltranadm.h msgadm.h message.h
flatcoor.o: strutil.h cellstate.h
ntupla.o: ntupla.h except.h stringp.h strutil.h real.h undefd.h impresion.h
ntupla.o: tbool.h value.h evaldeb.h
cellstate.o: cellstate.h cellpos.h ntupla.h except.h stringp.h real.h
cellstate.o: undefd.h impresion.h tbool.h value.h evaldeb.h
undefd.o: undefd.h
atomic.o: atomic.h model.h port.h modelid.h time.h portlist.h real.h undefd.h
atomic.o: impresion.h tbool.h except.h stringp.h value.h evaldeb.h cellpos.h
atomic.o: ntupla.h procadm.h process.h
coupled.o: coupled.h model.h port.h modelid.h time.h portlist.h real.h
coupled.o: undefd.h impresion.h tbool.h except.h stringp.h value.h evaldeb.h
coupled.o: cellpos.h ntupla.h procadm.h process.h
model.o: model.h port.h modelid.h time.h portlist.h real.h undefd.h
model.o: impresion.h tbool.h except.h stringp.h value.h evaldeb.h cellpos.h
model.o: ntupla.h procadm.h process.h strutil.h
modeladm.o: modeladm.h procadm.h process.h modelid.h time.h except.h
modeladm.o: stringp.h value.h strutil.h real.h undefd.h impresion.h tbool.h
modeladm.o: evaldeb.h idcell.h atomcell.h portlist.h port.h cellpos.h
modeladm.o: ntupla.h atomic.h model.h neighval.h mylist.h coupcell.h
modeladm.o: coupled.h ltranadm.h tdcell.h flatcoup.h
msgadm.o: msgadm.h message.h time.h value.h process.h modelid.h except.h
msgadm.o: stringp.h procadm.h port.h strutil.h real.h undefd.h impresion.h
msgadm.o: tbool.h evaldeb.h mainsimu.h root.h event.h ini.h loader.h
msgadm.o: ltranadm.h cellpos.h ntupla.h portlist.h model.h
real.o: real.h undefd.h impresion.h tbool.h except.h stringp.h value.h
real.o: evaldeb.h realprec.h mathincl.h
realfunc.o: realfunc.h real.h undefd.h impresion.h tbool.h except.h stringp.h
realfunc.o: value.h evaldeb.h mathincl.h
realprec.o: realprec.h value.h
impresion.o: impresion.h
port.o: port.h modelid.h
root.o: evaldeb.h root.h event.h time.h real.h undefd.h impresion.h tbool.h
root.o: except.h stringp.h value.h port.h modelid.h process.h procadm.h
root.o: msgadm.h message.h strutil.h modeladm.h coupled.h model.h portlist.h
root.o: cellpos.h ntupla.h mainsimu.h ini.h loader.h ltranadm.h
time.o: time.h stringp.h
ini.o: ini.h except.h stringp.h strutil.h real.h undefd.h impresion.h tbool.h
ini.o: value.h evaldeb.h prnutil.h
mainsimu.o: mainsimu.h root.h event.h time.h real.h undefd.h impresion.h
mainsimu.o: tbool.h except.h stringp.h value.h evaldeb.h port.h modelid.h
mainsimu.o: process.h procadm.h ini.h loader.h ltranadm.h cellpos.h ntupla.h
mainsimu.o: portlist.h model.h modeladm.h strutil.h coupled.h zone.h
mainsimu.o: flatcoup.h coupcell.h tdcell.h atomcell.h atomic.h neighval.h
mainsimu.o: mylist.h idcell.h
stdaload.o: time.h stdaload.h loader.h evaldeb.h macroexp.h except.h
stdaload.o: stringp.h realprec.h value.h impresion.h distri.h
process.o: process.h modelid.h time.h except.h stringp.h value.h model.h
process.o: port.h portlist.h real.h undefd.h impresion.h tbool.h evaldeb.h
process.o: cellpos.h ntupla.h procadm.h msgadm.h message.h strutil.h
procadm.o: procadm.h process.h modelid.h time.h except.h stringp.h value.h
procadm.o: simulat.h coordin.h strutil.h real.h undefd.h impresion.h tbool.h
procadm.o: evaldeb.h root.h event.h port.h coorcell.h flatcoor.h flatcoup.h
procadm.o: coupcell.h coupled.h model.h portlist.h cellpos.h ntupla.h
procadm.o: ltranadm.h
simulat.o: simulat.h process.h modelid.h time.h except.h stringp.h value.h
simulat.o: atomic.h model.h port.h portlist.h real.h undefd.h impresion.h
simulat.o: tbool.h evaldeb.h cellpos.h ntupla.h procadm.h message.h strutil.h
simulat.o: msgadm.h
portlist.o: portlist.h real.h undefd.h impresion.h tbool.h except.h stringp.h
portlist.o: value.h evaldeb.h port.h modelid.h cellpos.h ntupla.h
coordin.o: coordin.h process.h modelid.h time.h except.h stringp.h value.h
coordin.o: msgadm.h message.h procadm.h port.h strutil.h real.h undefd.h
coordin.o: impresion.h tbool.h evaldeb.h coupled.h model.h portlist.h
coordin.o: cellpos.h ntupla.h
atomcell.o: atomcell.h portlist.h real.h undefd.h impresion.h tbool.h
atomcell.o: except.h stringp.h value.h evaldeb.h port.h modelid.h cellpos.h
atomcell.o: ntupla.h atomic.h model.h time.h procadm.h process.h neighval.h
atomcell.o: mylist.h coupcell.h coupled.h ltranadm.h message.h strutil.h
tdcell.o: tdcell.h atomcell.h portlist.h real.h undefd.h impresion.h tbool.h
tdcell.o: except.h stringp.h value.h evaldeb.h port.h modelid.h cellpos.h
tdcell.o: ntupla.h atomic.h model.h time.h procadm.h process.h neighval.h
tdcell.o: mylist.h coupcell.h coupled.h ltranadm.h message.h strutil.h
tdcell.o: realfunc.h
idcell.o: idcell.h atomcell.h portlist.h real.h undefd.h impresion.h tbool.h
idcell.o: except.h stringp.h value.h evaldeb.h port.h modelid.h cellpos.h
idcell.o: ntupla.h atomic.h model.h time.h procadm.h process.h neighval.h
idcell.o: mylist.h coupcell.h coupled.h ltranadm.h message.h strutil.h
idcell.o: realfunc.h
ltranadm.o: ltranadm.h cellpos.h ntupla.h except.h stringp.h portlist.h
ltranadm.o: real.h undefd.h impresion.h tbool.h value.h evaldeb.h port.h
ltranadm.o: modelid.h time.h model.h procadm.h process.h parser.h neighval.h
ltranadm.o: mylist.h coupcell.h coupled.h strutil.h synnode.h realfunc.h
coupcell.o: coupcell.h coupled.h model.h port.h modelid.h time.h portlist.h
coupcell.o: real.h undefd.h impresion.h tbool.h except.h stringp.h value.h
coupcell.o: evaldeb.h cellpos.h ntupla.h procadm.h process.h ltranadm.h
coupcell.o: cellstate.h strutil.h atomcell.h atomic.h neighval.h mylist.h
coupcell.o: modeladm.h
coorcell.o: coorcell.h coordin.h process.h modelid.h time.h except.h
coorcell.o: stringp.h value.h coupcell.h coupled.h model.h port.h portlist.h
coorcell.o: real.h undefd.h impresion.h tbool.h evaldeb.h cellpos.h ntupla.h
coorcell.o: procadm.h ltranadm.h msgadm.h message.h strutil.h
synnode.o: synnode.h tbool.h except.h stringp.h real.h undefd.h impresion.h
synnode.o: value.h evaldeb.h realfunc.h ltranadm.h cellpos.h ntupla.h
synnode.o: portlist.h port.h modelid.h time.h model.h procadm.h process.h
synnode.o: neighval.h mylist.h coupcell.h coupled.h atomcell.h atomic.h
tbool.o: tbool.h except.h stringp.h real.h undefd.h impresion.h value.h
tbool.o: evaldeb.h
parser.o: parser.h except.h stringp.h synnode.h tbool.h real.h undefd.h
parser.o: impresion.h value.h evaldeb.h realfunc.h ltranadm.h cellpos.h
parser.o: ntupla.h portlist.h port.h modelid.h time.h model.h procadm.h
parser.o: process.h gram.h strutil.h mathincl.h
netload.o: netload.h loader.h time.h evaldeb.h bsdchann.h commchan.h except.h
netload.o: stringp.h
bsdchann.o: bsdchann.h commchan.h except.h stringp.h
gram.o: synnode.h tbool.h except.h stringp.h real.h undefd.h impresion.h
gram.o: value.h evaldeb.h realfunc.h ltranadm.h cellpos.h ntupla.h portlist.h
gram.o: port.h modelid.h time.h model.h procadm.h process.h parser.h
	