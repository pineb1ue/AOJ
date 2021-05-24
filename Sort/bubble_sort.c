#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bubble_sort(int *A, int N)
{
    int flag = 1;           // 逆の隣接行列が存在
    int i = 0;              // 未ソート部分列の先頭index
    int exchange_times = 0; // 交換回数

    while (flag)
    {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A[j] < A[j - 1]) // A[j] <= A[j - 1]だと安定ソートではなくなる
            {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                exchange_times += 1;
            }
        }
        i += 1;
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

    times = bubble_sort(A, N);
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