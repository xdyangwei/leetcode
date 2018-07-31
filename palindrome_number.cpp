#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
    if(x<0){
        return false;
    }else{
    list<int> v1;
    list<int> v2;
    while(x>=1){
        int n=x%10;
        v1.push_back(n);
        v2.push_front(n);
        x=(x-n)/10;
    }
    if(v1==v2){
        return true;
    }else{
        return false;
    }
    }
    }
};
int main(){
    Solution s;
    cout<<s.isPalindrome(12321);
    return 0;
}