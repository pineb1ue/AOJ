#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// int Matrix_Chain_Order(int n, int *r, int *c)
// {
//     int m[n + 1][n + 1];
//     int s[n + 1][n + 1];
//     int i, j, k;
//     int l;  // かける行列の個数
//     int m_min, min;
//     int k_min;

//     for (i = 1; i <= n; i++)
//     {
//         m[i][i] = 0;
//         s[i][i] = 0;
//     }

//     for (l = 2; l <= n; l++)
//     {
//         for (i = 1; i <= n - l + 1; i++)
//         {
//             j = i + l - 1;
//             min = 100000000;
//             for (int k = i; k < j; k++)
//             {
//                 m_min = m[i][k] + m[k + 1][j] + r[i]*c[k]*c[j];
//                 if (m_min < min)
//                 {
//                     min = m_min;
//                     k_min = k;
//                 }
//             }
//             m[i][j] = min;
//             s[i][j] = k_min;
//         }
//     }

//     return m[1][n];
// }

int n;
int m[101][101];

// int Recursive_Matrix_Chain(int *r, int *c, int i, int j)
// {
//     int m_min;
//     int min = 10000000;
//     if (i == j)
//     {
//         m[i][j] = 0;
//     }
//     else
//     {
//         for (int k = i; k < j; k++)
//         {
//             m_min = Recursive_Matrix_Chain(r, c, i, k) + Recursive_Matrix_Chain(r, c, k + 1, j) + r[i]*c[k]*c[j];
//             if (m_min < min)
//             {
//                 min = m_min;
//             }
//         }
//         m[i][j] = min;
//     }
//     return m[i][j];
// }

int Lookup_Chain(int *r, int *c, int i, int j)
{
    int m_min;
    int min = 1000000;
    if (m[i][j] == 1000000)
    {
        if (i == j)
        {
            m[i][j] = 0;
        }
        else
        {
            for (int k = i; k < j; k++)
            {
                m_min = Lookup_Chain(r, c, i, k) + Lookup_Chain(r, c, k + 1, j) + r[i] * c[k] * c[j];
                if (m_min < min)
                {
                    min = m_min;
                }
            }
            m[i][j] = min;
        }
    }
    return m[i][j];
}

/* メモ化再帰 */
int Memorized_Matrix_Chain(int n, int *r, int *c)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            m[i][j] = 1000000;
        }
    }
    return Lookup_Chain(r, c, 1, n);
}

int main(void)
{
    // int n;
    int r[101], c[101];

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &r[i], &c[i]);
    }

    printf("%d\n", Memorized_Matrix_Chain(n, r, c));

    return 0;
}