#include <stdio.h>
#include <stdlib.h>
void addf(int x);
void display();
struct node
{
    int data;
    struct node *next;
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
        addf(y);
    }
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