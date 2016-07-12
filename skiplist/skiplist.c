/*************************************************************************
	> File Name: skiplist.c
	> Author: 
	> Mail: 
	> Created Time: 三  6/22 15:39:30 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include"skiplist.h"
#include"util.h"

static Node *createnode(int level, DataType data)
{
    Node *node = (Node *)malloc(sizeof(Node) + level * sizeof(Node*));
    
    assert(NULL != node);

    node->data = data;

    return node;
}

static int destroynode(Node **node)
{
    if(NULL == *node)
    {
        return 0;
    }
    free(*node);
    *node = NULL;
    return 1;
}

Skiplist *create()
{
    Skiplist *skiplist = (Skiplist *)malloc(sizeof(Skiplist));
    
    assert(NULL != skiplist);
    
    skiplist->level = 0;
    skiplist->head = createnode(MAX_LEVEL, 0);

    for(int i = 0; i < MAX_LEVEL; ++i)
    {
        skiplist->head->nexts[i] = NULL;
    }
    return skiplist;
}

void insert(Skiplist *skiplist, DataType data, int (*compare)(DataType v1, DataType v2))
{
    Node *next = NULL;
    Node *cur = skiplist->head;

    Node *updates[MAX_LEVEL] = {NULL};
    for(int i = skiplist->level - 1; i >= 0; --i)
    {
        while((next = cur->nexts[i]) && compare(data, next->data) > 0)
        {
            cur = next;
        }
        updates[i] = cur;
    }

    int level = randomlevel(MAX_LEVEL);
    if(level > skiplist->level)
    {
        for(int i = skiplist->level; i < level; ++i)
        {
            updates[i] = skiplist->head;
        }
        skiplist->level = level;
    }

    Node *node = createnode(level, data);
    for(int i = level - 1; i >= 0; --i)
    {
        node->nexts[i] = updates[i]->nexts[i];
        updates[i]->nexts[i] = node;
    }
}

int deleted(Skiplist *skiplist, DataType data, int (*compare)(DataType v1, DataType v2))
{
    if(NULL == skiplist)
    {
        return 0;
    }
    Node *next = NULL;
    Node *cur = skiplist->head;

    Node *updates[MAX_LEVEL] = {NULL};
    for(int i = skiplist->level - 1; i >= 0; --i)
    {
        while((next = cur->nexts[i]) && compare(data, next->data) > 0)
        {
            cur = next;
        }
        updates[i] = cur;
    }
    if(NULL != next && compare(data, next->data) != 0)
    {
        return 0;
    }
    for(int i = skiplist->level - 1; i >= 0; --i)
    {
        if(updates[i]->nexts[i] == next)
        {
            updates[i]->nexts[i] = next->nexts[i];
            if(NULL == skiplist->head->nexts[i])
            {
                skiplist->level--;
            }
        }
    }
    return destroynode(&next);
}

int search(Skiplist *skiplist, DataType data, int (*compare)(DataType v1, DataType v2))
{
    if(NULL == skiplist)
    {
        return 0;
    }
    Node *next = NULL;
    Node *cur = skiplist->head;

    for(int i = skiplist->level - 1; i >= 0; --i)
    {
        while((next = cur->nexts[i]) && compare(data, next->data) > 0)
        {
            cur = next;
        }
        if(NULL != next && data == next->data)
        {
            return 1;
        }
    }
    return 0;

}

void destroy(Skiplist **skiplist)
{
    if(NULL == *skiplist)
    {
        return;
    }
    Node *node = NULL;
    while(NULL != (node = (*skiplist)->head))
    {
        (*skiplist)->head = node->nexts[0];
        destroynode(&node);
    }
    free(*skiplist);
    *skiplist = NULL;
}

void output(Skiplist *skiplist)
{
    Node *node = NULL;
    for(int i = skiplist->level - 1; i >= 0; --i)
    {
        node = skiplist->head->nexts[i];
        printf("leve %d: ", i + 1);
        while(NULL != node)
        {
            printf("%d-->", node->data);
            node = node->nexts[i];
        }
        printf("\b\b\b   \n");
    }
}
