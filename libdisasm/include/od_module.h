#ifndef OD_MODULE_H
#define OD_MODULE_H

#ifdef __cplusplus
extern "C" {
#endif

// Example: od_load_module("disasm_elf") will load:
//   * disasm_elf.dll on Windows
//   * ??? on Mac OS X
//   * libdisasm_elf.so on Linux
void od_load_module(char*);

#ifdef __cplusplus
}
#endif

#endif
