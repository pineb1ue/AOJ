#include <stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFTY 1000000


int M[MAX][MAX];  // 隣接行列
int n;

int Prim(void)
{
    int color[MAX]; // vの訪問状態
    int d[MAX];     // 最小の重み
    int p[MAX];     // 親
    int minv;
    int i, u, v;
    int sum = 0;

    for (i = 0; i < n; i++)
    {
        color[i] = WHITE;
        d[i] = INFTY;
        p[i] = -1;
    }
    d[0] = 0;

    while (1)
    {
        minv = INFTY;
        u = -1;
        for (i = 0; i < n; i++)
        {
            if (minv > d[i] && color[i] != BLACK)
            {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1)
        {
            break;
        }
        color[u] = BLACK;
        for (v = 0; v < n; v++)
        {
            if (color[v] != BLACK && M[u][v] != INFTY)
            {
                if (d[v] > M[u][v])
                {
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (p[i] != -1)
        {
            sum += M[i][p[i]];
        }
    }

    return sum;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &M[i][j]);
            if (M[i][j] == -1)
            {
                M[i][j] = INFTY;
            }
        }
    }

    printf("%d\n", Prim());

    return 0;
}