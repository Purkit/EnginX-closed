project(EXApp VERSION 1.0.0)

add_executable(math_test ex_maths_test.cpp)

target_link_libraries(math_test PRIVATE ex_math)