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

int isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }

    return (root1->data == root2->data) &&
           isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main()
{
    Node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    if (isIdentical(root1, root2))
    {
        printf("Hai cây nhị phân giống hệt nhau.\n");
    }
    else
    {
        printf("Hai cây nhị phân không giống nhau.\n");
    }

    Node *root3 = createNode(1);
    root3->left = createNode(2);
    root3->right = createNode(3);
    root3->left->right = createNode(6);

    if (isIdentical(root1, root3))
    {
        printf("Hai cây nhị phân giống hệt nhau.\n");
    }
    else
    {
        printf("Hai cây nhị phân không giống nhau.\n");
    }

    return 0;
}
