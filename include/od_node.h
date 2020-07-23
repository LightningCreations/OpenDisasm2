#ifndef OD_NODE_H
#define OD_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct od_node od_node;
typedef struct od_node_vtable od_node_vtable;

// Call the iterator to get the next node
typedef od_node* od_node_iter(od_node *parent);

struct od_node_vtable {
    void (*dealloc)(od_node *parent);
    void (*destroy)(od_node *parent);
    od_node_iter* (*get_child_iterator)(od_node *parent);
    void *reserved3;
    void *reserved4;
    void *reserved5;
    void *reserved6;
    void *reserved7;
};

struct od_node {
    od_node_vtable *vtable;
    // Extensible struct
};

#ifdef __cplusplus
}
#endif

#endif
