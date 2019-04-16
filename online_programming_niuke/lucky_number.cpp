#include<iostream>
#include<vector>
#include<thread>
#include<stack>
#include<regex>
#include<sstream>
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

int hentai_jump(int n) {
	vector<int> v(n+1, 0);
	v[1] = 1; v[2] = 2;
	if (n < 3)
		return v[n];
	else {
		for (int i = 3; i <= n; i++) {
			for (int j = i; j >0; j--) {
				v[i] += v[j];
			}
			v[i] += 1;
		}
		return v[n];
	}
}

vector<int> multiply(const vector<int>& A) {
	vector<int> v(A.size(),1);
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < i; j++) {
			v[i] *= A[j];
		}
		for (int j = i + 1; j < A.size(); j++) {
			v[i] *= A[j];
		}
}
	return v;
}

string reverseWords(string s) {
	string ss = "\^(\\s\+)|(\\s+)\$";
	string ssr = "(\\w+[!.,-~?+]*)\\s+([!.,-~?+]*[\\w]+)";
	regex r(ss); regex r1(ssr); regex r2("(\\w+[!.,-~?+]*)\\s{2,}([!.,-~?+]*[\\w]+)");
	string str = regex_replace(s, r, "");
	string str1 = regex_replace(str, r1, "$1 $2");
	str1= regex_replace(str1, r2, "$1 $2");
	auto n = str1.size();
	reverse(str1.begin(), str1.end());
	auto start = str1.begin();
	auto it = find(str1.begin(), str1.end(), ' ');
	while (it != str1.end()) {
		reverse(start, it);
		start = it + 1;
		it = find(start, str1.end(), ' ');
	}
	auto it1 = str1.rfind(' ');
	reverse(it1 + str1.begin()+1, str1.end());
	return str1;
}

int main() {
	stringstream s("   one.   +two three?   ~four   !five- ");
	string str;
	while (s >> str) {
		cout << str << endl;
	}
	//cout << reverseWords("");
	getchar();
	return 0;
}