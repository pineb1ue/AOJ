#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int parent(int i)
{
    return (int)(i / 2);
}

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}

void upHeap(int *H, int i)
{
    int tmp;
    while (parent(i) >= 1)
    {
        if (H[i] > H[parent(i)])
        {
            tmp = H[i];
            H[i] = H[parent(i)];
            H[parent(i)] = tmp;
        }
        i = parent(i);
    }
}

void output(int *H, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("node %d: key = %d, ", i, H[i]);
        if (parent(i) >= 1)
        {
            printf("parent key = %d, ", H[parent(i)]);
        }
        if (left(i) <= n)
        {
            printf("left key = %d, ", H[left(i)]);
        }
        if (right(i) <= n)
        {
            printf("right key = %d, ", H[right(i)]);
        }
        printf("\n");
    }
}

int main(void)
{
    int H[251];
    int n;
    int key;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &key);
        H[i] = key;
        // upHeap(H, i);
    }

    output(H, n);

    return 0;
}