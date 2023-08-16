project(EnginX_Shared_Library VERSION 1.0.1)

file(GLOB_RECURSE ENGINX_MAIN_LIBRARY_SOURCES ${PROJECT_SOURCE_DIR}/src/enginx/*/*.cpp)
file(GLOB_RECURSE ENGINX_MATH_LIBRARY_SOURCES ${PROJECT_SOURCE_DIR}/src/ex_maths/*.cpp)

add_library(
    enginx SHARED
    ${ENGINX_MAIN_LIBRARY_SOURCES}    
)

add_library(
    ex_math SHARED
    ${ENGINX_MATH_LIBRARY_SOURCES}
)

target_link_libraries(enginx PRIVATE X11 GL)

target_include_directories(enginx PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(ex_math PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")