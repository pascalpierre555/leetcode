#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *gengenPar(char *input, char **output, int pos, int l, int r, int n, int *returnSize) {
    if (pos == 2 * n) {
        input[pos] = 0;
        output[*returnSize] = (char *)malloc(((2 * n) + 1) * sizeof(char));
        strcpy(output[*returnSize], input);
        (*returnSize)++;
        return 0;
    }
    if (l < n) {
        input[pos] = '(';
        gengenPar(input, output, pos + 1, l + 1, r, n, returnSize);
    }
    if ((r < n) && (r < l)) {
        input[pos] = ')';
        gengenPar(input, output, pos + 1, l, r + 1, n, returnSize);
    }
    return 0;
}

char **generateParenthesis(int n, int *returnSize) {
    (*returnSize) = 0;
    if (n == 0) {
        return 0;
    }
    char **output = (char **)malloc(2048 * sizeof(char *));
    char *input = (char *)malloc(((2 * n) + 1) * sizeof(char));
    gengenPar(input, output, 0, 0, 0, n, returnSize);
    return output;
}

int main() {
    int *returnSize = malloc(sizeof(int));
    int a;
    scanf("%d", &a);
    char **output = generateParenthesis(a, returnSize);
    for (int i = 0; i < (*returnSize); i++) {
        printf("%s\n", output[i]);
    }
    return 0;
}