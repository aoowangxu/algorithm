/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2016 11:20:30 AM EDT
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H
#define N 100
typedef struct node
{
    int arr[N]; 
    int top ;
}stack;

int pop(stack *s1);
int push(stack *s1, int num);
int empty(stack *s1);
int get_count(stack *s1);
#endif
