#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left && root->right) {
        root->left->next = root->right;
    }
    if (root->next) {
        if (root->right) {
            if (root->next->left) {
                root->right->next = root->next->left;
            }
            else if (root->next->right) {
                root->right->next = root->next->right;
            }
        }
        else if (root->left) {
            if (root->next->left) {
                root->left->next = root->next->left;
            }
            else if (root->next->right) {
                root->left->next = root->next->right;
            }
        }
        connect(root->next);
    }
}