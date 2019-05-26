#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<chrono>
#include<thread>
#include"queue_with_stack.h"
#include<ctime>
#include<cstring>
using namespace std;
int programmer_manager() {
	string s;
	int count = 0;
	vector<vector<int>> v;
	while (getline(cin, s)) {
		if (s == "")
			break;
		auto it = s.find(' ');
		auto start = 0;
		vector<int> v1;
		while (it != s.npos) {
			auto x = stoi(string(s.begin() + start, s.begin() + it));
			if (x == 1)
				count++;
			v1.push_back(x);
			start = it + 1;
			it = s.find(' ', it+1);
		}
		auto it1 = s.rfind(' ');
		auto x = stoi(string(s.begin() + it1 + 1, s.end()));
		if (x == 1) count++;
		v1.push_back(x);
		v.push_back(v1);
	}
	bool flag = 1;
	auto m = v.size(); auto n = v[0].size();
	int co = 0;
	while (true) {
		auto vv = v;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 2) {
					if (i - 1 >= 0 && v[i - 1][j] == 1&&vv[i-1][j]!=2) {
						vv[i - 1][j] = 2; count--;
						//cout << "here1" << endl;
					}
					if (i + 1 < m&&v[i + 1][j] == 1 && vv[i + 1][j] != 2) {
						vv[i + 1][j] = 2; count--;
						//cout << i<<" " <<j<< endl;
					}
					if (j - 1 >= 0 && v[i][j - 1] == 1 && vv[i][j-1] != 2) {
						vv[i][j-1] = 2; count--;
						//cout << "here3" << endl;
					}
					if (j + 1 < n && v[i][j + 1] == 1 && vv[i][j+1] != 2) {
						vv[i][j + 1] = 2; count--;
						//cout << "here4" << endl;
					}
				}
			}
		co++;
		if (vv == v) {
			if (count != 0)
				flag = 0;
				break;
		}
		v = vv;
	}
	if (flag == 1)
		return co-1;
	return -1;
}

int robot() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(0);
	int x;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	vector<int> energy(v.size(),0);
	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i - 1] > v[i])
			energy[i - 1] = ceil((v[i]+energy[i]) / 2.0);
		else
		{
			energy[i - 1] = ceil((v[i] + energy[i]) /2.0);
		}
	}
	return energy[0];
}

void right_value_test(int&& a) {
	cout << a << endl;
	a = 1;
}

//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
//使用回溯法
static stack<pair<int,int>> s;
int recursive_movingCount(vector<vector<int>>& flag,int m,int n,int rows,int cols,int& count) {
	if (m < rows&&n < cols&&m >= 0 && n >= 0 && flag[m][n] == 0) {
		flag[m][n] = 1;
		s.push(make_pair(m,n));
		count += recursive_movingCount(flag, m - 1, n, rows, cols, count);
		count += recursive_movingCount(flag, m, n + 1, rows, cols, count);
		count += recursive_movingCount(flag, m + 1, n, rows, cols, count);
		count += recursive_movingCount(flag, m, n - 1, rows, cols, count);
		return 1;
	}
	else {
		if (s.size() == 1)
			return count;
		s.pop();
		//auto x = s.top();
		return 0;
	}

}
int movingCount(int threshold, int rows, int cols) {
	vector<vector<int>> v(rows,vector<int>(cols,0));
	int count = 0;
	return recursive_movingCount(v, 0, 0, rows, cols, count);
}

int main() {
	cout << movingCount(10, 3, 4);
	getchar();
}