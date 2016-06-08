/*************************************************************************
	> File Name: order_list.h
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sun 01 May 2016 10:24:20 PM EDT
 ************************************************************************/

#ifndef _ORDER_LIST_H
#define _ORDER_LIST_H

#define MAX_SIZE 100
typedef struct
{
    int array[MAX_SIZE];
    int len;
}order_list;

int getnum(order_list *list, int i);
int insert(order_list *list, int tmp, int j);
int deleted(order_list *list, int i);
int isempty(order_list *list);
int output(order_list *list);
#endif
