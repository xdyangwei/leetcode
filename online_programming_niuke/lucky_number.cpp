#include<iostream>
#include<vector>
using namespace std;
int split_number(int x, int n) {//
	vector<int> v;
	while (x != 0) {
		auto y = x % n;
		v.push_back(y);
		x = (x - y) / n;
	}
	int sum = 0;
	for (auto &xx : v)
		sum += xx;
	return sum;
}
int lucky_number(int n) {
	vector<int> v;
	for (size_t i = 1; i <= n; i++)
	{
		if (split_number(i, 2) == split_number(i, 10))
			v.push_back(i);
	}
	return v.size();
}
int main() {
	int n;
	cin >> n;
	cout << lucky_number(n) << endl;
	return 0;
}