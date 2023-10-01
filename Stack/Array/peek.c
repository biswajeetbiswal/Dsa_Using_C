#include <stdio.h>
int arr[5];
int top = -1;
void push(int x)
{
    if (top == (5 - 1))
    {
        printf("Stack overflow\n");
    }
    else
    {
        arr[++top] = x;
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
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("%d", arr[top]);
    }
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
    peek();
}