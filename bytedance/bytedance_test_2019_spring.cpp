#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include"queue_with_stack.h"
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
int main() {
	auto x = new MyClass[3];
	getchar();
}