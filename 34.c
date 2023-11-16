#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int *output = (int *)malloc(2 * sizeof(int));
    output[0] = -1;
    output[1] = -1;
    int l = 0, r = numsSize - 1;
    int m;
    *returnSize = 2;
    while (l <= r) {
        m = l + (r - l) / 2;
        if ((m + 1 <= r) && (nums[m] < target) && (nums[m + 1] == target)) {
            output[0] = m + 1;
        }
        else if (nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    l = 0;
    r = numsSize - 1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if ((m + 1 <= r) && (nums[m] == target) && (nums[m + 1] > target)) {
            output[0] = m;
        }
        else if (nums[m] <= target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return output;
}

int main() {
    int numsSize;
    scanf("%d", &numsSize);
    int target;
    scanf("%d", &target);
    int *returnSize = malloc(sizeof(int));
    int *nums = (int *)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", nums[i]);
    }
    int *output = searchRange(nums, numsSize, target, returnSize);
    for (int i = 0; i < 2; i++) {
        printf("%d ", output[i]);
    }
    return 0;
}