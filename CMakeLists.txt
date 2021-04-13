cmake_minimum_required(VERSION 3.16)
project(HWSeria)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/out/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/out/bin)

add_subdirectory(HWSeriaLib)
add_subdirectory(test)