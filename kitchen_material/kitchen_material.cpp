#include<iostream>
#include<set>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
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

int main() {
	
	
}