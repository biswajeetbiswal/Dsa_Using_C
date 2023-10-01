#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp;
void push(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
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
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("The stack is empty");
    }
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void peek()
{
    if (head == NULL)
    {
        printf("Stack Underflow");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
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
        push(x);
    }
    display();
    peek();
}