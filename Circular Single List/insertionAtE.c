#include <stdio.h>
#include <stdlib.h>
void adde(int y);
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
        adde(y);
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
void adde(int y)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = y;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        newnode->next = head;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}