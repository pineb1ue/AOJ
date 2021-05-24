#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
};

void init(struct node *T)
{
    T->parent = NULL;
    T->left = NULL;
    T->right = NULL;
}

void treeInsert(struct node *T, struct node *z)
{
    struct node *x;
    struct node *y;
    y = NULL;
    x = T;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NULL)
    {
        T = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
}

void inorder_tree_work(struct node *T)
{
    inorder_tree_work(T->left);
    printf("%d", T->key);
    inorder_tree_work(T->right);
}

void preorder_tree_work(struct node *T)
{
    printf("%d", T->key);
    inorder_tree_work(T->left);
    inorder_tree_work(T->right);
}

int main(void)
{
    struct node *Tree;
    struct node *z;
    int n;
    int key;
    char command[10];

    init(Tree);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);
        if (command[0] == 'i')
        {
            init(z);
            scanf("%d", key);
            z->key = key;
            treeInsert(Tree, z);
        }
        else if (command[0] == 'p')
        {
            inorder_tree_work(Tree);
            preorder_tree_work(Tree);
        }
    }

    return 0;
}