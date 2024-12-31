#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int calculateHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->left->left = createNode(8);

    int height = calculateHeight(root);
    printf("Chiều cao của cây nhị phân là: %d\n", height);

    return 0;
}
