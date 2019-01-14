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
		int x; cin >> x; 
		sum += x;
		v.push_back(x); 
	}
	auto average = sum / (v.size());
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
		if (size == 1 && v[0] == average) {
			v.pop_back();
			break;
		}
		count++;
		v[0] += 2; v[size - 1] -= 2;
		if (v[0] == average)
			v.pop_front();
		size = v.size();
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

void sum_of_array() {
	int n, sum;
	cin >> n >> sum;
	vector<int> v; int x;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	n = v.size();
	vector<vector<long long>> v1(n+1, vector<long long>(sum+1, 0));
	for (int i = 0; i < n+1; i++)
		v1[i][0] = 1;
	for (int i = 1; i <= sum; i++)
		v1[0][i] = 0;
	for(int i=1;i<n+1;i++)
		for (int j = 0; j <= sum; j++) {
			if (v[i-1] <= j) {
				v1[i][j] = v1[i - 1][j] + v1[i - 1][j - v[i-1]];
			}
			else {
				v1[i][j] = v1[i - 1][j];
			}
		}
	cout << v1[n][sum];
}

void star_war() {
	long long h;
	cin >> h;
	auto x = sqrtl(h);
	cout.setf(ios::fixed);//十进制计数法，不是科学计数法
	cout.precision(0);
	if(x==(long)x)
		cout << x - 1;
	else{
		if(floor(x)*(floor(x)+1)<=h)
		cout << floor(x);
		else {
			cout << floor(x)-1;
		}
	}
}

void maxsum_Continuity() {
	vector<int> v;
	normal_input(v);
	vector<int> v1(v.size(), 0);
	int x = 0,max_sum=v[0];
	for (int i = 0; i < v.size(); i++) {
		x += v[i];
		if (x < 0)
			x = 0; else {
			max_sum = max(max_sum, x);
		}
	}
	cout << max_sum << endl;
}

void help(int n, int m, deque<int> &d, int begin) {
	if (m == 0) {
		for (int i = 0; i < d.size(); i++)
			i == 0 ? cout << d[i] : cout << " " << d[i];
		cout << endl;
	}
	else {
		for (int i = begin; i <= m && i <= n; i++) {
			d.push_back(i);
			help(n, m - i, d, i + 1);
			d.pop_back();
		}
	}
}

void sum_of_array_number() {
	int n, m;
	cin >> n >> m;
	deque<int> d;
	help(n, m, d, 1);
}


int main() {
	sum_of_array_number();
	system("pause");
}