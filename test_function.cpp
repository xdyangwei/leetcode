#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
bool compare(int a, int b)
{
    return a > b ? true : false;
}
void pointer_plus(int *&(p))
{
    cout << p << endl;
    p++;
    cout << p << endl;
}
int main()
{
    int i=0x12345678;
    cout<<"good"<<endl;
    return 0;
}