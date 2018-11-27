#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int first_number(int x) {
	while (x > 10) {
		x = (x-x % 10)/10;
	}
	return x;
}
int biggest_first_number(vector<int> v) {
	int max = 0;
	auto i=0;
	for (int ii = 0; ii < v.size();ii++) {
		if (first_number(v[ii]) > max) {
			max = first_number(v[ii]);
			i = ii;
		}
	}
	return i;
}
int main() {
	int n;
	cin >> n;
	int x;
	vector<int> v;
	for (size_t i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	vector<int> v1;
	for (size_t i = 0; i < n; i++)
	{
		v1.push_back(v[biggest_first_number(v)]);
		v.erase(biggest_first_number(v)+v.begin());
	}
	string s = "";
	for (auto ss : v1)
		s += to_string(ss);
	cout << s << endl;
}