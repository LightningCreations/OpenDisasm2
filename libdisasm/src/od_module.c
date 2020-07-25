#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <od_module.h>

static void od_module_register_fn_def(char *uuid, void *base, od_detect_fn *detect_fn) {
}

#ifdef _WIN32 // Windows

// Extra includes
#include <windows.h>

void od_load_module(char* name) {
    // WIP
}

#else // Mac and Linux

// Extra includes
#include <dlfcn.h>

void od_load_module(char* name) {
    char *libname = malloc(
            3 + // "lib"
            strlen(name) +
#ifdef __APPLE__
            6 + // ".dylib"
#else // most POSIX
            3 + // ".so"
#endif
            1); // "\0"
    libname[0] = 0;
    strcat(libname, "lib");
    strcat(libname, name);
#ifdef __APPLE__
    strcat(libname, ".dylib");
#else
    strcat(libname, ".so");
#endif
    void *module = dlopen(libname, RTLD_LAZY | RTLD_LOCAL);
    od_bool (*od_module_register)(od_module_register_fn*, void*) = dlsym(module, "od_module_register");
    od_module_register(od_module_register_fn_def, NULL); // base will be replaced later with something useful
}

#endif

od_bool od_module_register(od_module_register_fn *register_fn, void *base) {
    printf("I'm being loaded as a module... :thonk:\n");
    return 1;
}
