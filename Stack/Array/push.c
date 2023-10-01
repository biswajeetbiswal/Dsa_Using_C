#include <stdio.h>

int arr[5];
int top = -1;
void push(int x)
{
    if (top == (5 - 1))
    {
        printf("Stack Overflow\n");
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
}