cmake_minimum_required(VERSION 2.6)
project(EventHorizon)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extra/cmake")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/game")
set(EXTRAS_LIB "${CMAKE_SOURCE_DIR}/extra")
set(GOOGLETEST "${EXTRAS_LIB}/googletest")

###########################################################################
# Visual studio is really "special"
###########################################################################
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Bin )
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Bin )
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Bin )

###########################################################################
# Boost special settings (use OgreSDK if on Windows)
###########################################################################
set(BOOST_COMPONENTS thread date_time)

###########################################################################
# Ogre and other required friends
###########################################################################
find_package(OpenGL REQUIRED)
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)
