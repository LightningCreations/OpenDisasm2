project(OpenDisasmCLI
        DESCRIPTION "OpenDisasm Command Line Interface"
        LANGUAGES C)

cmake_minimum_required(VERSION 3.17)

add_executable(disasm-cli src/main.c)
target_link_libraries(disasm-cli disasm)
set_target_properties(disasm-cli PROPERTIES VERSION 0.1.0)
install(TARGETS disasm-cli
        EXPORT disasm-cli
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
