#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    int i = 1;
    struct ListNode *curr = head;
    while (curr->next) {
        i++;
        curr = curr->next;
    }
    i -= (n + 1);
    curr = head;
    if (i < 0) {
        head = head->next;
    }
    while (i > 0) {
        i--;
        curr = curr->next;
    }
    if (curr->next) {
        curr->next = curr->next->next;
    }
    return head;
}

int main() {
    return 0;
}