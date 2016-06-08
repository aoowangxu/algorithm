/*************************************************************************
	> File Name: order_list.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sun 01 May 2016 10:24:20 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"order_list.h"
#include<assert.h>
int getnum(order_list *list, int i)
{
    assert(i >= 0 && i < list->len);
    return list->array[i];
}

int insert(order_list *list, int tmp, int j)
{
    assert(list->len < MAX_SIZE);
    int i = 0;
    for ( i = 0; i <= list->len - j; ++i)
    {
        list->array[list->len - i] = list->array[list->len - i -1];
    }
    list->array[j] = tmp;
    list->len++;
    return 0;
}

int deleted(order_list *list, int i)
{
    assert(i >= 0 && i < list->len);
    int j = 0;
    for (j = 0; i < list->len - i; ++i)
    {
        list->array[i] = list->array[i+1];
    }
    list->array[list->len--] = 0; 
}
int isempty(order_list *list)
{
    return (list->len == 0);
}

int output(order_list *list)
{
    assert(list->len > 0 && list->len < MAX_SIZE);
    int i = 0;
    for ( i = 0; i < list->len; ++i)
    {
        printf("%d-->", list->array[i]);
    }
    printf("\b\b\b   \n");
    return 0;
}
