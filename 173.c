#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    struct TreeNode *node;
    stack *next;
} stack;

typedef struct {
    struct TreeNode *next;
} BSTIterator;

stack *push(struct TreeNode *node, stack *next) {
    stack *output = (stack *)malloc(sizeof(stack));
    output->node = node;
    output->next = next;
    return output;
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root) {
    stack *stack1 = push(root, NULL);
    while (stack1->node->right) {
        stack1 = push(stack1->node->right, stack1);
    }
    BSTIterator *bst = (BSTIterator *)malloc(sizeof(BSTIterator));
}

int bSTIteratorNext(BSTIterator *obj) {
}

bool bSTIteratorHasNext(BSTIterator *obj) {
}

void bSTIteratorFree(BSTIterator *obj) {
    free(obj);
}

int main() {
    return 0;
}