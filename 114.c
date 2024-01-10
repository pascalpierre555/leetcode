#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void moveToRight(struct TreeNode *root) {
    if (root->left) {
        root->right = root->left;
        root->left = NULL;
        moveToRight(root->right);
    }
    return;
}

void traverse(struct TreeNode *root, struct TreeNode *prev) {
    if (root->left) {
        prev->left = root->left;
        prev = prev->left;
        traverse(root->left, prev);
    }
    if (root->right) {
        prev->left = root->right;
        prev = prev->left;
        traverse(root->right, prev);
    }
    return;
}

void flatten(struct TreeNode *root) {
    if (root) {
        traverse(root, root);
        moveToRight(root);
    }
    return root;
}

int main() {
    return 0;
}