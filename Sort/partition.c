#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100000

int partition(int *A, int p, int r)
{
    int x = A[r];
    int i, j;
    int tmp;

    i = p - 1;
    for (j= p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i += 1;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;

    return i + 1;
}


int main(void)
{
    int n;
    int A[MAX];
    int q;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    q = partition(A, 0, n - 1);

    printf("%d", A[0]);
    for (int i = 1; i < n; i++)
    {
        if (i == q)
        {
            printf(" [%d]", A[i]);
        }
        else
        {
            printf("% d", A[i]);
        }
    }
    printf("\n");

    return 0;
}