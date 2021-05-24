/*  Doubly Linked List (双方向連結リスト) */
/* リストの最初と最後が繋がっていること(環状)に注意!! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    unsigned int key;
    struct node *next;
    struct node *prev;
};

typedef struct node *NodePointer;

NodePointer nil;

NodePointer listSearch(int key)
{
    NodePointer t;
    for (t = nil->next; t != nil; t = t->next)
    {
        if (t->key == key)
        {
            return t;
        }
    }
    return nil;
}

void init(void)
{
    nil = malloc(sizeof(struct node));
    nil->next = nil;
    nil->prev = nil;
}

void printList(void)
{
    NodePointer cur = nil->next;
    int isf = 1;
    while (1)
    {
        if (cur == nil)
            break;
        if (isf == 0)
            printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
        isf = 0;
    }
    printf("\n");
}

void deleteNode(NodePointer t)
{
    NodePointer a_del = t->next, b_del = t->prev;
    if (a_del == nil)
    {
        nil->prev = b_del;
        b_del->next = nil;
    }
    else if (b_del == nil)
    {
        nil->next = a_del;
        a_del->prev = nil;
    }
    else
    {
        a_del->prev = b_del;
        b_del->next = a_del;
    }
    free(t);
}

void deleteFirst(void)
{
    NodePointer t = nil->next;
    if (t == nil)
        return;
    deleteNode(t);
}

void deleteLast(void)
{
    NodePointer t = nil->prev;
    if (t == nil)
        return;
    deleteNode(t);
}

void delete (int key)
{
    NodePointer t = listSearch(key);
    if (t == nil)
        return;
    deleteNode(t);
}

void insert(int key)
{
    NodePointer x;
    x = malloc(sizeof(struct node));
    x->key = key;

    if (nil->prev == NULL)
    {
        nil->prev = x;
    }

    if (nil->next == NULL)
    {
        nil->next = x;
        x->prev = nil;
        x->next = nil;
    }
    else
    {
        nil->next->prev = x;
        x->next = nil->next;
        x->prev = nil;
        nil->next = x;
    }
}

int main(void)
{
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;
    scanf("%d", &n);
    init();
    for (i = 0; i < n; i++)
    {
        scanf("%s%d", com, &key);
        if (com[0] == 'i')
        {
            insert(key);
            np++;
            size++;
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                    deleteFirst();
                else if (com[6] == 'L')
                    deleteLast();
            }
            else
            {
                delete (key);
                nd++;
            }
            size--;
        }
    }

    printList();
    return 0;
}