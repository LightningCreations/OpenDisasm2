#ifndef OD_MODULE_H
#define OD_MODULE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "od_types.h"
#include "od_node.h"

// Example: od_load_module("disasm_elf") will load:
//   * disasm_elf.dll on Windows
//   * libdisasm_elf.dylib on Mac OS X
//   * libdisasm_elf.so on Linux
void od_load_module(char *name);

// Call to detect if a block of data can be disassembled by this disassembler
typedef od_bool od_detect_fn(od_node_raw *data);

// Called by modules to register critical base functions
typedef void od_module_register_fn(char *uuid, od_detect_fn *detect_fn);

// Defined by modules, called by the loader.
od_bool od_module_register(od_module_register_fn *register_fn, void *base);

#ifdef __cplusplus
}
#endif

#endif
