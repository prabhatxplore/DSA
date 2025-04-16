#include <stdio.h>

#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == SIZE - 1)
    {
        printf(
            "Queue is full\n");

        return;
    }
    if (front == -1)
        front++;
    rear++;
    queue[rear] = val;
    printf("inserted %d \n", val);
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("queue is empty\n");
        return;
    }
    printf("dequeued %d\n", queue[front]);
    front++;
}
void peek()
{
    if (front == -1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("%d", queue[front]);
}
void display()
{
    if (front == -1)
    {
        printf(
            "queue is empty\n");
        return;
    }
    // printf("hello");
    for (int i = front; i <= rear; i++)
    {
        // printf("hello");
        printf(" %d   ", queue[i]);
    }
    printf("\n");
}
int main()
{
    enqueue(1);
    enqueue(3);
    enqueue(6);
    enqueue(10);
    display();
    dequeue();
    display();
    enqueue(50);
    display();
    return 0;
}