find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRECTORIES})
enable_testing()

set(PROJECT_TEST gtest.cpp)

add_executable(${HASHT_TEST} ${PROJECT_TEST})
target_compile_definitions(${HASHT_TEST} PUBLIC -DQUEUE_HASHT=1)
target_link_libraries(${HASHT_TEST} hashtable GTest::Main)
	
include(GoogleTest)
if(SANITIZERS)
	message("Build hash table with sanitizers")
	target_compile_options(${HASHT_TEST} PUBLIC -fsanitize=address -g)
	set_target_properties(${HASHT_TEST} PROPERTIES LINK_FLAGS "-fsanitize=address")
endif()
	
add_custom_target(run_${HASHT_TEST}
	  COMMENT "Running hash table tests"
	  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${HASHT_TEST})
add_dependencies(run_${HASHT_TEST} ${HASHT_TEST})