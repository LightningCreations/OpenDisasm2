project(libdisasm
        DESCRIPTION "OpenDisasm core library"
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

include(GNUInstallDirs)

add_library(disasm_obj OBJECT src/od_module.c src/od_node.c)
target_include_directories(disasm_obj PRIVATE include)
set_target_properties(disasm_obj PROPERTIES POSITION_INDEPENDENT_CODE ON)

install(DIRECTORY include/ TYPE INCLUDE)

if(OD_BUILD_SHARED)
    add_library(disasm_shared SHARED $<TARGET_OBJECTS:disasm_obj>)
    target_link_libraries(disasm_shared PRIVATE dl)
    target_include_directories(disasm_shared INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIRECTORY}/include>)
    set_target_properties(disasm_shared PROPERTIES VERSION 0.1.0)
    set_target_properties(disasm_shared PROPERTIES SOVERSION 0.1)
    set_target_properties(disasm_shared PROPERTIES OUTPUT_NAME "disasm")
    install(TARGETS disasm_shared
            EXPORT disasm
           )
    add_library(disasm ALIAS disasm_shared)
endif()
if(OD_BUILD_STATIC)
    add_library(disasm_static STATIC $<TARGET_OBJECTS:disasm_obj>)
    target_link_libraries(disasm_static PRIVATE dl)
    target_include_directories(disasm_static INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIRECTORY}/include>)
    set_target_properties(disasm_static PROPERTIES VERSION 0.1.0)
    set_target_properties(disasm_static PROPERTIES SOVERSION 0)
    set_target_properties(disasm_static PROPERTIES OUTPUT_NAME "disasm")
    install(TARGETS disasm_static
            EXPORT disasm
           )        
    if(NOT OD_BUILD_SHARED)
        add_library(disasm ALIAS disasm_static)
    endif()
endif()

install(EXPORT disasm
        NAMESPACE disasm::
        DESTINATION lib/cmake/disasm)
