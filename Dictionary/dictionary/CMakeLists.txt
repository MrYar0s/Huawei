add_library(hashtable INTERFACE)
target_include_directories(hashtable INTERFACE include)

if(HASHT_BENCHMARK)
        add_subdirectory(benchmark)
endif()

if(HASHT_TEST)
        add_subdirectory(tests)
endif()