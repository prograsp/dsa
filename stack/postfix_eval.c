

#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 100
#define POSTFIXSIZE 100

int stack[MAXSTACK];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    int item = stack[top--];
    return item;
}

void EvalPostfix(char postfix[])
{

    char ch;
    int val, A, B;

    for (int i = 0; postfix[i] != ')'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop();
            B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
    }
    printf(" \nEvaluated result: %d \n", pop());
}

int main()
{

    int i;
    char postfix[POSTFIXSIZE];
    printf("Enter expression with ')' at the end: ");
    scanf("%s", postfix);
    EvalPostfix(postfix);

    return 0;
}
