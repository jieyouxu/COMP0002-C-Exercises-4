#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "sort-int-array.h"

// Quicksort algorithm from CLRS + https://www.geeksforgeeks.org/quick-sort/
void quicksort(int32_t* integers, size_t size, int32_t low, int32_t high);

void copy_array(int32_t* dest, int32_t* src, size_t size);

int32_array_t* sort(int32_array_t* int32_array) {
    if (int32_array == NULL || int32_array->elements == NULL) {
        return NULL;
    }
    
    int32_t* newArray = calloc(int32_array->size, sizeof(int32_t));
    int32_array_t* newArrayWrapper = calloc(1, sizeof(int32_array_t));

    if (int32_array->size == 0) {
        newArrayWrapper->size = 0;
        newArrayWrapper->elements = newArray;
    } else {
        copy_array(newArray, int32_array->elements, int32_array->size);
        quicksort(newArray, int32_array->size, 0, int32_array->size-1);
        newArrayWrapper->size = int32_array->size;
        newArrayWrapper->elements = newArray;
    }

    return newArrayWrapper;
}

int32_t partition(int32_t* integers, size_t size, int32_t low, int32_t high);

void quicksort(int32_t* integers, size_t size, int32_t low, int32_t high) {
    if (low < high) {
        int32_t partitioning_index = partition(integers, size, low, high);
        quicksort(integers, size, low, partitioning_index - 1);
        quicksort(integers, size, partitioning_index + 1, high);
    }
}

int32_t partition(int32_t* integers, size_t size, int32_t low, int32_t high) {
    int32_t pivot = integers[high];
    int32_t i = (low - 1);
    int32_t temp1 = 0;
    for (int32_t j = low; j <= high - 1; j++) {
        if (integers[j] <= pivot) {
            i++;
            temp1 = integers[j];
            integers[j] = integers[i];
            integers[i] = temp1;
        }
    }

    int32_t temp2 = integers[i+1];
    integers[i+1] = integers[high];
    integers[high] = temp2;

    return i + 1;
}

void copy_array(int32_t* dest, int32_t* src, size_t size) {
    for (size_t i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}