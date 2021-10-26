#Minimum cmake version
cmake_minimum_required(VERSION 3.11)
#Project info
project(stack)
#Choose language
enable_language(CXX)
#Add options
add_compile_options(-Wall -Werror)

option(TESTING "Включить тестирование" ON)
option(BENCHMARK "Включить бенчмапк" ON)
option(TIDY "Включить clang-tidy" ON)

set(APP_INCLUDES include)

add_library(stack INTERFACE)

target_include_directories(stack INTERFACE ${APP_INCLUDES})

if(TIDY)
	set(CMAKE_CXX_CLANG_TIDY
		clang-tidy;
		--format-style=file;
		--header-filter=include/*.h*;
		)
	include(clang-format.cmake)
	message(STATUS "clang-tidy подключен")
endif()

if(TESTING)
	add_subdirectory(tests)
	message(STATUS "Тестирование включено")
endif()

if(BENCHMARK)
	add_subdirectory(bench)
	message(STATUS "Бенчмарк подключен")
endif()
