/*************************************************************************
	> File Name: main.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 21 May 2016 10:48:35 PM EDT
 ************************************************************************/

#include<stdio.h>
#include"str.h"
#include<string.h>
int main()
{
    char ch[100] = "123 456 qwe o";
    char word[20] = " ";
    //printf("input string");
    //scanf("%s",ch);
    printf("input sub str:");
    scanf("%s", word);

    judge(ch, word, strlen(word));
    
    return 0;
}

