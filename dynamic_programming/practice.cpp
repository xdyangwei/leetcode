#include<iostream>
#include<vector>
#include<cmath>
#include<set>
#include<string>
#include<algorithm>
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

int length_of_lis(int n, vector<int> &v, vector<int> v1);
void longest_increase_squence(vector<int> v1) {
	vector<int> v(100,0);
	v[1] = 1;
	length_of_lis(v1.size(),v,v1);
	int max = 0;
	for (size_t i = 1; i <= v1.size(); i++)
	{
		if (v[i] > max)
			max = v[i];
	}
	cout << max << endl;
}

int length_of_lis(int n,vector<int> &v,vector<int> v1) {
	if (n <= 0) {
		return 0;
	}
	if (v[n] != 0) {
		//cout << v[n] << endl;
		return v[n];
	}
	else if(v1[n-1]>v1[n-2]){
		v[n] = length_of_lis(n - 1, v, v1) + 1;
		return v[n];
	}
	else
	{
		v[n] = length_of_lis(n - 1, v, v1);
		return v[n];
	}
}

int lcs(vector<vector<int>> &v, vector<char> v1, vector<char> v2, int i, int j);

void longest_common_squence(vector<char> v1,vector<char> v2) {
	vector<vector<int>> v;
	for (size_t i = 0; i <= v1.size(); i++)
	{
		vector<int> v3;
		v.push_back(v3);
		for (size_t j = 0; j <= v2.size(); j++)
		{
			v[i].push_back(0);
		}
	}
	cout << lcs(v, v1, v2, v1.size(), v2.size());
}

//int max(int a,int b) {
//	return a > b ? a : b;
//}
int lcs(vector<vector<int>> &v,vector<char> v1,vector<char> v2,int i,int j) {
	if (!i || !j)
		return 0;
	if (v1[i-1] == v2[j-1]) {
		v[i][j] = lcs(v, v1, v2, i - 1, j - 1) + 1;
		return v[i][j];
	}
	else {
		v[i][j] = max(lcs(v,v1,v2,i-1,j),lcs(v,v1,v2,i,j-1));
		return v[i][j];
	}

}

long combine_money(int n) {
	int N=n;
	char a[6] = { 1,5,10,20,50,100 };
	vector<long> d(N + 1, 0);
	d[0] = 1;
	for (int i = 0; i < 6; i++)
		for (int j = 1; j <= N; j++)
			if (j >= a[i])
				d[j] = d[j] + d[j - a[i]];

	return d[N];
	
}


string longestPalindrome(string s) {
	if (s.empty())
		return "";
	int max_len = 0,k,j,start;
	for (int i = 0; i < s.size()-1;i++) {
		while (s[i] == s[i + 1]) {
			i++;
		}
		k = i + 1;
		j = i;
		while (s[j - 1] == s[k + 1] && j > 0 && k < s.size() - 1)
		{
			++k; --j;
		}
		if (k - j + 1 > max_len) {
			max_len = k - j + 1;
			start = j;
		}
	}
	return s.substr(start, max_len);
}

