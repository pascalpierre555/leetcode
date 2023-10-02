#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *initializeNode(int value) {
    struct ListNode *new = malloc(sizeof(struct ListNode));
    new->val = value;
    new->next = NULL;
    return new;
}

void insertNode(int value, struct ListNode *prev) {
    if (prev != NULL) {
        struct ListNode *new = malloc(sizeof(struct ListNode));
        new->val = value;
        new->next = NULL;
        prev->next = new;
    }
    else {
        struct ListNode *new;
        new->val = value;
        new->next = NULL;
    }
}

void merge(struct ListNode **lists, struct ListNode **left, struct ListNode **right, int leftSize, int rightSize) {
    int lIndex = 0, rIndex = 0, index = 0;
    while ((lIndex < leftSize) && (rIndex < rightSize)) {
        if ((left[lIndex] == NULL) || ((right[rIndex] != NULL) && (left[lIndex]->val <= right[rIndex]->val))) {
            lists[index] = left[lIndex];
            lIndex++;
        }
        else {
            lists[index] = right[rIndex];
            rIndex++;
        }
        index++;
    }
    while (lIndex < leftSize) {
        lists[index] = left[lIndex];
        lIndex++;
        index++;
    }
    while (rIndex < rightSize) {
        lists[index] = right[rIndex];
        rIndex++;
        index++;
    }
}

void mergeSort(struct ListNode **lists, int size) {
    if (size <= 1) {
        return;
    }
    int mid = size / 2;
    struct ListNode **left = (struct ListNode **)calloc(mid, sizeof(struct ListNode *));
    struct ListNode **right = (struct ListNode **)calloc((size - mid), sizeof(struct ListNode *));
    for (size_t i = 0; i < mid; i++) {
        left[i] = lists[i];
    }
    for (size_t i = mid; i < size; i++) {
        right[i - mid] = lists[i];
    }
    mergeSort(left, mid);
    mergeSort(right, (size - mid));
    merge(lists, left, right, mid, size - mid);
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    mergeSort(lists, listsSize);
    if (listsSize != 0) {
        struct ListNode *output = calloc(1, sizeof(struct ListNode));
        struct ListNode *head = output;
        struct ListNode *current = NULL;
        while (listsSize > 0) { //每個while迴圈會讓list多加一項
            current = lists[0];
            for (size_t i = 1; i < listsSize; i++) { //檢查新的lists[0]是否為最小的一項，如果不是就將它往後移到正確位置
                if (((current == NULL) || (lists[i] == NULL)) || (current->val > lists[i]->val)) {
                    lists[i - 1] = lists[i];
                    lists[i] = current;
                }
                else {
                    break;
                }
            }
            if (current != NULL) {
                if (lists[0] != NULL) {
                    output->next = lists[0]; //如果lists[0]存在，就將它接到output的下一位，並把output指向新的node
                    output = output->next;
                    if (lists[0]->next != NULL) { //把lists[0]指向它的下一項
                        lists[0] = lists[0]->next;
                    }
                    else {
                        lists[0] = NULL;
                    }
                }
            }
            else {
                listsSize--;
            }
            current = lists[0];
        }
        return head->next;
    }
    else {
        return NULL;
    }
}

int main() {
    int listsSize;
    int input;
    struct ListNode *tempNode;
    scanf("%d", &listsSize);
    struct ListNode **lists = (struct ListNode **)calloc(listsSize, sizeof(struct ListNode *));
    int *list_l = (int *)calloc(listsSize, sizeof(int));
    for (size_t i = 0; i < listsSize; i++) {
        scanf("%d", &list_l[i]);
    }
    for (size_t i = 0; i < listsSize; i++) {
        for (size_t j = 0; j < list_l[i]; j++) {
            scanf("%d", &input);
            if (j == 0) {
                lists[i] = initializeNode(input);
                tempNode = lists[i];
            }
            else {
                insertNode(input, tempNode);
                tempNode = tempNode->next;
            }
        }
    }
    struct ListNode *output = mergeKLists(lists, listsSize);
    return 0;
}