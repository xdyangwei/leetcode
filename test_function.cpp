#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<cmath>
#include<bitset>
using namespace std;
bool compare(int a,int b){
    return a>b?true:false;
}
int main(){
    auto a = int(3.14 + 3);
    cout << a << endl;
    return 0;
}