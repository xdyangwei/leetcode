#include<iostream>
#include"node_of_list.h"
#include<string>
#include<vector>
#include<map>
using namespace std;
int number_of_diamond(node *head) {
	map<node*, int> m;
	vector<char> v;
	while (head->next != nullptr) {
		if (m.find(head) == m.end()) {
			m.insert(make_pair(head, 1));
			v.push_back(head->type);
			if (count(v.begin(), v.end(), 'A') >= 1 && count(v.begin(), v.end(), 'B') >= 1 && count(v.begin(), v.end(), 'C') >= 1 && count(v.begin(), v.end(), 'D') >= 1 && count(v.begin(), v.end(), 'E') >= 1) {
				break;
			}
			head = head->next;
		}
		else
		{
			break;
		}
	}
	return m.size();
}
int main() {
	string s;
	while (cin >> s) {
	auto n = s.size();
	node iter;
	node *first = &iter;
	first->type = s[0];
	auto head = first;
	int i = 1;
	while (n > 1) {
		node *x=new node;
		x->type = s[i++];
		first->next = x;
		if (i == 1)
			head = first;
		first = x;
		n--;
	}
	first->next = head;
	int max = 0;
	for (auto i = head; i != first; i=i->next)
	{
		auto size = number_of_diamond(i);
		
		if ((s.size() - size) > max)
			max = s.size() - size;
	}
	auto last = s.size() - number_of_diamond(first);
	if (max < last)
		max = last;
	cout << max << endl;
}
	return 0;
}