#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isAnagram(char *s, char *t) {
    int letters[26] = {0};
    for (int i = 0; s[i]; i++) {
        letters[s[i] - 'a']++;
    }
    for (int i = 0; t[i]; i++) {
        letters[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (letters[i] != 0) {
            return 0;
        }
    }
    return 1;
}