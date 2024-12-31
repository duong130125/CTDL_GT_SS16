#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    return search(root->left, key) || search(root->right, key);
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

    int key;
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &key);

    if (search(root, key))
    {
        printf("Giá trị %d được tìm thấy trong cây nhị phân.\n", key);
    }
    else
    {
        printf("Giá trị %d không được tìm thấy trong cây nhị phân.\n", key);
    }

    return 0;
}
