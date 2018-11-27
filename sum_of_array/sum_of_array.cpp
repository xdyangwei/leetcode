#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main() {
	int  m;
	double n;
	while (cin >> n >> m) {
	//cin >> n >> m;
	double sum = n;
	while (m > 1) {
		n = sqrt(n);
		sum += n;
		m--;
	}
	printf("%.2lf\n", sum);
	}
}