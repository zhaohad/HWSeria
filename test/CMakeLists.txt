include_directories(../HWSeriaLib/include)

add_executable(HWSeria_Test main.cpp DataStruct.cpp DataStruct.h)
target_link_libraries(HWSeria_Test HWSeria)