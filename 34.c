#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
    int output[2] = [ -1, -1 ];
    int l = 0, r = numsSize - 1;
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if ((m + 1 < numsSize) && (nums[m] < target) && (nums[m + 1] == target)) {
            output[0] = m + 1;
        }
        else if (nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
}

int main() {
    return 0;
}