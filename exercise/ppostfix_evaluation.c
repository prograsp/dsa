#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}

int evaluate_postfix(char exp[])
{
    int i = 0, A, B;

    while (exp[i] != ')')
    {
        if (exp[i] == 32 || exp[i] == '\t')
            continue;

        else if (isdigit(exp[i]))
            push(exp[i] - '0');

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            A = pop();
            B = pop();
            int val;
            switch (exp[i])
            {
            case '+':
                val = B + A;
                break;
            case '-':
                val = B - A;
                break;
            case '*':
                val = B * A;
                break;
            case '/':
                val = B / A;
                break;

            default:
                break;
            }

            push(val);
        }
        i++;
    }
    printf("Evaluated result: %d\n", pop());
}

int main()
{
    char postfix[SIZE];
    printf("Enter expression with ')' at the end: ");
    scanf("%s", postfix);
    evaluate_postfix(postfix);
}