#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<regex>
#include<iomanip>
#include<cmath>
#include<stack>
#include<deque>
using namespace std;

template <typename T>
struct Binary_Node {
	T data;
	Binary_Node<T>* left_child;
	Binary_Node<T>* right_child;
	Binary_Node(T v) :
		data(v), left_child(nullptr), right_child(nullptr) {}
	Binary_Node() = default;

};

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

class goods {
public:
	goods(int x, int y, int z) :
		m(x), w(y), s(z) {}
	goods() = default;
	int m;
	int w;
	int s;
};


int recursive_bag(vector<goods> v1,int v,int j) {
	if (v > 0) {
		int largest = 0;
		if (j >= 0) {
			v1[j].m -= 1;
		}
		for (auto i = 0; i < v1.size();i++) {
			if (v1[i].w <= v&&v1[i].m>=1) {
				largest = max(recursive_bag(v1, v - v1[i].w,i)+v1[i].s, largest);
			}
		}
		return largest;
	}
	else {
		return 0;
	}


}

int QQ_bag() {
	int n, v;
	cin >> n >> v;
	vector<goods> v1;
	while (n--) {
		int m, w, s;
		cin >> m >> w >> s;
		v1.push_back(goods(m,w,s));
	}
	sort(v1.begin(), v1.end(), [](goods a, goods b) {return a.w < b.w ? true : false; });
	return recursive_bag(v1, v,-1);
}

