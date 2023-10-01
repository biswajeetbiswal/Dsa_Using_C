#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *temp;
void addf(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void adde()
{
    int pos, data;
    printf("Enter the position:");
    scanf("%d", &pos);
    printf("Enter data:");
    scanf("%d", &data);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (pos == 1)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else
    {
        temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = newnode;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
    }
}
int main()
{
    int x;
    printf("Enter no. of data:");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int y;
        printf("Enter data:");
        scanf("%d", &y);
        addf(y);
    }
    display();
    adde();
    display();
}