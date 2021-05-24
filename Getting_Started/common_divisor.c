#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    int common_divisor;

    if(x < y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }

    if (x % y == 0)
    {
        return y;
    }
    else
    {
        return gcd(y, x % y);
    }
}

int main(void)
{
    int x, y;

    scanf("%d%d", &x, &y);
    printf("%d\n", gcd(x, y));
    return 0;
}