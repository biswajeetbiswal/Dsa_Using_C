#include <stdio.h>
int arr[5];
int rear = -1;
int font = 0;
void enque(int x)
{
    if (rear == (5 - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        arr[++rear] = x;
    }
}
void display()
{
    if (rear == -1)
    {
        printf("The queue is empty:");
    }
    else
    {
        for (int i = font; i < 5; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}
void dequeue()
{
    if (rear == -1)
    {
        printf("Queue Underflow");
    }
    else
    {
        font++;
    }
}
int main()
{
    int n;
    printf("Enter no. of data");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        printf("Enter data");
        scanf("%d", &x);
        enque(x);
    }
    display();
    dequeue();
    display();
}