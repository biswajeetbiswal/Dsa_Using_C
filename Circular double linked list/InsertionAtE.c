#include <stdio.h>
#include <stdlib.h>
void adde(int data);
void display();
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *tail = NULL;
int main()
{
    int n;
    printf("Enter the no.of element:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int y;
        printf("Enter data:");
        scanf("%d", &y);
        adde(y);
    }
    display();
}
void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void adde(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        tail = newnode;
    }
}