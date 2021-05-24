#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define inf 1145141919

int C[21];  // 各コインの額面
int T[50001]; // コインの最小枚数
int dp[20][500001];
int n, m;

int _min(int a, int b)
{
    return a < b ? a : b; 
}

int getTheNumberOfCoin()
{
    for (int j = 0; j <= n; j++)
    {
        T[j] = inf;
    }
    T[0] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = C[i]; j <= n; j++)
        {
            T[j] = _min(T[j], T[j - C[i]] + 1);
        }
    }
    return T[n];
}

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &C[i]);
    }
    printf("%d\n", getTheNumberOfCoin());
}