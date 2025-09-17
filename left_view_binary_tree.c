
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void leftViewUtil(struct Node* node, int level, int* maxLevel) {
    if (node == NULL) return;

    if (*maxLevel < level) {
        printf("%d ", node->data);
        *maxLevel = level;
    }

    leftViewUtil(node->left, level + 1, maxLevel);
    leftViewUtil(node->right, level + 1, maxLevel);
}

void leftView(struct Node* root) {
    int maxLevel = 0;
    leftViewUtil(root, 1, &maxLevel);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Left view of binary tree: ");
    leftView(root);
    printf("\n");

    return 0;
}
