include_directories(../HWSeriaLib/include)

add_executable(HWSeria_Test main.cpp)
target_link_libraries(HWSeria_Test HWSeria)