#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

size_t stringSize(char* s) {
    if (s == NULL) {
        return 0;
    }

    char currentCharacter = *(s + 0);
    size_t stringLength = 0;
    while (currentCharacter != '\0') {
        currentCharacter = *(s + stringLength);
        if (currentCharacter != '\0') {
            stringLength++;
        }
    }

    return stringLength;
}

char* stringCopy(char* s) {
    if (s == NULL) {
        return NULL;
    }

    // Allow one extra for string terminator '\0'
    size_t size = stringSize(s) + 1;
    char* copy = (char*) malloc(size);

    for (size_t i = 0; i < size; i++) {
        *(copy + i) = *(s + i);
    }

    *(copy + size) = '\0';

    return copy;
}