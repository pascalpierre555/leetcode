#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}
int trap(int *height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int h;
    int hl = height[l], hr = height[r];
    int output = 0;
    h = min(hl, hr);
    while (l < r) {
        if (hl <= hr) {
            l++;
            if (height[l] > hl) {
                hl = height[l];
                h = min(hl, hr);
                continue;
            }
            output += (h - height[l]);
        }
        else {
            r--;
            if (height[r] > hr) {
                hr = height[r];
                h = min(hl, hr);
                continue;
            }
            output += (h - height[r]);
        }
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
    int output = trap(nums, *numsSize);
    printf("%d", output);
    return 0;
}