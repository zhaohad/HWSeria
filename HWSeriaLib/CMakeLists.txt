
set(HWSERIA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${HWSERIA_INCLUDE_DIR})

add_library(HWSeria src/HWSeria.cpp)