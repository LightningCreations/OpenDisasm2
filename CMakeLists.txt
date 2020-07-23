project(OpenDisasm
        DESCRIPTION "Extensible open reverse engineering interface"
        LANGUAGES C)

cmake_minimum_required(VERSION 3.17)

if(NOT DEFINED OD_BUILD_SHARED)
    set(OD_BUILD_SHARED ON)
endif()

if(NOT DEFINED OD_BUILD_STATIC)
    set(OD_BUILD_STATIC ON)
endif()

if(NOT OD_BUILD_SHARED AND NOT OD_BUILD_STATIC)
    message(FATAL_ERROR "libdisasm error: Not building either shared or static library!")
endif()

add_library(disasm_obj OBJECT src/od_node.c)
target_include_directories(disasm_obj PUBLIC include)

if(OD_BUILD_SHARED)
    add_library(disasm_shared SHARED $<TARGET_OBJECTS:disasm_obj>)
    set_target_properties(disasm_shared PROPERTIES VERSION 0.1.0)
    set_target_properties(disasm_shared PROPERTIES SOVERSION 0.1)
    set_target_properties(disasm_shared PROPERTIES OUTPUT_NAME "disasm")
    install(TARGETS disasm_shared
            EXPORT disasm
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
    add_library(disasm ALIAS disasm_shared)
endif()
if(OD_BUILD_STATIC)
    add_library(disasm_static STATIC $<TARGET_OBJECTS:disasm_obj>)
    set_target_properties(disasm_static PROPERTIES VERSION 0.1.0)
    set_target_properties(disasm_static PROPERTIES SOVERSION 0)
    set_target_properties(disasm_static PROPERTIES OUTPUT_NAME "disasm")
    install(TARGETS disasm_static
            EXPORT disasm
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
    if(NOT OD_BUILD_SHARED)
        add_library(disasm ALIAS disasm_static)
    endif()
endif()

install(EXPORT disasm
        NAMESPACE disasm::
        DESTINATION lib/cmake/disasm)
