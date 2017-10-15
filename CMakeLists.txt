cmake_minimum_required(VERSION 3.0)

set(EXTRA_BINCFLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${EXTRA_BINCFLAGS})

project (soundex)
add_subdirectory(/Users/noesis/Projects/soundex/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(/Users/noesis/Projects/soundex/googletest/googlemock/include)

set(sources /Users/noesis/Projects/soundex/)
set(sources ${sources}/soundex_test.cpp)
add_executable(soundex_test ${sources})
target_link_libraries(soundex_test gtest_main)
