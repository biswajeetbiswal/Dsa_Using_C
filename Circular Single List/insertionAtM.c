#include <stdio.h>
#include <stdlib.h>
void addf(int x);
void display();
void addm(int pos, int z);
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL, *temp;
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
    int pos, x;
    printf("\nEnter the position where you want to insert data:");
    scanf("%d", &pos);
    printf("Enter data:");
    scanf("%d", &x);
    addm(pos, x);
    display();
}
void display()
{
    struct node *ptr;
    ptr = head;
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
void addm(int pos, int z)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = z;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = head;
        return;
    }
    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
        tail->next = head;
        return;
    }
    temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void addf(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = head;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}