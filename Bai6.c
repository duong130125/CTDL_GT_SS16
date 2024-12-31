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

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

int countNodesGreaterThanX(Node *root, int X)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 0;
    if (root->data > X)
    {
        count = 1;
    }

    return count + countNodesGreaterThanX(root->left, X) + countNodesGreaterThanX(root->right, X);
}

int main()
{
    Node *root = NULL;
    int n, value, X;

    printf("Nhập số lượng nút trong cây: ");
    scanf("%d", &n);

    printf("Nhập các giá trị để chèn vào cây:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Nhập giá trị X: ");
    scanf("%d", &X);

    int result = countNodesGreaterThanX(root, X);
    printf("Số lượng nút có giá trị lớn hơn %d là: %d\n", X, result);

    return 0;
}
