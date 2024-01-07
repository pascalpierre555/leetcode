#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void traverse(struct TreeNode *root, int *max, int *path) {
    if (root->left) {
        (*path)++;
        if (*path > *max) {
            *max = *path;
        }
        traverse(root->left, max, path);
    }
    if (root->right) {
        (*path)++;
        if (*path > *max) {
            *max = *path;
        }
        traverse(root->right, max, path);
    }
    (*path)--;
    return;
}

int maxDepth(struct TreeNode *root) {
    int max = 0;
    int path = 0;
    if (root) {
        path++;
        if (path > max) {
            max = path;
        }
        traverse(root, &max, &path);
    }
    return max;
}