/*************************************************************************
	> File Name: stach.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Mon 02 May 2016 02:43:30 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"stack.h"
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int initstack(stack **s)
{
    *s = (stack *)malloc(sizeof(stack));
    assert(*s != NULL);

    memset((*s)->array, '0', MAX_SIZE);
    (*s)->top = -1;
    return 0;
}

int destorystack(stack *s)
{
    assert(s != NULL);
    free(s);
    return 0;
}

int clearstack(stack *s)
{
    assert(s != NULL);
    //memset(s->array, '0', sizeof(s->array));//not zero array;don't stupid！
    memset(s->array, 0, sizeof(s->array));
    printf("memset secuess %d\n",sizeof(s->array));
    return 0;
}

int stackempty(stack *s)
{
    assert(s != NULL);
    return s->top == -1 ? 0 : 1;
}

int gettop(stack *s, int *e)
{
    assert(s != NULL && s->top != -1);
    *e = s->array[s->top];
    return 0;
}

int push(stack *s, int e)
{
    assert((s != NULL) && (s->top < MAX_SIZE));
    s->array[++s->top] = e;
    return 0;
}

int pop(stack *s, int *e)
{
    assert(s != NULL && s->top != -1);
    *e = s->array[s->top--];
    return 0;
}

int stracklength(stack *s)
{
    assert(s != NULL);
    return s->top + 1;
}
