#include <stdio.h>
#include <stdlib.h>
#define size 5
int stack[size], top = -1;

void push(int val)
{
    if (top >= size - 1)
    {
        printf("Stack is full.\n");
    }
    else
    {
        top++;

        stack[top] = val;
        printf("Inserted element: %d\n", stack[top]);
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("No element to delete.\n");
    }
    else
    {
        printf("The popped element = %d\n", stack[top]);
        top--;
    }
}

void show()
{
    if (top >= 0)
    {
        printf("Stack Elements are:\n");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }
    else
    {
        printf("Stack is Empty\n");
    }
}

void stacksize()
{
    int count = 0;
    int i = 0;
    if (top >= 0)
    {
        for (i = 0; i <= top; i++)
            count = i;
    }
    count++;

    printf("%d", count);
}

int main(int argc, char const *argv[])
{
    int ch, val;
    do
    {

        printf("\nMenu");
        printf("\n1. PUSH");
        printf("\n2. POP ");
        printf("\n3. SHOW STACK");
        printf("\n4. STACK SIZE");
        printf("\n5. Exit");
        printf("\nEnter your choice 1 to 4=");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to be pushed=");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;

        case 3:
            show();
            break;
        case 4:
            stacksize();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice!");
            break;
        }

    } while (ch <= 3);
    return 0;
}
