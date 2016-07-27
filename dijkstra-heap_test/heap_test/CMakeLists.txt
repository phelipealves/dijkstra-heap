#include(CTest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runHeapTests basic.cpp)

target_link_libraries(runHeapTests gtest gtest_main)
