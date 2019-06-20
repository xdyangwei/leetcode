#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<chrono>
#include<thread>
#include"queue_with_stack.h"
#include<ctime>
#include<cstring>
#include<regex>
#include<map>
#include<set>
using namespace std;
int programmer_manager() {
	string s;
	int count = 0;
	vector<vector<int>> v;
	while (getline(cin, s)) {
		if (s == "")
			break;
		auto it = s.find(' ');
		auto start = 0;
		vector<int> v1;
		while (it != s.npos) {
			auto x = stoi(string(s.begin() + start, s.begin() + it));
			if (x == 1)
				count++;
			v1.push_back(x);
			start = it + 1;
			it = s.find(' ', it+1);
		}
		auto it1 = s.rfind(' ');
		auto x = stoi(string(s.begin() + it1 + 1, s.end()));
		if (x == 1) count++;
		v1.push_back(x);
		v.push_back(v1);
	}
	bool flag = 1;
	auto m = v.size(); auto n = v[0].size();
	int co = 0;
	while (true) {
		auto vv = v;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				if (v[i][j] == 2) {
					if (i - 1 >= 0 && v[i - 1][j] == 1&&vv[i-1][j]!=2) {
						vv[i - 1][j] = 2; count--;
						//cout << "here1" << endl;
					}
					if (i + 1 < m&&v[i + 1][j] == 1 && vv[i + 1][j] != 2) {
						vv[i + 1][j] = 2; count--;
						//cout << i<<" " <<j<< endl;
					}
					if (j - 1 >= 0 && v[i][j - 1] == 1 && vv[i][j-1] != 2) {
						vv[i][j-1] = 2; count--;
						//cout << "here3" << endl;
					}
					if (j + 1 < n && v[i][j + 1] == 1 && vv[i][j+1] != 2) {
						vv[i][j + 1] = 2; count--;
						//cout << "here4" << endl;
					}
				}
			}
		co++;
		if (vv == v) {
			if (count != 0)
				flag = 0;
				break;
		}
		v = vv;
	}
	if (flag == 1)
		return co-1;
	return -1;
}

int robot() {
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(0);
	int x;
	while (n--) {
		cin >> x;
		v.push_back(x);
	}
	vector<int> energy(v.size(),0);
	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i - 1] > v[i])
			energy[i - 1] = ceil((v[i]+energy[i]) / 2.0);
		else
		{
			energy[i - 1] = ceil((v[i] + energy[i]) /2.0);
		}
	}
	return energy[0];
}

void right_value_test(int&& a) {
	cout << a << endl;
	a = 1;
}

//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
//使用回溯法
bool judge_row_col(int m,int n,int count) {
	auto s1 = to_string(m);
	auto s2 = to_string(n);
	int x = 0;
	for (auto xx : s1) {
		x += (xx - '0');
	}
	for (auto xx : s2) {
		x += (xx - '0');
	}
	if (x <= count)
		return true;
	return false;
}
int recursive_movingCount(vector<vector<int>>& flag,int m,int n,int rows,int cols,int& count) {
	if (m < rows&&n < cols&&m >= 0 && n >= 0 && flag[m][n] == 0&&judge_row_col(m,n,count)) {
		flag[m][n] = 1;
		return 1+ recursive_movingCount(flag, m - 1, n, rows, cols, count)+ recursive_movingCount(flag, m, n + 1, rows, cols, count)+ recursive_movingCount(flag, m + 1, n, rows, cols, count)+ recursive_movingCount(flag, m, n - 1, rows, cols, count);
	}
	else {
		return 0;
	}

}
int movingCount(int threshold, int rows, int cols) {
	vector<vector<int>> v(rows,vector<int>(cols,0));
	int count = 0;
	return recursive_movingCount(v, 0, 0, rows, cols, threshold);
}

//在一个二维数组中（每个一维数组的长度相同），
//每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//思路：从左下角开始找起，比当前数大的排除这一列，比当前数小的排除这一行
bool Find(int target, vector<vector<int> > array) {
	if (array.empty() || array[0].empty())
		return false;
	auto m = array.size();
	auto n = array[0].size();
	bool flag = false;
	for (int i = m - 1; i >= 0; i--) {
		if (array[i][0] == target) {
			flag = true;
			break;
		}
		else if (array[i][0] > target) {
			continue;
		}
		else {
			for (int j = 1; j < n; j++) {
				if (array[i][j] == target) {
					flag = true; break;
				}
			}
		}
	}
	return flag;
}

//替换空格，将一个字符串中的每个空格替换成“%20”。
//思路：使用正则表达式regex
void replaceSpace(string str) {
	string s = "(\\w+)\\s+(\\w+)";
	regex r(s);
	string s1=str;
	while (s1.find(" ") != string::npos) {
		s1 = regex_replace(s1,r,"$1%20$2");
	}
	cout << s1;
}


//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
//但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
//思路：使用set即可
bool duplicate(int numbers[], int length, int* duplication) {
	set<int> s1;
	bool flag = false; int x = -1;
	for (int i = 0; i < length; i++) {
		if (s1.find(numbers[i]) != s1.end()) {
			flag = true; x = numbers[i];
			break;
		}
		else
			s1.insert(numbers[i]);
	}
	*duplication = x;
	return flag;
}

//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
//而'*'表示它前面的字符可以出现任意次（包含0次）。
bool match(char* str, char* pattern)
{
	if (*str == '\0')
		return false;
	while (*str != '\0') {
		if (*str == *pattern||*pattern=='.') {
			str++;
			pattern++;
		}
		else if (*pattern == '*') {
			auto x = str - 1;
			if (*x != *str)
				break;
			while (*str == *x) {
				x++;
			}
			str = x;
			pattern++;
		}
		else {
			auto x = pattern + 1;
			while (*x == *pattern)
				x++;
			if (*x == '*') {
				pattern = x + 1;
				str++;
			}
			else
			{
				break;
			}

		}
	}
	if (*str != '\0')
		return false;
	return true;
}

int main() {
	replaceSpace("We Are Happy 20 30");
	getchar();
}