/* BinaryTree + Heap */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    struct node *left;
    struct node *right;
    int key;
    int priority;
};

struct node *delete(struct node *T, int key);
struct node *_delete(struct node *T, int key);

struct node *rightRotate(struct node *T)
{
    struct node *s = T->left;
    T->left = s->right;
    s->right = T;
    return s;
}

struct node *leftRotate(struct node *T)
{
    struct node *s = T->right;
    T->right = s->left;
    s->left = T;
    return s;
}

struct node *makenode(int key, int priority)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->key = key;
    new->priority = priority;
    new->left = NULL;
    new->right = NULL;

    return new;
}

/* 再帰的に探索 */
struct node *insert(struct node *T, int key, int priority)
{
    if (T == NULL)
    {
        return makenode(key, priority);
    }
    if (key == T->key) // 重複したkeyは無視
    {
        return T;
    }
    if (key < T->key)
    {
        T->left = insert(T->left, key, priority);
        if (T->priority < (T->left)->priority) // 左の子の方が優先度が高い場合右回転
        {
            T = rightRotate(T);
        }
    }
    else
    {
        T->right = insert(T->right, key, priority);
        if (T->priority < (T->right)->priority) // 右の子の方が優先度が高い場合左回転
        {
            T = leftRotate(T);
        }
    }
    return T;
}

/* 削除対象の接点を探索 */
struct node *delete(struct node *T, int key)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (key < T->key)
    {
        T->left = delete(T->left, key);
    }
    else if (key > T->key)
    {
        T->right = delete(T->right, key);
    }
    else
    {
        return _delete(T, key);
    }
    return T;
}

/* 削除対象の接点の場合 */
struct node *_delete(struct node *T, int key)
{

    if (T->left == NULL && T->right == NULL) // 葉の場合
    {
        return NULL;
    }
    else if (T->left == NULL) // 右の子のみを持つ場合
    {
        T = leftRotate(T);
    }
    else if (T->right == NULL) // 左の子のみを持つ場合
    {
        T = rightRotate(T);
    }
    else // 両方の子を持つ場合
    {
        if ((T->left)->priority > (T->right)->priority) // 優先度が高い方を持ち上げる
        {
            T = rightRotate(T);
        }
        else
        {
            T = leftRotate(T);
        }
    }
    return delete(T, key);
}

int find(struct node *T, int key)
{
    struct node *x = T;
    while (x != NULL)
    {
        if (key == x->key)
        {
            return 1;
        }
        else if (key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return 0;
}

void inorder_tree_work(struct node *T)
{
    if (T != NULL)
    {
        inorder_tree_work(T->left);
        printf(" %d", T->key);
        inorder_tree_work(T->right);
    }
}

void preorder_tree_work(struct node *T)
{
    if (T != NULL)
    {
        printf(" %d", T->key);
        preorder_tree_work(T->left);
        preorder_tree_work(T->right);
    }
}

int main(void)
{
    struct node *Tree = NULL;
    int n;
    int k, p; // key, priority
    char command[10];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);
        if (command[0] == 'p')
        {
            inorder_tree_work(Tree);
            printf("\n");
            preorder_tree_work(Tree);
            printf("\n");
        }
        else if (command[0] == 'd')
        {
            scanf("%d", &k);
            Tree = delete(Tree, k);
        }
        else if (command[0] == 'i')
        {
            scanf("%d%d", &k, &p);
            Tree = insert(Tree, k, p);
        }
        else if (command[0] == 'f')
        {
            scanf("%d", &k);
            if (find(Tree, k))
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
    }
    return 0;
}