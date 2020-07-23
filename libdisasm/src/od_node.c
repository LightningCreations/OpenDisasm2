#include <stdlib.h>

#include <od_node.h>

void destroy_node_iter_data(od_node_iter *iter) {
    iter->vtable->destruct(iter->data);
}

void free_node_iter_data(od_node_iter *iter) {
    if(!iter->data) return;
    iter->vtable->dealloc(iter->data);
    iter->data = NULL;
}

void destroy_node_data(od_node *node) {
    node->vtable->destruct(node->data);
}

void free_node_data(od_node *node) {
    if(!node->data) return;
    node->vtable->dealloc(node->data);
    node->data = NULL;
}
