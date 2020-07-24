project(disasm_elf
        DESCRIPTION "OpenDisasm ELF library"
        LANGUAGES C)

cmake_minimum_required(VERSION 3.17)

add_library(disasm_elf SHARED src/elf_disasm.c)
target_link_libraries(disasm_elf disasm)
set_target_properties(disasm_elf PROPERTIES VERSION 0.1.0)
set_target_properties(disasm_elf PROPERTIES SOVERSION 0.1)
install(TARGETS disasm_elf
        EXPORT disasm_elf
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
