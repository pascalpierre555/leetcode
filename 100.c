#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {

    int l = 1;
    int r = 1;
    if (((p == NULL) && (q != NULL)) || ((p != NULL) && (q == NULL))) {
        return 0;
    }
    else if ((p == NULL) && (q == NULL)) {
        return 1;
    }
    else if ((p && q) && (p->val != q->val)) {
        return 0;
    }
    if (p->left && q->left) {
        l = isSameTree(p->left, q->left);
    }
    else if (p->left || q->left) {
        l = 0;
    }
    if (p->right && q->right) {
        r = isSameTree(p->right, q->right);
    }
    else if (p->right || q->right) {
        r = 0;
    }
    return l * r;
}