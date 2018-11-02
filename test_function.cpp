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
int a[3][4]={{0},{1},{2}};
auto *p=a;
cout<<*(p+1)[0];
    return 0;
}