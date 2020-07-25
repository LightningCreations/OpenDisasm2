#include <stdio.h>

#include <od_module.h>

static void od_module_register_fn(char *uuid, void *base, od_detect_fn *detect_fn) {
}

#ifdef _WIN32 // Windows

// Extra includes
#include <windows.h>

void od_load_module(char* name) {
    // WIP
}

#else // Mac and Linux

void od_load_module(char* name) {
    // WIP
}

#endif

od_bool od_module_register(od_module_register_fn *register_fn, void *base) {
    printf("I'm being loaded as a module... :thonk:\n");
    return 1;
}
