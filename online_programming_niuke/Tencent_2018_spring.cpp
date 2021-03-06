#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<unordered_map>
#include<bitset>
#include<set>
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

//找到0123...111213...101102..这样数字序列中的第n个数字
//首先需要确定n所在位置是几位数所在区域，因此使用一个函数来返回n所在几位数
int nth_area(int n) {
	int i = 2;
	if (n <= 0)
		return -1;
	if (n > 0 && n <= 10)
		return 1;
	while (true) {
		auto x = 9 * pow(10, i-1)*i + pow(10, i - 1);
		if (n <= x) {
			break;
		}
		i++;
	}
	return i;
}

int nth_number_of_array(int n) {
	auto x = nth_area(n);
	if (x == -1)
		return -1;
	auto num = ceil((n - pow(10, x - 1)) / x);
	auto seq = (int)(n - pow(10, x - 1)) % x;
	auto number = to_string(pow(10, x - 1) + num-1);
	auto nth_number = number[x-1 - seq];
	//cout << number << endl;
	return nth_number-'0';
}

//把数组排成最小的数
//思路：把数字转换成字符串然后进行拼接，通过比较字符串大小从而得到最小数
string PrintMinNumber(vector<int> numbers) {
	vector<string> v;
	for (auto number : numbers)
		v.push_back(to_string(number));
	sort(v.begin(), v.end(), [](string a, string b) {
		return a + b < b + a ? true : false;
	});
	string a;
	for (auto str : v)
		a += str;
	return a;
}

//字符串翻译问题，将1可以翻译成a，将2可以翻译成b，以此类推，某个数字有几种翻译方法
//思路：可以考虑使用动态规划，计算以i结尾的翻译方法种类，当i-1和i组成的数字在1~26之间时可以有两种方案
int translate(int num) {
	if (num < 0)
		return 0;
	auto str = to_string(num);
	auto n = str.size();
	vector<int> v(n, 0);
	auto x = stoi(to_string(str[0]-'0') + to_string(str[1]-'0'));
	v[0] = 1; v[1] = x<=25&&x>=10?2:1;
	for (int i = 2; i < n; i++) {
		auto y = stoi(to_string(str[i - 1] - '0') + to_string(str[i] - '0'));
		v[i] =  y<= 25&&y>=10 ? v[i - 1] + v[i - 2] : v[i - 1];
		//cout << stoi(to_string(str[i-1] - '0') + to_string(str[i] - '0')) << endl;
	}
	return v[n-1];
}

//礼物的最大价值，给一个二维数组，每一格都放置了礼物，从左上角开始拿起，可以向右或向下继续
//问如何拿到最大价值的礼物
//思路：使用动态规划循环即可
int max_value_present(vector<vector<int>> v) {
	if (v.empty() || v[0].empty())
		return 0;
	auto m = v.size(); auto n = v[0].size();
	vector<vector<int>> max_matrix(m, vector<int>(n, 0));
	max_matrix[0][0] = v[0][0];
	for (int i = 1; i < m; i++)
		max_matrix[i][0] = max_matrix[i - 1][0] + v[i][0];
	for (int j = 1; j < n; j++)
		max_matrix[0][j] = max_matrix[0][j - 1] + v[0][j];
	for(int i=1;i<m;i++)
		for (int j = 1; j < n; j++) {
			max_matrix[i][j] = max(max_matrix[i-1][j],max_matrix[i][j-1])+v[i][j];
		}
	return max_matrix[m - 1][n - 1];
}

//丑数：把只包含质因子2、3和5的数称作丑数（Ugly Number）习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
//思路：丑数可以由之前较小的丑数乘以2、3或5获得，然后将其排序即可
int GetUglyNumber_Solution(int index) {
	if (index < 7)return index;
	vector<int> res(index);
	res[0] = 1;
	int t2 = 0, t3 = 0, t5 = 0, i;
	for (i = 1; i < index; ++i)
	{
		res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
		if (res[i] == res[t2] * 2)t2++;
		if (res[i] == res[t3] * 3)t3++;
		if (res[i] == res[t5] * 5)t5++;
	}
	return res[index - 1];
}

//求解字符串中最长不含重复字符的子字符串长度
//思路：使用动态规划找出以下标i为结尾的最长不含重复字符的子字符串的长度，然后如果在i+1时的字符未出现
//在其中，则长度+1，若出现了，则需要判断两个重复字符之间相隔的距离然后与此时的长度进行比较
int longest_no_repeat_substr(string str) {
	auto n = str.size();
	auto v = vector<int>(n, 0);
	v[0] = 1;
	for (int i = 1; i < n; i++) {
		auto it = find(str.begin() + i - v[i - 1], str.begin() + i , str[i]);
		//decltype(it) end;
		if (it == str.begin()+i) {
			v[i] = v[i - 1] + 1;
			//cout << "here"<<endl;
		}
		else
		{
			auto nn = str.begin() + i - 1 - it + 1;
			v[i] = nn;
		}
	}
	int MAX = 0;
	for (auto vv : v) {
		MAX = max(MAX, vv);
	}
	return MAX;
}

