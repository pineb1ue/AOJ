#include <stdio.h>

int fib_rec(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fibdp[1000000];
/* メモ化再帰 */
int getFib(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (fibdp[n] != 0)
    {
        return fibdp[n];
    }
    return fibdp[n] = getFib(n - 1) + getFib(n - 2);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", getFib(n));
    return 0;
}