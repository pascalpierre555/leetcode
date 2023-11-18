#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    int output = 1;
    for (int i = 2; i <= n; i++) {
        output *= i;
    }
    return output;
}

int **findArr(int n) {
    int facn = factorial(n);
    int **output = (int **)malloc(facn * sizeof(int *));
    for (int i = 0; i < facn; i++) {
        output[i] = malloc(n * sizeof(int));
    }
    if (n == 1) {
        output[0][0] = 0;
    }
    else {
        int **input = findArr(n - 1);
        for (int i = 0; i < facn / n; i++) {
            for (int j = 0; j < n - 1; j++) {
                for (int k = 0; k < n; k++) {
                    output[n * i + k][j] = (input[i][j] + k) % n;
                }
            }
        }
        for (int i = 0; i < facn / n; i++) {
            for (int k = 0; k < n; k++) {
                output[n * i + k][n - 1] = (n - 1 + k) % n;
            }
        }
        for (int i = 0; i < facn / n; i++) {
            free(input[i]);
        }
        free(input);
    }
    return output;
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int **arr = findArr(numsSize);
    *returnSize = factorial(numsSize);
    (*returnColumnSizes) = (int *)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            arr[i][j] = nums[arr[i][j]];
        }
    }
    return arr;
}

int main() {
    int numsSize;
    scanf("%d", &numsSize);
    int *nums = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    int returnSize;
    int **retrunColumnSize;
    int **output = permute(nums, numsSize, &returnSize, retrunColumnSize);
    return 0;
}