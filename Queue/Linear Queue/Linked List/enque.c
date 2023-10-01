#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        temp = head;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the no. of element:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter data");
        scanf("%d", &x);
        enqueue(x);
    }
    display();
}