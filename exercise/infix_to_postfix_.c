#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

int infix_to_postfix(char exp[])
{
    int i = 0;
    char x;

    while (exp[i] != '\0')
    {
        if (exp[i] == 32 || exp[i] == '\t')
            continue;
        else if (isalnum(exp[i]))
            printf("%c", exp[i]);

        else if (exp[i] == '(')
            push(exp[i]);

        else if (exp[i] == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (precedence(stack[top]) >= precedence(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
        i++;
    }

    while (top != -1)
    {
        printf("%c", pop());
    }
    printf("\n");
}

int main()
{
    char exp[100];
    printf("Enter the expression : ");
    scanf("%s", exp);
    infix_to_postfix(exp);
}