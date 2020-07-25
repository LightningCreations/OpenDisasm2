#include <stdlib.h>

#include <od_core.h>
#include "od_data.h"

od_data* od_init() {
    od_data *data = malloc(sizeof(od_data));
    data->disasms = ll_init();
    return data;
}
