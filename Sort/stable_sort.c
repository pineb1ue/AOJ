#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Trump
{
    char design;
    int value;
};

/* バブルソートは安定ソート */
void bubble_sort(struct Trump *A, int N)
{
    int flag = 1; // 逆の隣接行列が存在
    int i = 0;    // 未ソート部分列の先頭index
    struct Trump tmp;

    while (flag)
    {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A[j].value < A[j - 1].value) // A[j] <= A[j - 1]だと安定ソートではなくなる
            {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
            }
        }
        i += 1;
    }
}

/* 選択ソートは安定ではない */
void selection_sort(struct Trump *A, int N)
{
    int minj; // 未ソート部分の最小の要素
    struct Trump tmp;

    for (int i = 0; i < N; i++)
    {
        minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[j].value < A[minj].value)
            {
                minj = j;
            }
        }
        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
    }
}

int main(void)
{
    int N;
    struct Trump B[36];  // bubble sort
    struct Trump S[36];  // selection sort
    int flag = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        // %cの前に空白を入れる必要あり('\n'を読み込まないため)
        scanf(" %c%d", &B[i].design, &B[i].value);
        S[i].design = B[i].design;
        S[i].value = B[i].value;
    }

    bubble_sort(B, N);
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            printf("%c%d\n", B[i].design, B[i].value);
        }
        else
        {
            printf("%c%d ", B[i].design, B[i].value);
        }
    }
    printf("Stable\n");  // 常にStable

    selection_sort(S, N);
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            printf("%c%d\n", S[i].design, S[i].value);
        }
        else
        {
            printf("%c%d ", S[i].design, S[i].value);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if(S[i].design != B[i].design || S[i].value != B[i].value)
        {
            flag += 1;
        }
    }
    if (flag == 0)
    {
        printf("Stable\n");
    }
    else
    {
        printf("Not stable\n");
    }

    return 0;
}