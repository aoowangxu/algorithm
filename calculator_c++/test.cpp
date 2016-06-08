/*************************************************************************
	> File Name: test.cpp
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Fri 20 May 2016 07:24:06 PM EDT
 ************************************************************************/

#include<iostream>
using namespace std;
#include<stack>

int main()
{
    stack<int> s1;
    int tmp = 0;

    for (int i = 0; i < 10; ++i)
    {
        s1.push(i);
    }
    for(int i = 0; i < 10; ++i)
    {
        cout << s1.top()  << ' ';
        s1.pop();
    }
    return 0;
}
