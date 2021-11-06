

cmake_minimum_required (VERSION 3.0.2)
project (spiral_matrix_2 VERSION 1.0)
set( CMAKE_CXX_FLAGS "-std=c++11" )
add_executable(${PROJECT_NAME} "../src/main.cpp""../src/solution.cpp")
set( CMAKE_BUILD_TYPE Debug )
