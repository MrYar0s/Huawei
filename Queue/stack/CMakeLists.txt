#Minimum cmake version
cmake_minimum_required(VERSION 3.11)
#Project info
project(stack)
#Choose language
enable_language(CXX)
#Add options
add_compile_options(-Wall -Werror)

set(APP_INCLUDES include)

add_library(stack INTERFACE)

target_include_directories(stack INTERFACE ${APP_INCLUDES})
