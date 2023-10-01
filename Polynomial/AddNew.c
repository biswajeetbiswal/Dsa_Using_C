#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node *temp = NULL;
void create(int coeff, int expo, struct node **head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        temp = *head;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void add(struct node *p1, struct node *p2, struct node **result)
{
    struct node *newnode;
    while (p1->next && p2->next)
    {
        if (p1->expo > p2->expo)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->expo = p1->expo;
            newnode->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p2->expo > p1->expo)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->expo = p2->expo;
            newnode->coeff = p2->coeff;
            p2 = p2->next;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->expo = p1->expo;
            newnode->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (*result == NULL)
        {
            *result = newnode;
            temp = *result;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            temp->next = NULL;
        }
    }
    while (p1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->expo = p1->expo;
        newnode->coeff = p1->coeff;
        p1 = p1->next;
        temp->next = newnode;
        temp = newnode;
        temp->next = NULL;
    }
    while (p2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->expo = p2->expo;
        newnode->coeff = p2->coeff;
        p2 = p2->next;
        temp->next = newnode;
        temp = newnode;
        temp->next = NULL;
    }
}
void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->expo);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
int main()
{
    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    create(41, 7, &poly1);
    create(12, 5, &poly1);
    create(65, 0, &poly1);
    create(21, 5, &poly2);
    create(15, 2, &poly2);
    printf("Polynomial1:");
    display(poly1);
    printf("Polynomial2:");
    display(poly2);
    add(poly1, poly2, &result);
    printf("\nAfter addition:");
    display(result);
    return 0;
}