
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node* nodes[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->nodes[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->nodes[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void levelOrderTraversal(struct Node* root) {
    struct Queue q;
    q.front = q.rear = 0;
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* node = dequeue(&q);
        printf("%d ", node->data);

        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level order traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
