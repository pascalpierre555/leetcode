#include <stdio.h>
#include <stdlib.h>

int binarySort(int* nums, int l, int r, int target) {
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (nums[m] == target) {
            return m;
        }
        else if (nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return -1;
}

int search(int* nums, int numsSize, int target) {
    int head = nums[0];
    int tail = nums[numsSize - 1];
    int l = 0;
    int r = numsSize - 1;
    int m;
    while (r >= l) {
        m = l + (r - l) / 2;
        if ((m + 1 <= r) && (nums[m] > nums[m + 1])) {
            if (target > head) {
                return binarySort(nums, 0, m, target);
            }
            else if (target < head) {
                return binarySort(nums, m + 1, numsSize - 1, target);
            }
            else {
                return 0;
            }
        }
        else if ((m - 1 >= l) && (nums[m - 1] > nums[m])) {
            if (target > head) {
                return binarySort(nums, 0, m - 1, target);
            }
            else if (target < head) {
                return binarySort(nums, m, numsSize - 1, target);
            }
            else {
                return 0;
            }
        }
        else if (nums[m] > head) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return binarySort(nums, 0, numsSize - 1, target);
}