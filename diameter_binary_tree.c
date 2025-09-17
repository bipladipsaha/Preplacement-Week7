
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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int diameter(struct Node* node) {
    if (node == NULL) return 0;

    int lheight = height(node->left);
    int rheight = height(node->right);

    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Diameter of binary tree: %d\n", diameter(root));
    return 0;
}
