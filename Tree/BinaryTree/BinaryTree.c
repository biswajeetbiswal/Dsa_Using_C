#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data '-1 for no node'");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d\n", x);
    newnode->left = create();
    printf("Enter right child of %d\n", x);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}
int main()
{
    struct node *root;
    root = NULL;
    root = create();
    printf("Preorder");
    preorder(root);
    printf("\n");
    printf("postorder");
    postorder(root);
    printf("\n");
    printf("inorder");
    inorder(root);
}