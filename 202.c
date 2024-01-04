#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

int ansCal(int n) {
    int ans = 0;
    while (n > 0) {
        ans += ((n % 10) * (n % 10));
        n /= 10;
    }
    return ans;
}

bool isHappy(int n) {
    if ((n == 1) || (n == 7)) {
        return 1;
    }
    while (1) {
        int tortoise = ansCal(n);
        int hare = ansCal(ansCal(n));
        if ((tortoise == 1) || (hare == 1) || (tortoise == 7) || (hare == 7)) {
            return 1;
        }
        else if (tortoise == hare) {
            return 0;
        }
    }
    return 1;
}