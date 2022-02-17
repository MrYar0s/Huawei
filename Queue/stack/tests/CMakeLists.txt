find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRECTORIES})

set(PROJECT_TEST gtest.cpp)
add_executable(test ${PROJECT_TEST})

if(SANITIZERS)
	message("Build with sanitizers")
	target_compile_options(test PUBLIC -fsanitize=address -g)
	set_target_properties(test PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

target_link_libraries(test stack GTest::Main)
enable_testing()

add_custom_target(run_tests
		  COMMENT "Running tests"
		  COMMAND ./test)
add_dependencies(test stack)
