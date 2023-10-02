#include <stdio.h>
#include <stdlib.h>

char **appendLetter(char **input, char *append, int returnSize) {
    char **output = (char **)malloc(257 * sizeof(char *));
    int i = 0;
    int i2 = 0;
    for (int k = 0; k < returnSize; k++) {
        while (input[i][0] != NULL) {
            int j = 0;
            while (input[i][j] != NULL) {
                output[i2][j] = input[i][j];
                j++;
            }
            output[i][j] = append[k];
            i++;
            i2++;
        }
        i = 0;
    }
    return output;
}

char **letterCombinations(char *digits, int *returnSize) {
    char **output = (char **)malloc(257 * sizeof(char *));
    char letters[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for (int i = 0; i < 5; i++) {
        if (digits[i] != NULL) {
            appendLetter(output, letters[digits[i] - 48], returnSize[digits[i] - 48]);
        }
    }
}

int main() {
    int returnSize;
    char *digits = (char *)calloc(5, sizeof(char));
    scanf("%d", &returnSize);
    scanf("%s", digits);
    int i = 0, j = 0;
    char **output = (char **)malloc(257 * sizeof(char *));
    while (output[i][0] != NULL) {
        printf("%s", output[i]);
        i++;
        j = 0;
    }
    return 0;
}