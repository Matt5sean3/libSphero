
SET(BIND_OCTAVE ON)

# Try to find the octave executable
FIND_PROGRAM(OCTAVE_FOUND octave)
IF(NOT OCTAVE_FOUND)
SET(BIND_OCTAVE OFF)
MESSAGE("Could not locate octave executable")
ENDIF(NOT OCTAVE_FOUND)

# Try to find the octave-config executable
FIND_PROGRAM(OCTAVE_CONFIG_FOUND octave-config)
IF(NOT OCTAVE_CONFIG_FOUND)
SET(BIND_OCTAVE OFF)
MESSAGE("Could not locate octave-config executable")
ENDIF(NOT OCTAVE_CONFIG_FOUND)

# Try to find the mkoctfile executable
FIND_PROGRAM(MKOCTFILE_FOUND mkoctfile)
IF(NOT MKOCTFILE_FOUND)
SET(BIND_OCTAVE OFF)
MESSAGE("Could not locate mkoctfile executable")
ENDIF(NOT MKOCTFILE_FOUND)

# Try to find the octave libraries
FIND_LIBRARY(OCTAVE_LIB octave)
IF(NOT OCTAVE_LIB)
SET(BIND_OCTAVE OFF)
MESSAGE("Could not locate octave library")
ENDIF(NOT OCTAVE_LIB)

# Badly hard coded right now
# TODO use system introspection to locate the octave header files
FIND_PATH(OCTAVE_INCLUDE1 NAMES octave/oct.h PATHS /usr/include /usr/include/octave-3.8.1)
FIND_PATH(OCTAVE_INCLUDE2 NAMES oct.h PATHS /usr/include /usr/include/octave-3.8.1/octave)
IF(NOT OCTAVE_INCLUDE1 OR NOT OCTAVE_INCLUDE2)
SET(BIND_OCTAVE OFF)
MESSAGE("Could not locate octave headers")
ENDIF(NOT OCTAVE_INCLUDE1 OR NOT OCTAVE_INCLUDE2)

# Need to run swig more or less manually for this case
# It just doesn't naturally create an oct file
IF(BIND_OCTAVE)
INCLUDE_DIRECTORIES(${OCTAVE_INCLUDE1})
INCLUDE_DIRECTORIES(${OCTAVE_INCLUDE2})
SET_SOURCE_FILES_PROPERTIES(${SWIG_SOURCE_FILE} PROPERTIES CPLUSPLUS ON)
SWIG_ADD_MODULE(octsphero octave ${SWIG_SOURCE_FILE} ${SOURCE_FILE_LIST})
SWIG_LINK_LIBRARIES(octsphero ${PROJECT_LIBRARIES})
MESSAGE(STATUS "Octave bindings will be created")
ELSE(BIND_OCTAVE)
MESSAGE(STATUS "Unable to create Octave bindings")
ENDIF(BIND_OCTAVE)
