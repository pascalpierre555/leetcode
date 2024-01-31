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
    struct TreeNode *leftNode = root;
    struct TreeNode *rightNode = root;
    int left = 1;
    int right = 1;
    while (leftNode->left) {
        leftNode = leftNode->left;
        left *= 2;
    }
    while (rightNode->right) {
        rightNode = rightNode->right;
        right *= 2;
    }
    if (left == right) {
        return left + right - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}