#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<unordered_map>
#include<string>
#include<regex>
#include<deque>
#include<bitset>
#include<set>
#include<unordered_map>
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
	while (scanf("%d:%d|%d", &n, &l, &r)) {
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

void bus(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v;
	vector<vector<int>> v2(n+1,vector<int>(n+1,0));
	auto z=m;
	while(m){
		int n1;
		cin>>n1;
		vector<int> v1(n1,0);
		auto x=n1;
		while(n1){
			int xx;
			cin>>xx;
			v1[x-n1]=xx;
			n1--;
		}
		v.push_back(v1);
		m--;
	}
	//cout<<v.size()<<endl;
	// for(auto zz:v){
		
	// 	for(auto zzz:zz){
	// 		cout<<zzz<<" ";
	// 	}
	// 	cout<<endl;
	// }
	//int count=0;
	for(auto lt=v.begin();lt!=v.end();lt++){
	for(auto it=(*lt).begin();it!=(*lt).end();it++){
	for(auto ii=(*lt).begin();ii!=(*lt).end();ii++){
		//  if(ii==it)
		//  continue;
		//cout<<*it<<" "<<*ii<<endl;
		v2[*it][*ii]=1;
		//cout<<++count<<endl;
	}
	}
	}
	vector<int> v3(n+1,0);
	v3[1]=0;
	for(int i=2;i<n+1;i++){
		int min_len=100001;
		for(int j=1;j<i;j++){
			if(v2[j][i]==1&&v3[j]!=-1)
				min_len=min(min_len,v3[j]);
		}
		if(min_len==100001)
		v3[i]=-1;
		else{
			v3[i]=min_len+1;
		}
	}
	cout<<v3[n]<<endl;
}

void judge_problem() {
	int n, t, a;
	cin >> n >> t >> a;
	int max;
	if (t > a) {
		max = n - (t - a);
	}
	else if (t == a) {
		max = n;
	}
	else {
		max = n - (a - t);
	}
	cout << max << endl;
}

long fibonacci(int n) {
	long *a = new long[n+1];
	a[0] = 0; a[1] = 1; a[2] = 1;
	for (int i = 3; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}

void fibonacci_sequence() {
	int n;
	cin >> n;
	cout << fibonacci(n) << endl;
	
}

void roast_fish() {
	int n, m;
	cin >> n >> m;
	int length;
	if (m >= n) {
		length = 2;
	}
	else {
		auto x = n % m;
		auto y = n / m;
		length = 2*y;
		if (x != 0) {
			if (x <= m / 2) {
				length += 1;
			}
			else
			{
				length += 2;
			}
		}
	}
	cout << length << endl;
}

bool is_sushu(int n) {
	if (n == 2) {
		return true;
	}
	else {
		int i = 2;
		for (; i <= sqrt(n); i++) {
			if (n%i == 0)
				break;
		}
		//cout << sqrt(n)+1 << endl;
		if (i == (int)sqrt(n)+1) {
			return true;
		}
		else
		{
			return false;
		}
	}
}

void limit_area() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (is_sushu(i) == true) {
			auto x = i;
			v.push_back(x);
			int j = 2;
			while ((x=pow(i,j)) <= n) {
				v.push_back(x);
				j++;
			}
		}
	}
	cout << v.size() << endl;
}

void memory() {
	int L, R, W;
	cin >> L >> R >> W;
	if (L - R >= W) {
		cout << "OK";
	}
	else {
		cout << "DEADLOCK";
	}
}

bool is_square(pair<int,int> p1,pair<int,int> p2,pair<int,int> p3,pair<int,int> p4){
if((p1.first*p2.first+p1.second*p2.second==0)&&((p3==p4)||(p3.first==(0-p4.first)&&p3.second==(0-p4.second))))
return true;
return false;
}

void magic() {
	int n;
	cin >> n;
	vector<pair<string,string>> m;
	string s1,s2;
	while (n--) {
		cin >> s1; cin >> s2;
		m.push_back(make_pair(s1, s2));
	}
	for (auto mm : m) {
		//cout << mm.first << " " << mm.second << endl;
		auto side1 = make_pair(mm.first[1] - mm.first[0], mm.second[1] - mm.second[0]);
		auto side2= make_pair(mm.first[2] - mm.first[0], mm.second[2] - mm.second[0]);
		auto side3= make_pair(mm.first[3] - mm.first[0], mm.second[3] - mm.second[0]);
		auto x = pow(mm.first[1] - mm.first[0], 2) + pow(mm.second[1] - mm.second[0], 2);
		auto y= pow(mm.first[2] - mm.first[0], 2) + pow(mm.second[2] - mm.second[0], 2);
		auto z= pow(mm.first[3] - mm.first[0], 2) + pow(mm.second[3] - mm.second[0], 2);
		//cout<<x<<" "<<y<<" "<<z<<endl;
		if (x == y&&x+y==z) {
			auto side4= make_pair(mm.first[3] - mm.first[2], mm.second[3] - mm.second[2]);
			if (is_square(side1,side2,side4,side1)) {
				cout << "YES"<<endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else if (x == z&&x+z==y) {
			auto side4 = make_pair(mm.first[2] - mm.first[1], mm.second[2] - mm.second[1]);
			if (is_square(side1,side3,side4,side3)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else if (y == z&&y+z==x) {
			auto side4 = make_pair(mm.first[2] - mm.first[1], mm.second[2] - mm.second[1]);
			if (is_square(side2,side3,side4,side3)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
}
int main() {
	magic();
	system("pause");
}
