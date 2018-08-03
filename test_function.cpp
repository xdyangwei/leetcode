#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a,int b){
    return a>b?true:false;
}
int main(){
    vector<int> v={1,3,4};
    auto x=find_if(v.begin(),v.end(),bind(compare,std::placeholders::_1,2));
    cout<<*x<<endl;
    return 0;
}