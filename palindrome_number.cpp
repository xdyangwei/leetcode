#include<iostream>
#include<list>
using namespace std;
class Solution {
public:
//回文数：顺着读和倒着读一样的数，比如121
//思路：由题意，负数肯定不满足，正数的话求出它的每一位，分别使用两个list容器,一个push_back插入每一位
//另一个push_front插入，最后比较这两个容器是否相等即可得出此数是否回文数
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
    //将字符串中的字符都变为小写
    //思路：使用for-each语句引用的方式遍历整个字符串，当发现ascii码值为大写时加上32即可
    string toLowerCase(string str) {
        for(auto& c:str){
            if(c>='A'&&c<='Z'){
                c+=32;
            }
        }
        return str;
    }
};
int main(){
    Solution s;
    cout<<s.toLowerCase("ABCdEf");
    return 0;
}