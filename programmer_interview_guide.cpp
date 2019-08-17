//程序员代码面试指南
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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
                if (*(--s.end()) - *s.begin()+1 == (s.size()))
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

int main()
{
    longest_sortable_subarray_length();
    return 0;
}