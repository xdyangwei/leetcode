//程序员代码面试指南
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <numeric>
#include <cstring>
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

//用两个栈实现队列，支持队列的基本操作。
template <typename T>
class Stack
{
public:
    void push(T a)
    {
        s1.push(a);
    }
    T top()
    {
        while (!s1.empty())
        {
            auto x = s1.top();
            s2.push(x);
            s1.pop();
        }
        auto x = s2.top();
        while (!s2.empty())
        {
            auto x = s2.top();
            s1.push(x);
            s2.pop();
        }
        return x;
    }
    void pop()
    {
        while (!s1.empty())
        {
            auto x = s1.top();
            s2.push(x);
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            auto x = s2.top();
            s1.push(x);
            s2.pop();
        }
    }

private:
    stack<T> s1;
    stack<T> s2;
};

void queue_implemented_stack()
{
    Stack<int> s1;
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
        //cout<<vv<<endl;
        auto it = vv.find(" ");
        if (it != string::npos)
        {
            auto ss = stoi(vv.substr(it + 1));
            s1.push(ss);
        }
        if (vv == "peek")
        {
            cout << s1.top() << endl;
        }
        if (vv == "poll")
            s1.pop();
    }
}

//用递归函数和栈逆序一个栈
//思路：使用两次递归，第一次递归取出每次栈底的值，第二次递归将这个值插入到栈中
int get_bottom_and_remove(stack<int> &s)
{
    auto x = s.top();
    s.pop();
    if (s.empty())
        return x;
    else
    {
        auto last = get_bottom_and_remove(s);
        s.push(x);
        return last;
    }
}

void recursive_reverse_stack(stack<int> &s)
{
    if (s.empty())
        return;
    int i = get_bottom_and_remove(s);
    recursive_reverse_stack(s);
    s.push(i);
}

void recursive_print(stack<int> &s)
{
    if (s.empty())
        return;
    else
    {
        auto x = s.top();
        s.pop();
        recursive_print(s);
        cout << x << " ";
    }
}

void reverse_stack_with_recursive()
{
    int n;
    cin >> n;
    stack<int> s1;
    while (n--)
    {
        int x;
        cin >> x;
        s1.push(x);
    }
    recursive_reverse_stack(s1);
    recursive_print(s1);
}

//给定一个数组arr，该数组无序，但每个值均为正数，再给定一个正数k。
//求arr的所有子数组中所有元素相加和为k的最长子数组的长度
//思路：使用双指针法，一前一后指针一开始都指向第一个元素，当两者之间的和小于k时右指针向右移一位，
//小于k的话左指针向左移一位，=k的话将两个指针之间的距离与当前结果比较取较大值，当右指针超过数组最右边时循环结束
void longest_subarray_sum_k()
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
    int i = 0, j = 0, sum = v[0], len = 1;
    while (j < v.size())
    {
        //cout<<i<<" "<<j<<" "<<sum<<endl;
        if (sum < k)
        {
            if (j == v.size() - 1)
                break;
            j++;
            sum += v[j];
        }
        else if (sum > k)
        {
            sum -= v[i];
            i++;
        }
        else
        {
            len = max(len, j - i + 1);
            sum -= v[i];
            i++;
        }
    }
    cout << len << endl;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
//链表中环的入口节点
//第一步：找出是否有环，使用快慢指针
//第二步：算出环的长度,在二者相遇的地方再让快指针走，两者再一次相遇时就走了整个环的长度
//再使用一个快指针先走环的长度，然后再使用一个慢指针，二者相遇的地方就是环的入口地址
ListNode *meet;
int CircleLength;
//确定链表是否有环
bool hascircle(ListNode *pHead)
{
    auto p1 = pHead, p2 = pHead;
    bool flag = false;
    while (p2 != nullptr)
    {
        p1 = p1->next;
        if (p2->next != nullptr)
            p2 = p2->next->next;
        else
        {
            break;
        }
        if (p1 == p2)
        {
            meet = p1;
            flag = true;
            break;
        }
    }
    return flag;
}

//计算出环的长度
int circle_length(ListNode *meet)
{
    auto p1 = meet;
    auto p2 = meet->next;
    int i = 1;
    while (p1 != p2)
    {
        p2 = p2->next;
        i++;
    }
    CircleLength = i;
    return i;
}

