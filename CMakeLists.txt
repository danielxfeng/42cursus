cmake_minimum_required(VERSION 3.14)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Google Test subdirectory
add_subdirectory(gtest)

# Enable testing
enable_testing()

# Add test executable(s)
add_executable(cpp09ex00test test/cpp09/ex00/test.cpp src/cpp09/ex00/BitcoinExchange.cpp)
add_executable(cpp09ex02test test/cpp09/ex02/test.cpp src/cpp09/ex02/SpanSlice.cpp src/cpp09/ex02/PmergeMe.cpp)

target_include_directories(cpp09ex00test PRIVATE ${CMAKE_SOURCE_DIR}/src/cpp09/ex00/)
target_include_directories(cpp09ex02test PRIVATE ${CMAKE_SOURCE_DIR}/src/cpp09/ex02/)

# Link Google Test libraries to your tests
target_link_libraries(cpp09ex00test PRIVATE gtest_main)
target_link_libraries(cpp09ex02test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(cpp09ex00test)
gtest_discover_tests(cpp09ex02test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

#cmake -S . -B build
#cmake --build build
#cd ./build
#ctest cpp09ex00 --verbose