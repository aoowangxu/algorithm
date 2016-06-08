/*************************************************************************
	> File Name: str.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 21 May 2016 10:48:35 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int judge(char *ch, char *word, int word_len)
{
    int j = 0;
    int i = 0;
    char word_tmp[20] = "";
    while ('\0' != *ch) 
    {
        if (' '!= *ch)
        {
            word_tmp[i++] = *ch;
        }
        else
        {
            word_tmp[i] = '\0';
            for ( j = 0; j < word_len; ++j)
            {
                if (word[j] != word_tmp[j])
                {
                    break;
                }
            }
            if (j == word_len)
            {
                printf("yes\n");
            }
            i = 0;
        }
        ++ch;
    }
    return 0;
}
