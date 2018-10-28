#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "../bdd-for-c.h"

#include "sort-int-array.h"

spec("integer array sort") {
    describe("int32_array_t* sort(int32_array_t* int32_array)") {
        it("should return NULL when n is null") {
            int32_array_t badInput = {
                .size = 1,
                .elements = NULL
            };

            check(sort(NULL) == NULL);
            check(sort(&badInput) == NULL);
        }

        it("should return {0, []} when elements is an empty array [] of length 0") {
            int32_t emptyArray[] = {};
            int32_array_t emptyArrayWrapper = {
                .size = 0,
                .elements = emptyArray
            };

            int32_array_t* resultArrayWrapper = sort(&emptyArrayWrapper);
            check(resultArrayWrapper != NULL);
            check(resultArrayWrapper->size == 0);
            free(resultArrayWrapper);
        }

        it("should return {1, [1]} when input consists of a single element") {
            int32_t singleElementArray[] = {1};
            int32_array_t singleElementArrayWrapper = {
                .size = 1,
                .elements = singleElementArray
            };

            int32_array_t* resultArrayWrapper = sort(&singleElementArrayWrapper);
            check(resultArrayWrapper != NULL);
            check(resultArrayWrapper->size == 1);
            check(resultArrayWrapper->elements[0] == 1);
            free(resultArrayWrapper);
        }

        it("should sort {2, [2, 1]} to {2, [1, 2]}") {
            int32_t multipleElementArray[] = {2, 1};
            int32_array_t multipleElementArrayWrapper = {
                .size = 2,
                .elements = multipleElementArray
            };

            int32_array_t* resultArrayWrapper = sort(&multipleElementArrayWrapper);
            check(resultArrayWrapper != NULL);
            check(resultArrayWrapper->size == 2);
            check(resultArrayWrapper->elements[0] == 1);
            check(resultArrayWrapper->elements[1] == 2);
            free(resultArrayWrapper);
        }

        it("should sort {2, [1, 2]} to {2, [1, 2]}") {
            int32_t multipleElementArray[] = {1, 2};
            int32_array_t multipleElementArrayWrapper = {
                .size = 2,
                .elements = multipleElementArray
            };

            int32_array_t* resultArrayWrapper = sort(&multipleElementArrayWrapper);
            check(resultArrayWrapper != NULL);
            check(resultArrayWrapper->size == 2);
            check(resultArrayWrapper->elements[0] == 1);
            check(resultArrayWrapper->elements[1] == 2);
            free(resultArrayWrapper);
        }

        it("should sort {3, [3, 2, 1]} to {3, [1, 2, 3]}") {
            int32_t multipleElementArray[] = {3, 2, 1};
            int32_array_t multipleElementArrayWrapper = {
                .size = 3,
                .elements = multipleElementArray
            };

            int32_array_t* resultArrayWrapper = sort(&multipleElementArrayWrapper);
            check(resultArrayWrapper != NULL);
            check(resultArrayWrapper->size == 3);
            check(resultArrayWrapper->elements[0] == 1);
            check(resultArrayWrapper->elements[1] == 2);
            check(resultArrayWrapper->elements[2] == 3);
            free(resultArrayWrapper);
        }

        it("should sort {3, [2, 3, 1]} to {3, [1, 2, 3]}") {
            int32_t multipleElementArray[] = {2, 3, 1};
            int32_array_t multipleElementArrayWrapper = {
                .size = 3,
                .elements = multipleElementArray
            };

            int32_array_t* resultArrayWrapper = sort(&multipleElementArrayWrapper);
            check(resultArrayWrapper != NULL);
            check(resultArrayWrapper->size == 3);
            check(resultArrayWrapper->elements[0] == 1);
            check(resultArrayWrapper->elements[1] == 2);
            check(resultArrayWrapper->elements[2] == 3);
            free(resultArrayWrapper);
        }
    }
}