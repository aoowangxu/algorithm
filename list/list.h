/*************************************************************************
	> File Name: list.h
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Mar 2016 10:56:01 AM EST
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H

typedef struct node
{
    int data;
    struct node *next;
}Node, *Head;

int creat(Head *head);
void output(Head head);
void destory(Head *head);
void deleted(Head *head, int data);
int createtail(Head *head);

#endif
