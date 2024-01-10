#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

void connectParallel(struct Node *root, struct Node *prev) {
    if (root->left && root->right) {
        if (prev) {
            prev->next = root->left;
        }
        root->left->next = root->right;
        prev = root->right;
    }
    else if (root->left) {
        if (prev) {
            prev->next = root->left;
        }
        prev = root->left;
    }
    else if (root->right) {
        if (prev) {
            prev->next = root->right;
        }
        prev = root->right;
    }
    if (root->next) {
        connectParallel(root->next, prev);
    }
    return;
}

struct Node *connect(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node *output = root;
    connectParallel(root, NULL);
    while (1) {
        if (root->left) {
            root = root->left;
            connectParallel(root, NULL);
        }
        else if (root->right) {
            root = root->right;
            connectParallel(root, NULL);
        }
        else if (root->next) {
            root = root->next;
        }
        else {
            break;
        }
    }
    return output;
}