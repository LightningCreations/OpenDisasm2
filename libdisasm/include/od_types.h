#ifndef OD_TYPES_H
#define OD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef uint8_t od_bool;

typedef struct {
   uint64_t hi;
   uint64_t lo;
} od_uuid;

#ifdef __cplusplus
}
#endif

#endif
