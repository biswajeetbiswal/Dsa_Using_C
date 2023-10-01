#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *next;
};
struct node *poly1 = NULL, *poly2 = NULL, *temp1 = NULL, *temp2 = NULL;
void addp1(int x, int y)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = x;
    newnode->expo = y;
    newnode->next = NULL;
    if (poly1 == NULL)
    {
        poly1 = newnode;
        temp1 = poly1;
    }
    else
    {
        temp1->next = newnode;
        temp1 = newnode;
    }
}
void addp2(int a, int b)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = a;
    newnode->expo = b;
    newnode->next = NULL;
    if (poly2 == NULL)
    {
        poly2 = newnode;
        temp2 = poly2;
    }
    else
    {
        temp2->next = newnode;
        temp2 = newnode;
    }
}
void display()
{
    struct node *ptr1, *ptr2;
    ptr1 = poly1;
    while (ptr1 != NULL)
    {
        printf("%d", ptr1->coeff);
        printf("x^");
        printf("%d\t", ptr1->expo);
        if (ptr1->next != NULL)
        {
            printf("+\t");
        }
        ptr1 = ptr1->next;
    }
    printf("\n");
    ptr2 = poly2;
    while (ptr2 != NULL)
    {
        printf("%d", ptr2->coeff);
        printf("x^");
        printf("%d\t", ptr2->expo);
        if (ptr2->next != NULL)
        {
            printf("+\t");
        }
        ptr2 = ptr2->next;
    }
}
int main()
{
    int n, m;
    printf("Enter the no.of element for polynomial1:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        printf("Enter coefficient:");
        scanf("%d", &x);
        printf("Enter exponent:");
        scanf("%d", &y);
        addp1(x, y);
    }
    printf("Enter the no.of element for polynomial2:");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        printf("Enter coefficient:");
        scanf("%d", &a);
        printf("Enter data");
        scanf("%d", &b);
        addp2(a, b);
    }
    display();
}
