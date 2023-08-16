project(EXApp VERSION 1.0.0)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(ex_app ${SOURCES})

target_link_libraries(ex_app PRIVATE GL enginx)