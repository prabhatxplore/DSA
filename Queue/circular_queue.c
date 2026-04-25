#include <stdio.h>
#define size 3

int arr[size];
int front = -1, rear = -1;
// circular linked list
int isFull()
{
    return (front == 0 && rear == size - 1) || (front == rear + 1);
}
int isEmpty()
{
    return (front == -1);
}
void enqueue(int val)
{
    if (isFull())
    {
        printf("Queue overflow. \n");
        return;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
    }
    else
        rear++;
    arr[rear] = val;
    printf("%d inserted\n", val);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted %d\n", arr[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("queue is empty\n");
        return;
    }
    int i = front;
    while (1)
    {
        printf("%d      ", arr[i]);
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % size;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(60);
    enqueue(90);
    display();
    dequeue();
    display();
    enqueue(50);
    display();
    return 0;
}