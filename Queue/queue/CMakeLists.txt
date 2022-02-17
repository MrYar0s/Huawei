add_library(queue INTERFACE)
target_include_directories(queue INTERFACE include)
target_link_libraries(queue INTERFACE stack)

if(BENCHMARK)
        add_subdirectory(benchmark)
endif()

if(QUEUE_STACK OR QUEUE_LIST)
        add_subdirectory(tests)
endif()
