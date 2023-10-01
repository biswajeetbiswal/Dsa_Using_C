#include <stdio.h>
#include <stdlib.h>
void adde(int data);
void display();
void delete(int c);
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
    printf("If you are interested to delete data at any position then press 1 otherwise press 0:");
    scanf("%d", &choose);
    while (choose)
    {
        int c;
        printf("Enter the position to delete");
        scanf("%d", &c);
        delete (c);
        display();
        printf("If you are interested to delete data at any position then press 1 otherwise press 0:");
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
void delete(int c)
{
    if (c == 0)
    {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *prev;
    temp=head;
    for (int i = 0; i < c; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
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