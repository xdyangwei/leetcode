#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
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
    //罗马字母转换成数字
    //思路：使用while循环遍历字符串，当发现第一个是有I或X或C的时候查看第二个数是否
    //为V、X或L、C或D、M，如果是的话就第二个数减去第一个数，然后迭代器+2,不然直接相加，迭代器+1
    int romanToInt(string s) {
    auto ss=s.begin();
    int sum=0;
    while(ss!=s.end()){
        if(*ss=='I'){
            switch (*(ss+1))
            {
                case 'V':
                    sum+=4;
                    ss=ss+2;
                    break;
                case 'X':
                    sum+=9;
                    ss=ss+2; 
                    break;           
                default:
                    sum+=1;
                    ss=ss+1;
                    break;
            }
        }else if(*ss=='X'){
            switch (*(ss+1))
            {
                case 'L':
                    sum+=40;
                    ss=ss+2;
                    break;
                case 'C':
                    sum+=90;
                    ss=ss+2;
                    break;            
                default:
                    sum+=10;
                    ss=ss+1;
                    break;
            }
        }else if(*ss=='C'){
            switch (*(ss+1))
            {
                case 'D':
                    sum+=400;
                    ss=ss+2;
                    break;
                case 'M':
                    sum+=900;
                    ss=ss+2;  
                    break;          
                default:
                    sum+=100;
                    ss=ss+1;
                    break;
            }
        }else if(*ss=='V'){
            sum+=5;
            ss++;
        }else if(*ss=='L'){
            sum+=50;
            ss++;
        }else if(*ss=='D'){
            sum+=500;
            ss++;
        }else if(*ss=='M'){
            sum+=1000;
            ss++;
        }
    }   
    return sum; 
    }
    /*
    最长公共前缀
    思路：首先使用stl中的sort方法将vector中的字符串按照长度大小从小到大排列
    将第一个字符串也就是最短的字符串当作比较的对象，一个while循环遍历这个字符串
    另一个for循环遍历vector对象，如果发现有相同下标的值不相同即break退出
    否则就继续遍历
    */
    string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(),strs.end(),[](string &a, string &b){  
    return a.size() < b.size();  
});
    string s1=strs[0];
    int i=0;
    int j=0;
    while(i!=s1.size()){
        bool flag=1;
        for(j=0;j!=strs.size();j++){
            if(strs[j][i]!=s1[i]){
                flag=0;
                break;
            }
            if(flag==0){
            break;}
        }
       if(flag==0){
            break;}
            else{
                i++;
            }
    }
    //cout<<i<<endl;
    string ss="";
    for(int k=0;k<i;k++){
        ss+=s1[k];
    }
    return ss;
    }
};
int main(){
    Solution s;
    vector<string> v1={"dog","docecar","dor"};
    cout<<s.longestCommonPrefix(v1);
    return 0;
}