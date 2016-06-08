/*************************************************************************
	> File Name: stack.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2016 11:20:30 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int pop(stack *s1)
{
    if (0 == s1->top)
    {
        printf("empty stack! pop() failed!\n");
        exit(1);
    }
    printf("%d\t", s1->arr[--s1->top]);
    return 0;
}

int push(stack *s1, int num)
{
    if (s1->top < 0 || s1->top >= 100)
    {
        exit(1);
    }

    s1->arr[s1->top++] = num;
    printf("push %d\n", s1->arr[s1->top - 1]);
    return 0;
}

int empty(stack *s1)
{
    if(0 == s1->top)
    {
        printf("stack is empty!\n");
        return 0;
    }
    else
    {
        printf("stack is't empty!\n");
        return 1;
    }
}

int get_count(stack *s1)
{
    return s1->top;
}
