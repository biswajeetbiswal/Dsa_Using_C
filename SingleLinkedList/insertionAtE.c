#include <stdio.h>
#include <stdlib.h>
void adde(int data);
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *temp = NULL;
int main()
{
    int choice = 1;
    while (choice)
    {
        int n;
        printf("Enter the number:");
        scanf("%d", &n);
        adde(n);
        printf("if you are intersted to input more data then press 1 otherwise press 0");
        scanf("%d", &choice);
    }
    display();
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
}
void adde(int data)
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