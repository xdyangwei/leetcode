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
   vector<int> v1={1,2,2};
   v1.insert(v1.end(),2,2);
   while(next_permutation(v1.begin(),v1.end())){
       for(auto x:v1){
           cout<<x<<" ";
       }
       cout<<endl;
   }
   
    return 0;
}