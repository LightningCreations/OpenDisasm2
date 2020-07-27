#ifndef OD_STRING_H
#define OD_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct od_string od_string;
typedef struct od_string_vtable od_string_vtable;

#include <stddef.h>
#include <stdint.h>

struct od_string_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*destruct)(void*);
    void (*dealloc)(void*);
    const char* (*c_str)(void*);
    size_t (*length)(void*);
};

struct od_string {
    void *data;
    const od_string_vtable *vtable;
};

#ifdef __cplusplus
};
#endif

#endif
