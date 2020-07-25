#include <stdio.h>
#include <stdlib.h>

#include <od_node.h>

static od_node_vtable file_node_vtable;
static od_bool file_node_vtable_set; // = 0
typedef struct file_node_data {
    FILE *file;
    od_bool eof;
} file_node_data;
static void destruct_file_node_data(void *v_data) {
    file_node_data *data = (file_node_data*) v_data;
    fclose(data->file);
}

const char* od_node_raw_get_uuid(void *data) {
    return NULL; // WIP
}

od_node_raw* od_load_file_as_node(FILE *file) {
    if(!file_node_vtable_set) {
        file_node_vtable.size = sizeof(file_node_data);
        file_node_vtable.align = alignof(file_node_data);
        file_node_vtable.dealloc = free;
        file_node_vtable.destruct = destruct_file_node_data;
        file_node_vtable.get_child_iterator = NULL; // WIP (should return NULL)
        file_node_vtable.get_uuid = od_node_raw_get_uuid;
        file_node_vtable.get_name = NULL; // WIP (should return "file: <filename>")
        file_node_vtable.reserved5 = NULL;
        file_node_vtable_set = 1;
    }
    return NULL; // WIP
}

void od_destroy_node_iter_data(od_node_iter *iter) {
    iter->vtable->destruct(iter->data);
}

void od_free_node_iter_data(od_node_iter *iter) {
    if(!iter->data) return;
    iter->vtable->dealloc(iter->data);
    iter->data = NULL;
}

void od_destroy_node_data(od_node *node) {
    node->vtable->destruct(node->data);
}

void od_free_node_data(od_node *node) {
    if(!node->data) return;
    node->vtable->dealloc(node->data);
    node->data = NULL;
}
