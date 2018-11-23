#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<set>
using namespace std;
int main() {
	//第一种解法
	/*set<int> v1;
	for (size_t i = 1; i < 10001; i++)
	{
		v1.insert(i);
	}
	int x;
	for (size_t i = 0; i < 9997; i++)
	{
		cin >> x;
		v1.erase(x);
	}
	*/
	//空间换时间的大佬解法
	/*
	int book[10005];
	int main(){
	int x,i;
	for(i=0;i<9997;i++){
		scanf("%d",&x);
		book[x]=1;
	}
	long long sum=0;
	string res="",s;
	for(i=1;i<=10000;i++)
		if(book[i]==0){
			stringstream ss;
			ss<<i,ss>>s;
			res+=s;
		}
	stringstream ss(res);
	ss>>sum;
	printf("%d\n",sum%7);
	*/
	//我的lowb解法
	vector<int> v, v1;
	int n = 0, x;
	while (n < 9997) {
		cin >> x;
		v.push_back(x);
		n++;
	}
	sort(v.begin(), v.end());
	for (size_t i = 0; i < 9997; i++)
	{
		if (i >= 1) {
			auto n = v[i] - v[i - 1];
			if (n != 1) {
				for (size_t j = 1; j < n; j++)
				{
					v1.push_back(v[i] - j);
				}
			}
		}
		else
		{
			auto n = v[0];
			if (v[0] != 1) {
				for (size_t i = 1; i < n; i++)
				{
					v1.push_back(i);
				}
			}

		}
	}
	auto nn = 3 - v1.size();
	if (v1.size() != 3) {
		for (size_t i = 1; i <= nn; i++)
		{
			v1.push_back(v[v.size() - 1] + i);
		}
	}
	sort(v1.begin(), v1.end());
	stringstream ss;
	for (auto i = v1.begin(); i != v1.end(); i++) {
		ss << *i;
	}
	string s = ss.str();
	istringstream sss(s);
	long long z;
	sss >> z;
	
	cout << (z%7) << endl;
	return 0;
}