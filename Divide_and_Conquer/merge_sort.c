#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define inf 1000000000

int cnt = 0;

void merge(int *A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1];
    int R[n2 + 1];
    int i, j;

    for (i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1] = inf;
    R[n2] = inf;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i += 1;
        }
        else
        {
            A[k] = R[j];
            j += 1;
        }
        cnt += 1;
    }
}

void mergeSort(int *A, int left, int right)
{
    int mid;
    int cnt;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void)
{
    int n;
    int S[5000000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    mergeSort(S, 0, n);

    printf("%d", S[0]);
    for (int i = 1; i < n; i++)
    {
        printf("% d", S[i]);
    }
    printf("\n%d\n", cnt);

    return 0;
}