#include <stdbool.h>
#include <stdio.h>
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
}