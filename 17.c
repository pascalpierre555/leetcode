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
    int* i = (int*)calloc(l, sizeof(int));
    while (l > 0) {
        output[(*returnSize)] = (char*)malloc((l + 1) * sizeof(char));
        for (int j = 0; j < l; j++) {
            output[*returnSize][j] = letters[digits[j] - 49][i[j]];
        }
        output[*returnSize][l] = 0;
        (*returnSize)++;
        int tick = l - 1;
        while ((tick >= 0) && ((i[tick] + 1 > 3) || (letters[digits[tick] - 49][i[tick] + 1] == 0))) {
            i[tick] = 0;
            tick--;
        }
        if (tick >= 0) {
            i[tick]++;
        }
        else {
            break;
        }
    }
    return output;
}

int main() {
    int* returnSize = (int*)malloc(sizeof(int));
    char input[100] = { 0 };
    fgets(input, 100, stdin);
    char** output = letterCombinations(input, returnSize);
}