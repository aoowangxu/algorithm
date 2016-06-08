/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2016 11:43:48 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{
    stack s;
    s.arr[0] = 0;
    s.top = 0;
    int i = 0;
    int num = 0;
    empty(&s);

    for (i = 0; i < N; ++i)
    {
        printf("please input push num:");
        scanf("%d", &num);
        if (-1 == num)
        {
            break;
        }
        push(&s, num);
    }
    get_count(&s);

    printf("pop squeue:");
    while (s.top != 0)
    {
        pop(&s);
    }
    putchar(10);

    return 0;
}
