#Minimum cmake version
cmake_minimum_required(VERSION 3.8)
#Project info
project(stack)
#Choose language
enable_language(CXX)
#Set flags
set(CMAKE_CXX_FLAGS -Wall)

option(TESTING "Включить тестирование" ON)

set(APP_TEST tests/gtest.cpp)
set(APP_SOURCES source/stack_bool.cpp)
set(APP_INCLUDES include)

if(TESTING)
	find_package(GTest REQUIRED)
	find_package(Threads REQUIRED)
	add_executable(${PROJECT_NAME} ${APP_TEST} ${APP_SOURCES})
	target_include_directories(${PROJECT_NAME} PRIVATE ${APP_INCLUDES} ${GTEST_INCLUDE_DIRS})
	set(APP_TEST tests/gtest.cpp)
	set(APP_SOURCES source/stack_bool.cpp)
	target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} -pthread)
	message(STATUS "Тестирование включено")
endif()

find_package(benchmark REQUIRED)

#add_executable(${PROJECT_NAME} ${APP_SOURCES})

#target_link_libraries(${PROJECT_NAME} benchmark::benchmark)

#Add target
add_custom_target(val COMMENT "Included valgrind" COMMAND valgrind ./${PROJECT_NAME})
enable_testing()
