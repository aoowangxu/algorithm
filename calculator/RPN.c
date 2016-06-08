/*************************************************************************
	> File Name: RPN.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 07 May 2016 12:03:24 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<assert.h>
#include"RPN.h"
#include"stack.h"

int calculate(char *s)
{

}

int isopeartechar(char ch)
{
    if('-' == ch || '+' == ch || '(' == ch || ')' == ch || '*' == ch || '/' == ch)
    {
        return 1;
    }
    return 0;
}

int compare(char ch1, char tmp)
{
    if (')' == tmp ||'*' == ch1 || '/' == ch1)
    {
        return 1;
    }
    else if (tmp != '*' || tmp != '/')
    {
        return 1;
    }
    return 0;
}
void turn_rpn(char *s, char *s1)
{
    assert(NULL != s  && NULL != s1);
    int i = 0;
    int j = 0;
    char tmp = ' ';
    stack ch;
    stack *stack_ch = &ch;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            s1[j++] = s[i];
        }
        else if (isopeartechar(s[i]))
        {
            while (1)
            {
                if (stackempty(stack_ch))
                {
                    push(stack_ch, s[i]);
                    break;
                }
                gettop(stack_ch, &tmp);
                if (compare(s[i], tmp))
                {
                    pop(stack_ch, &tmp);
                    s1[j++] = ',';
                    s1[j++] = tmp;
                }
                else
                {
                    push(stack_ch, s[i]);
                }
            }
        }
        ++i;
    }
    return;
}
