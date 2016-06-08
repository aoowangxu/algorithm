/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Apr 2016 11:33:30 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"double_list.h"
#include"insert.h"
int main()
{
    Head head = NULL;//  变量为初始化， 导致调用函数发生段错误
    int n = 0;
    creat(&head);
    
    output(head);
    printf("please enter delete data:\n");
    scanf("%d", &n);
    m_delete(&head, n);
    output(head);
    destory(&head);
    
    return 0;
}
