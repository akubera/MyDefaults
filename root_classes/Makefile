#
# Makefile
#
# Generic makefile for compiling root classes
#
# Assumes all source and header files are in one directory and each class is defined in a
# a source and header file with the same name as the class.
#
# Only pairs headers and sources. If a source depends on multiple headers, and one of the 
# headers change, the code MAY not build. Fixed with a `make clean all`
#

ROOTCINT ?= rootcint
ROOTCONFIG ?= root-config
CXX = $(shell ${ROOTCONFIG} --cxx)
CFLAGS = -Wall -fPIC $(shell ${ROOTCONFIG} --cflags)
ROOTLIBS = $(shell ${ROOTCONFIG} --libs)

RM = rm -vf

####################
#
# The classes - source and header filenames will be generated from these
#
#####
CLASSNAMES = Test1 Test2

##########
#
# The shared object library containing your classes
#
OUTPUT_LIBRARY = MyLib.so

## directory containing sources
SRC_PREFIX = src/
BUILD_PREFIX = build/

HEADER_SUFFIX = .h
SRC_SUFFIX = .cxx

HEADERS = $(addprefix ${SRC_PREFIX}, $(addsuffix ${HEADER_SUFFIX}, ${CLASSNAMES})) 
SRCS = $(addprefix ${SRC_PREFIX}, $(addsuffix ${SRC_SUFFIX}, ${CLASSNAMES})) 
OBJS = $(addprefix ${BUILD_PREFIX}, $(addsuffix .o, ${CLASSNAMES}))

LIBS = ${ROOTLIBS}

GENRDICT = generated_root_dict.C

all: ${OUTPUT_LIBRARY}

${OUTPUT_LIBRARY}: ${GENRDICT} ${OBJS}
	${CXX} ${CFLAGS} ${GENRDICT} -c -o generated_library.o
	${CXX} ${CFLAGS} -shared generated_library.o ${OBJS} -o $@ ${LIBS}

${BUILD_PREFIX}%.o: ${SRC_PREFIX}%${SRC_SUFFIX} ${SRC_PREFIX}%${HEADER_SUFFIX}
	${CXX} ${CFLAGS} -c $< -o $@

${GENRDICT}: ${HEADERS}
	${ROOTCINT} -f $@ -c ${HEADERS}


clean:
	${RM} ${BUILD}*.o
	${RM} *.so
	${RM} ${GENRDICT} *.pcm
