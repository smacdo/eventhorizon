include_directories( ${OpenGL_INCLUDE_DIR}
                     ${OGRE_INCLUDE_DIRS}
                     ${OIS_INCLUDE_DIRS}
                     ${PROJECT_SOURCE_DIR}/include )

file(GLOB app_srcs *.cpp)
file(GLOB app_incs ../include/*.h)

add_executable(eventhorizon ${app_srcs} ${app_incs})

target_link_libraries(eventhorizon 
                      ${OpenGL_LIBRARIES}
                      ${OIS_LIBRARIES}
                      ${OGRE_LIBRARIES} )
