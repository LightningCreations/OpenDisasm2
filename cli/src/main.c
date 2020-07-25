#include <stdio.h>
#include <od_module.h>

#define NUM_MODULES 1

static const char *modules[NUM_MODULES] = {
    "disasm_elf"
};

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    od_data *disasm = od_init();
    for(int i = 0; i < NUM_MODULES; i++) {
        od_load_module(disasm, modules[i]);
    }
}
