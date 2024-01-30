#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool traverse(struct TreeNode *root, struct TreeNode *node) {
    bool left = 0;
    bool right = 0;
    if (root == node) {
        return 1;
    }
    else {
        if (root->left) {
            left = traverse(root->left, node);
        }
        if (root->right) {
            right = traverse(root->right, node);
        }
        if (left || right) {
            return 1;
        }
    }
    return 0;
}

struct TreeNode *traverse_p(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root == p) {
        return root;
    }
    else {
        if (root->left) {
            struct TreeNode *output = traverse_p(root->left, p, q);
            if ((root == q) || (output == p && root->right && traverse(root->right, q))) {
                return root;
            }
            else if (output) {
                return output;
            }
        }
        if (root->right) {
            struct TreeNode *output = traverse_p(root->right, p, q);
            if ((root == q) || (output == p && root->left && traverse(root->left, q))) {
                return root;
            }
            else if (output) {
                return output;
            }
        }
    }
    return NULL;
}

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root == NULL) {
        return NULL;
    }
    if (traverse(p, q)) {
        return p;
    }
    return traverse_p(root, p, q);
}

int main() {
    return 0;
}