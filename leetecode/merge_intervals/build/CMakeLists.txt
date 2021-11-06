

cmake_minimum_required (VERSION 3.0.2)
project (merge_intervals VERSION 1.0)
set( CMAKE_CXX_FLAGS "-std=c++11" )
add_executable(${PROJECT_NAME} "../src/main.cpp""../src/solution.cpp")
