#include<iostream>
#include<cstdio>
#include<map>
#include<unordered_map>
#include<string>
#include<regex>
#include<deque>
#include<bitset>
using namespace std;
class BSTNode {
public:
	BSTNode(int a, BSTNode* b, BSTNode* c) :
		data(a), left(b), right(c) {}
	BSTNode(int a) :
		data(a),left(nullptr),right(nullptr) {}
	int data;
	BSTNode* left;
	BSTNode* right;
};


bool search_BST_recursive(BSTNode* root,BSTNode* now,bool flag=0){
	if (now) {
		if (now->data > root->data || now->data < root->data) {
			flag = 1;
			return flag;
		}
		else {
			search_BST_recursive(root, root->left);
			search_BST_recursive(root, root->right);
		}
	}
	else {
		return flag;
	}
}

int judge_BST() {
	int root;
	cin >> root;
	unordered_map<int, BSTNode*> m;
	auto x = new BSTNode(root);
	m.insert(make_pair(root, x));
	int n, l,r;
	while (scanf_s("%d:%d|%d", &n, &l, &r)) {
		//auto y = m[n];
		if (n == 0)
			break;
		/*if (l > n || r < n)
			flag = 1;*/
		auto y = l==-1?0:new BSTNode(l);
		auto z = r==-1?0:new BSTNode(r);
		if (y != 0) {
			m.insert(make_pair(l, y));
		}
		if (z != 0) {
			m.insert(make_pair(r, z));
		}
		m[n]->left = y;
		m[n]->right =z;
	}
	/*if (flag == 1)
		return 0;*/
	auto mm = m[root];
	bool flag = search_BST_recursive(mm, mm);
	return (int)flag;
}

void problems_list() {
	int n;
	cin >> n;
	string s; double x, y;
	map<string, int> m;
	while (n--) {
		cin >>s>> x >> y;
		auto z = y / x <= 0.3 ? 5 : y / x <= 0.6 ? 4 : 3;
		m.insert(make_pair(s,z));
	}
	for (auto mm : m)
		cout << mm.first << " " << mm.second << endl;
}

void combine_stones() {
	int n,x;
	cin >> n;
	vector<int> v,v1(n+1,0);
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	v1[1] = v[0];
	v1[2] = v[0] * v[1];
	int sum = v[0]+v[1];
	for (int i = 3; i < v1.size(); i++) {
		v1[i] = v1[i - 1] + sum * v[i-1];
		sum += v[i - 1];
	}
	cout << v1[v.size()] << endl;
}

void repeat_substr() {
	string s;
	cin >> s;
	vector<int> v(s.size(), 0);
	if (s.empty())
		cout << 0 << endl;
	else {
		v[0] = 0;
		for (auto i = 1; i < s.size(); i++) {
			auto ss = s.substr(i - v[i - 1], v[i - 1] + 1);
			regex r(ss); smatch result;
			if (regex_search(s.cbegin(), s.cbegin()+i-v[i-1]-1, result, r)) {
				v[i] = v[i - 1] + 1;
			}
			else {
				v[i] = v[i - 1];
			}
		}
	}
	int max_len = 0;
	for (auto xx : v)
		max_len = max(xx,max_len);
	cout << max_len;
}

void number_transfer_machine() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a > c || b > d)
		cout << -1 << endl;
	else if ((a == c && b != d) || (a != c && b == d)) {
		cout << -1 << endl;
	}
	else if ((c%2==1&&d%2==0)||(c%2==0&&d%2==1)) {
		cout << -1 << endl;
	}
	else if (a == c && b == d) {
		cout << 0 << endl;
	}
	else {
		int count = 0;
		while (a*4 <= c && b*4 <= d) {
			a *= 2; b *= 2;
			count++;
		}
		if (c % 2) { c -= 1; d -= 1; count++;  }
		if (c / 2 - a != d / 2 - b) { cout << -1 << endl; }
		else {
			count += (c / 2 - a + 1);
			cout << count << endl;
		}
	}
}

void bit_different_numbers() {
	int a, b;
	cin >> a >> b;
	bitset<32> b1(a), b2(b); int count = 0;
	for (int i = 0; i < 32; i++) {
		if (b1[i] != b2[i])
			count += 1;
	}
	cout << count << endl;
}

int main() {
	bit_different_numbers();
	system("pause");
}