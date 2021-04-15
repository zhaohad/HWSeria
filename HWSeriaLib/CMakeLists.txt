
set(HWSERIA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${HWSERIA_INCLUDE_DIR})

add_library(HWSeria
        src/HWSeria.cpp
        src/HWSeriable.cpp
        src/HWSeriaDataBuf.cpp)

add_custom_command(TARGET HWSeria
        COMMAND cp -r ${HWSERIA_INCLUDE_DIR} ${LIBRARY_OUTPUT_PATH}/include)