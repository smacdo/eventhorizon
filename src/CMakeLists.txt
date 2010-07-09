project(eventhorizon-client)

include_directories( ${OpenGL_INCLUDE_DIR}
                     ${OGRE_INCLUDE_DIRS}
					 ${Boost_INCLUDE_DIRS}
                     ${OIS_INCLUDE_DIRS}
                     ${CMAKE_SOURCE_DIR}/include )

file(GLOB app_srcs *.cpp)
file(GLOB app_incs ../include/*.h)

add_executable(eventhorizon WIN32 ${app_srcs} ${app_incs})

# ${Boost_LIBRARIES}
target_link_libraries(eventhorizon 
                      ${OpenGL_LIBRARIES}  
                      ${OIS_LIBRARIES}
                      ${OGRE_LIBRARIES} )			  
					  
if(WIN32)
	configure_file(${OGRE_BINARY_DBG} "${PROJECT_BINARY_DIR}/" COPYONLY)
	configure_file(${OGRE_BINARY_REL} "${PROJECT_BINARY_DIR}/" COPYONLY)
	configure_file(${OIS_BINARY_DBG} "${PROJECT_BINARY_DIR}/" COPYONLY)
	configure_file(${OIS_BINARY_REL} "${PROJECT_BINARY_DIR}/" COPYONLY)
endif(WIN32)

configure_file(${CMAKE_SOURCE_DIR}/content/config/plugins.cfg.in 
               ${PROJECT_BINARY_DIR}/plugins.cfg)
			   
configure_file(${CMAKE_SOURCE_DIR}/content/config/plugins_d.cfg.in 
               ${PROJECT_BINARY_DIR}/plugins_d.cfg)
			   
configure_file(${CMAKE_SOURCE_DIR}/content/config/resources.cfg.in 
               ${PROJECT_BINARY_DIR}/resources.cfg)

configure_file(${CMAKE_SOURCE_DIR}/content/config/resources_d.cfg.in 
               ${PROJECT_BINARY_DIR}/resources_d.cfg)	