#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the stack

char stack[MAX_SIZE];
int top = -1; // Top pointer of the stack

void push(char item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow. Unable to push '%c'\n", item);
        return;
    }

    top++;
    stack[top] = item;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow. Unable to pop.\n");
        return '\0';
    }

    char item = stack[top];
    top--;
    return item;
}

char peek()
{
    if (top == -1)
    {
        printf("Stack is empty. Unable to peek.\n");
        return '\0';
    }

    return stack[top];
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

int getPrecedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (ch == ' ' || ch == '\t')
        {
            i++;
            continue;
        }

        if (isOperator(ch))
        {
            while (top != -1 && getPrecedence(peek()) >= getPrecedence(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }

            if (top == -1)
            {
                printf("Invalid infix expression. Unbalanced parentheses.\n");
                return;
            }

            pop(); // Pop '('
        }
        else
        {
            postfix[j] = ch;
            j++;
        }

        i++;
    }

    while (top != -1)
    {
        if (peek() == '(')
        {
            printf("Invalid infix expression. Unbalanced parentheses.\n");
            return;
        }

        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infixExpression[100];
    char postfixExpression[100];

    printf("Enter the infix expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
