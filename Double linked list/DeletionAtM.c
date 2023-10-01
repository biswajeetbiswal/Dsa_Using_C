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
void delete(int x)
{
    struct node *ptr;
    temp = head;
    int pos;
    printf("Enter position where you want to delete data");
    scanf("%d", &pos);
    if (pos == 1)
    {
        if (head->next == NULL)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
    }
    else if (pos == x)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        temp->next->prev = ptr;
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
    delete (x);
    display();
}