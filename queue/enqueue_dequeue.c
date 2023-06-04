#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

int circularQueue[MAX_SIZE];
int front = -1; // Front pointer
int rear = -1;  // Rear pointer

int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(int item)
{
    if (isFull())
    {
        printf("Circular queue is full. Unable to enqueue.\n");
        return;
    }

    if (front == -1 && rear == -1)
        front = rear = 0;
    else if (rear == MAX_SIZE - 1)
        rear = 0;
    else
        rear++;

    circularQueue[rear] = item;

    printf("Enqueued: %d\n", item);
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Circular queue is empty. Unable to dequeue.\n");
        return -1;
    }

    int item = circularQueue[front];

    if (front == rear)
        front = rear = -1;
    else if (front == MAX_SIZE - 1)
        front = 0;
    else
        front++;

    printf("Dequeued: %d\n", item);
    return item;
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("Circular queue is empty.\n");
        return;
    }

    printf("Circular queue elements: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", circularQueue[i]);
        if (i == MAX_SIZE - 1)
            i = 0;
        else
            i++;
    }
    printf("%d\n", circularQueue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    displayQueue();

    dequeue();
    dequeue();

    displayQueue();

    enqueue(60);
    enqueue(70);

    displayQueue();

    return 0;
}
