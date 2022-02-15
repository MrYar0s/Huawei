find_package(benchmark REQUIRED)

set(STACK_BENCH stack_bench)
set(LIST_BENCH list_bench)

add_executable(${STACK_BENCH} queue_stack_bench.cpp)
target_link_libraries(${STACK_BENCH} benchmark::benchmark)

add_executable(${LIST_BENCH} queue_list_bench.cpp)
target_link_libraries(${LIST_BENCH} benchmark::benchmark)

add_custom_target(run_bench
		  COMMENT "Running all benchmarks"
		  COMMAND ./${STACK_BENCH}
		  COMMAND ./${LIST_BENCH})
add_dependencies(run_bench ${STACK_BENCH} ${LIST_BENCH})
