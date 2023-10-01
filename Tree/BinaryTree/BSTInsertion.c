#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *insert(struct node *node, int data)
{

    if (node == NULL)
    {

        node = (struct node *)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
    return node;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 33);
    root = insert(root, 75);
    root = insert(root, 95);
    printf("inorder\n");
    inorder(root);
    printf("\npreorder\n");
    preorder(root);
    printf("\npostorder\n");
    postorder(root);
}