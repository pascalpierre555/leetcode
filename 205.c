#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isIsomorphic(char *s, char *t) {
    if (strlen(s) != strlen(t)) {
        return 0;
    }
    int s1[128] = {0};
    int t1[128] = {0};
    for (int i = 0; ((s[i] != 0) && (t[i] != 0)); i++) {
        if (s1[s[i]] != t1[t[i]]) {
            return 0;
        }
        s1[s[i]] = i + 1;
        t1[t[i]] = i + 1;
    }
    return 1;
}

int main() {
    return 0;
}