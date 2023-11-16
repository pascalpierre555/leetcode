#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    if ((divisor == -1) && (dividend == __INT_MAX__ + 1)) {
        return __INT_MAX__;
    }
    int q = dividend / divisor;
    return q;
}