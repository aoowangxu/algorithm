/*************************************************************************
	> File Name: stack.h
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Mon 02 May 2016 02:43:30 AM EDT
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#define MAX_SIZE 100

typedef struct 
{
    int array[MAX_SIZE];
    int top;
}stack;

int initstack(stack **s);
int destorystack(stack *s);
int clearstack(stack *s);
int stackempty(stack *s);
int gettop(stack *s, int *e);
int push(stack *s, int e);
int pop(stack *s, int *e);
int stracklength(stack *s);

#endif
