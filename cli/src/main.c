#include <stdio.h>
#include <od_module.h>

const int NUM_MODULES = 1;

const char *modules[NUM_MODULES] = {
    "disasm_elf"
};

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    for(int i = 0; i < NUM_MODULES; i++) {
        od_load_module(modules[i]);
    }
}
