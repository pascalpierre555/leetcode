#include <stdio.h>
#include <stdlib.h>

void merge(int *nums, int l, int r, int m) {
    int *tmp1 = (int *)malloc((m - l + 1) * sizeof(int));
    int *tmp2 = (int *)malloc((r - m) * sizeof(int));
    for (int i = l; i <= m; i++) {
        tmp1[i - l] = nums[i];
    }
    for (int i = m + 1; i <= r; i++) {
        tmp2[i - (m + 1)] = nums[i];
    }
    int idx1 = 0, idx2 = 0;
    while ((idx1 < (m - l + 1)) && (idx2 < (r - m))) {
        if (tmp1[idx1] < tmp2[idx2]) {
            nums[l + idx1 + idx2] = tmp1[idx1];
            idx1++;
        }
        else {
            nums[l + idx1 + idx2] = tmp2[idx2];
            idx2++;
        }
    }
    while (idx1 < (m - l + 1)) {
        nums[l + idx1 + idx2] = tmp1[idx1];
        idx1++;
    }
    while (idx2 < (r - m)) {
        nums[l + idx1 + idx2] = tmp2[idx2];
        idx2++;
    }
    free(tmp1);
    free(tmp2);
}

void mergeSort(int *nums, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, r, m);
    }
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int **output = (int **)malloc(sizeof(int *));
    mergeSort(nums, 0, numsSize - 1);
    int size = 0;
    int pos = 0, neg = numsSize - 1;
    int i1, i2;
    int k1 = 123456, k2 = 123456, k3 = 123456;
    for (int i = 0; i < numsSize; i++) { //找到正與負從哪開始
        if (nums[i] >= 0) {
            neg = i - 1;
            break;
        }
    }
    for (int i = neg + 1; i < numsSize; i++) {
        if (nums[i] > 0) {
            pos = i;
            break;
        }
    }
    for (int i = 1; i < numsSize - 1; i++) {
        if ((nums[i] == k2) && (i != 1)) {
            i1 = i - 1;
            i2 = i + 1;
            while ((i1 >= 0) && (i2 < numsSize) && (nums[i1] == nums[i])) {
                if ((nums[i1] == k1) || (nums[i1] + nums[i] + nums[i2] > 0)) {
                    i1--;
                }
                else if ((nums[i2] == k2) || (nums[i1] + nums[i] + nums[i2] < 0)) {
                    i2++;
                }
                else {
                    size++;
                    output = (int **)realloc(output, size * sizeof(int *));
                    output[size - 1] = (int *)malloc(3 * sizeof(int));
                    output[size - 1][0] = nums[i1];
                    output[size - 1][1] = nums[i];
                    output[size - 1][2] = nums[i2];
                    k1 = nums[i1];
                    k2 = nums[i2];
                    i1--;
                    i2++;
                }
            }
            continue;
        }
        else {
            k1 = 123456;
            k2 = nums[i];
            k3 = 123456;
            if (nums[i] == 0) {
                i1 = i - 1;
                i2 = i + 1;
            }
            else if (nums[i] > 0) {
                i1 = neg;
                i2 = i + 1;
            }
            else {
                i1 = i - 1;
                i2 = pos;
            }
            while ((i1 >= 0) && (i2 < numsSize)) {
                if ((nums[i1] == k1) || (nums[i1] + nums[i] + nums[i2] > 0)) {
                    i1--;
                }
                else if ((nums[i2] == k2) || (nums[i1] + nums[i] + nums[i2] < 0)) {
                    i2++;
                }
                else {
                    size++;
                    output = (int **)realloc(output, size * sizeof(int *));
                    output[size - 1] = (int *)malloc(3 * sizeof(int));
                    output[size - 1][0] = nums[i1];
                    output[size - 1][1] = nums[i];
                    output[size - 1][2] = nums[i2];
                    k1 = nums[i1];
                    k2 = nums[i2];
                    i1--;
                    i2++;
                }
            }
        }
    }
    *returnSize = size;
    returnColumnSizes = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        returnColumnSizes[i] = (int *)malloc(sizeof(int));
        returnColumnSizes[i][0] = 3;
    }
    return output;
}

int main() {
    int *numsSize = (int *)malloc(sizeof(int));
    scanf("%d", numsSize);
    int *nums = (int *)calloc(*numsSize, sizeof(int));
    for (int i = 0; i < *numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    int *returnSize = (int *)calloc(1, sizeof(int));
    int **returnColumnSize;
    int **output = threeSum(nums, *numsSize, returnSize, returnColumnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("[%d, %d, %d]\n", output[i][0], output[i][1], output[i][2]);
    }
    return 0;
}