void reset_number() {
	int n;
	std::cin >> n;
	std::vector<int> v; int x;
	while (n--) {
		std::cin >> x; v.push_back(x);
	}
	for (auto xx : v) {
		auto z = xx;
		bool flag = 0;
		std::vector<std::string> v1;
		while (xx >= 1) {
			auto x = xx % 10;
			v1.insert(v1.begin(),std::to_string(x));
			xx = xx / 10;
		}
		while (std::next_permutation(v1.begin(), v1.end())) {
			std::string s;
			for (auto x : v1) {
				s += x;
			}
			if (std::stoi(s) % z==0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			std::cout << "Possible" << std::endl;
		else {
			std::cout << "Impossible" << std::endl;
		}
	}
}

void least_coins() {
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(begin(a), end(a));
	cout << a[3] - a[0] + a[2] - a[1] << endl;
}

struct busline
{
	int start;
	int end;
	int time;
	busline(int a, int b, int c) :
		start(a), end(b), time(c) {}
};

int recursive_transfer(int d,vector<busline> v) {
	//vector<busline> v1;
	if (d == 0) {
		return 0;
	}
	else {
		auto sum = 100000000;
		//int flag = 0;
		for (auto xx : v) {
			if (xx.end == d) {
				//flag = 1;
				sum = min(sum, recursive_transfer(xx.start, v) + xx.time);
			}
		}
		//if(flag)
		return sum;
		
	}
}

void transfer() {
	int d, n;
	cin >> d >> n;
	vector<busline> v;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(busline(a, b, c));
	}
	cout << recursive_transfer(d, v);
}

void number_char_mix_sort() {
	string s;
	cin >> s;
	sort(begin(s), end(s), [](char a,char b)->bool {
		if (a >= 'a'&&a <= 'z'&&b >= '0'&&b <= '9') {
			return true;
		}
		else if (a >= '0'&&a <= '9'&&b >= 'a'&&b <= 'z') {
			return false;
		}
		else
		{
			return a < b;
		}
	});
	for (auto xx : s)
		cout << xx;
}

bool is_leap_year(int n) {
	if ((n % 4 == 0 && n % 100 == 1) || n % 400 == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

void nth_day_of_year() {
	int year, month, day;
	while (cin >> year >> month >> day) {
		if (month <= 2) {
			cout << (month == 1) ? day : 31 + day;
		}
		else
		{
			int flag = 0;
			if (is_leap_year(year))
				flag = 1;
				switch (month)
				{
				case 3:
					cout << 31 + 28 + flag + day; break;
				case 4:
					cout<< 31 + 28 + flag + day+31; break;
				case 5:
					cout << 31 + 28 + flag + day + 30+31; break;
				case 6:
					cout << 31 + 28 + flag + day + 31+30+31; break;
				case 7:
					cout << 31 + 28 + flag + day + 30+31+31+30; break;
				case 8:
					cout << 31 + 28 + flag + day + 30+31+31+30+31; break;
				case 9:
					cout << 31 + 28 + flag + day + 30 + 31 + 31 + 30 + 31+31; break;
				case 10:
					cout << 31 + 28 + flag + day + 30 + 31 + 31 + 30 + 31+31+30; break;
				case 11:
					cout << 31 + 28 + flag + day + 30 + 31 + 31 + 30 + 31+31+30+31; break;
				case 12:
					cout << 31 + 28 + flag + day + 30 + 31 + 31 + 30 + 31+31+30+31+30; break;
				}
		}
	}
}

void bracket_match() {
	string s;
	cin >> s;
	stack<char> s1;
	int count1 = 0, count2 = 0;
	auto ss = s;
	for (auto xx : s) {
		if (xx == '[') {
			s1.push(xx);
			count1++;
		}
		else {
			if (!s1.empty()) {
				auto x = s1.top();
				if (x == '[') {
					//s1.push(xx);
					s1.pop(); count1--;
				}
				else {
					s1.push(xx);
					count2++;
				}
			}
			else
			{
				s1.push(xx);
				count2++;
			}
		}
	}
	while (count1--) {
		ss.append(string(1,']'));
	}
	while (count2--) {
		ss.insert(0, string(1, '['));
	}
	cout << ss << endl;
}

template <typename T>
std::vector<std::vector<int> > Print(Binary_Node<T>* pRoot) {
	std::stack<Binary_Node<T>*> s1; std::stack<Binary_Node<T>*> s2;
	s1.push(pRoot); int i = 1;
	std::vector<std::vector<T>> result;
	while (!s1.empty() || !s2.empty()) {
		if (!s1.empty()) {
			std::vector<T> data;
			while (i % 2 == 1) {
				auto x = s1.top();
				data.push_back(x->data);
				s1.pop();
				if (x->left_child != nullptr)
					s2.push(x->left_child);
				if (x->right_child != nullptr)
				s2.push(x->right_child);
				if (s1.empty()) {
					i++;
				}
			}
			result.push_back(data);
		}
		if (!s2.empty())
		{
			std::vector<T> data;
			while (i % 2 == 0) {
				auto x = s2.top();
				data.push_back(x->data);
				s2.pop();
				if(x->right_child!=nullptr)
					s1.push(x->right_child);
				if (x->left_child != nullptr)
					s1.push(x->left_child);
				if (s2.empty()) {
					i++;
				}
			}
			result.push_back(data);
		}
	}
	return result;
}

template <typename T>
void recursive_find_path(Binary_Node<T>* root, int expectNumber,vector<int>& v,vector<vector<int>>& v1) {
	if (root != nullptr) {
		if ((expectNumber-root->data) == 0&&root->left_child==nullptr&&root->right_child==nullptr) {
			v.push_back(root->data);
			v1.push_back(v);
		}
		else {
			v.push_back(root->data);
			if (root->left_child != nullptr)
				recursive_find_path(root->left_child, expectNumber - root->data, v, v1);
			if(root->right_child!=nullptr)
				recursive_find_path(root->right_child, expectNumber - root->data, v, v1);
		}
		v.pop_back();
	}
	else {
		return ;
	}
}

template <typename T>
vector<vector<int> > FindPath(Binary_Node<T>* root, int expectNumber) {
	vector<vector<int>> v1;
	if (root != nullptr) {
		vector<int> v;
		recursive_find_path(root, expectNumber, v, v1);
		return v1;
	}
	else {
		return v1;
	}
}

int main() {
	Binary_Node<int> n1(1); Binary_Node<int> n2(2); Binary_Node<int> n3(3);
	Binary_Node<int> n4(4); Binary_Node<int> n5(5); Binary_Node<int> n6(6); Binary_Node<int> n7(7);
	Binary_Node<int> n8(8); Binary_Node<int> n9(9); Binary_Node<int> n10(10); Binary_Node<int> n11(11);
	n1.left_child = &n2; n1.right_child = &n3; n2.left_child = &n4; n2.right_child = &n5; n3.left_child = &n6; n3.right_child = &n7;
	n4.left_child = &n8; n4.right_child = &n9; n5.left_child = &n10;
	auto z = FindPath(&n1,18);
	for(auto x:z){
		for(auto xx:x)
			std::cout<<xx<<" ";
		std::cout<<std::endl;
	}
	getchar();
	return 0;
}