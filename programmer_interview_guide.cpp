//程序员代码面试指南
#include<iostream>
#include<vector>
using namespace std;
void find_specific_number_in_matrix(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> v;
    int n1=n;
    while(n1--){
        int m1=m;
        vector<int> v1;
        while(m1--){
            int x;
            cin>>x;v1.push_back(x);
        }
        v.push_back(v1);
    }
    bool flag=false;int start=0,end=m-1;
    for(int i=0;i<n;){
        for(int j=m-1;j>=0;){
            if(v[i][j]==k){
                flag=true;break;
            }else if(v[i][j]>k){
                j--;
            }else{
                break;
            }
        }
        if(flag==true)
            break;
        else
        {
            i++;
        } 
    }
    if(flag)
    cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
}
int main(){
    find_specific_number_in_matrix();
    return 0;
}