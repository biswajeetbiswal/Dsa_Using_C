#include <stdio.h>
int arr[5];
int rear = -1;
int font = 0;
void enqueue(int x)
{
    if (rear == (5 - 1))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        arr[++rear] = x;
    }
}
void display()
{
    if (rear == -1||font>rear)
    {
        printf("Queue is empty");
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
int main()
{
    int x;
    printf("Enter the no. of element");
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int y;
        printf("Enter data");
        scanf("%d", &y);
        enqueue(y);
    }
    display();
}