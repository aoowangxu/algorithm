/*************************************************************************
	> File Name: sort.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sun 10 Jul 2016 02:19:56 AM EDT
 ************************************************************************/

#include<stdio.h>
#include"sort.h"

static void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

static int compare(int a, int b)
{
    return a > b ? 1 : 0;
}

static void adjust(int *arr, int n, int root)
{
    /*
    int i = 2*root + 1;
    if(i <= n - 1 && !compare(arr[i], arr[i+1]))
    {
        ++i;
    }
    if (compare(arr[root], arr[i]))
    {
        return;
    }
    if(i >= n)
    {
        return;
    }
    arr[root] = arr[i];
    root = i;
    adjust(arr, n, root);
    */
    int temp = *(arr + root);
    int i= 0;
    for (i = 2 * root + 1; i < n; i = 2 * i +1)
    {
        if (i < (n - 1) && !compare(arr[i], arr[i+1]))//if i+1 = size?
            {
                ++i;
            }
        if (compare(temp, arr[i]))
            {
                break;
            }
        arr[root] = arr[i];
        root = i;
    }
    arr[root] = temp;

}

static void init(int *arr, int n)
{
    int i = 0;
    for (i = n/2 -1; i >= 0; --i)
    {
        adjust(arr, n, i);
    }
}


void sort(int *arr, int n)
{
    init(arr, n);
    int i = 0;
    for (i = n-1; i > 0; --i)
    {
        swap(arr, arr + i);
        adjust(arr, i, 0);
    }
}
