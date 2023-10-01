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
struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data < key)
    {
        return search(root->right, key);
    }
    if (root->data > key)
    {
        return search(root->left, key);
    }
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 25);
    insert(root, 80);
    insert(root, 10);
    insert(root, 33);
    insert(root, 75);
    insert(root, 95);
    printf("Search 80 from this tree\n");
    int key = 80;
    if (search(root, key) == NULL)
    {
        printf("%d not found\n", key);
    }
    else
    {
        printf("%d found\n", key);
    }
    return 0;
}