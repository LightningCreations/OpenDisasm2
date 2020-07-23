project(disasm_elf
        DESCRIPTION "OpenDisasm ELF library"
        LANGUAGES C)

cmake_minimum_required(VERSION 3.17)

if(NOT DEFINED OD_BUILD_SHARED)
    set(OD_BUILD_SHARED ON)
endif()

if(NOT DEFINED OD_BUILD_STATIC)
    set(OD_BUILD_STATIC ON)
endif()

if(NOT OD_BUILD_SHARED AND NOT OD_BUILD_STATIC)
    message(FATAL_ERROR "disasm_elf error: Not building either shared or static library!")
endif()

add_library(disasm_elf_obj OBJECT src/elf_disasm.c)

if(OD_BUILD_SHARED)
    add_library(disasm_elf_shared SHARED $<TARGET_OBJECTS:disasm_elf_obj>)
    set_target_properties(disasm_elf_shared PROPERTIES VERSION 0.1.0)
    set_target_properties(disasm_elf_shared PROPERTIES SOVERSION 0.1)
    set_target_properties(disasm_elf_shared PROPERTIES OUTPUT_NAME "disasm_elf")
    install(TARGETS disasm_elf_shared
            EXPORT disasm_elf
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
    add_library(disasm_elf ALIAS disasm_elf_shared)
endif()
if(OD_BUILD_STATIC)
    add_library(disasm_elf_static STATIC $<TARGET_OBJECTS:disasm_elf_obj>)
    set_target_properties(disasm_elf_static PROPERTIES VERSION 0.1.0)
    set_target_properties(disasm_elf_static PROPERTIES SOVERSION 0)
    set_target_properties(disasm_elf_static PROPERTIES OUTPUT_NAME "disasm_elf")
    install(TARGETS disasm_elf_static
            EXPORT disasm_elf
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib)
    if(NOT OD_BUILD_SHARED)
        add_library(disasm_elf ALIAS disasm_elf_static)
    endif()
endif()
