#include "demo.h"
#include "unity.h"

int superDigit(char* n, int k) {
    long long s = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        s += n[i] - '0';
    }
    s *= k;
    while (s >= 10) {
        s = digitSum(s);
    }
    return (int)s;
}
