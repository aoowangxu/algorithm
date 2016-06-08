/*************************************************************************
	> File Name: main.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Mon 02 May 2016 02:43:31 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"stack.h"

int main(void)
{
    int i = 0;
    stack *s;
    initstack(&s);

    for (i = 0; i < 10; ++i)
    {
        push(s, i);
    }

    printf("empty? %d\n", stackempty(s));

    int tmp = 0;
    gettop(s, &tmp);
    printf("top is %d\n", tmp);
/*
    printf("len is %d\n", stracklength(s));
    for (i = 0; i < 10; ++i)
    {
        pop(s, &tmp);
        printf("%d->>", tmp);
    }
    printf("\b\b\b   \n");
    */
   
    clearstack(s);
    for (i = 0; i < 10; ++i)
    {
        pop(s, &tmp);
        printf("%d->>", tmp);
    }
    printf("\b\b\b   \n");

    destorystack(s);
    return 0;

}
