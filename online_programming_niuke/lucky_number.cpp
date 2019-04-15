#include<iostream>
#include<vector>
#include<thread>
#include<stack>
#include<regex>
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
	string ssr = "(\\w*[!.,]*)\\s+([\\w]+)";
	regex r(ss); regex r1(ssr);
	string str = regex_replace(s, r, "");
	string str1 = regex_replace(str, r1, "$1 $2");
	return str1;
}

int main() {
	cout << reverseWords("  hello    world!      yy     ww.       askjldj  ");
	getchar();
	return 0;
}