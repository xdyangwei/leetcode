#include<iostream>
#include<set>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<iterator>
#include<regex>
#include<map>
using namespace std;
int a[1000][1000] = { 0 };
int count_of_material() {
	string s;
	set<string> materials;
	while (getline(cin, s)){
		istringstream ss(s);
		string material;
		while (ss >> material)
			materials.insert(material);
	}
	return materials.size();
}
int count_morethan_half() {
	string s;
	vector<int> v;
	getline(cin, s);
	istringstream ss(s);
	string snumer;
	while (ss >> snumer)
		v.push_back(stoi(snumer));
	sort(v.begin(), v.end());
	auto vs = v.size();
	return (vs%2)?v[vs/2]:v[vs/2-1];
}
void reverse_string() {
	string s;
	deque<string> v;
	getline(cin, s);
	istringstream ss(s);
	string str;
	while (ss >> str)
		v.push_front(str);
	for (auto vv = v.begin(); vv != v.end(); vv++)
	{
		if(vv!=(v.end()-1))
		cout << *vv << " ";
		else
		{
			cout << *vv;
		}
	}
}
void delete_substr() {
	string s;
	getline(cin, s);
	auto x=s.find_last_of(' ');
	string s1(s, 0,x);
	string s2(s, x+1);
	for (size_t i = 0; i < s2.length(); i++)
	{
		for (size_t j = 0; j < s1.length(); j++)
		{
			if (s1[j] == s2[i])
				s1.erase(j,1);
		}
	}
	cout << s1;
}

void word_like() {
	istream_iterator<char> word(cin),eof;
	ostream_iterator<string> cword(cout);
	vector<char> v,v1;
	while (word != eof) {
		v.push_back(*word++);
	}
	unique_copy(v.begin(), v.end(),back_inserter(v1), [](char a, char b) {return a == b ? true : false; });
	if (v1.size()!=v.size())
		*cword = "Dislikes";
	else {
		regex r("([^A-Z]+|([A-Z])\\2|([A-Z])[A-Z]*([A-Z])[A-Z]*\\3[A-Z]*\\4)");
		string word1;
		for (auto e : v)
			word1 += e;
		if (!regex_search(word1, r)) {
			cout << "Likes\n";
		}
	}
	cout << endl;
}

void smallest_number() {
	int n;
	cin >> n;
	int number;
	vector<int> v;
	while (n-- != 0) {
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	if (v[0] == 1) {
	}
	else
	{
		cout << 1 << endl;
	}
}

void buy_apple() {
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0;i<20;i++)
		for (int j = 0; j < 13; j++) {
			if (6 * i + 8 * j == n)
				v.push_back(i + j);
		}
	if (v.size() != 0) {
		sort(v.begin(), v.end());
		cout << v[0] << endl;
	}
	else {
		cout << -1 << endl;
	}
}
bool isprime(int a) {
	bool flag = true;
	if (a == 2)
		return true;
	if (a == 1)
		return false;
	for (size_t i = 2; i <= a/2; i++)
	{
		if (a%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

void prime_number_sum() {
	int x;
	cin >> x;
	map<int, int> m;
	for (size_t i = 1; i <=x/2 ; i++)
	{
		if (isprime(i) && isprime(x - i))
			m.insert(make_pair(i,x-i));
	}
	cout << m.size() << endl;
}

void not_two() {
	int w, h, res = 0;
	cin >> w >> h;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 0)
			{
				res++;
				if ((i + 2) < w) a[i + 2][j] = -1;
				if ((j + 2) < h) a[i][j + 2] = -1;
			}
		}
	}
	cout << res;
}
bool is_palindrome_string(string s) {
	string s1;
	reverse_copy(s.begin(), s.end(), back_inserter(s1));
	if (s1 == s)
		return true;
	else {
		return false;
	}
}
void count_palindrome_string() {
	string s1, s2;
	cin >> s1 >> s2;
	string s3; s3 = s1;
	int count = 0;
	for (auto i = s1.begin(); i !=s1.end(); i++) {
		s3.insert(i-s1.begin(), s2);
		if (is_palindrome_string(s3))
			count++;
		s3 = s1;
	}
	s3.insert(s3.end(), s2.begin(), s2.end());
	if (is_palindrome_string(s3))
		count++;
	cout << count << endl;
	//cout << is_palindrome_string(s1) << endl;
}

void construct_queue() {
	int n;
	cin >> n;
	vector<int> v1;
	while (n-- > 0) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	for (auto i = 0; i < v1.size(); i++) {
		auto size = v1[i];
		vector<int> v2;
		if (size == 1) {
			cout << 1<<endl;
		}
		else {
			v2.push_back(size);
			v2.push_back(size - 1);
			int ii = 1; size -= 1;
			while (--size > 0) {
				v2.insert(v2.begin(), *(v2.end() - 1));
				v2.pop_back();
				v2.insert(v2.begin() + 1, size);
			}
			for (auto xx : v2)
				cout << xx << " ";
			cout << endl;
		}
	}
}
void filename_extension() {
	string s;
	cin >> s;
	regex r("\\.(\\w+\\b)");
	smatch result;
	if(regex_search(s.cbegin(),s.cend(),result,r))
	cout<<result[1]<<endl;
	else{
		cout<<"null"<<endl;
	}
}

