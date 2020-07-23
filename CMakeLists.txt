project(OpenDisasm
        DESCRIPTION "Extensible open reverse engineering interface"
        LANGUAGES C)

cmake_minimum_required(VERSION 3.17)

add_subdirectory(libdisasm)
add_subdirectory(modules)
