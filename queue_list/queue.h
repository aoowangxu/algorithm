/*************************************************************************
	> File Name: queue.h
	> Author: 
	> Mail: 
	> Created Time: Fri 22 Apr 2016 07:40:56 PM EDT
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H
typedef struct queue
{
    int num;
    struct queue *next;
}Node, *Head;

int come_out(Head *head);
int come_in(Head *head, int num, Head *tail);

#endif
