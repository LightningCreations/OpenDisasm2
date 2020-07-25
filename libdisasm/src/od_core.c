#include <stdlib.h>

#include <od_core.h>
#include "od_data.h"

od_data* od_init() {
    return malloc(sizeof(od_data));
}
