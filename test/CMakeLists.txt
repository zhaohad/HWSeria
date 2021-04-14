include_directories(../HWSeriaLib/include)

add_executable(HWSeria_Test main.cpp DataStruct.cpp DataStruct.h SubD.cpp SubD.h SubSubD.cpp SubSubD.h)
target_link_libraries(HWSeria_Test HWSeria)