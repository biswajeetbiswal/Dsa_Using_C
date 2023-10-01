#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail;
void add(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        tail = head;
    }
    else
    {
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
    }
}
void delete()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        head = head->next;
        tail->next = head;
        free(temp);
    }
}
void peek()
{
    printf("%d\n", head->data);
}
void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main()
{
    int x;
    printf("Enter the no. of element you want to insert:");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int y;
        printf("Enter element:");
        scanf("%d", &y);
        add(y);
    }
    display();
    delete ();
    peek();
    display();
}