#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* gengenPar(char** output, char* tmp, int n, int returnSize) {
    int returnSize2 = (returnSize + 1) / 3;
    if (n == 1) {
        strcat(output[0], "()");
        return 0;
    }
    else {
        gengenPar(output, tmp, n - 1, returnSize2);
        memset(tmp, 0, (2 * n + 1) * sizeof(char));
        strcat(tmp, "(");
        strcat(tmp, output[0]);
        strcat(tmp, ")");
        strcat(output[returnSize - 1], tmp);
        returnSize--;
        memset(tmp, 0, (2 * n + 1) * sizeof(char));
        strcat(output[0], "()");
        for (int i = 1; i < returnSize2; i++) {
            memset(tmp, 0, (2 * n + 1) * sizeof(char));
            strcat(tmp, "()");
            strcat(tmp, output[i]);
            strcat(output[returnSize - 1], tmp);
            returnSize--;
            memset(tmp, 0, (2 * n + 1) * sizeof(char));
            strcat(tmp, "(");
            strcat(tmp, output[i]);
            strcat(tmp, ")");
            strcat(output[returnSize - 1], tmp);
            returnSize--;
            strcat(output[i], "()");
        }
    }
    return 0;
}

char** generateParenthesis(int n, int* returnSize) {
    if (n == 0) {
        (*returnSize) = 0;
        return 0;
    }
    (*returnSize) = 1;
    for (int i = 0; i < n - 1; i++) {
        (*returnSize) = ((*returnSize) * 3) - 1;
    }
    char** output = (char**)malloc((*returnSize) * sizeof(char*));
    char* tmp = (char*)calloc((2 * n + 1), sizeof(char));
    for (int i = 0; i < (*returnSize); i++) {
        output[i] = (char*)calloc((2 * n + 1), sizeof(char));
    }
    gengenPar(output, tmp, n, (*returnSize));
    return output;
}

int main() {
    int* returnSize = malloc(sizeof(int));
    int a;
    scanf("%d", &a);
    char** output = generateParenthesis(a, returnSize);
    for (int i = 0; i < (*returnSize); i++) {
        printf("%s\n", output[i]);
    }
}