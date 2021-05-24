#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int selection_sort(int *A, int N)
{
    int minj;               // 未ソート部分の最小の要素
    int exchange_times = 0; // 交換回数
    int tmp;

    for (int i = 0; i < N; i++)
    {
        minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (minj != i)
        {
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            exchange_times += 1;
        }
    }

    return exchange_times;
}

int main(void)
{
    int N;
    int A[100];
    int times;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    times = selection_sort(A, N);
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            printf("%d\n", A[i]);
        }
        else
        {
            printf("%d ", A[i]);
        }
    }
    printf("%d\n", times);

    return 0;
}