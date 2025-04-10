#include <stdio.h>
#include <stdlib.h>

void rotate(int **matrix, int matrixSize, int *matrixColSize) {
    int tmp;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixSize - 1; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize / 2; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - 1 - j];
            matrix[i][matrixSize - 1 - j] = tmp;
        }
    }
}

int main() {

    return 0;
}