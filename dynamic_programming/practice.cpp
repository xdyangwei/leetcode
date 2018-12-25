#include<iostream>
#include<vector>
#include<cmath>
#include<set>
using namespace std;

int count_of_steps(int n, vector<int> &p) {
	if (n <= 0) {
		return 0;
	}
	else {
		if (p[n] != -1) {
			return p[n];
		}
		else {
			p[n] = count_of_steps(n - 1, p) + count_of_steps(n - 2, p);
			return p[n];
		}
	}
}
int count_of_steps_top_to_bottle(int n) {
	vector<int> v;
	for (int i = 0; i != n+1; i++)
		v.push_back(-1);
	v[1] = 1; v[2] = 2;
	int x= count_of_steps(n,v);
	for (auto xx : v)
		cout << xx << endl;
	return x;
}

int count_of_steps_bottle_to_top(int n) {
	vector<int> v(n+1, 0);
	v[1] = 1, v[2] = 2;
	for (int i = 3; i < n+1; i++)
		v[i] = v[i - 1] + v[i - 2];
	return v[n];
}

int length_of_lis(int n, vector<int> &v, vector<int> v1);
void longest_increase_squence(vector<int> v1) {
	vector<int> v(100,0);
	v[1] = 1;
	length_of_lis(v1.size(),v,v1);
	int max = 0;
	for (size_t i = 1; i <= v1.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	cout << max << endl;
}

int length_of_lis(int n,vector<int> &v,vector<int> v1) {
	if (n <= 0) {
		return 0;
	}
	if (v[n] != 0) {
		//cout << v[n] << endl;
		return v[n];
	}
	else if(v1[n-1]>v1[n-2]){
		v[n] = length_of_lis(n - 1, v, v1) + 1;
		return v[n];
	}
	else
	{
		v[n] = length_of_lis(n - 1, v, v1);
		return v[n];
	}
}

int lcs(vector<vector<int>> &v, vector<char> v1, vector<char> v2, int i, int j);

void longest_common_squence(vector<char> v1,vector<char> v2) {
	vector<vector<int>> v;
	for (size_t i = 0; i <= v1.size(); i++)
	{
		vector<int> v3;
		v.push_back(v3);
		for (size_t j = 0; j <= v2.size(); j++)
		{
			v[i].push_back(0);
		}
	}
	cout << lcs(v, v1, v2, v1.size(), v2.size());
}

int max(int a,int b) {
	return a > b ? a : b;
}
int lcs(vector<vector<int>> &v,vector<char> v1,vector<char> v2,int i,int j) {
	if (!i || !j)
		return 0;
	if (v1[i-1] == v2[j-1]) {
		v[i][j] = lcs(v, v1, v2, i - 1, j - 1) + 1;
		return v[i][j];
	}
	else {
		v[i][j] = max(lcs(v,v1,v2,i-1,j),lcs(v,v1,v2,i,j-1));
		return v[i][j];
	}

}

long combine_money(int n) {
	int N=n;
	char a[6] = { 1,5,10,20,50,100 };
	vector<long> d(N + 1, 0);
	d[0] = 1;
	for (int i = 0; i < 6; i++)
		for (int j = 1; j <= N; j++)
			if (j >= a[i])
				d[j] = d[j] + d[j - a[i]];

	return d[N];
	
}
int main() {
	int N;
	char a[6] = { 1,5,10,20,50,100 };
	cin >> N;
	vector<long long> d(N + 1, 0);
	d[0] = 1;
	for (int i = 0; i < 6; i++)
		for (int j = 1; j <= N; j++)
			if (j >= a[i])
				d[j] = d[j] + d[j - a[i]];

	cout << d[N] << endl;
	system("pause");
}