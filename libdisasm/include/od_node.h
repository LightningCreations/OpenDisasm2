#ifndef OD_NODE_H
#define OD_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct od_node od_node;
typedef struct od_node_vtable od_node_vtable;
typedef struct od_node_iter od_node_iter;
typedef struct od_node_iter_vtable od_node_iter_vtable;

// Builtin node types
typedef od_node od_node_void; // (simple inner tree node; has no data) UUID: ???

typedef od_node od_node_raw; // (simple leaf node; data is u8 iterator) UUID: ???
typedef struct od_node_raw_data od_node_raw_data;
typedef struct od_node_raw_data_vtable od_node_raw_data_vtable;

#include <stdint.h>

#if defined(_MSC_VER) && !defined(__cplusplus)
#define alignof(T) __alignof(T)
#elif defined(__cplusplus) && __cplusplus >= 201103L
// Nothing
#elif __STDC_VERSION__ >= 201112L
#include <stdalign.h>
#elif defined(__GNUC__)
#define alignof(T) __alignof__((T))
#else
#define alignof(T) 1 // Last resort
#endif

#include <od_types.h>
#include <od_string.h>

struct od_node{
    void* data;
    const od_node_vtable* vtable;
};

struct od_node_iter_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*destruct)(void *data);
    void (*dealloc)(void *data);
    od_node (*next)(void *data);
};

struct od_node_iter {
    void *data;
    const od_node_iter_vtable *vtable;
};

struct od_node_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*destruct)(void *data);
    void (*dealloc)(void *data);
    od_node_iter* (*get_child_iterator)(void *data);
    od_uuid (*get_uuid)(const void *data);
    od_string (*get_name)(const void *data);
    void (*set_name)(void *data,od_string);
};

struct od_node_raw_data_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*destruct)(void *data);
    void (*dealloc)(void *data);
    uint8_t (*next)(void *data);
    od_bool (*has_next)(void *data);
    void *reserved4;
    void *reserved5;
};

struct od_node_raw_data {
    void *data;
    const od_node_raw_data_vtable *vtable;
};

void od_destroy_node_iter_data(od_node_iter*);
void od_free_node_iter_data(od_node_iter*);

void od_destroy_node_data(od_node*);
void od_free_node_data(od_node*);

#ifdef __cplusplus
}
#endif

#endif
