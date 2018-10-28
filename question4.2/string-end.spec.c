#include "../bdd-for-c.h"

#include "string-end.h"

spec("string-end") {
    describe("int strend(char* s, char* t)") {
        it("should return 0 if either argument is a null_ptr") {
            check(strend(NULL, NULL) == 0);
            char s[] = "";
            char t[] = "";
            check(strend(s, NULL) == 0);
            check(strend(NULL, t) == 0);
        }

        it("should return 0 if t is longer than s") {
            char s[] = "";
            char t[] = "1";
            check(strend(s, t) == 0);
        }

        it("should return 1 if t occurs at the end of s") {
            char s[] = "blahblahTEST";
            char t[] = "TEST";
            check(strend(s, t) == 1);
        }

        it("should return 0 if t does not occur at the end of s") {
            char s[] = "blahblahblahTEST";
            char t[] = "TES";
            check(strend(s, t) == 0);
        }
    }
}