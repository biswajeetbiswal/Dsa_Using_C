#include <stdio.h>
int arr[5];
int top = -1;
int isFull()
{
    if (top == (5 - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int x)
{
    if (isFull())
    {
        printf("Stack overflow\n");
    }
    else
    {
        arr[++top] = x;
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
    }
    else
    {
        top--;
    }
}
void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the no. of data you want to insert:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter data");
        scanf("%d", &x);
        push(x);
    }
    display();
    pop();
    display();
}