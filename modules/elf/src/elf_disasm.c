#include <od_module.h>

od_bool elf_detect(od_data *base, od_node_raw *data) {
    return 0; // No, this is clearly not an ELF file, why would it be?
}

od_bool od_module_register(od_data *base, od_module_register_fn *register_fn) {
    register_fn(base, "meep-uuid-test-yep", elf_detect);
    return 0; // No, we did not fail in registering, why would we?
}
