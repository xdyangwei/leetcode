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
    for(int x=1;x<=5;x++){
        auto sum=1;
        for(int j=x;j>0;j--)
        sum*=j;
        cout<<sum<<endl;
    }
    return 0;
}