#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	map<char, int> m;
	auto n = s.size();
	for (size_t i = 0; i < n; i++)
	{
		if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z')) {
			if (m.find(s[i]) != m.end()) {
				m[s[i]] += 1;
				if (m[s[i]] == 3) {
					cout << s[i];
					break;
				}
			}
			else {
				m.insert(make_pair(s[i], 1));
			}
		}
		else
		{
			continue;
		}
	}
	return 0;
}