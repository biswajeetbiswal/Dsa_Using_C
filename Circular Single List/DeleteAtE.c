#include <stdio.h>
#include <stdlib.h>
void addf(int x);
void display();
void delete();
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
    delete ();
    display();
    delete ();
    display();
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
void delete()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("The list is empty");
        return;
    }
    if (head == tail)
    {
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
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