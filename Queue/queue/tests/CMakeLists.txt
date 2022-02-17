find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRECTORIES})
enable_testing()

set(PROJECT_TEST gtest.cpp)

set(STACK_TEST stack_test)
set(LIST_TEST list_test)

if(QUEUE_STACK)
	add_executable(${STACK_TEST} ${PROJECT_TEST})
	target_compile_definitions(${STACK_TEST} PUBLIC -DQUEUE_STACK=1)
	target_link_libraries(${STACK_TEST} queue GTest::Main)
	
	include(GoogleTest)
	if(SANITIZERS)
		message("Build queue stack with sanitizers")
		target_compile_options(${STACK_TEST} PUBLIC -fsanitize=address -g)
		set_target_properties(${STACK_TEST} PROPERTIES LINK_FLAGS "-fsanitize=address")
	endif()

	add_custom_target(run_${STACK_TEST}
			  COMMENT "Running queue stack tests"
			  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${STACK_TEST})
	add_dependencies(run_${STACK_TEST} ${STACK_TEST})
endif()

if(QUEUE_LIST)
	add_executable(${LIST_TEST} ${PROJECT_TEST})
	target_compile_definitions(${LIST_TEST} PUBLIC -DQUEUE_LIST=1)
	target_link_libraries(${LIST_TEST} queue GTest::Main)

        include(GoogleTest)
        if(SANITIZERS)
                message("Build queue list with sanitizers")
		target_compile_options(${LIST_TEST} PUBLIC -fsanitize=address -g)
		set_target_properties(${LIST_TEST} PROPERTIES LINK_FLAGS "-fsanitize=address")
        endif()

	add_custom_target(run_${LIST_TEST}
                          COMMENT "Running queue stack tests"
			  COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${LIST_TEST})
	add_dependencies(run_${LIST_TEST} ${LIST_TEST})
endif()
