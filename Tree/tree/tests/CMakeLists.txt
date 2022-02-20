find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRECTORIES})
enable_testing()

set(PROJECT_TEST gtest.cpp)
set(TREE_TEST test)

add_executable(${TREE_TEST} ${PROJECT_TEST})

#include(GoogleTest)
if(SANITIZERS)
	message("Build tree with sanitizers")
	target_compile_options(${TREE_TEST} PUBLIC -fsanitize=address -g)
	set_target_properties(${TREE_TEST} PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()

target_link_libraries(${TREE_TEST} tree GTest::Main)

add_custom_target(run_${TREE_TEST}
	  COMMENT "Running tree tests"
	  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${TREE_TEST})
add_dependencies(run_${TREE_TEST} ${TREE_TEST})