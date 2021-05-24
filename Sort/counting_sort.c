#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 10001

void countingSort(int *A, int *B, int k, int n)
{
    int C[k];

    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }

    /* C[i]にiの出現数を記録する */
    for (int j = 0; j < n; j++)
    {
        C[A[j]] += 1;
    }
    /* C[i]にi以下の数の出現数を記録する */
    for (int i = 1; i < k; i++)
    {
        C[i] += C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--)
    {
        C[A[j]] -= 1;
        B[C[A[j]]] = A[j];
    }
}


int main(void)
{
    int n;
    int A[2000000];
    int B[2000000];
    int k = MAX;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    countingSort(A, B, k, n);

    printf("%d", B[0]);
    for (int i = 1; i < n; i++)
    {
        printf("% d", B[i]);
    }
    printf("\n");

    return 0;
}