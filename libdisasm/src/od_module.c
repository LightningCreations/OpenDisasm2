#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <od_module.h>

static void od_module_register_fn_def(od_data *data, char *uuid, od_detect_fn *detect_fn) {
}

#ifdef _WIN32 // Windows

// Extra includes
#include <windows.h>

// Code adapted from https://docs.microsoft.com/en-us/windows/win32/dlls/using-run-time-dynamic-linking
void od_load_module(od_data *data, char *name) {
    char *libname = malloc(
            strlen(name) +
            5); // ".dll\0"
    libname[0] = 0;
    strcat(libname, name);
    strcat(libname, ".dll");
    HINSTANCE module = LoadLibrary(TEXT(libname));
    free(libname);
    od_bool (*od_module_register)(od_data*, od_module_register_fn*) = GetProcAddress(module, "od_module_register");
    od_module_register(data, od_module_register_fn_def);
}

#else // Mac and Linux

// Extra includes
#include <dlfcn.h>

void od_load_module(od_data *data, char *name) {
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
    free(libname);
    od_bool (*od_module_register)(od_data*, od_module_register_fn*) = dlsym(module, "od_module_register");
    od_module_register(data, od_module_register_fn_def);
}

#endif

od_bool od_module_register(od_data *data, od_module_register_fn *register_fn) {
    printf("I'm being loaded as a module... :thonk:\n");
    return 1;
}
