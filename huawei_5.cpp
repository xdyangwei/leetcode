#include<iostream>
#include<string>
#include<vector>
using namespace std;

//字符串匹配，判断短字符串中的字符是否都在长字符串中
void str_match(){
    string short_str,long_str;
    while(cin>>short_str>>long_str){
        bool flag=true;
        for(auto ss:short_str){
            if(long_str.find(ss)==string::npos)
                flag=false;
        }
        if(flag==true)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
}

//真分数分解为埃及分数，埃及分数：分子为1的分数
void pcRealFraction(){
    char ch;
    int a, b;
    while (cin >> a >> ch >> b)
    {
        while (a != 1){
            if (b % (a - 1) == 0){
                cout << 1 << "/" << b / (a - 1) << "+";
                a = 1;
            }
            else{
                int c;
                c = b / a + 1;
                a = a - b%a;
                b = b*c;
                cout << 1 << "/" << c << "+";
                if (b%a == 0){
                    b = b / a;
                    a = 1;
                }
            }
        }
        cout << 1 << "/" << b << endl;
    }
}

//统计大写字母个数
void CalcCapital(){
    string str;
    while(cin>>str){
        int Count=0;
        for(auto ss:str){
            if(ss>='A'&&ss<='Z')
            Count+=1;
        }
        cout<<Count<<endl;
    }
}

//密码截取
void max_passwd(){
    string str;
    while(cin>>str){
        int Max=1;vector<int> v(str.size(),1);
        
    }
}

int main(){
    CalcCapital();
    return 0;
}