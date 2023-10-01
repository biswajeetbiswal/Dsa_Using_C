#include <stdio.h>
#include <stdlib.h>
void addf(int data);
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int main()
{
    int choice = 1;
    while (choice)
    {
        int n;
        printf("Enter the number:");
        scanf("%d", &n);
        addf(n);
        printf("if you are intersted to input more data then press 1 otherwise press 0");
        scanf("%d", &choice);
    }
    display();
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
}
void addf(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}