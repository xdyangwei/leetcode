#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int fibonacci_number(int n) {
	if (n == 1)
		return 0;
	else if(n==2)
	{
		return 1;
	}
	else
	{
		return fibonacci_number(n - 1) + fibonacci_number(n - 2);
	}
}
vector<int> fibonacci_array(int x) {
	int n = 1;
	vector<int> v1;
	auto z = fibonacci_number(n);
	while (z <=x ) {
		v1.push_back(z);
		n++;
		z = fibonacci_number(n);
	}
	return v1;
}
bool bigger_than(int a,int b) {
	return a >= b ? true : false;
}
int step_to_fibonacci(int x) {
	auto z = fibonacci_array(1000000);
	auto zz = bind(bigger_than,placeholders::_1,x);
	auto iter=find_if(z.begin(), z.end(),zz);
	auto zzz = iter - 1;
	return (*iter - x) <= (x-*(zzz) ) ? (*iter - x) : (x-*(zzz) );
}
int step_to_fibonacci2(int x) {
	int  y = x,n=x;
	auto v = fibonacci_array(1000000);
	while (true) {
		if (find(v.begin(), v.end(), n) != v.end()||find(v.begin(),v.end(),y)!=v.end())
			break;
		else {
			n = n + 1;
			y = y - 1;
		}
	}
	return (n - x) <= (x - y) ? n - x : x - y;
}
int main() {
	int x;
	cin >> x;
	cout << step_to_fibonacci2(x) << endl;

}