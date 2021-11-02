find_package(benchmark REQUIRED)

add_executable(bench bench.cpp)
target_link_libraries(bench stack benchmark::benchmark)

add_custom_target(run_bench
		  COMMENT "Running benchmark"
		  COMMAND ./bench)
add_dependencies(run_bench stack)
