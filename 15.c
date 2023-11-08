#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int l, int r, int m) {
    int* tmp1 = (int*)malloc((m - l + 1) * sizeof(int));
    int* tmp2 = (int*)malloc((r - m) * sizeof(int));
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

void mergeSort(int* nums, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, r, m);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int** output = (int**)malloc(512 * sizeof(int*));
    mergeSort(nums, 0, numsSize - 1);
    *returnSize = 0;
    int l, r;
    int i1 = 123456, i2 = 123456, i3 = 123456;
    for (int i = 0; (i < numsSize - 2) && (nums[i] <= 0); i++) {
        if (nums[i] == i1) {
            continue;
        }
        i2 = 123456;
        i3 = 123456;
        l = i + 1;
        r = numsSize - 1;
        while (l < r) {
            if ((nums[i] + nums[l] + nums[r] < 0) || (nums[l] == i2)) {
                i2 = nums[l];
                l++;
            }
            else if ((nums[i] + nums[l] + nums[r] > 0) || (nums[r] == i3)) {
                i3 = nums[r];
                r--;
            }
            else {
                (*returnSize)++;
                if (*returnSize % 512 == 0) {
                    output = realloc(output, ((*returnSize / 512) + 1) * 512 * sizeof(int*));
                }
                output[*returnSize - 1] = (int*)malloc(3 * sizeof(int));
                output[*returnSize - 1][0] = nums[i];
                output[*returnSize - 1][1] = nums[l];
                output[*returnSize - 1][2] = nums[r];
                i2 = nums[l];
                i3 = nums[r];
                l++;
                r--;
            }

        }
        i1 = nums[i];
    }
    (*returnColumnSizes) = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        returnColumnSizes[0][i] = 3;
    }
    return output;
}

int main() {
    int* numsSize = (int*)malloc(sizeof(int));
    scanf("%d", numsSize);
    int* nums = (int*)calloc(*numsSize, sizeof(int));
    for (int i = 0; i < *numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    int* returnSize = (int*)calloc(1, sizeof(int));
    int** returnColumnSize;
    int** output = threeSum(nums, *numsSize, returnSize, returnColumnSize);
    for (int i = 0; i < *returnSize; i++) {
        printf("[%d, %d, %d]\n", output[i][0], output[i][1], output[i][2]);
    }
    return 0;
}