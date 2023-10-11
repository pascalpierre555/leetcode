#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    if (x <= y) {
        return x;
    }
    else {
        return y;
    }
}

int maxArea(int *height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    int water = 0;
    while (right > left) {
        water = (min(height[right], height[left]) * (right - left));
        if (water > max) {
            max = water;
        }
        if (height[right] > height[left]) {
            left++;
        }
        else {
            right--;
        }
    }
    return max;
}

int main() {
    return 0;
}
