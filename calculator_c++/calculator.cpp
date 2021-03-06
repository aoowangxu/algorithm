/*************************************************************************
	> File Name: calculator.cpp
	> Author: Xu Wang
	> Mail: aoo_wangxu@163.com 
	> Created Time: Fri 20 May 2016 07:41:31 PM EDT
 ************************************************************************/

#include<iostream>
#include<stack>
#include<list>
#include<string>
using namespace std;

typedef struct data
{
    double n;
    char ch;
}Data;
//compare operate;
bool compare(Data d1, data top)
{
    if (d1.ch == ')' && top.ch != '(')
    {
        return true;
    }
    if ((d1.ch == '+' || d1.ch == '-') && (top.ch == '*' || top.ch == '/'))
    {
        return true;
    }
    return false;
};


// calcuate list_epi;
double calcuate(list<Data> s1)
{
    stack<Data> stack_tmp;
    Data d1, d2;
    list<Data>::iterator it = s1.begin();
    while (it != s1.end())
    {
        if ((*it).n != 0)
        {
            stack_tmp.push(*it);
        }
        else
        {
            d1 = stack_tmp.top();
            stack_tmp.pop();
            d2 = stack_tmp.top();
            stack_tmp.pop();
            switch ((*it).ch)
            {
                case '*':
                {
                    d1.n = d1.n * d2.n;
                    break;
                }
                case '/':
                {
                    d1.n = d1.n / d2.n;
                    break;
                }
                case '+':
                {
                    d1.n = d1.n + d2.n;
                    break;
                }
                case '-':
                {
                    d1.n = d1.n - d2.n;
                    break;
                }
                default:
                {
                    break;
                }
            }
            stack_tmp.push(d1);
        }
        ++it;
    }
    d1 =  stack_tmp.top();
    stack_tmp.pop();
    return d1.n;
}

int main()
{
    list<Data> s_mid;
    list<Data> s_epi;
    stack<Data> sym;
    double tmp = 0;
    Data data_tmp;

    string string_cin;
    cout << "input expression" << endl;
    cin >> string_cin;

//string2list_mid;
    string::iterator it = string_cin.begin();
    while(it != string_cin.end())
    {
        if (*it < '0' && *it > 9)
        {
            data_tmp.n = 0;
            data_tmp.ch = *it;
            s_mid.push_back(data_tmp);
            ++it;
            continue;
        }
        while (*it >= '0' && *it <= '9') 
        {
            tmp = tmp * 10 + (*it) - 48; 
            ++it;
        }
        data_tmp.n = tmp;
        data_tmp.ch = 0;
        s_mid.push_back(data_tmp);
        tmp = 0;
    }





    
    list<Data>::iterator it_list = s_mid.begin();
//test

    cout << "mid_list**************" << endl;
    it_list = s_mid.begin();
    while(it_list != s_mid.end())
    {
        cout << (*it_list).n << "," << (*it_list).ch <<endl;
        ++it_list;
    }
//  

//list_mid2list_epi;
    
    Data sym_top;

    it_list = s_mid.begin();
    Data sym_tmp;
    while(it_list != s_mid.end())
    {
        if((*it_list).ch == 0)
        {
            s_epi.push_back(*it_list);
        }
        else
        {
            if (sym_top.ch == '(')
            {
                sym.push(*it_list);
            }
            if (!sym.empty())
            {
                sym_top = sym.top();
            }
            if ((*it_list).ch == '-' || (*it_list).ch == '+')
            {
                if (sym_top.ch == '(')
                {
                    sym.push(*it_list);
                }
                else
                {
                    while (!sym.empty() && sym_top.ch != '(')
                    {
                        sym_tmp = sym.top();
                        sym.pop();
                        s_epi.push_back(sym_tmp);
                    }
                    sym.push(*it_list);
                }
            }
            else if ((*it_list).ch == '*' || (*it_list).ch == '/' || (*it_list).ch == '(')
            {
                sym.push(*it_list);
            }
            else if ((*it_list).ch == ')'=
            {
                while (sym_top.ch != '(')
                {
                    sym_tmp = sym.top();
                    sym.pop();
                    s_epi.push_back(sym_tmp);
                }
                sym.pop();
            }
        }
        ++it_list;
    }

    while (!sym.empty())
    {
        
        sym_tmp = sym.top();
        sym.pop();
        s_epi.push_back(sym_tmp);
    }

    //test
    cout << "pei_list************" << endl; 
    it_list = s_epi.begin();
    while(it_list != s_epi.end())
    {
        cout << (*it_list).n << "," << (*it_list).ch <<endl;
        ++it_list;
    }
    

    double result =  calcuate(s_epi);
    cout <<"retult: " << result << endl;
    return 0;
}

