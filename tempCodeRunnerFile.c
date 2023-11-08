#include <stdlib.h>
#include <stdio.h>

char** letterCombinations(char* digits, int* returnSize) {
    int size = 1;
    int l = 0;
    (*returnSize) = 0;
    char letters[9][4] = {
        {0, 0, 0, 0},
        {'a', 'b', 'c', 0},
        {'d', 'e', 'f', 0},
        {'g', 'h', 'i', 0},
        {'j', 'k', 'l', 0},
        {'m', 'n', 'o', 0},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v', 0},
        {'w', 'x', 'y', 'z'}
    };
    for (int i = 0; (digits[i] != 0) && (digits[i] != '\n'); i++) {
        size *= 4;
        l++;
    }
    char** output = (char**)malloc(size * sizeof(char*));