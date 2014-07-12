
#######################################
# LibSphero
#######################################

#######################################
# Project
#######################################

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(libsphero)

SET(PROJECT_SOURCE_DIR ${LibSphero_SOURCE_DIR})

SET(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++0x")

INCLUDE_DIRECTORIES(include)

SET(SOURCE_FILE_LIST
	${PROJECT_SOURCE_DIR}/src/CommandMessage.cpp
	${PROJECT_SOURCE_DIR}/src/ResponseMessage.cpp
	${PROJECT_SOURCE_DIR}/src/Robot.cpp
	${PROJECT_SOURCE_DIR}/src/Macro.cpp
	)

ADD_LIBRARY(
	Sphero
	SHARED
	${SOURCE_FILE_LIST}
	)

TARGET_LINK_LIBRARIES(
	Sphero
	bluetooth
)

FIND_PACKAGE(catkin)
IF(catkin_FOUND)
catkin_package(
	INCLUDE_DIRS include
	LIBRARIES Sphero
	)

ENDIF(catkin_FOUND)

INSTALL_TARGETS(/lib Sphero)
INSTALL_FILES(/include include/libSphero.h)

