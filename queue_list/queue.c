/*************************************************************************
	> File Name: queue.c
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2016 07:40:56 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int come_out(Head *head)
{
    if (NULL == *head)
    {
        printf("come_in failed, queue is empty.");
        exit(1);
    }

    Head p = *head;
    int tmp = (*head)->num;
    *head = (*head)->next;
    free(p);
    return tmp;
}

int come_in(Head *head, int num, Head *tail)
{
    Head p = (Head)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("malloc() failed!\n");
        exit(1);
    }
    p->next = NULL;
    p->num = num;

    if(NULL == *head)
    {
        *head = p;
    }
    else
    {
        (*tail)->next = p;
    }
    *tail = p;
    return 0;
}

