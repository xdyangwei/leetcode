#include<iostream>
#include<string>
using namespace std;
struct node {
	char type;
	node* next;
};
int main() {
	string s;
	while (cin >> s) {
		auto n = s.size();
		int i = 0;
		while (i<n-1) {
			node ss;
			node sss;
			ss.type = s[i];
			ss.next = sss;
			sss.type = s[i + 1];
		}
	}
	return 0;
}