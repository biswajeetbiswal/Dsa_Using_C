#include <stdio.h>
#include <stdlib.h>
void adde(int data);
void display();
void delete();
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
        printf("Enetr data:");
        scanf("%d", &x);
        adde(x);
        printf("if you are intersted to input more data then press 1 otherwise press 0:");
        scanf("%d", &choice);
    }
    display();
    int choose;
    printf("If you are interested to delete data at end then press 1 otherwise press 0:");
    scanf("%d", &choose);
    while (choose)
    {
        delete ();
        display();
        printf("If you are interested to delete data at end then press 1 otherwise press 0:");
        scanf("%d", &choose);
    }
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
    printf("\n");
}
void delete()
{
    if (head == NULL)
    {
        printf("The list is empty");
        return;
    }
    struct node *prev;
    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
        printf("The list empty");
    }
    else
    {
        prev->next = NULL;
        free(temp);
    }
}
void adde(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));
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