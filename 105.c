#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void insertLeftNode(struct TreeNode *root, int left) {
    struct TreeNode *leftNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    leftNode->val = left;
    leftNode->left = NULL;
    leftNode->right = NULL;
    root->left = leftNode;
    return;
}

void insertRightNode(struct TreeNode *root, int right) {
    struct TreeNode *rightNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    rightNode->val = right;
    rightNode->left = NULL;
    rightNode->right = NULL;
    root->right = rightNode;
    return;
}

int search(int *order, int left, int right, int target) {
    for (int i = left; i <= right; i++) {
        if (order[i] == target) {
            return i;
        }
    }
    return -1;
}

void createSubTree(struct TreeNode *root, int *preorder, int *inorder, int left, int mid, int right, int *i, int preorderSize) {
    if ((*i) + 1 >= preorderSize) {
        return;
    }
    int index = search(inorder, left, right, preorder[(*i) + 1]);
    if (index > mid) {
        insertRightNode(root, preorder[(*i) + 1]);
        (*i)++;
        createSubTree(root->right, preorder, inorder, mid + 1, index, right, i, preorderSize);
    }
    else if (index >= 0) {
        insertLeftNode(root, preorder[(*i) + 1]);
        (*i)++;
        createSubTree(root->left, preorder, inorder, left, index, mid - 1, i, preorderSize);
        if ((*i) + 1 >= preorderSize) {
            return;
        }
        index = search(inorder, left, right, preorder[(*i) + 1]);
        if (index > mid) {
            insertRightNode(root, preorder[(*i) + 1]);
            (*i)++;
            createSubTree(root->right, preorder, inorder, mid + 1, index, right, i, preorderSize);
        }
    }
    else {
        return;
    }
    return;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    if (preorderSize <= 0) {
        return NULL;
    }
    int i = 0;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = preorder[0];
    createSubTree(root, preorder, inorder, 0, search(inorder, 0, inorderSize - 1, preorder[i]), preorderSize - 1, &i, preorderSize);
    return root;
}

int main() {
}