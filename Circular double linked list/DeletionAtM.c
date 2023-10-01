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
    int pos;
    printf("Enter the position");
    scanf("%d", &pos);
    struct node *temp, *ptr;
    temp = head;

    if (pos == 1)
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = tail;
            tail->next = head;
            free(temp);
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        temp->next->prev = ptr;
        ptr->next = temp->next;
        free(temp);
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