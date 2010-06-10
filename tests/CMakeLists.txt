include_directories( ${OpenGL_INCLUDE_DIR}
                     ${OGRE_INCLUDE_DIRS}
                     ${OIS_INCLUDE_DIRS}
                     ${PROJECT_SOURCE_DIR}/include
                     ${GOOGLETEST}/include )

file(GLOB test_srcs test_*.cpp)
file(GLOB test_incs ../include/*.h)

list(REMOVE_ITEM test_srcs eventhorizon.cpp)
list(APPEND test_srcs testrunner.cpp)

add_executable(eventhorizon-testrunner 
                      ${GOOGLETEST}/gtest-all.cc
                      ${test_srcs}
                      ${test_incs} )

target_link_libraries(eventhorizon-testrunner 
                      ${OpenGL_LIBRARIES}
                      ${OIS_LIBRARIES}
                      ${OGRE_LIBRARIES} )
