#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num, i;
    struct Node *next;
} Node;

bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    Node **hash = (Node **)calloc(numsSize, sizeof(Node)); // array of linked lists

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) % numsSize;

        for (Node *b = hash[index]; b; b = b->next)
            if (b->num == nums[i] && abs(b->i - i) <= k)
                return true;

        // Not found => insert in start
        Node *new = (Node *)malloc(sizeof(Node));
        new->num = nums[i];
        new->i = i;
        new->next = hash[index];
        hash[index] = new;
    }

    return false;
}