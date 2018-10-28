#include <stddef.h>
#include <string.h>
#include <stdbool.h>

#include "string-end.h"

int strend(char* s, char* t) {
    if (s == NULL || t == NULL) {
        return 0;
    }

    size_t s_size = strlen(s);
    size_t t_size = strlen(t);

    if (s_size < t_size) {
        return 0;
    }
    
    int offset = s_size - t_size;
    for (int i = 0; i < t_size; i++) {
        if (*(s + i + offset) != *(t + i)) {
            return 0;
        }
    }

    return 1;
}