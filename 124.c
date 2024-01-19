#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxSideSum(struct TreeNode *root, int *output) {
    if (root == NULL) {
        return 0;
    }
    int left = 0;
    int right = 0;
    if (root->left) {
        left = maxSideSum(root->left, output);
        if (left < 0) {
            left = 0;
        }
    }
    if (root->right) {
        right = maxSideSum(root->right, output);
        if (right < 0) {
            right = 0;
        }
    }
    if (root->val + right + left > (*output)) {
        *output = root->val + right + left;
    }
    if (left > right) {
        return left + root->val;
    }
    else if (right > left) {
        return right + root->val;
    }
    return root->val;
}

int maxPathSum(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int output = -__INT_MAX__;
    maxSideSum(root, &output);
    return output;
}

int main() {
    return 0;
}