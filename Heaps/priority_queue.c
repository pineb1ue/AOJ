#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SWAP(a, b) (a += b, b = a - b, a -= b)

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
    while (parent(i) >= 1 && H[i] > H[parent(i)])
    {
        SWAP(H[i], H[parent(i)]);
        i = parent(i);
    }
}

void insert(int *H, int *hsize, int key)
{
    *hsize += 1;
    H[*hsize] = key;
    upHeap(H, *hsize);
}

void maxHeapify(int *H, int *hsize, int i)
{
    int u = i;
    int l = left(u);
    int r = right(u);
    int largest;

    if (l <= *hsize && H[l] > H[u])
    {
        largest = l;
    }
    else
    {
        largest = u;
    }
    if (r <= *hsize && H[r] > H[largest])
    {
        largest = r;
    }

    if (largest != u)
    {
        SWAP(H[u], H[largest]);
        maxHeapify(H, hsize, largest);
    }
}

int extractMax(int *H, int *hsize)
{
    int max = H[1];
    H[1] = H[*hsize];
    *hsize -= 1;

    maxHeapify(H, hsize, 1);

    return max;
}

int main(void)
{
    int H[2000001];
    char command[10];
    int hsize = 0;
    int key;
    int max_value;

    while (1)
    {
        scanf("%s", command);
        if (command[0] == 'e' && command[1] == 'n')
        {
            break;
        }
        else if (command[0] == 'i')
        {
            scanf("%d", &key);
            insert(H, &hsize, key);
        }
        else if (command[0] == 'e')
        {
            max_value = extractMax(H, &hsize);
            printf("%d\n", max_value);
        }
    }

    return 0;
}