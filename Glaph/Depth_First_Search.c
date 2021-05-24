#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxN 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[maxN][maxN];
int d[maxN];
int f[maxN];
int color[maxN];
int time;
int n;

void init(void)
{
    for (int u = 1; u < maxN; u++)
    {
        d[u] = -1;
        f[u] = -1;
        color[u] = WHITE;
        for (int v = 1; v < maxN; v++)
        {
            G[u][v] = 0;
        }
    }
}

/* 再帰処理 */
void traverse(int v)
{
    color[v] = GRAY;
    time += 1;
    d[v] = time;
    for (int u = 1; u <= n; u++)
    {
        if (G[v][u] == 0)
        {
            continue;
        }
        if (color[u] == WHITE)
        {
            traverse(u);
        }
    }
    color[v] = BLACK;
    time += 1;
    f[v] = time;
}

void DFS(void)
{
    time = 0;
    for (int u = 1; u <= n; u++)
    {
        if (color[u] == WHITE)
        {
            traverse(u);
        }
    }
}


int main(void)
{
    int i, j;
    int u, k, v;

    init();

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &u, &k);
        for (j = 1; j <= k; j++)
        {
            scanf("%d", &v);
            G[u][v] = 1;
        }
    }
    
    DFS();

    for (u = 1; u <= n; u++)
    {
        printf("%d %d %d\n", u, d[u], f[u]);
    }

    return 0;
}