//找出环的入口节点
ListNode *circle_entrance(ListNode *pHead)
{
    auto p1 = pHead;
    auto p2 = pHead;
    while (CircleLength--)
    {
        p2 = p2->next;
    }
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

//数组中重复的数字
//使用数组下标
bool duplicate(int numbers[], int length, int *duplication)
{
    vector<int> v(length, 0);
    bool flag = false;
    for (int i = 0; i < length; i++)
    {
        v[numbers[i]] += 1;
        if (v[numbers[i]] > 1)
        {
            *duplication = numbers[i];
            flag = true;
            break;
        }
    }
    return flag;
}

//二维数组的查找
//每次找右上面的点，比它小的话可以排除这一列，比它大的话可以排除这一行
bool Find(int target, vector<vector<int>> array)
{
    if (array.empty() || array[0].empty())
        return false;
    int m = array.size();
    int n = array[0].size();
    bool flag = false;
    for (int i = 0; i < m;)
    {
        cout << "i:" << i << endl;
        for (int j = n - 1; j >= 0;)
        {
            cout << "j:" << j << endl;
            if (array[i][j] < target)
            {
                i++;
                break;
            }
            else if (array[i][j] > target)
            {
                j--;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }
    return flag;
}

//替换空格
//使用辅助字符串
void replaceSpace(char *str, int length)
{
    string s(str);
    auto it = s.begin();
    while ((it = find(it, s.end(), ' ')) != s.end())
    {
        s.replace(it, it + 1, string("%20"));
    }
    strcpy(str, s.c_str());
}

//输入一个链表，按链表从尾到头的顺序返回。
//使用递归或栈都可
//递归版本
vector<int> results;
ListNode *printListFromTailToHead_recursive(ListNode *head)
{
    if (head->next)
    {
        printListFromTailToHead_recursive(head->next)->next = head;
        results.push_back(head->val);
    }
    else
    {
        results.push_back(head->val);
    }
    return head;
}

vector<int> printListFromTailToHead(ListNode *head)
{
    printListFromTailToHead_recursive(head);
    return results;
}

//使用栈的版本
vector<int> printListFromTailToHead_1(ListNode *head)
{
    stack<int> s1;
    while (head)
    {
        s1.push(head->val);
        head = head->next;
    }
    vector<int> v;
    while (!s1.empty())
    {
        v.push_back(s1.top());
        s1.pop();
    }
    return v;
}

//零钱兑换，动态规划
int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[j]; j < amount + 1; j++)
        {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    return dp[amount] < amount + 1 ? dp[amount] : -1;
}

//最长回文子串
string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    int start;
    int max_len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = i, j = i;
        while (s[i] == s[i + 1])
            i++;
        k = i;
        while (j > 0 && k < s.size() - 1 && s[j - 1] == s[k + 1])
        {
            j--;
            k++;
        }
        if (k - j + 1 > max_len)
        {
            max_len = k - j + 1;
            start = j;
        }
    }
    return s.substr(start, max_len);
}

//不同路径，动态规划
int uniquePaths(int m, int n)
{
    vector<vector<int>> v(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        v[i][0] = 1;
    for (int i = 0; i < n; i++)
        v[0][i] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }
    return v[m - 1][n - 1];
}

//不同路径，含障碍物
//动态规划
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long>> v(m, vector<long>(n, 0));
    for (int i = 0; i < m; i++)
    {
        if (obstacleGrid[i][0] != 1)
            v[i][0] = 1;
        else
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (obstacleGrid[0][i] != 1)
            v[0][i] = 1;
        else
            break;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                v[i][j] = 0;
            else
                v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }
    return v[m - 1][n - 1];
}

//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//思路：找出第一个偶数，然后找出这个偶数之后的第一个奇数，将这个奇数插入到这第一个偶数之前
//直到这个偶数之后没有奇数
void odd_even_exchange(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i] & 0x1)
        {
            i++;
        }
        int j = i;
        auto it = find_if(v.begin() + j, v.end(), [](int a) {
            return a & 0x1;
        });
        if (it == v.end())
            break;
        else
        {
            auto x = *it;
            v.erase(it);
            v.insert(v.begin() + j, x);
        }
    }
}

//剪绳子，给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），
//每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
//思路：使用动态规划
int cutRope(int number)
{
    if (number < 2)
        return 0;
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;

    int *products = (int *)malloc((number + 1) * sizeof(int));
    //assert(products != NULL);
    memset(products, 0, (number + 1) * sizeof(int));
    /****长度为1、2、3、4的绳子的最大积********/
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    int i = 0;
    int j = 0;

    for (i = 4; i <= number; i++)
    {
        max = 0;
        for (j = 1; j <= i / 2; j++)
        {
            int product = products[j] * products[i - j];
            if (max < product)
                max = product;

            products[i] = max;
        }
    }
    max = products[number];

    free(products);
    products = NULL;

    return max;
}

//0-1背包问题
//使用动态规划
int Knapsack_01()
{
    int n, w;
    cin >> n >> w;
    int n1 = n;
    vector<pair<int, int>> goods;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        goods.push_back(make_pair(x, y));
    }
    vector<vector<int>> v(n1 + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = w; j >= 1; j--)
        {
            if (j >= goods[i - 1].first)
            {
                v[i][j] = max(v[i - 1][j], v[i - 1][j - goods[i - 1].first] + goods[i - 1].second);
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
        }
    }
    int Max = 0;
    for (auto x : v)
    {
        for (auto xx : x)
        {
            Max = max(xx, Max);
        }
    }
    return Max;
}

int main()
{
    cout << Knapsack_01() << endl;
    return 0;
}