/*************************************************************************
	> File Name: bmi.c
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Sat 21 May 2016 09:38:14 PM EDT
 ************************************************************************/

#include<stdio.h>

enum stats  {thin, normal, fat, mild_fat, mod_fat, severe_fat};
typedef struct people
{
    int age;
    int weight;
    int hight;
    double bmi;
    enum stats;
}People;


int result(People *p)
{
    printf("please input people info:age weight hight\n");
    scanf("%d %d %d", &(*p).age, &(*p).weight, &(*p).hight);
    (*p).bmi = (*p).weight * 1.0 / (*p).hight;

    if ((*p).age >0 && (*p).age <= 5)
    {
        if ((*p).bmi < 15)
        {
            (*p).stat = thin;
        }
        else if ((*p).bmi < 18)
        {
            (*p).stat = normal;
        }
        else if ((*p).bmi < 20)
        {
            (*p).stat = fat;
        }
        else if ((*p).bmi < 22)
        {
            (*p).stat = mild_fat;
        }
        else if ((*p).bmi < 25)
        {
            (*p).stat = severe_fat;
        }
    }
    return 0;
}



int main()
{
    People p1;
    while (1)
    {
    }

}
