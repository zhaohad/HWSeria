cmake_minimum_required(VERSION 3.16)

#set(CMAKE_SYSTEM_NAME Android)
#set(CMAKE_SYSTEM_VERSION 21) # API level
#set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)
#set(CMAKE_ANDROID_NDK /path/to/android-ndk)
#set(CMAKE_ANDROID_STL_TYPE gnustl_static)

project(HWSeria)

set(CMAKE_CXX_STANDARD 14)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/out/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/out/bin)

add_subdirectory(HWSeriaLib)
add_subdirectory(test)