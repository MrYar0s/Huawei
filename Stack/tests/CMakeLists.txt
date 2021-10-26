find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRECTORIES})

set(PROJECT_TEST gtest.cpp)

add_executable(test ${PROJECT_TEST})

target_link_libraries(test stack GTest::Main)

enable_testing()
