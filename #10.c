#include <stdbool.h>
#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    bool **match = (bool **)malloc((s_len + 1) * sizeof(bool *));
    for (size_t i = 0; i < s_len + 1; i++) {
        match[i] = (bool *)calloc((p_len + 2), sizeof(bool));
    }
    match[0][0] = 1;
    for (size_t j = 0; j < p_len; j++) {
        if (p[j] == '*') {
            match[0][j + 1] = match[0][j - 1];
        }
    }

    for (size_t i = 0; i < s_len; i++) {
        for (size_t j = 0; j < p_len; j++) {
            if (s[i] == p[j] || p[j] == '.') {
                match[i + 1][j + 1] = match[i][j];
            }
            else if (p[j] == '*') {
                if (s[i] == p[j - 1] || p[j - 1] == '.') {
                    match[i + 1][j + 1] = match[i + 1][j - 1] || match[i + 1][j] || match[i][j + 1];
                }
                else if (j > 0) {
                    match[i + 1][j + 1] = match[i + 1][j - 1];
                }
            }
        }
    }
    return match[s_len][p_len];
=======
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
>>>>>>> 296bdcd5d30d140f76aa2c6824f7fc5de030bbc2
}

int main() {
    char s[21];
    char p[21];
<<<<<<< HEAD
    scanf("%s %s", s, p);
    printf("%d", isMatch(s, p));
=======
    scanf("%s", s);
    scanf("%s", p);
>>>>>>> 296bdcd5d30d140f76aa2c6824f7fc5de030bbc2
    return 0;
}