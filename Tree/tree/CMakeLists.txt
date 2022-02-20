add_library(tree INTERFACE)
target_include_directories(tree INTERFACE include)

if(TEST)
        add_subdirectory(tests)
endif()