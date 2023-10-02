#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int *nums, int numsSize) {
    if (numsSize != 0) {
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] <= 0) {
                nums[i] = numsSize + 1;
            }
        }
        for (int i = 0; i < numsSize; i++) {
            if ((abs(nums[i]) <= numsSize) && (nums[abs(nums[i]) - 1] > 0)) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for (int i = 0; i < numsSize; i++) {
            if (nums[i] > 0) {
                return (i + 1);
            }
        }
        return numsSize + 1;
    }
    else {
        return 1;
    }
}

int main() {
    int numsSize;
    scanf("%d", &numsSize);
    int *nums = (int *)calloc(numsSize, sizeof(int));
    for (size_t i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    printf("%d", firstMissingPositive(nums, numsSize));
}