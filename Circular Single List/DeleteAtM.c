#include <stdio.h>
#include <stdlib.h>
void addf(int x);
void display();
void delete(int n);
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
    delete (n);
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
void delete(int size)
{
    int pos;
    printf("Enter position where you want delete");
    scanf("%d", &pos);
    if (head == NULL)
    {
        printf("The list is empty");
        return;
    }
    struct node *temp, *prev;
    temp = head;
    if (pos == 0)
    {
        head = head->next;
        tail->next = head;
        free(temp);
    }
    else if (pos == size - 1)
    {
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
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