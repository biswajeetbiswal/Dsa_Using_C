#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
struct node *ptr;
void create(int x, int y, struct node **temp)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = x;
    newnode->pow = y;
    newnode->next = NULL;
    if (*temp == NULL)
    {
        *temp = newnode;
        ptr = *temp;
    }
    else
    {
        ptr->next = newnode;
        ptr = newnode;
    }
}
void add(struct node *p1, struct node *p2, struct node *result)
{
    while (p1->next && p2->next)
    {
        if (p1->pow > p2->pow)
        {
            result->pow = p1->pow;
            result->coeff = p1->coeff;
            p1 = p1->next;
        }
        else if (p1->pow < p2->pow)
        {
            result->pow = p2->pow;
            result->coeff = p2->coeff;
            p2 = p2->next;
        }
        else
        {
            result->pow = p1->pow;
            result->coeff = p1->coeff + p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        result->next = (struct node *)malloc(sizeof(struct node));
        result = result->next;
        result->next = NULL;
    }
    while (p1->next || p2->next)
    {
        if (p1->next)
        {
            result->pow = p1->pow;
            result->coeff = p1->coeff;
            p1 = p1->next;
        }
        if (p2->next)
        {
            result->pow = p2->pow;
            result->coeff = p2->coeff;
            p2 = p2->next;
        }
        result->next = (struct node *)malloc(sizeof(struct node));
        result = result->next;
        result->next = NULL;
    }
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->pow);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf("+");
        }
    }
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
    printf("\nPolynomial2:");
    display(poly2);
    result = (struct node *)malloc(sizeof(struct node));
    add(poly1, poly2, result);
    printf("\nAfter addition:");
    display(result);
    return 0;
}
