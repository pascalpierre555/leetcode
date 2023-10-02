#include <stdio.h>
#include <string.h>

char **appendLetter(char **input, char *append, int returnSize) {
    char **output = (char **)malloc(257 * sizeof(char *));
    int i = 0;
    int i2 = 0;
    for (int k = 0; k < returnSize; k++) {
        while (input[i][0] != '\0') {
            int j = 0;
            while (input[i][j] != '\0') {
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
        if (digits[i] != '\0') {
            appendLetter(output, letters[digits[i] - 48], returnSize[digits[i] - 48]);
        }
    }
    return output;
}

int main() {
    int returnSize[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    char *digits = (char *)calloc(5, sizeof(char));
    scanf("%d", &returnSize);
    scanf("%s", digits);
    int i = 0, j = 0;
    char **output = letterCombinations(digits, returnSize);
    while (output[i][0] != '\0') {
        printf("%s", output[i]);
        i++;
        j = 0;
    }
    return 0;
}