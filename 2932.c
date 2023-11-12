#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int max(int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int maximumStrongPairXor(int *nums, int numsSize) {
    int output = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if ((min(nums[i], nums[j]) >= abs(nums[i] - nums[j])) && ((nums[i] ^ nums[j]) > output)) {
                output = nums[i] ^ nums[j];
            }
        }
    }
    return output;
}

int main() {
    return 0;
}