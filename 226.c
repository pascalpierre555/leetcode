#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
    struct TreeNode *tmp;
    if (root) {
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left) {
            invertTree(root->left);
        }
        if (root->right) {
            invertTree(root->right);
        }
    }
    return root;
}