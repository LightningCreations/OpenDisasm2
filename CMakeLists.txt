project(OpenDisasm
        DESCRIPTION "Extensible open reverse engineering interface"
        LANGUAGES C)

cmake_minimum_required(VERSION 3.17)

include_directories(libdisasm/include)

add_subdirectory(libdisasm)
add_subdirectory(modules)
add_subdirectory(cli)
