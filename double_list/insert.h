/*************************************************************************
	> File Name: insert.h
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Apr 2016 10:33:39 AM EDT
 ************************************************************************/

#ifndef _INSERT_H
#define _INSERT_H


typedef struct D_list
{
    struct D_list *pre;
    struct D_list *next;
    int data;
}Node, *Head;

int head_insert(Head *head, int data);
int middle_insert(Head *head, int data);
int tail_insert(Head *head, int data, Head *p_tail);
#endif
