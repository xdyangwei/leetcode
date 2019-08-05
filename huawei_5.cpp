#include<iostream>
#include<string>
using namespace std;
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
int main(){
    str_match();
    return 0;
}