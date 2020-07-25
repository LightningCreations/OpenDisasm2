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

#include <stdint.h>

#include "od_types.h"

struct od_node_iter_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*dealloc)(void *data);
    void (*destruct)(void *data);
    od_node* (*next)(void *data);
    void *reserved3;
    void *reserved4;
    void *reserved5;
};

struct od_node_iter {
    od_node_iter_vtable *vtable;
    void *data;
};

struct od_node_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*dealloc)(void *data);
    void (*destruct)(void *data);
    od_node_iter* (*get_child_iterator)(void *data);
    const char* (*get_uuid)(void *data);
    void *reserved4;
    void *reserved5;
};

struct od_node {
    od_node_vtable *vtable;
    void *data;
};

struct od_node_raw_data_vtable {
    uintptr_t size;
    uintptr_t align;
    void (*dealloc)(void *data);
    void (*destruct)(void *data);
    uint8_t (*next)(void *data);
    od_bool (*has_next)(void *data);
    void *reserved4;
    void *reserved5;
};

struct od_node_raw_data {
    od_node_raw_data_vtable *vtable;
    void *data;
};

void destroy_node_iter_data(od_node_iter*);
void free_node_iter_data(od_node_iter*);

void destroy_node_data(od_node*);
void free_node_data(od_node*);

#ifdef __cplusplus
}
#endif

#endif
