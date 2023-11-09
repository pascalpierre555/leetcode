#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = (struct ListNode*)malloc(sizeof(struct ListNode));
    if ((list1) && (list2)) {
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
    }
    else if (list1) {
        return list1;
    }
    else if (list2) {
        return list2;
    }
    else {
        return 0;
    }
    curr = head;
    while ((list1) && (list2)) {
        if (list1->val < list2->val) {
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
        }
        else {
            curr->next = list2;
            curr = curr->next;
            list2 = list2->next;
        }
    }
    if (list1) {
        curr->next = list1;
    }
    else if (list2) {
        curr->next = list2;
    }
    return head;
}