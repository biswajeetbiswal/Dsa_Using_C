#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp;
void add(int data)
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
void reverse()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    struct node *prev;
    prev = head;
    struct node *curr = head->next;
    while (curr != NULL)
    {
        struct node *nextnode = curr->next;
        curr->next = prev;
        // update
        prev = curr;
        curr = nextnode;
    }
    head->next = NULL;
    head = prev;
}
void display()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    add(5);
    add(6);
    add(8);
    add(9);
    display();
    reverse();
    display();
}
