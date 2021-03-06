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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/9c184221/Func-Ex-Preg01.o \
	${OBJECTDIR}/_ext/9c184221/Func-Ex-Preg02.o \
	${OBJECTDIR}/_ext/9c184222/Func-Ex-Preg03.o \
	${OBJECTDIR}/main.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/examen-preg-03.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/examen-preg-03.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/examen-preg-03 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/9c184221/Func-Ex-Preg01.o: /C/Users/La\ Rosa/Desktop/LP1/Parcial/2018-2/Examen-Preg-02/Func-Ex-Preg01.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/9c184221
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9c184221/Func-Ex-Preg01.o /C/Users/La\ Rosa/Desktop/LP1/Parcial/2018-2/Examen-Preg-02/Func-Ex-Preg01.cpp

${OBJECTDIR}/_ext/9c184221/Func-Ex-Preg02.o: /C/Users/La\ Rosa/Desktop/LP1/Parcial/2018-2/Examen-Preg-02/Func-Ex-Preg02.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/9c184221
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9c184221/Func-Ex-Preg02.o /C/Users/La\ Rosa/Desktop/LP1/Parcial/2018-2/Examen-Preg-02/Func-Ex-Preg02.cpp

${OBJECTDIR}/_ext/9c184222/Func-Ex-Preg03.o: /C/Users/La\ Rosa/Desktop/LP1/Parcial/2018-2/Examen-Preg-03/Func-Ex-Preg03.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/9c184222
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/9c184222/Func-Ex-Preg03.o /C/Users/La\ Rosa/Desktop/LP1/Parcial/2018-2/Examen-Preg-03/Func-Ex-Preg03.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

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
