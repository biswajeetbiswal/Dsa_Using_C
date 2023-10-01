#include <stdio.h>
int MAXSIZE = 8;
int queue[8];
int rear = -1;
int font = 0;
int isempty()
{
    if (rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    if (rear == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int data)
{
    if (!isfull())
    {
        queue[++rear] = data;
    }
    else
    {
        printf("Queue is full");
    }
}
void dequeue()
{
    if (!isempty())
    {
        font = font + 1;
    }
    else
    {
        printf("Queue is empty");
    }
}
void display()
{
    for (int i = font; i < 8; i++)
    {
        printf("Data:%d\n", queue[i]);
    }
}
void peek()
{
    printf("Peek:%d", queue[font]);
}
int main()
{
    enqueue(15);
    enqueue(25);
    enqueue(65);
    enqueue(85);
    enqueue(75);
    enqueue(30);
    enqueue(85);
    enqueue(100);
    enqueue(50);
    display();
    printf("After dequeue:");
    dequeue();
    peek();
}