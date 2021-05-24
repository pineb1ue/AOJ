#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int insertion_sort(int *A, int N, int g)
{
    int v;
    int j;
    int cnt = 0;

    for (int i = g; i < N; i++)
    {
        v = A[i];
        j = i - g;
        while (j >= 0 && A[j] > v)
        {
            A[j + g] = A[j];
            j -= g;
            cnt += 1;
        }
        A[j + g] = v;
    }
    return cnt;
}

void shell_sort(int *A, int N)
{
    int cnt = 0;
    int m = 0;
    int G[100];

    for (int h = 1; h <= N; h = 3 * h + 1)
    {
        G[m] = h;
        m += 1;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        cnt += insertion_sort(A, N, G[i]);
    }

    printf("%d\n", m);
    for (int i = m - 1; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d\n", G[i]);
        }
        else
        {
            printf("%d ", G[i]);
        }
    }
    printf("%d\n", cnt);
}

int main(void)
{
    int N;
    int A[1000000];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    shell_sort(A, N);
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

    return 0;
}