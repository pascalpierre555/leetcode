#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int left = 0;
    int right = 0;
    if (root->left) {
        left = countNodes(root->left);
    }
    if (root->right) {
        right = countNodes(root->right);
    }
    return left + right + 1;
}
int main() {
    return 0;
}