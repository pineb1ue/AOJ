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


struct node *treeInsert(struct node *T, struct node *z)
{
    struct node *r, *x, *y;
    r = T;
    y = NULL;
    x = r;
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
        r = z;
    }
    else
    {
        if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
    return r;
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

struct node *treeSearch(struct node *T, int a)
{
    struct node *x = T;

    while (x != NULL && x->key != a)
    {
        if (a < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return x;
}


struct node *treeMinimum(struct node *T)
{
    struct node *x = T;
    while (x ->left != NULL)
    {
        x = x->left;
    }
    return x;
}

struct node *treeDelete(struct node *T, struct node *z)
{
    struct node *r, *y, *x;
    r = T;
    y = NULL;
    x = NULL;

    if (z->left == NULL || z->right == NULL)
    {
        y = z;
    }
    else
    {
        y = treeMinimum(z->right);
    }

    if (y->left != NULL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NULL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NULL)
    {
        r = x;
    }
    else
    {
        if (y == y->parent->left)
        {
            y->parent->left = x;
        }
        else
        {
            y->parent->right = x;
        }
    }
    if (y != z)
    {
        z->key = y->key;
    }
    free(y);

    return r;
}

int main(void)
{
    struct node *Tree = NULL;
    struct node *y, *z;
    int n;
    int key;
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
        else
        {
            scanf("%d", &key);
            if (command[0] == 'd')
            {
                y = treeSearch(Tree, key);
                if (y != NULL)
                {
                    treeDelete(Tree, y);
                }
            }
            else
            {
                z = (struct node *)malloc(sizeof(struct node));
                z->key = key;
                z->left = NULL;
                z->right = NULL;
                if (command[0] == 'i')
                {
                    Tree = treeInsert(Tree, z);
                }
                else if (command[0] == 'f')
                {
                    scanf("%d", &key);
                    z = (struct node *)malloc(sizeof(struct node));
                    z->key = key;
                    z->left = NULL;
                    z->right = NULL;
                    y = treeSearch(Tree, z->key);
                    if (y != NULL)
                    {
                        printf("yes\n");
                    }
                    else
                    {
                        printf("no\n");
                    }
                }
            }
        }
    }
    return 0;
}