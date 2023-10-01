#include <stdio.h>
#include <stdlib.h>
// void addf(int data);
// void display();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *tail = NULL, *temp;

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
void addf(int data)
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
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        head = newnode;
        tail->next = head;
    }
}
void addm(int pos, int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (pos == 0)
    {
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        head = newnode;
        tail->next = head;
    }
    else
    {
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}
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
        addf(y);
    }
    display();
    int x, z;
    printf("\nEnter the position of data");
    scanf("%d", &x);
    printf("Enter data");
    scanf("%d", &z);
    addm(x, z);
    display();
}