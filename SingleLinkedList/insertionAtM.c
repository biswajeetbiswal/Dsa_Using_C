#include <stdio.h>
#include <stdlib.h>
void addf(int data);
void display();
void addm(int pos, int val);
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
        int x;
        printf("Enter the number:");
        scanf("%d", &x);
        addf(x);
        printf("if you are intersted to input more data then press 1 otherwise press 0");
        scanf("%d", &choice);
    }
    int input;
    printf("If you are intersetd to put data any position then press 1 otherwise press 0");
    scanf("%d", &input);
    while (input)
    {
        int y, z;
        printf("Enter the position where you want add data");
        scanf("%d", &z);
        printf("Enter data");
        scanf("%d", &y);
        addm(z, y);
        printf("if you are intersted to input more data then press 1 otherwise press 0");
        scanf("%d", &input);
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
void addm(int pos, int val)
{
    struct node *secnode;
    secnode = (struct node *)malloc(sizeof(struct node));
    secnode->data = val;
    secnode->next = NULL;
    struct node *ptr;
    ptr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    secnode->next = ptr->next;
    ptr->next = secnode;
}
void addf(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
