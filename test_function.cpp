#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(int a,int b){
    return a>b?true:false;
}
int main(){
    vector<pair<int,int>> v(3);
    //auto x=find_if(v.begin(),v.end(),bind(compare,std::placeholders::_1,2));
    //cout<<*x<<endl;
    //v[0]={1,1};v[1]={0,2};v[2]={1,0};
    sort(v.begin(),v.end());
    for(auto s:v){
        cout<<s.first<<" "<<s.second<<endl;
    }
    return 0;
}