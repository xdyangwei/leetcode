#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<regex>
using namespace std;
int reverse_array(int n,int m) {
	return n / 2 * m;
}
int card_game() {
	int n;
	cin >> n;
	int x;
	vector<int> v;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for (auto it = v.rbegin(); it != v.rend(); ) {
		if (it != v.rend() - 1) {
			sum += (*it - *(it + 1));
			it += 2;
		}
		else
		{
			sum += *it;
			it += 1;
		}
	}
	return sum;
}

int greedy_q() {
	int n, m;
	cin >> n >> m;
	return 0;
}

int FindGreatestSumOfSubArray(vector<int> array) {
	auto s = array.size();
	vector<int> v(s, 0);
	v[0] = array[0];
	for (int i = 1; i < s; i++) {
		v[i] = max(v[i - 1] + array[i], array[i]);
	}
	return v[s - 1];
}

string LeftRotateString(string str, int n) {
	auto sss = str.substr(0, n);
	auto ss = str.substr(n);
	str = ss + sss;
	return str;
}

bool isNumeric(const char* string)
{
	auto str = "[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?";
	regex r(str);
	if (regex_match(string, r) == 1)
		return true;
	else {
		return false;
	}
}

int StrToInt(string str) {
	auto s = "[\\+\\-]?\\d+";
	regex r(s);
	if (regex_match(str, r) == 0)
		return 0;
	else {
		auto ss = str.size();
		int sum = 0;
		for (int i = ss - 1; i != 0; i--) {
			sum += ((str[i] - '0')*pow(10, ss - i - 1));
		}
		if (str[0] == '+') {
			return sum;
		}
		else if (str[0] == '-') {
			sum = 0 - sum;
			return sum;
		}
		else {
			sum += ((str[0] - '0')*pow(10, ss - 1));
			return sum;
		}
	}

}

int main() {
	string s = "22";
	cout << isNumeric(s.c_str());
	getchar();
	return 0;
}