#include<iostream>
#include<vector>
using namespace std;

int count_of_steps(int n, vector<int> &p) {
	if (n <= 0) {
		return 0;
	}
	else {
		if (p[n] != -1) {
			return p[n];
		}
		else {
			p[n] = count_of_steps(n - 1, p) + count_of_steps(n - 2, p);
			return p[n];
		}
	}
}
int count_of_steps_top_to_bottle(int n) {
	vector<int> v;
	for (int i = 0; i != n+1; i++)
		v.push_back(-1);
	v[1] = 1; v[2] = 2;
	int x= count_of_steps(n,v);
	for (auto xx : v)
		cout << xx << endl;
	return x;
}

int count_of_steps_bottle_to_top(int n) {
	vector<int> v(n+1, 0);
	v[1] = 1, v[2] = 2;
	for (int i = 3; i < n+1; i++)
		v[i] = v[i - 1] + v[i - 2];
	return v[n];
}

void longest_common_squence(vector<int> v) {

}

vector<int> length_of_lcs(int n,vector<vector<int>> v1) {
	if (!v1[n].empty())
		return v1[n];

}
int main() {
	cout << count_of_steps_bottle_to_top(4);
	getchar();
}