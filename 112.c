#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int targetSum) {
    if ((root->val == targetSum) && (root->left == NULL) && (root->right == NULL)) {
        return 1;
    }
    else if (root->left) {
        if (hasPathSum(root->left, targetSum - root->val) == 1) {
            return 1;
        }
    }
    else if (root->right) {
        return hasPathSum(root->right, targetSum - root->val);
    }
    else {
        return 0;
    }
}

int main() {
    return 0;
}