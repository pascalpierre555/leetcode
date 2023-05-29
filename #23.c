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

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if ((lists[0] != NULL) && (listsSize != 0)) {
        struct ListNode *output = lists[0];
        struct ListNode *head = lists[0];
        lists[0] = lists[0]->next;
        struct ListNode *tmp = lists[0];
        int i = 1;
        while ((i < listsSize) && (tmp->val > lists[i]->val)) {
            lists[i - 1] = lists[i];
            lists[i] = tmp;
            i++;
        }
        while (lists[0] != NULL) {
            output->next = lists[0]; //如果lists[0]存在，就將它接到output的下一位，並把output指向新的node
            output = output->next;
            if (lists[0]->next != NULL) { //把lists[0]指向它的下一項
                lists[0] = lists[0]->next;
            }
            else {
                lists[0] = NULL;
            }
            tmp = lists[0]; //檢查新的lists[0]是否為最小的一項，如果不是就將它往後移到正確位置
            int i = 1;
            while ((i < listsSize) && ((tmp == NULL) || (tmp->val > lists[i]->val))) {
                lists[i - 1] = lists[i];
                lists[i] = tmp;
                i++;
            }
        }
        return head;
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