#Minimum cmake version
cmake_minimum_required(VERSION 3.8)
#Project info
project(stack)
#Choose language
enable_language(CXX)
#Set flags
set(CMAKE_CXX_FLAGS -Wall)

option(TESTING "Включить тестирование" ON)

set(APP_SOURCES source/stack_bool.cpp)
set(APP_INCLUDES include)

if(TESTING)
	find_package(GTest REQUIRED)
	find_package(Threads REQUIRED)

	set(APP_TEST tests/gtest.cpp)

	add_executable(${PROJECT_NAME} ${APP_TEST} ${APP_SOURCES})
	target_include_directories(${PROJECT_NAME} PRIVATE ${APP_INCLUDES} ${GTEST_INCLUDE_DIRS})
	target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} -pthread)
	message(STATUS "Тестирование включено")
endif()

#Add target
add_custom_target(val COMMENT "Included valgrind" COMMAND valgrind ./${PROJECT_NAME})

enable_testing()