int maxSubArray(vector<int>& nums) {
	int res = nums[0], temp = 0;
	for (int i = 0; i < nums.size(); i++) {
		temp += nums[i];
		if (temp > res) res = temp;
		if (temp < 0) temp = 0;
	}
	return res;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> v(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
		v[i][0] = 1;
	for (int i = 0; i < n; i++)
		v[0][i] = 1;
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			v[i][j] = v[i - 1][j] + v[i][j - 1];
	return v[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	auto m = obstacleGrid.size();
	auto n = obstacleGrid[0].size();
	vector<vector<int>> v(m, vector<int>(n, 0));
	int m_flag = 0,n_flag=0;
	for (int i = 0; i < m; i++) {
		if (obstacleGrid[i][0] == 1)
			m_flag = 1;
		if(m_flag==0)
		v[i][0] = 1;
		else
		{
			v[i][0] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (obstacleGrid[0][i] == 1)
			n_flag = 1;
		if (n_flag)
			v[0][i] = 0; else
		{
			v[0][i] = 1;
		}
		
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[i][j] == 1) {
				v[i][j] = 0;
			}
		}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++) {
			if (obstacleGrid[i][j] == 1) {
				v[i][j] = 0;
			}
			else {
				if (obstacleGrid[i - 1][j] == 1)
					v[i][j] = v[i][j - 1];
				else if (obstacleGrid[i][j - 1] == 1)
					v[i][j] = v[i - 1][j];
				else {
					v[i][j] = v[i - 1][j] + v[i][j - 1];
				}
			}
		}
	return v[m - 1][n - 1];
}

int minPathSum(vector<vector<int>>& grid) {
	auto m = grid.size();
	auto n = grid[0].size();
	vector<vector<int>> v(m, vector<int>(n, 0));
	v[0][0] = grid[0][0];
	for (int i = 1; i < m; i++) {
		v[i][0] = v[i-1][0]+grid[i][0];
	}
	for (int i = 1; i < n; i++)
		v[0][i] = grid[0][i]+v[0][i-1];
	for(int i=1;i<m;i++)
		for (int j = 1; j < n; j++) {
			v[i][j] = min(v[i - 1][j], v[i][j - 1])+grid[i][j];
		}
	return v[m - 1][n - 1];
}

int numDecodings(string s) {
	if (s.length() == 0) {
		return 0;
	}
	int n = s.length();
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = s[0] != '0' ? 1 : 0;
	for (int i = 2; i <= n; i++) {
		int first = s[i - 1] - '0';
		int second = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
		if (first >= 1 && first <= 9) {
			dp[i] += dp[i - 1];
		}
		if (second >= 10 && second <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[n];
}

int decode(string s,vector<int> &v,int n) {
	if (v[n] != 0)
		return v[n];
	else {
		if (s[n - 1] - '0' > 0 && s[n - 1] - '0' < 9) {
			v[n] += decode(s, v, n - 1);
		}
		if ((s[n - 2]-'0') * 10 + s[n - 1] - '0' > 0 && (s[n - 2]-'0') * 10 + s[n - 1] - '0' <= 26) {
			v[n] += decode(s, v, n - 2);
		}
		return v[n];
	}
}

int numDecodings2(string s) {
	if (s.empty())
		return 0;
	vector<int> v(s.size()+1,0);
	v[0] = 1;
	if (s[0] == '0')
		v[1] = 0;
	else
	{
		v[1] = 1;
	}
	decode(s, v, s.size());
	return v[s.size()];
}

string longestPalindrome2(string s) {
	int start, max_len=0;
	for (int i = 0; i < s.size(); i++) {
		int k = i, j = i;
		while (s[i] == s[i + 1])
			i++;
		k = i;
		while (j > 0 && k < s.size() - 1 && s[j - 1] == s[k + 1])
		{
			j--; k++;
		}
		if (k - j + 1 > max_len) {
			max_len = k - j + 1; start = j;
		}
	}
	return s.substr(start, max_len);
}

int minimumTotal(vector<vector<int>>& triangle) {
	auto n = triangle.size();	
	vector<vector<int>> v(n, vector<int>(n,0));
	v[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if(j>=1&&j<i)
			v[i][j] = min(v[i - 1][j], v[i - 1][j - 1]) + triangle[i][j];
			else if (j == i) {
				v[i][j] = v[i - 1][j - 1] + triangle[i][j];
			}
			else {
				v[i][j] = v[i - 1][j] + triangle[i][j];
			}
		}
	}
	int sum = v[n-1][0],i=0;
	for (auto x : v[n - 1]) {
		sum = min(sum, x);
	}
	return sum;
}

bool wordBreak(string s, vector<string>& wordDict) {
	if (wordDict.empty())
		return false;
	vector<bool> v(s.size() + 1, false);
	v[0] = true;
	for(int i=0;i<=s.size();i++)
		for (int j = i - 1; j >= 0; j--) {
			if (v[j]) {
				string ss(s.substr(j,i-j));
				if (find(wordDict.begin(), wordDict.end(), ss) != wordDict.end()) {
					v[i] = true;
					break;
				}
			}
		}
	return v[s.size()];
}

int maxProduct(vector<int>& nums) {
	if (nums.empty())
		return 0;
	auto n = nums.size();
	vector<int> v(n, 0);
	vector<int> v1(n, 0);
	v[0] = nums[0]; v1[0] = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] < 0) {
			v[i] = max(v1[i - 1] * nums[i], nums[i]);
			v1[i] = min(v[i - 1] * nums[i], nums[i]);
		}
		else {
			v[i] = max(v[i - 1] * nums[i], nums[i]);
			v1[i] = min(v1[i - 1] * nums[i], nums[i]);
		}
	}
	int max_product = v[0];
	for (auto x : v)
		max_product = max(max_product, x);
	return max_product;
}

