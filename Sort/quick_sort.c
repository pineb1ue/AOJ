#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100000
#define inf 1000000000

void merge(int *A, int *idx, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1 + 1], idx_L[n1 + 1];
    int R[n2 + 1], idx_R[n2 + 1];
    int i, j;

    for (i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
        idx_L[i] = idx[left + i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
        idx_R[i] = idx[mid + i];
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
            idx[k] = idx_L[i];
            i += 1;
        }
        else
        {
            A[k] = R[j];
            idx[k] = idx_R[j];
            j += 1;
        }
    }
}

void mergeSort(int *A, int *idx, int left, int right)
{
    int mid;
    if (left + 1 < right)
    {
        mid = (left + right) / 2;
        mergeSort(A, idx, left, mid);
        mergeSort(A, idx, mid, right);
        merge(A, idx, left, mid, right);
    }
}

int partition(int *A, int *idx, int p, int r)
{
    int x = A[r];
    int i, j;
    int tmp, tmp_s;

    i = p - 1;
    for (j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i += 1;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;

            tmp_s = idx[i];
            idx[i] = idx[j];
            idx[j] = tmp_s;
        }
    }
    tmp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = tmp;

    tmp_s = idx[i + 1];
    idx[i + 1] = idx[r];
    idx[r] = tmp_s;

    return i + 1;
}

void quickSort(int *A, int *idx, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(A, idx, p, r);
        quickSort(A, idx, p, q - 1);
        quickSort(A, idx, q, r);
    }
}


int main(void)
{
    int n;
    int A[MAX], B[MAX];
    int idx_A[MAX], idx_B[MAX];
    char design[MAX], design_A[MAX], design_B[MAX];
    int stable = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", &design[i], &A[i]);
        design_A[i] = design[i];
        design_B[i] = design[i];
        B[i] = A[i];
        idx_A[i] = i;
        idx_B[i] = i;
    }

    quickSort(A, idx_A, 0, n - 1);
    mergeSort(B, idx_B, 0, n);

    for (int i = 0; i < n; i++)
    {
        design_A[i] = design[idx_A[i]];
        design_B[i] = design[idx_B[i]];
        if (design_A[i] != design_B[i])
        {
            stable += 1;
        }
    }

    if (stable == 0)
    {
        printf("Stable\n");
    }
    else
    {
        printf("Not stable\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("%c% d\n", design_A[i], A[i]);
    }

    return 0;
}