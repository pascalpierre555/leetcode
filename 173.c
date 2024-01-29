#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct stack {
    struct TreeNode *node;
    struct stack *next;
} stack;

typedef struct {
    stack *top;
} BSTIterator;

stack *push(struct TreeNode *node, stack *next) {
    stack *output = (stack *)malloc(sizeof(stack));
    output->node = node;
    output->next = next;
    return output;
}

stack *pop(stack *stack1) {
    if (stack1->next) {
        stack *output = stack1->next;
        free(stack1);
        return output;
    }
    return NULL;
}

BSTIterator *bSTIteratorCreate(struct TreeNode *root) {
    stack *stack1 = push(root, NULL);
    stack *output = NULL;
    while (stack1->node->right) { // find biggest value in the tree
        stack1 = push(stack1->node->right, stack1);
    }

    while (stack1) {
        output = push(stack1->node, output);
        if (stack1->node->left) {
            stack1 = push(stack1->node->left, stack1);
            while (stack1->node->right) { // find biggest value in the tree
                stack1 = push(stack1->node->right, stack1);
            }
        }
        else {
            while ((stack1) && (stack1->node->val >= output->node->val)) {
                stack1 = pop(stack1);
            }
        }
    }
    BSTIterator *bst = (BSTIterator *)malloc(sizeof(BSTIterator));
    bst->top = output;
    return bst;
}

int bSTIteratorNext(BSTIterator *obj) {
    if (obj->top) {
        int output = obj->top->node->val;
        obj->top = pop(obj->top);
        return output;
    }
    return 0;
}

bool bSTIteratorHasNext(BSTIterator *obj) {
    if (obj->top) {
        return 1;
    }
    return 0;
}

void bSTIteratorFree(BSTIterator *obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);

 * bool param_2 = bSTIteratorHasNext(obj);

 * bSTIteratorFree(obj);
*/

int main() {
    return 0;
}