#include<iostream>
#include<string>
using namespace std;
void split_id_number(string s) {
	auto x = s.find(' ');
	while (x != string::npos) {
		s.erase(x, 1);
		x = s.find(' ');
	}
	auto n = s.size();
	if (n <= 6)
		cout << s << endl;
	else if (n > 6 && n <= 14) {
		s.insert(6, 1, ' ');
		cout << s << endl;
	}
	else {
		s.insert(6, 1, ' ');
		s.insert(15, 1, ' ');
		cout << s << endl;
	}
		
}
int main() {
	string s;
	while (getline(cin, s)) {
		split_id_number(s);
	}
	return 0;
}