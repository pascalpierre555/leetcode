#include <stdio.h>
#include <stdlib.h>

void merge(int left, int mid, int right, int *arr, int *index) {
    int i = 0;
    int j = 0;
    int k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int L2[n1], R2[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        L2[i] = index[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + i + 1];
        R2[i] = index[mid + i + 1];
    }
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            index[k] = L2[i];
            i++;
        }
        else {
            arr[k] = R[j];
            index[k] = R2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        index[k] = L2[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        index[k] = R2[j];
        j++;
        k++;
    }
}

void mergeSort(int left, int right, int *arr, int *index) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid, arr, index);
        mergeSort(mid + 1, right, arr, index);
        merge(left, mid, right, arr, index);
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    returnSize[0] = 2;
    int *index = (int *)malloc(sizeof(int) * numsSize);
    int *output = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        index[i] = i;
    }
    mergeSort(0, numsSize - 1, nums, index);
    int right = numsSize - 1;
    int left = 0;
    while (right > left) {
        if (nums[right] + nums[left] == target) {
            output[0] = index[left];
            output[1] = index[right];
            break;
        }
        else if (nums[right] + nums[left] < target) {
            printf("%d\n", left);
            left++;
        }
        else {
            printf("%d\n", right);
            right--;
        }
    }
    return output;
}

int main() {
    int numsSize, target;
    scanf("%d", &numsSize);
    int *nums = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &target);
    int *output = twoSum(nums, numsSize, target, 0);
    printf("%d %d", output[0], output[1]);
    return 0;
}