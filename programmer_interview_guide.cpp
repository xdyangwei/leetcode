//程序员代码面试指南
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <string>
using namespace std;
void find_specific_number_in_matrix()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v;
    int n1 = n;
    while (n1--)
    {
        int m1 = m;
        vector<int> v1;
        while (m1--)
        {
            int x;
            cin >> x;
            v1.push_back(x);
        }
        v.push_back(v1);
    }
    bool flag = false;
    int start = 0, end = m - 1;
    for (int i = 0; i < n;)
    {
        for (int j = m - 1; j >= 0;)
        {
            if (v[i][j] == k)
            {
                flag = true;
                break;
            }
            else if (v[i][j] > k)
            {
                j--;
            }
            else
            {
                break;
            }
        }
        if (flag == true)
            break;
        else
        {
            i++;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
}

//给定一个数组arr, 请返回其中最大可整合子数组的长度
//如果一个数组在排序之后，每相邻两个数的差的绝对值都为1，或者该数组长度为1，则该数组为可整合数组。
//思路：先将数组排序，然后两个for循环遍历数组，使用set容器对当前子数组进行排序，
//当子数组中有重复值时肯定不可能满足条件，没有重复值时最大值-最小值+1如果等于长度的话说明子数组可整合
void longest_sortable_subarray_length()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int Max = 1, tmp = 1;
    for (int i = 0; i < v.size(); i++)
    {
        set<int> s;
        for (int j = i; j < v.size(); j++)
        {
            if (s.find(v[j]) == s.end())
            {
                s.insert(v[j]);
                if (*(--s.end()) - *s.begin() + 1 == (s.size()))
                {
                    Max = max(Max, (int)s.size());
                }
            }
            else
            {
                break;
            }
        }
    }
    cout << Max << endl;
}

//给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序二元组
//思路：使用双指针法，当前后两者加起来=k时输出，而为了处理重复的值需要把前后相等的值跳过
//相加>k时后指针往前移，<k时前指针往后移
void sum_equal_k()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0, j = v.size() - 1; i < j;)
    {
        //cout<<i<<" "<<j<<endl;
        if (v[i] + v[j] == k)
        {
            cout << v[i] << " " << v[j] << endl;
            while (v[i] == v[i + 1])
                i++;
            i++;
            while (v[j] == v[j - 1])
            {
                j--;
            }
            j--;
        }
        else if (v[i] + v[j] > k)
        {
            while (v[j] == v[j - 1])
            {
                j--;
            }
            j--;
        }
        else
        {
            while (v[i] == v[i + 1])
                i++;
            i++;
        }
    }
}

//给定排序数组arr和整数k，不重复打印arr中所有相加和为k的不降序三元组
void sum_equal_k_2()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++)
    {
        int x = k - v[i];
        while (v[i] == v[i + 1])
            i++;
        for (int j = i + 1, k = v.size() - 1; j < k;)
        {
            if (v[j] + v[k] == x)
            {
                cout << v[i] << " " << v[j] << " " << v[k] << endl;
                while (v[j] == v[j + 1])
                    j++;
                j++;
                while (v[k] == v[k - 1])
                    k--;
                k--;
            }
            else if (v[j] + v[k] > x)
            {
                while (v[k] == v[k - 1])
                    k--;
                k--;
            }
            else
            {
                while (v[j] == v[j + 1])
                    j++;
                j++;
            }
        }
    }
}

void stack_with_getmin()
{
    stack<int> s1;
    stack<int> s2;
    int n;
    cin >> n;
    vector<string> v;
    cin.get();
    while (n)
    {
        string s;
        getline(cin, s);
        v.push_back(s);
        n--;
    }
    for (auto vv : v)
    {
        auto it = vv.find(" ");
        if (it != string::npos)
        {
            auto ss = stoi(vv.substr(it + 1));
            s1.push(ss);
            if (s2.empty())
                s2.push(ss);
            else
            {
                if (ss < s2.top())
                    s2.push(ss);
                else
                    s2.push(s2.top());
            }
        }
        else
        {
            if (vv == "pop")
            {
                s1.pop();
                s2.pop();
            }
            if (vv == "getMin")
            {
                cout << s2.top() << endl;
            }
        }
    }
}

int main()
{
    stack_with_getmin();
    return 0;
}