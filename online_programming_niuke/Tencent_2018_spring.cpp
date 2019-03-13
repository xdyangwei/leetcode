#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<regex>
#include<iomanip>
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

int LCS_longest_increase_subarray(vector<int> &v) {
	auto n = v.size();
	vector<int> v1(n, 0);
	v1[0] = 1; v[1] > v[0] ? v1[1] = 2 : v1[1] = 1;
	for (auto i = 2; i < n; i++) {
		auto j = i - 1; bool flag = false;
			for ( ; j >= 0; j--) {
				if (v[i] > v[j]) {
					v1[i] = max(v1[j] + 1, v1[i]);
					flag = true;
				}
			}
			if (flag==false)
				v1[i] = 1;
	}
	/*int max_length = v1[0];
	for (auto x : v1) {
		max_length = max(max_length, x);
	}*/
	return v1[n-1];
}

//递归暴力求解，指数级复杂度只能过40%的case
double recursive_card(vector<int> v, double p, double q) {
	//cout << v.size() << endl;
	if (v.size() > 2) {
		auto n = v.size(); auto x = v[0];  auto z = v[n - 1];
		return p * (x + q * recursive_card(vector<int>(v.begin() + 2, v.end()), p, q) + (1 - q)*recursive_card(vector<int>(v.begin() + 1, v.end() - 1), p, q)) +
			(1 - p) * (z + q * recursive_card(vector<int>(v.begin() + 1, v.end() - 1), p, q) + (1 - q)*recursive_card(vector<int>(v.begin(), v.end() - 2), p, q));
	}
	else {
		//cout << v[0] << " " << v[v.size()-1] << endl;
		double z= p * v[0] + (1 - p)*v[v.size() - 1];
		//cout << z << endl;
		return z;
	}
}
double cards_game() {
	int n, x; double p, q;
	cin >> n >> p >> q; vector<int> v;
	p /= 100; q /=100;
	while (n--) {
		cin >> x; v.push_back(x);
	}
	double xx = recursive_card(v,p,q);
	//cout << xx << endl;
	return xx;
}

//动态规划求解抽牌问题
double dp_cards_game() {
	int n, x; double p, q;
	cin >> n >> p >> q; vector<int> v;
	auto z = n;
	p /= 100; q /= 100;
	while (n--) {
		cin >> x; v.push_back(x);
	}
	n = z;
	vector<vector<double>> v1(n, vector<double>(n, 0));
	for (auto i = 0; i < n; i++) {
		v1[i][i] = v[i];
		if (i < n - 1) {
			v1[i][i + 1] = p * v[i] + (1 - p)*v[i + 1];
		}
	}
	for (int l = 2; l <= n - 1; l++) {
		for (int i = 0; i < n - l; i++)
		{
			auto j = i + l;
			v1[i][j] = p * (q * v1[i + 2][j] + (1 - q) * v1[i + 1][j - 1] + v[i])
				+ (1 - p)*(q * v1[i + 1][j - 1] + (1 - q) * v1[i][j - 2] + v[j]);;
		}
	}
	return v1[0][n - 1];
}
double dp_cards_game2() {
	int n;
	int a;
	int b;
	cin >> n >> a >> b;
		double p = a / 100.0;
		double q = b / 100.0;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		vector<vector<double>> dp(n, vector<double>(n, 0));
		for (int i = 0; i < n; i++) {
			dp[i][i] = arr[i];
			if (i < n - 1) {
				dp[i][i + 1] = p * arr[i] + (1 - p) * arr[i + 1];
			}
		}
		for (int l = 2; l <= n - 1; l++) {
			for (int i = 0; i < n - l; i++) {
				int j = i + l;
				dp[i][j] = p * (q * dp[i + 2][j] + (1 - q) * dp[i + 1][j - 1] + arr[i])
					+ (1 - p)*(q * dp[i + 1][j - 1] + (1 - q) * dp[i][j - 2] + arr[j]);
			}
		}
		return dp[0][n - 1];
	}

int main() {
	cout << setiosflags(ios::fixed);
	cout << setprecision(3)<<dp_cards_game();
	getchar();
	return 0;
}