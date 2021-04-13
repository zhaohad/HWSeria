
set(HWSERIA_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

include_directories(${HWSERIA_INCLUDE_DIR})

add_library(HWSeria src/HWSeria.cpp src/HWSeriable.cpp include/HWSeriable.h src/DataBuf.cpp include/DataBuf.h)

add_custom_command(TARGET HWSeria
        COMMAND cp -r ${HWSERIA_INCLUDE_DIR} ${LIBRARY_OUTPUT_PATH}/include)