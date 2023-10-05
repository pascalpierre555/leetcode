#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *newNode(struct ListNode *curr) {
    struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
    next->val = 0;
    next->next = NULL;
    if (curr != NULL) {
        curr->next = next;
    }
    else {
        curr = next;
    }
    return next;
}

struct ListNode *newNode2(struct ListNode *curr, int input) {
    struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
    next->val = input;
    next->next = NULL;
    if (curr != NULL) {
        curr->next = next;
    }
    else {
        curr = next;
    }
    return next;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int carry = 0;
    int sum = 0;
    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;
    while (l1 != NULL && l2 != NULL) {
        curr = newNode(curr);
        if (head == NULL) {
            head = curr;
        }
        sum = l1->val + l2->val;
        if (carry > 0) {
            sum++;
            carry = 0;
        }
        if (sum >= 10) {
            carry++;
            sum -= 10;
        }
        curr->val = sum;
        sum = 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL) {
        curr = newNode(curr);
        if (head == NULL) {
            head = curr;
        }
        sum = l1->val;
        if (carry > 0) {
            sum++;
            carry = 0;
        }
        if (sum >= 10) {
            carry++;
            sum -= 10;
        }
        curr->val = sum;
        sum = 0;
        l1 = l1->next;
    }
    while (l2 != NULL) {
        curr = newNode(curr);
        if (head == NULL) {
            head = curr;
        }
        sum = l2->val;
        if (carry > 0) {
            sum++;
            carry = 0;
        }
        if (sum >= 10) {
            carry++;
            sum -= 10;
        }
        curr->val = sum;
        sum = 0;
        l2 = l2->next;
    }
    if (carry > 0) {
        curr = newNode(curr);
        sum++;
        carry = 0;
        curr->val = sum;
        sum = 0;
    }
    return head;
}

int main() {
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *curr = NULL;
    int input;
    int ll1, ll2;
    scanf("%d %d", &ll1, &ll2);
    for (int i = 0; i < ll1; i++) {
        scanf("%d", &input);
        curr = newNode2(curr, input);
        if (l1 == NULL) {
            l1 = curr;
        }
    }
    curr = NULL;
    for (int i = 0; i < ll2; i++) {
        scanf("%d", &input);
        curr = newNode2(curr, input);
        if (l2 == NULL) {
            l2 = curr;
        }
    }
    struct ListNode *head = addTwoNumbers(l1, l2);
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}