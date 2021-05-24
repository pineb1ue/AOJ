#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SWAP(a, b) (a += b, b = a - b, a -= b)

int hsize; // ヒープサイズ

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

void maxHeapify(int *H, int i)
{
    int l = left(i);
    int r = right(i);
    int largest;

    if (l <= hsize && H[l] > H[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (r <= hsize && H[r] > H[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        SWAP(H[i], H[largest]);
        maxHeapify(H, largest);
    }
}

void buildMaxHeap(int *H)
{
    for (int i = hsize / 2; i >= 1; i--)
    {
        maxHeapify(H, i);
    }
}

int main(void)
{
    int H[500001];
    int key;

    scanf("%d", &hsize);
    for (int i = 1; i <= hsize; i++)
    {
        scanf("%d", &key);
        H[i] = key;
    }

    buildMaxHeap(H);

    for (int i = 1; i <= hsize; i++)
    {
        printf(" %d", H[i]);
    }
    printf("\n");

    return 0;
}