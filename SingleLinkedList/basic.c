#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data");
        scanf("%d", &newnode->data);
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
        printf("if you are interested to insert newnode then press 1 otherwise press 0");
        scanf("%d", &choice);
    }
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    return 0;
}
