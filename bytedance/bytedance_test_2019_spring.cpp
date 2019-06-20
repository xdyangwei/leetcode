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

//������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
//ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
//ʹ�û��ݷ�
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

//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
//ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
//˼·�������½ǿ�ʼ���𣬱ȵ�ǰ������ų���һ�У��ȵ�ǰ��С���ų���һ��
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

//�滻�ո񣬽�һ���ַ����е�ÿ���ո��滻�ɡ�%20����
//˼·��ʹ��������ʽregex
void replaceSpace(string str) {
	string s = "(\\w+)\\s+(\\w+)";
	regex r(s);
	string s1=str;
	while (s1.find(" ") != string::npos) {
		s1 = regex_replace(s1,r,"$1%20$2");
	}
	cout << s1;
}


//��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�
//����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
//���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
//˼·��ʹ��set����
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

//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ���
//��'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
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