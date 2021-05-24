#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define inf 1145141919
#define NMAX 100000

int A[NMAX + 1];  // 数列A
int n;

// /* DP : O(n^2) */
// int L[NMAX + 1];  // LISの長さ
// int P[NMAX + 1];  // LISの最後から2番目のindex

// void LIS(void)
// {
//     int k;

//     L[0] = 0;
//     A[0] = -1;
//     P[0] = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         k = 0;
//         for (int j = 0; j < i; j++)
//         {
//             if ((A[j] < A[i]) && (L[j] > L[k]))
//             {
//                 k = j;
//             }
//         }
//         L[i] = L[k] + 1;  // A[j] < A[i]を満たし, L[j]が最大であるjがkとなる
//         P[i] = k;         // LISにおけるA[i]の1つ前の要素がA[k]
//     }
// }

/* DP + 二分探索 : O(nlogn) */
int L[NMAX];  // 増加部分列の最後の要素を最小値とする配列
int length;   // 最長増加部分列の長さ

void LIS(void)
{
    L[0] = A[0];
    length = 1;
    for (int i = 0; i < n; i++)
    {
        if (L[length] < A[i])
        {
            L[length++] = A[i];
        }
        else
        {
            L[j] = L[i];
        }
        
    }
    
}