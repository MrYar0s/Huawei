#Minimum cmake version
cmake_minimum_required(VERSION 3.11)
#Project info
project(Queue)
#Choose language
enable_language(CXX)
#Add options
add_compile_options(-Wall -Werror)

option(TIDY "Enable clang-tidy" ON)
option(FORMAT "Enable clang-format" ON)

if(TIDY)
	set(CMAKE_CXX_CLANG_TIDY
		clang-tidy;
		--format-style=file;
		--header-filter=*.hpp;
	)
	message(STATUS "clang-tidy ON")
endif()

if(FORMAT)
	file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)
	add_custom_target(
		format
		COMMAND clang-format
		-style=file
		-i
		${ALL_SOURCE_FILES}
	)
	message(STATUS "clang-format ON")
endif()

add_subdirectory(queue)
add_subdirectory(stack)