void treasure_map() {
	string s1, s2;
	cin >> s1 >> s2;
	string pattern = "";
	for (auto x : s2) {
		string s(1,x);
		pattern += "\.*" + s;
	}
	pattern += "\.*";
	regex r(pattern);
	smatch result;
	if (regex_search(s1.cbegin(), s1.cend(), result, r))
		cout << "Yes" << endl;
	else
	{
		cout << "No" << endl;
	}
}

void calculate_candy() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = (a + c )/ 2;
	int B = (b + d) / 2;
	int C = d - B;
	if ((A - B == a) && (B - C == b) && (A + B == c) && (B + C == d))
		cout << A << " " << B << " " << C;
	else
	{
		cout << "No";
	}
}

void toutiao_hire() {
	int n;
	cin >> n;
	vector<int> v1;
	while (n-- > 0) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	sort(v1.begin(),v1.end());
	int sum = 0;
	auto x = v1.begin();
	auto y = x;
	while (x!=v1.end()) {
		y = unique(x, v1.end(), [](int a, int b) {return (b - a > 10) ? true : false; });
		auto z = y - x;
		if ((z + 1) % 3 == 0) {
			sum += 1;
		}
		else if ((z + 2) % 3 == 0)
			sum += 2;
		x = y;
	}
	cout << sum << endl;
}

int judge_array(vector<int> v) {
	int sum = 0;
	for (auto it = v.begin(); it != v.end()-1; it++) {
		for (auto ii = it + 1; ii != v.end(); ii++) {
			if (*ii > *it)
				sum++;
		}
	}
	return sum;
}
void reset_array() {
	int n, k;
	cin >> n >> k;
	vector<int> v1;
	auto nn = n;
	while (nn-- > 0) {
		int x;
		cin >> x;
		v1.push_back(x);
	}
	/*auto count_zero = count(v1.begin(), v1.end(), 0);*/
	set<int> v2;
	auto nnn = 0;
	while (nnn++ < n)
		v2.insert(nnn);
	for (auto xx : v1) {
		v2.erase(xx);
	}
	vector<int> v3(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	int sum=0;
	auto ii = 0;
	auto v4 = v1;
	for (auto &xx : v4) {
		if (xx == 0)
			xx = v3[ii++];
	}
	auto zz = judge_array(v4);
	if (zz == k)
		sum++;
	v4 = v1;
	while (next_permutation(v3.begin(), v3.end())) {
		auto iii = 0;
		for (auto &xx : v4) {
			if (xx == 0)
				xx = v3[iii++];
		}
		auto z = judge_array(v4);
		if (z == k)
			sum++;
		v4 = v1;
	}
	cout << sum;
}

void count_end_zero() {
	int n, counter = 0;
	cin >> n;
	while (n /= 5)
	{
		counter += n;
	}
	cout << counter;
}

int count_of_radix(int a,int n) {
	vector<int> v;
	while (a) {
		auto x = a % n;
		v.push_back(x);
		a = a / n;
	}
	int sum = 0;
	for (auto xx : v)
		sum += xx;
	return sum;
}

int greatest_common_divisr(int a,int b) {
	int max=1,min;
	if (a >= b) {
		min = b;
	}
	else
	{
		min = a;
	}
	for (int i = 1; i <=min  ; i++) {
		if (a%i == 0 && b%i == 0) {
			if (i > max)
				max = i;
		}
	}
	return max;
}
void average_radixs() {
	int x;
	while (cin >> x) {
		int sum=0;
		for (auto i = 2; i < x; i++)
			sum += count_of_radix(x, i);
		cout << (sum/greatest_common_divisr(sum,x-2)) <<"/"<<((x-2)/greatest_common_divisr(sum,x-2))<< endl;
	}
}

void encode() {
	string s;
	cin >> s;
	int index = 0;
	switch (s.size())
	{
	case 1:
		index = (s[0] - 'a')*(25*25*25+25*25+25+1);
		break;
	case 2:
		index = (s[0] - 'a')*(25 * 25 * 25 + 25 * 25 + 25 + 1)+(s[1]-'a')*(25*25+25+1);
		break;
	case 3:
		index = (s[0] - 'a')*(25 * 25 * 25 + 25 * 25 + 25 + 1) + (s[1] - 'a')*(25 * 25 + 25 + 1)+(s[2]-'a')*(25+1);
		break;
	case 4:
		index= (s[0] - 'a')*(25 * 25 * 25 + 25 * 25 + 25 + 1) + (s[1] - 'a')*(25 * 25 + 25 + 1) + (s[2] - 'a')*(25 + 1); + s[3] - 'a';
		break;
	}
	cout << index;
}
int main() {
	encode();
}