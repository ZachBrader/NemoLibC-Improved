#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Graph.o \
	${OBJECTDIR}/NautyLink.o \
	${OBJECTDIR}/RandESU.o \
	${OBJECTDIR}/RandomGraphAnalysis.o \
	${OBJECTDIR}/RandomGraphGenerator.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/nauty/gtools.o \
	${OBJECTDIR}/nauty/naugraph.o \
	${OBJECTDIR}/nauty/naurng.o \
	${OBJECTDIR}/nauty/nausparse.o \
	${OBJECTDIR}/nauty/nautil.o \
	${OBJECTDIR}/nauty/nautinv.o \
	${OBJECTDIR}/nauty/naututil.o \
	${OBJECTDIR}/nauty/nauty.o \
	${OBJECTDIR}/nauty/schreier.o \
	${OBJECTDIR}/nauty/sorttemplates.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nemolib.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nemolib.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nemolib ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Graph.o: Graph.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Graph.o Graph.cpp

${OBJECTDIR}/NautyLink.o: NautyLink.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NautyLink.o NautyLink.cpp

${OBJECTDIR}/RandESU.o: RandESU.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandESU.o RandESU.cpp

${OBJECTDIR}/RandomGraphAnalysis.o: RandomGraphAnalysis.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomGraphAnalysis.o RandomGraphAnalysis.cpp

${OBJECTDIR}/RandomGraphGenerator.o: RandomGraphGenerator.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomGraphGenerator.o RandomGraphGenerator.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/nauty/gtools.o: nauty/gtools.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/gtools.o nauty/gtools.c

${OBJECTDIR}/nauty/naugraph.o: nauty/naugraph.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naugraph.o nauty/naugraph.c

${OBJECTDIR}/nauty/naurng.o: nauty/naurng.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naurng.o nauty/naurng.c

${OBJECTDIR}/nauty/nausparse.o: nauty/nausparse.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nausparse.o nauty/nausparse.c

${OBJECTDIR}/nauty/nautil.o: nauty/nautil.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nautil.o nauty/nautil.c

${OBJECTDIR}/nauty/nautinv.o: nauty/nautinv.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nautinv.o nauty/nautinv.c

${OBJECTDIR}/nauty/naututil.o: nauty/naututil.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/naututil.o nauty/naututil.c

${OBJECTDIR}/nauty/nauty.o: nauty/nauty.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/nauty.o nauty/nauty.c

${OBJECTDIR}/nauty/schreier.o: nauty/schreier.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/schreier.o nauty/schreier.c

${OBJECTDIR}/nauty/sorttemplates.o: nauty/sorttemplates.c
	${MKDIR} -p ${OBJECTDIR}/nauty
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/nauty/sorttemplates.o nauty/sorttemplates.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
