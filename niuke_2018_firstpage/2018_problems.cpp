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
#include<iomanip>
#include<boost/lambda/lambda.hpp>
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

void super_link() {
	int n;
	cin >> n;
	set<string> s;
	string s1;
	while (n--) {
		cin >> s1; s.insert(s1);
	}
	int m;
	cin >> m;
	string s2;
	while (m--) {
		cin >> s2; s.erase(s2);
	}
	for (auto ss : s) {
		cout << ss << endl;
	}
}

void find_number() {
	int n;
	cin >> n;
	int x;
	vector<int> v;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end(), [](int a, int b) {return b - a != 1 ? true : false; });
	if (it == v.end()) {
		cout << 0 << endl;
	}
	else {
		cout << (*it) - 1 << endl;
	}
}

void construct_number() {
	int n;
	cin >> n;
	
}

void q_sort() {
	int n;
	cin >> n;
	int x;
	vector<int> v;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	auto it = unique(v.begin(), v.end(), [](int a, int b) {return a < b ? true : false; });
	if (it == v.end()) {
		cout << 0 << endl;
	}
	else {
		auto y = v[0];
		auto z = v[v.size() - 1];
		auto it1 = find_if(v.begin(), v.end(), [y](int a) {return a > y ? true : false; });
		auto it2 = find_if(v.begin(), v.end(), [z](int a) {return a < z ? true : false; });
		auto it3 = find_if(v.begin(), v.end(), [y](int a) {return a < y ? true : false; });
		auto it4 = find_if(v.begin(), v.end(), [z](int a) {return a > z ? true : false; });
		if (it1 == v.end() && it2 == v.end()) {
			cout << 3 << endl;
		}
		else if(it3==v.end()||it4==v.end()){
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}
}

void closest_string() {
	string s;
	cin >> s;
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			s[j]=s[i];
		}
	}
	cout << s << endl;
}

void greedy_bo() {
	int n; cin >> n;
	int nn = n;
	int x;long long sum = 0;
	while (n--) {
		cin >> x;
		sum += x;
	}
	cout << sum - nn + 1 << endl;
}

void max_grade() {
	int n;
	cin >> n;
	if (n == 0&&n==1) {
		cout << 0 << endl;
	}
	else if (n == 2) {
		cout << 1 << endl;
	}
	else if (n == 3) {
		cout << 3 << endl;
	}
	else {
		vector<int> v(n+1, 0);
		v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3;
		for (int i = 4; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				v[i] = max(v[i-j]*v[j],v[i]);
				//cout << v[i] << endl;
			}
		}
		cout << v[n] << endl;
	}
}

void delete_repeat_str() {
	string s;
	cin >> s;
	vector<char> v;
	for (auto ss : s) {
		if (find(v.begin(), v.end(), ss) == v.end()) {
			v.push_back(ss);
		}
	}
	for (auto vv : v)
		cout << vv;
}

void sort_sequence() {
	int n;
	cin >> n;
	vector<int> v;
	int x;
	while (n--) {
		cin >> x; v.push_back(x);
	}
	auto v1 = v; sort(v.begin(), v.end()); int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v1[i] != v[i])
			count++;
	}
	cout << count << endl;

}

void sum_of_array() {
	double n, m;
	vector<double> v;
	while (cin >> n >> m) {
		double sum=n;
		while (m>1) {
			sum += sqrt(n);
			n = sqrt(n);
			m--;
		}
		v.push_back(sum);
	}
	cout.setf(ios::fixed);
	cout << setprecision(2);
	for (auto xx : v)
		cout << xx << endl;
}

void str_override() {
	string s;
	cin >> s;
	string s1;
	cin >> s1;
	multiset<char> s2;
	for (auto ss : s1)
		s2.insert(ss);
	auto i = s2.rbegin();
	for (int j=0; (i != (s2.rend())&&j<s.size());j++) {
		if ((*i) > s[j]) {
			s[j] = (*i);
			i++;
		}
	}
	for (auto ss : s)
		cout << ss;
}

void cross_sequence() {
	int n;
	cin >> n;
	vector<int> v{0};
	int x;
	auto nn = n;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	vector<int> v1(nn+1 , 0);
	v1[1] = 1;
	if (nn >= 2) {
		v1[2] = v[1] == v[2] ? 1 : 2;
		for (int i = 3; i < v1.size(); i++) {
			if (v[i - 2] == v[i - 1]) {
				if (v[i] != v[i - 2]) {
					v1[i] = v1[i - 1] + 1;
				}
				else {
					v1[i] = v1[i - 1];
				}
			}
			else {
				if (v[i] != v[i - 1]) {
					v1[i] = v1[i - 1] + 1;
				}
				else {
					v1[i] = v1[i - 1];
				}
			}
		}
	}
	cout << v1[nn];
}

void magic_watch() {
	int n1, n2;
	cin >> n1 >> n2;
	int min_circle;
	if (n2 >= n1) {
		int x = n2 - n1;
		int y = n1 + 360 - n2;
		//int z = min(x, y);
		if (x == min(x, y))
			min_circle = x;
		else {
			min_circle = 0-y;
		}
	}
	else {
		int x = n1 - n2;
		int y = n2 + 360 - n1;
		if (x == min(x, y))
			min_circle = 0-x;
		else
		{
			min_circle = y;
		}
	}
	cout << min_circle << endl;
}

int F(int m, int n)
{
	if (m == 0 || n == 1)         
		return 1;     
	else if (m < n)         
		return F(m, m);     
	else         
		return F(m, n - 1) + F(m - n, n);
}

void drop_water() {
	int x;
	cin >> x;
	int m, n;
	vector<pair<int, int>> v;
	while (x--) {
		cin >> m >> n;
		v.push_back(make_pair(m, n));
	}
	for (auto vv : v) {
		cout <<F(vv.first,vv.second) << endl;
	}
}

int main() {
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;
	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " ");
	system("pause");
}
