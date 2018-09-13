#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//问题：设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
//如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
//如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
//思路：使用sort函数和一个排序判断lambda表达式，判断s1+s2与s2+s1拼接字符串谁更大
string shuchuan(){
int n;
    cin>>n;
    vector<string> v1;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        v1.push_back(x);
    }
    sort(v1.begin(),v1.end(),[](string s1, string s2){
        return (s1+s2) > (s2+s1);
    });
    string s="";
    for(auto v:v1){
        s+=v;
    }
    return s;
}
// 现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
// 思路：使用两个vector分别保存节点高度和节点子节点数量
int height_of_tree(){
    int n,H = 1;
    int i = 0;
    int f,c, h;
    vector<int> nodes(1000, 0);    //有效节点的高度
    nodes[0] = 1; // 题目说了至少有一个节点，高度只是是1
    vector<int> childnum(1000, 0); //记录节点的孩子数量
    cin >> n;
    while(--n){
        cin >> f >> c;
        //父节点不存在 或者 父节点已有两个子节点 就跳过
        if(nodes[f]==0 || childnum[f] == 2)
            continue;
        childnum[f] += 1;
        h = nodes[f] + 1;
        nodes[c] = h;
        if(h > H) H = h;
    }
    return H;
}
// 给定一个句子（只包含字母和空格）， 将句子中的单词位置反转，单词用空格分割, 单词之间只有一个空格，前后没有空格。
//比如： （1） “hello xiao mi”-> “mi xiao hello”
//思路：使用geline得到整行的输入，然后使用find方法找到每一个空格，将字符串存入一个vector中，然后reverse这个vector
//最后将vector中的个元素拼接在一起，最后的最后需要将末尾的空格删除。
string reverse_string(){
    vector<string> v;
    string s;
    getline(cin,s);
    auto y=find(s.begin(),s.end(),' ');
    auto x=s.begin();
    while(y!=s.end()){
        string ss(x,y);
        v.push_back(ss);
        x=y+1;y=find(x,s.end(),' ');
    }
    string ss(x,s.end());
    v.push_back(ss);
    reverse(v.begin(),v.end());
    string sss="";
    for(auto ss:v){
        sss=sss+ss+" ";
    }
    sss.erase(sss.end()-1,sss.end());
    return sss;
}
//继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，
//然后使用对应的大写字母代替 （"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"）， 
//然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。
//思路：观察每个大写字母中特有的字符，然后根据这些字符算出这些大写字母的数量，然后再根据其它共有的字符算出其它大写字母的数量，然后在减去8得到原来数字
//最后将每个数字组合使用sort函数从小到大排序即可
vector<vector<int>> phone_number_transform(){
    int n;
    vector<string> v1;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        v1.push_back(s);
    }
    vector<vector<int>> sum;
    for(auto v:v1){
       vector<int> vv;
       auto zero=count(v.begin(),v.end(),'Z');//the number of zero
       auto zero_1=zero;
       while((zero_1--)>0){
           vv.push_back(2);
       }
       auto eight=count(v.begin(),v.end(),'G');//the number of eight
       auto eight_1=eight;
       while((eight_1--)>0){
           vv.push_back(0);
       }
       auto six=count(v.begin(),v.end(),'X');//the number of six
       auto six_1=six;
       while((six_1--)>0){
           vv.push_back(8);
       }
       auto seven=count(v.begin(),v.end(),'S')-six;//the number of seven
       auto seven_1=seven;
       while((seven_1--)>0){
           vv.push_back(9);
       }
       auto five=count(v.begin(),v.end(),'V')-seven;//the number of five
       auto five_1=five;
       while((five_1--)>0){
           vv.push_back(7);
       }
       auto four=count(v.begin(),v.end(),'F')-five;//the number of four;
       auto four_1=four;
       while((four_1--)>0){
           vv.push_back(6);
       }
        auto two=count(v.begin(),v.end(),'W');//the number of two
        auto two_1=two;
        while((two_1--)>0){
           vv.push_back(4);
       }
        auto three=count(v.begin(),v.end(),'T')-two-eight;//the number of three;
        auto three_1=three;
        while((three_1--)>0){
           vv.push_back(5);
       }
        auto nine=count(v.begin(),v.end(),'I')-five-six-eight;//the number of nine
        auto nine_1=nine;
        while((nine_1--)>0){
           vv.push_back(1);
       }
        auto one=count(v.begin(),v.end(),'O')-zero-two-four;//the number of one
        auto one_1=one;
        //cout<<zero<<" "<<two<<" "<<four<<endl;
        while((one_1--)>0){
           vv.push_back(3);
       }
    sort(vv.begin(),vv.end());
    sum.push_back(vv);
    }
    return sum;
}
int main(){
    auto s=phone_number_transform();
    for(auto ss:s){
    for(auto sss:ss){
        cout<<sss;
    }
    cout<<endl;
    }
    return 0;
}