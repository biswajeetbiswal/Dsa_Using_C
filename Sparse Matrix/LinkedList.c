#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int data;
    struct node *next;
};
struct node *head = NULL, *temp;
void add(int row, int col, int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->row = row;
    newnode->col = col;
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        temp = head;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    printf("Row:");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->row);
        ptr = ptr->next;
    }
    printf("\n");
    ptr = head;
    printf("Column:");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->col);
        ptr = ptr->next;
    }
    printf("\n");
    ptr = head;
    printf("Value:");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");                                                                                                    
}
int main()
{
    int sparse[4][5] = {{0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0, 0}, {0, 2, 6, 0, 0}};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparse[i][j] != 0)
            {
                add(i, j, sparse[i][j]);
            }
        }
    }
    display();
}
