#include <stdio.h>
#include <stdlib.h>
void adde(int data);
void display();
void delete();
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
    delete ();
    display();
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void delete()
{
    struct node *temp;
    temp = head;
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        head->prev = temp;
        free(tail);
        tail = temp;
    }
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