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

    if ((*i) - 1 < 0) {
        return;
    }
    int index = search(inorder, left, right, preorder[(*i) - 1]);
    if ((index >= 0) && (index < mid)) {
        insertLeftNode(root, preorder[(*i) - 1]);
        (*i)--;
        createSubTree(root->left, preorder, inorder, left, index, mid - 1, i, preorderSize);
    }
    else if (index >= 0) {
        insertRightNode(root, preorder[(*i) - 1]);
        (*i)--;
        createSubTree(root->right, preorder, inorder, mid + 1, index, right, i, preorderSize);
        if ((*i) - 1 < 0) {
            return;
        }
        index = search(inorder, left, right, preorder[(*i) - 1]);
        if (index >= 0) {
            insertLeftNode(root, preorder[(*i) - 1]);
            (*i)--;
            createSubTree(root->left, preorder, inorder, left, index, mid - 1, i, preorderSize);
        }
    }
    else {
        return;
    }
    return;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize) {
    if (postorderSize <= 0) {
        return NULL;
    }
    int i = postorderSize - 1;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = postorder[postorderSize - 1];
    createSubTree(root, postorder, inorder, 0, search(inorder, 0, inorderSize - 1, postorder[i]), postorderSize - 1, &i, postorderSize);
    return root;
}