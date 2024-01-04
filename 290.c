#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool wordPattern(char *pattern, char *s) {
    char *letters[26] = {0};
    char *tok = strtok(s, " ");
    int i = 0;
    int len = strlen(pattern);
    while (tok) {
        if (i >= len) {
            return 0;
        }
        if (letters[pattern[i] - 'a'] == NULL) {
            letters[pattern[i] - 'a'] = tok;
        }
        else if (strcmp(letters[pattern[i] - 'a'], tok) != 0) {
            return 0;
        }
        tok = strtok(NULL, " ");
        i++;
    }
    if (i < len) {
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if ((letters[i]) && (letters[j]) && (strcmp(letters[i], letters[j]) == 0)) {
                return 0;
            }
        }
    }
    return 1;
}
