#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL, *temp;
void addf(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The list is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void delete()
{
    struct node *ptr;
    temp = head;
    if (head->next == NULL)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        free(temp);
    }
}
int main()
{
    int x;
    printf("Enter no. of data:");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int y;
        printf("Enter data:");
        scanf("%d", &y);
        addf(y);
    }
    display();
    delete ();
    display();
}