//输出整数中二进制位数为1的个数
//思路：使用bitset容器即可
int  NumberOf1(int n) {
		bitset<32> b=n;
		int count=0;
		auto nn=b.size();
		for(int i=0;i<nn;i++)
		{
			if(b[i]==1)
			count++;
		}
		return count;
     }

//思路2：使用位运算，将n分别与2的倍数相与然后若不为0即这位为1
int  NumberOf1_2(int n) {
int i=0,count=0;
while(i<=31){
		if(n&static_cast<int>(pow(2,i)))
		count++;
	i++;
}
return count;
}

//数组中的逆序对，输入一个数组,求出这个数组中的逆序对的总数P。输出P%1000000007
//思路：使用归并排序的思想，使用一个辅助数组，先计算子数组内的逆序对，再计算数组合并后的逆序对
int reverse_InversePairs(vector<int> v, vector<int> &v1, int start, int end);
int InversePairs(vector<int> data) {
	vector<int> v1(data.size(), 0);
	auto count = reverse_InversePairs(data, v1, 0, data.size() - 1);
	return count % 1000000007;
}

int reverse_InversePairs(vector<int> v,vector<int> &v1,int start,int end) {
	if (start == end) {
		v1[start] = v[start];
		return 0;
	}
	int middle = (start + end) / 2;
	int count = 0;
	count+=reverse_InversePairs(v, v1, start, middle);
	count+=reverse_InversePairs(v, v1, middle+1, end);
	for (int i = middle , j = end; i >= start && j >= middle+1;) {
		if (v1[i] > v1[j]) {
			swap(v1[i], v1[j]);
			count++;
			j--;
		}
		else {
			i--; j--;
		}
	}
	return count;
}


//在一个字符串(0<=字符串长度<=10000，全部由字母组成)
//中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
//思路：使用unordermap这一辅助的哈希表从而通过空间置换时间，可以在O(n)的时间复杂度内
//找到对应的第一次出现的字符
int FirstNotRepeatingChar(string str) {
      unordered_map<char,int> m;
	  for(int i=0;i<str.size();i++){
		  auto x=m.find(str[i]);
		  if(x==m.end()){
			  //cout<<str[i]<<endl;
			  m.insert(make_pair(str[i],1));
		  }else{
		  m[str[i]]+=1;}
	  }
	  char c='0';
	  for(auto s:str){
		  if(m[s]==1){
			  c=s;
			  break;
		  }
	  }
	  cout<<c<<endl;
	  auto count=str.find(c);
	  if(count==string::npos)
	  return -1;
	  return count;  
    }

//统计一个数字在排序数组中出现的次数。
//思路1：使用stl count函数
//思路2：使用二分查找的思想，先找出第一个出现的下标，当mid值小于k时在右边找，大于k时在左边找，=k时判断是否左边第一个数是否是k
//如果是则第一个k还出现在左边，如果不是说明这个就是我们需要的下标，再使用相同思路找出最后一个k的下标，如果不存在k则返回-1
int GetFirstK(vector<int> data, int k) {
	auto last = data.size()-1;
	auto first = 0;  auto x = -1;
	while (first <= last) {
		auto mid = (last + first) / 2;
		if (data[mid] > k) {
			last = mid-1;
		}
		else if (data[mid] < k) {
			first = mid + 1;
		}
		else {
			//flag = 1;
			if (mid >= 1) {
				if (data[mid - 1] == k)
					last = mid;
				else {
					x = mid; break;
				}
			}
			else {
				x = mid;
				break;
			}
		}
	}
	return x;
}

int GetLastK(vector<int> data, int k) {
	auto last = data.size() - 1;
	auto first = 0;  auto x = -1;
	while (first <= last) {
		auto mid = (last + first) / 2;
		if (data[mid] > k) {
			last = mid-1;
		}
		else if (data[mid] < k) {
			first = mid + 1;
		}
		else {
			//flag = 1;
			if (mid <= data.size()-2) {
				if (data[mid + 1] == k)
					first = mid;
				else {
					x = mid; break;
				}
			}
			else {
				x = mid;
				break;
			}
		}
	}
	return x;
}


int GetNumberOfK(vector<int> data, int k) {
	auto first = GetFirstK(data, k);
	if (first == -1)
		return -1;
	auto last= GetLastK(data, k);
	return last - first+1;
}

//int main() {
//	/*Binary_Node<int> n1(1); Binary_Node<int> n2(2); Binary_Node<int> n3(3);
//	Binary_Node<int> n4(4); Binary_Node<int> n5(5); Binary_Node<int> n6(6); Binary_Node<int> n7(7);
//	Binary_Node<int> n8(8); Binary_Node<int> n9(9); Binary_Node<int> n10(10); Binary_Node<int> n11(11);
//	n1.left_child = &n2; n1.right_child = &n3; n2.left_child = &n4; n2.right_child = &n5; n3.left_child = &n6; n3.right_child = &n7;
//	n4.left_child = &n8; n4.right_child = &n9; n5.left_child = &n10;
//	auto z = FindPath(&n1,18);
//	for(auto x:z){
//		for(auto xx:x)
//			std::cout<<xx<<" ";
//		std::cout<<std::endl;
//	}*/
//	cout << GetNumberOfK({ 1,2,3,3,3,3,4,5 }, 3);
//	getchar();
//	return 0;
//}