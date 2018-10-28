#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "../bdd-for-c.h"

#include "copy-string.h"

#define NULL_PTR ((void *) 0)

spec("copy-string") {
    describe("size_t stringSize(char* s)") {
        it("should handle nullptr and return 0") {
            check(stringSize(NULL) == 0);
        }

        it("should return 0 for empty string") {
            char* emptyString = (char *) malloc(0);
            *(emptyString + 0) = '\0';

            check(stringSize(emptyString) == 0);

            free(emptyString);
        }

        it("should return length of strings of various sizes") {
            char stringWithLength1[] = "1";
            check(stringSize(stringWithLength1) == 1);

            char stringWithLength2[] = "12";
            check(stringSize(stringWithLength2) == 2);

            char stringWithLength3[] = "123";
            check(stringSize(stringWithLength3) == 3);

            char stringWithLength4[] = "1234";
            check(stringSize(stringWithLength4) == 4);

            char stringWithLength5[] = "12345";
            check(stringSize(stringWithLength5) == 5);
        }
    }

    describe("char* stringCopy(char* s)") {
        it("should return nullptr for nullptr input") {
            check(stringCopy(NULL) == NULL);
        }

        it("should return an exact copy of the input") {
            it("should return an exact copy of an input string of length 0") {
                char expectedString0[] = "";
                char* actualString0 = stringCopy(expectedString0);
                check(strcmp(expectedString0, actualString0) == 0);
                free(actualString0);
            }

            it("should return an exact copy of an input string of length 1") {
                char expectedString1[] = "1";
                char* actualString1 = stringCopy(expectedString1);
                check(strcmp(expectedString1, actualString1) == 0);
                free(actualString1);
            }

            it("should return an exact copy of an input string of length 10") {
                char expectedString10[] = "1234567890";
                char* actualString10 = stringCopy(expectedString10);
                check(strcmp(expectedString10, actualString10) == 0);
                free(actualString10);
            }
        }
    }
}