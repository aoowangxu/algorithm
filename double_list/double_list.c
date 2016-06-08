/*************************************************************************
	> File Name: double_list.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Apr 2016 12:08:35 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"insert.h"

int creat(Head *head)
{
    int data;
    Head p = NULL;
    while(1)
    {
        printf("please input data:");
        scanf("%d", &data);
        if(data <= 0)
        {
            break;
        }
        //head_insert(head, data);
        middle_insert(head, data);
        //tail_insert(head, data, &p);
    }
    return 0;
}

int output(Head head)
{
    while (NULL != head)
    {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("\b\b\b   \n");
    return 0;
}

int destory(Head *head)
{
    Head p = *head;
    while (NULL != p)
    {
        *head = (*head)->next;
        free(p);
        p = *head;
    }
    return 0;
}


int m_delete(Head *head, int data)
{
    Head cur = *head;
    while (NULL != cur && data != cur->data)
    {
        cur = cur->next;
    }

    if (NULL == cur)
    {
        printf("no data\n");
    }
    else if(*head == cur)
    {
        *head = (*head)->next;
        free(cur);
    }
    else
    {
        cur->next->pre = cur->pre;
        cur->pre->next = cur->next;
        free(cur);
    }
    return 0;
}

