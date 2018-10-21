#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool not_empty(int x){
        return x==0?false:true;
    }
//整数反转    
void int_reverse(){
int x;
    cin>>x;
    auto flag=x>=0?true:false;
    x=abs(x);
    vector<int> v;
    if(x==0)
        cout<<0;
    while(x>0){
        int y=x%10;
        x/=10;
        v.push_back(y);
    }
    if(flag==false){
        cout<<"-";
    }
    auto zz=find_if(v.begin(),v.end(),not_empty);
    if(zz!=v.end()){
        for(auto xx=zz;xx!=v.end();xx++){
            cout<<*xx;
        }
    }
}
//整数求和:给定整数n，取若干个1到n的整数可求和等于整数m，编程求出所有组合的个数。
//比如当n=6，m=8时，有四种组合：[2,6], [3,5], [1,2,5], [1,3,4]。限定n和m小于120 
int count(int n,int m){
    if(!n){
        if(!m)
        return 1;
        else
        return 0;
    }
    if(n>m)
        return count(m,m);
    return count(n-1,m-n)+count(n-1,m);
}
void int_sum(){
    int n,m;
    cin>>n>>m;
    cout<<count(n,m);
}


int main(){
    int_sum();
    
    return 0;
}