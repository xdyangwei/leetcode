#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
//using vs
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


void third(){
    int n;
	std::cin >> n;
	std::vector<int> v;
	int x;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		v.push_back(x);
	}
	int m;
	std::cin >> m;
	std::vector<int> v2, v3;
	for (int i = 0; i < m; i++) {
		std::cin >> x;
		v2.push_back(x);
	}
	for (size_t i = 0; i < n; i++)
	{
		if (i > 0)
			v3.push_back(v3[i - 1] + v[i]);
		else
		{
			v3.push_back(v[i]);
		}
	}
	for (auto xx : v2) {	
		if (v3[0] >= xx) {
			std::cout << 1 << std::endl;
			continue;
		}
		int left = 0;
		int right = n-1 ;
		while (right - left > 1) {
			int middle = (left + right) / 2;
			if (v3[middle] < xx) {
				left = middle;
			}
			else {
				right = middle;
			}
		}
		std::cout << right+1 << std::endl;
	}
}
int biggest(initializer_list<int> a) {
	int max = 0;
	for (auto xx : a) {
		if (xx > max)
			max = xx;
	}
	return max;
}

 void fifth(){
int a, b, c;
	cin >> a >> b >> c;
	int sum=0;
	if (a == 1) {
		if (c == 1)
			sum = a + b + c;
		else
		{
			sum = (a + b)*c;
		}
	}
	else if (b == 1&&c!=1) {
		auto x = biggest({ a, b, c });
		if (x == a)
			sum = a * (b + c);
		else
		{
			sum = c * (a + b);
		}
	}
	else if (c == 1) {
		sum = a * (b + c);
	}
	else
	{
		sum = a * b*c;
	}
	cout << sum << endl;
 }

unordered_multimap<int, int> sort_map(pair<int,int> a,pair<int,int> b,pair<int,int> c) {
	auto a_length = a.first*a.first + a.second*a.second;
	auto b_length = b.first*b.first + b.second*b.second;
	auto c_length = c.first*c.first + c.second*c.second;
	int max,flag=0;
	unordered_multimap<int, int> m;
	if (a_length >= b_length) {
		max = a_length;
		flag = 1;
	}
	else {
		max = b_length;
		flag = 2;
	}
	if (max < c_length) {
		max = c_length;
		flag = 3;
	}
	if (flag == 1) {
		m.insert(a); m.insert(b); m.insert(c);
	}
	else if(flag==2)
	{
		m.insert(b); m.insert(a); m.insert(a);
	}
	else
	{
		m.insert(c); m.insert(a); m.insert(b);
	}
	return m;
}

bool is_square(pair<int,int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	auto ab = make_pair<int, int>(b.first-a.first,b.second-a.second);
	auto ac = make_pair<int, int>(c.first - a.first, c.second - a.second);
	auto ad = make_pair<int, int>(d.first - a.first, d.second - a.second);
	/*auto ab_length = ab.first*ab.first + ab.second*ab.second;
	auto ac_length = ac.first*ac.first + ac.second*ac.second;
	auto ad_length = ad.first*ad.first + ad.second*ad.second;*/
	auto m = sort_map(ab, ac, ad);
	auto diagonal = *(m.begin());
	auto x = ++m.begin();
	auto edge1 = *(x);
	auto edge2 = *(++x);
	auto diagonal_length = diagonal.first*diagonal.first + diagonal.second*diagonal.second;
	auto edge1_length = edge1.first*edge1.first + edge1.second*edge1.second;
	auto edge2_length = edge2.first*edge2.first + edge2.second*edge2.second;
	if ((diagonal.first == edge1.first + edge2.first) && (diagonal.second == edge1.second + edge2.second)) {
		if (edge1_length == edge2_length && edge1.first*edge2.first + edge1.second*edge2.second == 0)
			return true;
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	
}

void fourth(){
    
}
int main()
{
    second();
    return 0;
}