#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 1001
#define M 1001

char X[N];
char Y[M];
int dp[N][M];


int _max(a, b)
{
    return a > b ? a : b;
}

void init(int n, int m)
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }
}

int LCS(int i, int j)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == 0 || j == 0)
    {
        dp[i][j] = 0;
    }
    else if (X[i - 1] == Y[j - 1])
    {
        dp[i][j] = LCS(i - 1, j - 1) + 1;
    }
    else
    {
        dp[i][j] = _max(LCS(i, j - 1), LCS(i - 1, j));
    }
    return dp[i][j];
}


int main(void)
{
    int q;
    int lx, ly;
    int lcs;

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%s %s", X, Y);
        lx = strlen(X);
        ly = strlen(Y);
        init(lx, ly);
        lcs = LCS(lx, ly);
        printf("%d\n", lcs);
    }

    return 0;
}