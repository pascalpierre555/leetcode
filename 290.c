#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool wordPattern(char *pattern, char *s) {
    int i1 = 0;
    int i2 = 0;
    int length = 0;
    char *letters[26] = {0};
    for (int i = 0; pattern[i] != 0; i++) {
        while ((pattern[i2] != ' ') && (i2 <= strlen(s))) {
            i2++;
        }
        length = i2 - i1 - 1;
        if (letters[pattern[i] - 'a'] == NULL) {
            letters[pattern[i] - 'a'] = (char *)calloc(512, sizeof(char));
            strncpy(letters[pattern[i] - 'a'], s[i1], length);
        }
        else if ((letters[pattern[i] - 'a'] != NULL) && (strncmp(letters[pattern[i] - 'a'], &s[i1], length) != 0)) {
            return 0;
        }
        i1 = i2;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if ((strcmp(letters[i], letters[j]) == 0) && (i != j)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    return 0;
}