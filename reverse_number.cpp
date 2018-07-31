#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
//首先先判断正负，负数的话求出其绝对值，接着算出整数的每一位数，放入一个list中，再pop_front出来
//再从尾到头遍历list，求出最后的整数值
class Solution {
public:
    int reverse(int x) {
        int flag;
        if(x>=0)
        flag=1;
        else{
        flag=0;
        x=abs(x);
        }
        int y=x;
        list<int> v1;
    while(y>=1){
        int n=y%10;
        v1.push_back(n);
        y=(y-n)/10;
    }
   if(*v1.begin()==0){
       v1.pop_front();
   }
   int sum=0;
   int ss=1;
   auto s=(--v1.end());
while(s!=--v1.begin()){
    sum+=(*s)*ss;
    ss*=10;
    //cout<<sum<<endl;
    s--;
}
if(flag==0){
    sum=0-sum;
}
return sum;
}
};
int main(){
    Solution s;
    cout<<s.reverse(-321);
    return 0;
}