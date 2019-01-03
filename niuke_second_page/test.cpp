#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<regex>
#include<set>
#include<deque>
using namespace std;
template <typename T>
void normal_input(vector<T> &v) {
	int n;
	cin >> n;
	while (n--) {
		T x;
		cin >> x;
		v.push_back(x);
	}
}

void judge_sort() {
	vector<string> v;
	normal_input(v);
	auto v1 = v, v2 = v;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), [](string a, string b) {return a.size() < b.size() ? true : false; });
	if (v1 == v && v2 == v)
		cout << "both";
	else if (v1 == v)
		cout << "lexicographically";
	else if (v2 == v)
		cout << "lengths";
	else
		cout << "none";
}

void train_direction() {
	string s;
	while (cin >> s) {
		string ss(s.rbegin(),s.rend());
		string a;
		cin >> a;
		string b;
		cin >> b;
		regex pattern(a+"\\w*"+b);
		smatch result;
		if (regex_search(s.cbegin(), s.cend(), result, pattern) && regex_search(ss.cbegin(), ss.cend(), result, pattern))
			cout << "both"<<endl;
		else if(regex_search(s.cbegin(), s.cend(), result, pattern))
		{
			cout << "forward"<<endl;
		}
		else if (regex_search(ss.cbegin(), ss.cend(), result, pattern)) {
			cout << "backward"<<endl;
		}
		else {
			cout << "invalid"<<endl;
		}
	}
}

void dark_str() {
	vector<int> v;
	int x;
	while (cin >> x) {
		v.push_back(x);
	}
	auto n = v.size();
	for (int i = 0; i < n; i++) {
		auto m = v[i];
		long long dp[31] = { 0 };
		dp[1] = 3, dp[2] = 9;
		for (int i = 3; i <= m; i++)
			dp[i] = 2 * dp[i - 1] + dp[i - 2];
		cout << dp[m] << endl;
	}
}

void plalindrome_array() {
	int count = 0;
	int n;
	cin >> n;
	deque<int> d;
	while (n--) {
		int x; cin >> x; d.push_back(x);
	}
	while (d!=deque<int>(d.rbegin(),d.rend())) {
		auto first = d.front();
		auto last = d.back();
		if (first == last) {
			d.pop_back();
			d.pop_front();
		}
		else
		{
			count++;
			if (first <= last) {
				d.pop_front();
				auto x = first + d.front();
				d.pop_front();
				d.push_front(x);
			}
			else {
				d.pop_back();
				auto x = last + d.back();
				d.pop_back();
				d.push_back(x);
			}
		}
	}
	cout << count << endl;
}

void transfer() {
	int m, n;
	cin >> m >> n;
	int flag = 0;
	if (m < 0) {
		m = -m;
		flag = 1;
	}
	deque<char> v;
	while (m != 0) {
		auto x = m % n;
		if (x >= 10) {
			v.push_front(x - 10 + 'A');
		}
		else
		{
			v.push_front(x + '0');
		}
		
		m = (m - x) / n;
	}
	if (flag == 1)
		cout << "-";
	for (auto xx : v)
		cout << xx;
}

void deliver_apple() {
	int n; deque<int> v;
	cin >> n;
	int sum = 0;
	while (n--) {
		int x; cin >> x; v.push_back(x); sum += x;
	}
	auto average = sum / n;
	sort(v.begin(), v.end());
	auto it = find(v.begin(), v.end(), average);
	auto co = count(v.begin(), v.end(), average);
	v.erase(it, it + co);
	int count = 0;
	while (!v.empty()) {
		auto size = v.size();
		if ((average - v[0]) % 2 != 0 && (v[size - 1] - average) % 2 != 0) {
			break;
		}
		if (size == 1 && v[0] != average)
			break;
		if (size == 1 && v[0] == average)
			v.pop_back();
		count++;
		v[0] += 2; v[size - 1] -= 2;
		if (v[0] == average)
			v.pop_front();
		if (v[size - 1] == average)
			v.pop_back();
	}
	if (v.empty())
		cout << count << endl;
	else
	{
		cout << -1 << endl;
	}
}

int main() {
	deliver_apple();
	system("pause");
}