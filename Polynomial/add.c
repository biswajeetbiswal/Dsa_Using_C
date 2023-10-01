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


int main()
{
    int n, m;
    printf("Enter the no.of element for polynomial1:");
    scanf("%d", &n);
    int size1 = 0, size2 = 0;
    for (int i = 0; i < n; i++)
    {
        size1++;
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
        size2++;
        int a, b;
        printf("Enter coefficient:");
        scanf("%d", &a);
        printf("Enter data");
        scanf("%d", &b);
        addp2(a, b);
    }
    //add();
    display();
}
