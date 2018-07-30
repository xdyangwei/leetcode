#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
//首先算出整数的每一位数，放入一个vector中，再pop出来
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
    
};
int main(){
    Solution s;
    s.reverse(120);
    return 0;
}