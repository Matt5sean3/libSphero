
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

SET(PROJECT_SOURCE_DIR ${LibSphero_SOURCE_DIR})

SET(PROJECT_INCLUDE_DIR ${LibSphere_SOURCE_DIR})

SET(PROJECT_LIBRARIES bluetooth)

SET(SOURCE_FILE_LIST
	${PROJECT_SOURCE_DIR}/CommandMessage.cpp
	${PROJECT_SOURCE_DIR}/ResponseMessage.cpp
	${PROJECT_SOURCE_DIR}/Robot.cpp
	${PROJECT_SOURCE_DIR}/Macro.cpp
	)

INCLUDE_DIRECTORIES(${PROJECT_INCLUDE_DIR})

ADD_SUBDIRECTORY(swig)

ADD_LIBRARY(
	Sphero
	SHARED
	${SOURCE_FILE_LIST}
	)

TARGET_LINK_LIBRARIES(
	Sphero
	${PROJECT_LIBRARIES}
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

