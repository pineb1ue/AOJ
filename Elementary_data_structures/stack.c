/* Reverse Polish notation (逆ポーランド記法) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000

void initialize(int *top)
{
   *top = 0;
}

int isEmpty(int *top)
{
    return *top == 0;
}

int isFull(int *top)
{
    return *top >= MAX - 1;
}

void push(int *S, int *top, int x)
{
    if (isFull(top))
    {
        printf("error(overflow)\n");
        exit(0);
    }
    *top += 1;
    S[*top] = x;
}

int pop(int *S, int *top)
{
    if (isEmpty(top))
    {
        printf("error(underflow)\n");
        exit(0);
    }
    *top -= 1;
    return S[*top + 1];
}

int main(void)
{
    int S[102];
    int top;
    char s[202];
    int x;

    initialize(&top);

    while (scanf("%s", s) != EOF)
    {
        if (s[0] == '+')
        {
            x = pop(S, &top);
            S[top] += x;
        }
        else if (s[0] == '-')
        {
            x = pop(S, &top);
            S[top] -= x;
        }
        else if (s[0] == '*')
        {
            x = pop(S, &top);
            S[top] *= x;
        }
        else
        {
            x = atoi(s);
            push(S, &top, x);
        }
    }

    printf("%d\n", S[top]);

    return 0;
}