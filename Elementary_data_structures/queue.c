/*  The round-robin scheduling (ラウンドロビンスケジューリング) */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define LEN 100005
#define MAX 100000

typedef struct pp
{
    char name[100];
    int t;
} P;

/* Global Variable */
P Q[LEN + 1];


void initialize(int *head, int *tail)
{
    *head = 0;
    *tail = 0;
}

int isEmpty(int *head, int *tail)
{
    return *head == *tail;
}

int isFull(int *head, int *tail)
{
    return *head == (*tail + 1) % MAX;
}

void enqueue(P x, int *head, int *tail)
{
    if (isFull(head, tail))
    {
        printf("error(overflow)\n");
        exit(0);
    }
    Q[*tail] = x;
    if (*tail + 1 == MAX)
    {
        *tail = 0;
    }
    else
    {
        *tail += 1;
    }
}

int dequeue(int *head, int *tail)
{
    int x;

    if (isEmpty(head, tail))
    {
        printf("error(underflow)\n");
        exit(0);
    }

    x = *head;
    if (*head + 1 == MAX)
    {
        *head = 0;
    }
    else
    {
        *head += 1;
    }
    return Q[x].t;
}

int main(void)
{
    int head, tail, n;
    int elaps = 0, c;
    int i, q;
    P u;

    initialize(&head, &tail);

    scanf("%d %d", &n, &q);
    for (i = 0; i < n; i++)
    {
        scanf("%s", u.name);
        scanf("%d", &u.t);
        enqueue(u, &head, &tail);
    }

    while (!isEmpty(&head, &tail))
    {
        c = Q[head].t - q;
        if (c > 0)
        {
            elaps += q;
            u.t = c;
            strcpy(u.name, Q[head].name);
            dequeue(&head, &tail);
            enqueue(u, &head, &tail);
        }
        else
        {
            elaps += Q[head].t;
            printf("%s% d\n", Q[head].name, elaps);
            dequeue(&head, &tail);
        }
    }

    return 0;
}