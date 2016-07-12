/*************************************************************************
	> File Name: sort.h
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sun 10 Jul 2016 02:19:56 AM EDT
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H
static void adjust(int *arr, int n, int root);
static int compare(int a, int b);
static void init(int *arr, int n);
static void swap(int *pa, int *pb);

void sort(int *arr, int n);

#endif
