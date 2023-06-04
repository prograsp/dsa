#include <stdio.h>
#include <stdlib.h>
#define size 5

int a[size], i, j, front = -1, rear = -1;

void enqueue(int value)
{
    if ((front == rear + 1) || (front == 0 && rear == size - 1))
        printf("Queue is full.\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        a[rear] = value;
        printf("\n Inserted -> %d", value);
    }
}

void dequeue()
{
    int val;
    if (front == -1)
    {
        printf("No element to delete.\n");
    }
    else
    {
        val = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        printf("\n Deleted element - %d \n", val);
        return val;
    }
}

void display()
{
    if (rear == -1)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", a[i]);
        }
    }
}

int current_size()
{
    int count;
    if (front == -1 && rear == -1)
        count = 0;
    else if (front <= rear)
        count = rear - front + 1;
    else
        count = size - front + rear + 1;

    printf("Current size: %d\n", count);
    return count;
}

int main(int argc, char const *argv[])
{
    int ch, val;
    do
    {
        printf("\nMenu");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE ");
        printf("\n3. DISPLAY QUEUE");
        printf("\n4. Current number of element");
        printf("\n5. Exit");
        printf("\nEnter your choice 1 to 5=");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be inserted=");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            current_size();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
            break;
        }
    } while (ch <= 4);
    return 0;
}