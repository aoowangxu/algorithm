/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2016 07:40:56 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"queue.h"

int main(void)
{
    Head queue = NULL;
    int num = 0;
    Head tail = NULL;
    while (1)
    {
        printf("enter num:");
        scanf("%d", &num);
        if (-1 == num)
        {
            break;
        }
        come_in(&queue, num, &tail);
    }

    while (queue != NULL)
    {
        printf("%d-->", come_out(&queue));
    }
    printf("\b\b\b   \n");
    return 0;
}
