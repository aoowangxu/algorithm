/*************************************************************************
	> File Name: quick_sort.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 07 May 2016 10:53:41 AM EDT
 ************************************************************************/

#include<stdio.h>

void quick_sort(int *arr, int left, int right)
{
    if (left > right)
    {
        return;
    }
    int i = left;
    int j = right;
    int t = 0;
    int tmp = arr[left];

    while (i != j)
    {
        while (tmp <= arr[j] && j > i)
        {
            --j;
        }
        while (tmp >= arr[i] && j > i)
        {
            ++i;
        }
        
        if (i < j)
        {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[left] = arr[i];
    arr[i] = tmp;

    quick_sort(arr, left, i-1);
    quick_sort(arr, i+1, right);
    return;
}

int main(void)
{
    int arr[10] = {1, 3, 1, 5, 0, 3, 32, 423, 21};
    quick_sort(arr, 0, 9);

    int i = 0;
    for(i = 0; i < 10; ++i)
    {
        printf("%d  ", arr[i]);
    }
    putchar(10);
    return 0;

}
