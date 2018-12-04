#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int reverse_number(int x) {
	vector<string> v;
	while (x > 0) {
		auto n = x % 10;
		x = (x - n) / 10;
		v.push_back(to_string(n));
	}
	auto iter = find_if_not(v.begin(), v.end(), [](string i) {return i == "0"; });
	string sum = "";
	auto z = iter - v.begin();
	for (; iter != v.end(); iter++)
		sum += (*iter);
	return stoi(sum);
}
int main() {
	int x, y;
	cin >> x >> y;
	cout<<reverse_number(reverse_number(x)+reverse_number(y));
}