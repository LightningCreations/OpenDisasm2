#ifndef OD_STRING_H
#define OD_STRING_H

#ifdef __cplusplus
extern"C"{
#endif

#include <stdint.h>

struct od_string{
    void* data;
    const struct od_string_vtable* vtable;
};

struct od_string_vtable{
    uintptr_t size;
    uintptr_t align;
    void (*destroy)(void*);
    void (*dealloc)(void*);
    const char* (*c_str)(void*);
    size_t (*size)(void*);
};


#ifdef __cplusplus
};
#endif


#endif
