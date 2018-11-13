#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void first()
{
    int n, m;
    cin >> n >> m; //n is the number of row;m is the number of player plays
    vector<int> v;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int sum = 0;
    bool flag = true;
    while (true)
    {
        for (int i = 1; i <= n; i++)
        {
            auto x = find(v.begin(), v.end(), i);
            if (x == v.end())
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
            break;
        for (int i = 1; i <= n; i++)
        {
            auto x = find(v.begin(), v.end(), i);
            v.erase(x);
        }
        sum += 1;
    }
    cout << sum << endl;
}

void second()
{

int n,k;
    cin>>n>>k;
    int temp;
    vector<int >score(n,0);
    vector<int >awake(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        score[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        awake[i]=temp;
    }
    long sum=0,maxSum=0,baseSum = 0;
    //计算基本分数
    for(int i=0;i<n;i++)
    {
        if(awake[i])
        {
            baseSum+=score[i];
            score[i]=0;//把清醒取得的分数置0
        }
    }
    //若k大于等于n，则全部分数相加即可
    if(k>=n)
    {
        for(int i=0;i<n;i++)
        {
            maxSum+=score[i];
        }
    }
    //否则，滑动窗口，请窗口分数最大值
    else
    {
        for(int j=1;j<n-k+1;j++)
        {
            sum = 0;
            for(int kk=j;kk<j+k;kk++)
            {
                sum+=score[kk];
            }
            if(maxSum<sum)
                maxSum = sum;
        }
    }
    //输出两部分分数总和
    cout<<maxSum+baseSum;
    }
    

int main()
{
    second();
    return 0;
}