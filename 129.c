#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int poww(int x, int n) {
    int output = 1;
    for (int i = 0; i < n; i++) {
        output *= x;
    }
    return output;
}

int dfs(struct TreeNode *root, int n) {
    if (root == NULL) {
        return 0;
    }
    n = n * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return n;
    }
    int left = 0, right = 0;
    if (root->left) {
        left = dfs(root->left, n);
        printf("%d ", left);
    }
    if (root->right) {
        right = dfs(root->right, n);
    }
    return left + right;
}

int sumNumbers(struct TreeNode *root) {
    return dfs(root, 0);
}
int main() {
    return 0;
}