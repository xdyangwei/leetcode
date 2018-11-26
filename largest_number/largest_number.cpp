#include<iostream>
#include<string>
using namespace std;
int main() {
	string s; int n;
	cin >> s >> n;
	while (n > 0) {
		int i;
		auto nn = s.size();
		for (i = 0; i < nn-1; i++)
		{
			if (s[i]<s[i+1]) {
				s.erase(i, 1);
				break;
			}
		}
		if (i == nn - 1) {
			s.erase(nn - 1, 1);
		}
		
		n--;
	}
	cout << s << endl;
	return 0;
}