/*************************************************************************
	> File Name: main.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Mon 02 May 2016 02:43:31 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"stack.h"

int main(void)
{
    int i = 0;
    char string[100] = {'\0'};
    char s1[100] = {'\0'};
    char s2[100] = {'\0'};
    /*
    stack *s1;
    stack *s2;
    initstack(&s1);
    initstack(&s2);
*/
    printf("plase input string:");
    scanf("%s", string);
    turn_rpn(string, s1);
    printf("%s", s1);
    return 0;

}
