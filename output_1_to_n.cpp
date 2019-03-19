#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool plus_1(vector<char> &v){
    //cout<<v.size()<<endl;
auto it=find_if(v.rbegin(),v.rend(),[](char a){return a!='9'?true:false;});
//cout<<(it-v.rbegin())<<endl;
if(it!=v.rend()-1){
*it=*it+1;
//cout<<*it<<endl;
for(it=it-1;it>=v.rbegin();it--){
    *(it)='0';
}
auto it1=find_if(v.begin(),v.end(),[](char a){return a!='0'?true:false;});
for(;it1!=v.end();it1++)
cout<<*it1<<" ";
//cout<<endl;
return true;
}
return false;
}
//递归实现全排列，要点：在for循环里递归
void recursive_whole_permutation(vector<int>& v,int n,int i){
    if(i==n){
        for(auto xx:v)
        cout<<xx<<" ";
        cout<<endl;
        return ;
    }
    for(int j=0;j<=9;j++){
        v[i]=j;
        recursive_whole_permutation(v,n,i+1);
    }
}
void whole_permutation(int n){
    vector<int> v(n,0);
    for(int i=0;i<=9;i++){
        v[0]=i;
        recursive_whole_permutation(v,n,1);
    }
}

void output(int n){
    vector<char> v(n+1,'0');
    //plus_1(v);
    while(plus_1(v)){
        cout<<endl;
    }
}

int main(){
int n;
cin>>n;
whole_permutation(n);
}