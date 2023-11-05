#include <stdio.h>
#include <stdlib.h>

void *merge(int *nums, int l, int r, int m) {
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
    int **mergeSort(nums, 0, numsSize);
    int pos = 0, neg = numsSize - 1;
    int i1, i2;
    for (int i = 0; i < numsSize; i++) { //找到正與負從哪開始
        if (nums[i] >= 0) {
            neg = i - 1;
            break;
        }
    }
    for (int i = neg; i < numsSize; i++) {
        if (nums[i] > 0) {
            pos = i;
            break;
        }
    }
    if ()
        for (int i = 1; i < numsSize - 1; i++) {
            if (i <= neg) {
                i1 = i - 1;
            }
        }
}

int main() {
    int numsSize;
    scanf("%d", &numsSize);
    int *nums = (int *)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    mergeSort(nums, 0, numsSize - 1);
    return 0;
}