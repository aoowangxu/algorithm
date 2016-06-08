/*************************************************************************
	> File Name: main.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sun 01 May 2016 10:24:20 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"order_list.h"

int main()
{
    int i = 0;
    order_list l1;
    order_list *list1 = &l1;
    list1->len = 0;
    for (i = 0; i < 10; ++ i)
    {
        insert(list1, i, i);
        getnum(list1, i);
    }

    deleted(list1, 4);
    printf("is empty %d\n", isempty(list1));

    output(list1);
    return 0;
}