int rob(vector<int>& nums) {
	if (nums.empty())
		return 0;
	auto n = nums.size();
	if (n == 1)
		return nums[0];
	if (n == 2)
		return max(nums[0], nums[1]);
	if (n == 3)
		return max(nums[0]+nums[2],nums[1]);
	vector<int> v(n,0);
	v[0] = nums[0]; v[1] = nums[1]; v[2] = nums[0] + nums[2];
	for (int i = 3; i < n; i++) {
		v[i] = max(v[i-3]+nums[i],v[i-2]+nums[i]);
	}
	int max_len = 0;
	for (auto xx : v)
		max_len = max(xx, max_len);
	return max_len;
}

int rob_circle(vector<int>& nums) {
	if (nums.empty())
		return 0;
	if (nums.size() == 1)
		return nums[0];
	vector<int> v(nums.begin() + 1, nums.end());
	auto n1 = rob(v);
	vector<int> v1(nums.begin(), nums.end() - 1);
	auto n2 = rob(v1);
	auto max_len = max(n1, n2);
	return max_len;
}

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.empty())
		return 0;
	auto n = matrix.size();
	auto m = matrix[0].size();
	vector<vector<int>> v(n,vector<int>(m,0));
	for (int i = 0; i < n; i++)
		v[i][0] = matrix[i][0] - '0';
	for (int i = 0; i < m; i++)
		v[0][i] = matrix[0][i] - '0';
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][j] == '1') {
				if (v[i - 1][j - 1]!=0) {
					auto x = sqrt(v[i - 1][j - 1]); 
					auto y = x;
					int flag = 1;
					while (x) {
						if (matrix[i - x][j] == '0' || matrix[i][j - x] == '0')
							flag = 0;
						x -= 1;
					}
					if (flag == 1) {
						v[i][j] = pow(sqrt(v[i - 1][j - 1]) + 1, 2);
					}
					else
					{
						int z = 1;
						while (z != y) {
							if (matrix[i - z][j] == '1'&&matrix[i][j - z] == '1')
								z++;
							else {
								break;
							}
						}
						v[i][j] = pow(z, 2);
					}
				}
				else {
					v[i][j] = 1;
				}
			}
		}
	}
	int max_size = 0;
	for (auto x : v)
		for (auto xx : x)
			max_size = max(max_size, xx);
	return max_size;
}

void normal_input(vector<int> &v) {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}

void geohash_encode() {
	int n;
	cin >> n;
	vector<int> v;
	int x = 1;
	int left = -90;
	int right = 90;
	while (x++ <= 6) {
		auto mid = (left + right) / 2;
		if (n < mid) {
			v.push_back(0);
			right = mid;
		}
		else{
			v.push_back(1);
			left = mid;
		}
		/*else {
			v.push_back(1);
			break;
		}*/
	}
	for (auto xx : v)
		cout << xx;
}

int main() {
	geohash_encode();
	system("pause");
}