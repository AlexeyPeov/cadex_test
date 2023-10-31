cmake_minimum_required(VERSION 3.25)
project(cadex_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -fopenmp")

include_directories(src/curves_lib_release/include)

find_library(
    CURVES
    NAMES curves
    PATHS src/curves_lib_release
)

find_package(OpenMP)

add_executable(
    cadex_test
    src/main.cpp
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(cadex_test PUBLIC OpenMP::OpenMP_CXX ${CURVES})
else()
    target_link_libraries(cadex_test ${CURVES})
endif()

file(COPY src/curves_lib_release/curves.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/curves_lib_release/curves.lib DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
