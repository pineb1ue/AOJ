#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

/* O(n) */
int maximum_profit(int *A, int n)
{
    int maxv = -1000000000;
    int minv = A[0];

    for (int j = 1; j < n ; j++)
    {
        maxv = max(maxv, A[j] - minv);
        minv = min(minv, A[j]);
    }
    return maxv;
}

/* 効率悪い (O(n^2)) */
// int maximum_profit(int *A, int n)
// {
//     int maxv = -1000000;

//     for (int j = 1; j < n; j++)
//     {
//         for (int i = 0; i < j; i++)
//         {
//             if (A[j] - A[i] > maxv)
//             {
//                 maxv = A[j] - A[i];
//             }
//         }
//     }
//     return maxv;
// }

int main(void)
{
    int n;
    int A[200000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("%d\n", maximum_profit(A, n));

    return 0;
}