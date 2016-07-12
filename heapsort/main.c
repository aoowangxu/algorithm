/*************************************************************************
	> File Name: main.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sun 10 Jul 2016 02:19:56 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"sort.h"
#define N 8
int main()
{
    int arr[N] = {5,1,322,6,7,9,0,12};
    int i = 0;

    printf("begin arr is: \n");
    for(i = 0; i < N; ++i)
    {
        printf("%d\t", arr[i]);
    } 
    putchar(10);
    

    sort(arr, N);

    printf("sorted arr is: \n");

    for(i = 0; i < N; ++i)
    {
        printf("%d\t", arr[i]);
    } 
    putchar(10);
    return 0;
}
