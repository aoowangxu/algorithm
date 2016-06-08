/*************************************************************************
	> File Name: insert.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Apr 2016 10:33:39 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"insert.h"

int head_insert(Head *head, int data)
{
    Head p = (Head)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("malloc failed!\n");
        exit(1);
    }
    p->data = data;
    p->pre = NULL;
    p->next = *head;
    
    if (NULL != *head)
    {
        (*head)->pre = p;
    }
    *head = p;
    return 0;
}

int middle_insert(Head *head, int data)
{
    Head curent = *head;
    Head fore = NULL;
    Head p = (Head)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("malloc failed!\n");
        exit(1);
    }

    p->next = NULL;
    p->pre = NULL;
    p->data = data;

    if (NULL == *head)
    {
        *head = p;
        return 0;
    }
    while ((NULL != curent) && (data > curent->data))
    {
        fore = curent;
        curent = curent->next;
    }

    if (curent ==  *head)
    {
        p->next = *head;
        (*head)->pre = p;
        *head = p;
    }
    else if (NULL == curent)
    {
        fore->next = p;
        p->pre = fore;
    }
    else
    {
        p->next = curent;
        curent->pre = p;
        fore->next = p;
        p->pre = fore;
    }
    return 0;
}

int tail_insert(Head *head, int data, Head *p_tail)
{
    Head p = (Head)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("malloc failed!\ndfdf ");
        exit(1);
    }

    p->data = data;
    p->next = NULL;
    p->pre = NULL;

    if (NULL == *head)
    {
        *head = p;
    }
    else
    {
        (*p_tail)->next = p;
        p->pre = *p_tail;
    }
    *p_tail = p;
    return 0;
}
