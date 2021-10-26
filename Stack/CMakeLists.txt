#Minimum cmake version
cmake_minimum_required(VERSION 3.11)
#Project info
project(stack)
#Choose language
enable_language(CXX)
#Add options
add_compile_options(-Wall -Werror)
set(CMAKE_CXX_CLANG_TIDY
	clang-tidy;
	--format-style=file;
	--header-filter=include/*.h*;
	)

set(APP_INCLUDES include)

option(TESTING "Включить тестирование" ON)
option(BENCHMARK "Включить бенчмарк" ON)

add_library(stack INTERFACE)

target_include_directories(stack INTERFACE ${APP_INCLUDES})

if(TESTING)
	add_subdirectory(tests)
	add_custom_target(test_${PROJECT_NAME} COMMAND ./tests/test)
	message(STATUS "Тестирование включено")
endif()

if(BENCHMARK)
	add_subdirectory(bench)
	add_custom_target(bench_${PROJECT_NAME} COMMAND ./bench/bench)
	message(STATUS "Бенчмарк подключен")
endif()

include(clang-format.cmake)
