cmake_minimum_required(VERSION 2.6)
project(EventHorizon)

#set(PROJECT_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/game")
#set(PROJECT_BINARY_DIR "${CMAKE_SOURCE_DIR}/game")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extra/cmake")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/game")
set(EXTRAS_LIB "${CMAKE_SOURCE_DIR}/extra")
set(GOOGLETEST "${EXTRAS_LIB}/googletest")

set(OGRE_HOME $ENV{OGRE_HOME})


###########################################################################
# Check for library paths, and adjust them as needed
###########################################################################
# Boost paths on Windows
if(WIN32)
	if(DEFINED ENV{BOOST_ROOT})
		set(BOOST_ROOT $ENV{BOOST_ROOT})
	else()
		message("Did not find boost, using builtin Ogre boost")
		set(BOOST_ROOT "${OGRE_HOME}/boost_1_42")
	endif()
endif(WIN32)

###########################################################################
# Boost special settings (use OgreSDK if on Windows)
###########################################################################
if (NOT OGRE_BUILD_PLATFORM_IPHONE)
	if (WIN32 OR APPLE)
		set(Boost_USE_STATIC_LIBS TRUE)
	else ()
		# Statically linking boost to a dynamic Ogre build doesn't work on Linux 64bit
		set(Boost_USE_STATIC_LIBS ${OGRE_STATIC})
	endif ()
	if (MINGW)
		# this is probably a bug in CMake: the boost find module tries to look for
		# boost libraries with name libboost_*, but CMake already prefixes library
		# search names with "lib". This is the workaround.
		set(CMAKE_FIND_LIBRARY_PREFIXES ${CMAKE_FIND_LIBRARY_PREFIXES} "")
	endif ()
	
	set(Boost_ADDITIONAL_VERSIONS "1.42" "1.42.0" )
	
	# Components that need linking (NB does not include header-only components like bind)
	set(OGRE_BOOST_COMPONENTS thread date_time)
	find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	if (NOT Boost_FOUND)
		# Try again with the other type of libs
		set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
		find_package(Boost COMPONENTS ${OGRE_BOOST_COMPONENTS} QUIET)
	endif()
	find_package(Boost QUIET)
 
	# Set up referencing of Boost
	include_directories(${Boost_INCLUDE_DIR})
	add_definitions(-DBOOST_ALL_NO_LIB)
	set(OGRE_LIBRARIES ${OGRE_LIBRARIES} ${Boost_LIBRARIES})
endif()

# Ogre
if(NOT DEFINED ENV{OGRE_SDK})
	message("Could not find find OGRE SDK! This isn't going to work!")
endif()

###########################################################################
# Unix seems to place OGRE plugins in a nice central location
###########################################################################
if(UNIX)
	set(OGRE_PLUGIN_DIR_REL "/usr/local/lib/OGRE/")
	set(OGRE_PLUGIN_DIR_DBG "/usr/local/lib/OGRE/")
	
	set(OGRE_RENDER_SYSTEM_DBG "RenderSystem_GL_d")
	set(OGRE_RENDER_SYSTEM_REL "RenderSystem_GL")
elseif(WIN32)
	set(OGRE_RENDER_SYSTEM_DBG "RenderSystem_Direct3D9_d")
	set(OGRE_RENDER_SYSTEM_REL "RenderSystem_Direct3D9")
endif()

# Diagnostics
MESSAGE("OGRE : " $ENV{OGRE_SDK})
MESSAGE("BOOST: " $ENV{BOOST_ROOT})


set(BOOST_COMPONENTS thread date_time)

###########################################################################
# Ogre and other required friends
###########################################################################
find_package(OpenGL REQUIRED)
find_package(OGRE REQUIRED)
find_package(OIS REQUIRED)

###########################################################################
# Commands to set up the project's staging area
###########################################################################
set(GAME_CONTENT_DIR "${CMAKE_SOURCE_DIR}/content")
		   
			   
###########################################################################
# Finally, the project configuration
###########################################################################
INCLUDE_DIRECTORIES(
	${OGRE_INCLUDE_DIR}
	${OIS_INCLUDE_DIRS}
	${Boost_INCLUDE_DIR}
)

add_subdirectory(src)
add_subdirectory(tests)
