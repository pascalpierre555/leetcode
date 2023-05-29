#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if ((nums2Size > nums1Size) || ((nums1Size == nums2Size) && (nums1[0] < nums2[0]))) {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int tmpSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tmpSize;
    }
    int l = 0;
    int r = nums1Size - 1;
    double output = 0;
    int cursor1 = (nums1Size - 1) / 2; //選定中點當初始cursor
    int cursor2;
    if (nums2Size == 0) {
        if (nums1Size % 2 != 0) {
            return nums1[nums1Size / 2];
        }
        else {
            return (nums1[nums1Size / 2] + nums1[(nums1Size / 2) - 1]) * 0.5;
        }
    }
    while ((r - l) > 1) {
        //右-左的元素數量相差nums1Size - 2*(cursor1 + 1)
        cursor1 = (l + r) / 2;
        cursor2 = (nums1Size - 2 * (cursor1 + 1) + nums2Size - 2) / 2;
        if (cursor2 < 0) {
            r = cursor1;
        }
        else if (cursor2 >= nums2Size) {
            l = cursor1;
        }
        else {
            if (nums1[cursor1] > nums2[cursor2]) {
                r = cursor1;
            }
            else if (nums1[cursor1] < nums2[cursor2]) {
                l = cursor1;
            }
            else {
                l = cursor1;
                r = cursor1 + 1;
            }
        }
    }
    int l2 = ((nums1Size + nums2Size) / 2) - r - 2;
    int r2 = ((nums1Size + nums2Size) / 2) - l - 2;
    if ((nums1Size == nums2Size) && (nums1[0] >= nums2[nums2Size - 1])) {
        output = (nums1[0] + nums2[nums2Size - 1]) * 0.5;
    }
    else if ((nums1Size + nums2Size) % 2 == 0) {
        for (size_t i = 0; i < 2; i++) {
            if (((l2 < nums2Size) && (l2 >= 0)) && ((l < nums1Size) && (l >= 0))) {
                if (nums1[l] < nums2[l2]) {
                    l++;
                }
                else {
                    l2++;
                }
            }
            else if (l2 < 0) {
                l2++;
            }
            else if (l2 < nums2Size) {
                l2++;
            }
            else {
                l++;
            }
        }
        for (size_t i = 0; i < 2; i++) {
            if (((l2 < nums2Size) && (l2 >= 0)) && ((l < nums1Size) && (l >= 0))) {
                if (nums1[l] < nums2[l2]) {
                    output += nums1[l];
                    l++;
                }
                else {
                    output += nums2[l2];
                    l2++;
                }
            }
            else if (l2 < 0) {
                l2++;
            }
            else if (l2 < nums2Size) {
                output += nums2[l2];
                l2++;
            }
            else {
                output += nums1[l];
                l++;
            }
        }
        output *= 0.5;
    }
    else {
        int iteration;
        if ((nums1Size + nums2Size) < 4) {
            iteration = nums1Size + nums2Size - r2;
        }
        else {
            iteration = 4;
        }
        for (size_t i = 0; i < iteration; i++) {
            if (((l2 < nums2Size) && (l2 >= 0)) && ((l < nums1Size) && (l >= 0))) {
                if (nums1[l] < nums2[l2]) {
                    output = nums1[l];
                    l++;
                }
                else {
                    output = nums2[l2];
                    l2++;
                }
            }
            else if (l2 < 0) {
                l2++;
            }
            else if (l2 < nums2Size) {
                output = nums2[l2];
                l2++;
            }
            else {
                output = nums1[l];
                l++;
            }
        }
    }
    return output;
}