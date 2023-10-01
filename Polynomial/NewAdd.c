#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int pow;
    struct node *next;
};
void create(int x, int y, struct node **temp)
{
    struct node *r, *z;
    // z = *temp;
    if (*temp == NULL)
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = (struct node *)malloc(sizeof(struct node));
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = (struct node *)malloc(sizeof(struct node));
        r = r->next;
        r->next = NULL;
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
void display(struct node *p)
{
    while (p->next != NULL)
    {
        printf("%dx^%d", p->coeff, p->pow);
        p = p->next;
        if (p->next != NULL)
        {
            printf("+");
        }
    }
}
int main()
{
    struct node *p1, *p2 = NULL, *result = NULL;
    create(41, 7, &p1);
    create(12, 5, &p1);
    create(65, 0, &p1);
    create(21, 5, &p2);
    create(15, 2, &p2);
    printf("Polynomial 1:");
    display(p1);
    printf("\nPolynomial 2:");
    display(p2);
    result = (struct node *)malloc(sizeof(struct node));
    add(p1, p2, result);
    printf("\nAfter addition:");
    display(result);
    return 0;
}