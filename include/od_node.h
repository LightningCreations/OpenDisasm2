#ifndef OD_NODE_H
#define OD_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct od_node od_node;
typedef struct od_node_vtable od_node_vtable;
typedef struct od_node_iter od_node_iter;
typedef struct od_node_iter_vtable od_node_iter_vtable;

struct od_node_iter_vtable {
    void (*dealloc_data)(od_node_iter*);
    void (*destruct_data)(od_node_iter*);
    od_node* (*next)(od_node_iter *iter);
    void *reserved3;
    void *reserved4;
    void *reserved5;
    void *reserved6;
    void *reserved7;
};

struct od_node_iter {
    od_node_iter_vtable *vtable;
    void *data;
};

struct od_node_vtable {
    void (*dealloc_data)(od_node*);
    void (*destruct_data)(od_node*);
    od_node_iter* (*get_child_iterator)(od_node *parent);
    const char* (*get_uuid)(od_node*);
    void *reserved4;
    void *reserved5;
    void *reserved6;
    void *reserved7;
};

struct od_node {
    od_node_vtable *vtable;
    void *data;
};

#ifdef __cplusplus
}
#endif

#endif
