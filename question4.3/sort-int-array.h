#ifndef SORT_INT_ARRAY_H
#define SORT_INT_ARRAY_H

#include <stddef.h>
#include <stdint.h>

typedef struct int32_array_t {
    size_t size;
    int32_t* elements;
} int32_array_t;

int32_array_t* sort(int32_array_t* int32_array);

#endif