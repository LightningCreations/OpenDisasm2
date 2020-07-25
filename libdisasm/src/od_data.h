#ifndef INTERNAL_OD_DATA_H
#define INTERNAL_OD_DATA_H

#include <stdint.h>
#include <od_module.h>

typedef struct ll_node {
    struct ll_node *next;
    void *value;
} ll_node;

typedef struct ll {
    ll_node *first;
    ll_node *last;
    size_t size;
} ll;

ll* ll_init();
void ll_push(ll*, void*);
void ll_foreach(ll*, void(*)(void*));
void ll_free(ll*);

typedef struct disasm {
    const char *uuid;
    od_detect_fn *detect;
} disasm;

struct od_data {
    ll *disasms; // List of "disasm"s
};

#endif
