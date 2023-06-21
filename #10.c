#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool compare(char a, char b) {
    if ((a == b) || (b == '.')) {
        return 1;
    }
    else {
        return 0;
    }
}

bool isMatch(char *s, char *p) {
    bool *match = calloc(20, sizeof(bool));
    size_t j = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        if (compare(s[i], p[j]) == 1) {
            match[i] = 1;
        }
        else if (p[j])
    }
}

int main() {
    char s[21];
    char p[21];
    scanf("%s", s);
    scanf("%s", p);
    return 0;
}