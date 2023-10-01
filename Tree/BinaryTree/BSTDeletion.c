#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}
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
struct node *findmin(struct node *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    else
    {
        return findmin(root->left);
    }
}
struct node *findMax(struct node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    else
    {
        return findMax(root->right);
    }
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
// Deleting node
struct node *deletenode(struct node *root, int data)
{
    // return tree if rootis empty
    if (root == NULL)
    {
        return root;
    }
    // find the node that to be deleted
    if (data < root->data)
    {
        root->left = deletenode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deletenode(root->right, data);
    }
    else
    {
        // if node is width only child node
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        // if the node has two child
        struct node *temp = findmin(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    printf("Inorder traversal: ");
    inorder(root);

    printf("\nAfter deleting 10\n");
    root = deletenode(root, 10);
    printf("Inorder traversal: ");
    inorder(root);
    printf("Find min:");
    struct node *s = findmin(root);
    printf("%d", s->data);
    printf("Find max");
    struct node *t = findMax(root);
    printf("%d", t->data);
    struct node *x = search(root, 45);
    if (x != NULL)
    {
        printf("\n%d found", x->data);
    }
    else
    {
        printf("\nNot found");
    }
}
