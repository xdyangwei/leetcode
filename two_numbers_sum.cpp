#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
思路：遍历数组，使用目标值减去当前遍历值，再使用std中的find方法找到即可
find方法找到的是iterator，此时利用*取出此值，然后再一次for循环找出下标值
*/

//Definition for a binary tree node.
      struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<vector<int>::iterator> v1;
        vector<int> v2;
      for(auto num:nums){
          auto s=target-num;
          if(find(nums.begin(),nums.end(),s)!=nums.end()){
              v1.push_back(find(nums.begin(),nums.end(),s));
              v1.push_back(find(nums.begin(),nums.end(),num));
              cout<<*v1[0]<<" "<<*v1[1]<<endl;
              break;
          }
      }
    for(int i=0;i<=nums.size();i++){
        if(nums[i]==*v1[0]||nums[i]==*v1[1]){
            v2.push_back(i);
        }
    }
    //cout<<v2[0]<<" "<<v2[1]<<endl;
    return v2;
    }
    //问题：将字符串中大写字母变为小写
    //思路：遍历字符串中每个元素然后判断如果为大写字母则ascii码+32转换为小写字母
    string toLowerCase(string str) {
     for(auto &s:str){
         if(s>='A'&&s<='Z'){
             s+=32;
         }
     }
     return str;
    }
    //问题：将二叉树中的左叶子节点的值相加
    //思路：使用递归法，当前节点的左孩子如果是叶子节点的话就直接将它的值相加然后再遍历当前节点右孩子
    //如果不是叶子节点那就再遍历下去直到叶子节点，如果当前节点为空的话就加0
    int sumOfLeftLeaves(TreeNode* root) {
    if(root == NULL)
    return 0;
    if(root->left != NULL)
    {
    if(root->left->left == NULL && root->left->right == NULL)
    return root->left->val + sumOfLeftLeaves(root->right);
    else
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    else
    return sumOfLeftLeaves(root->right);
    }
    //问题：根据年龄发朋友请求
    //思路：遍历所给数组，从第一个数开始判断条件是否吻合，吻合则不做朋友，不吻合则做朋友，做朋友的话将两个年龄放入一个map中，最后计算map中的数量即可
    int numFriendRequests(vector<int>& ages) {
         int c[121]={0};
        for(auto age:ages)
        c[age]++;
        sort(ages.begin(),ages.end());
        ages.erase(unique(ages.begin(),ages.end()),ages.end());
        if(ages.size()==1){
            return c[ages[0]];
        }
        multimap<int,int> m;
        for(auto x=ages.begin();x!=ages.end();x++){
           for(auto y=ages.begin();y!=ages.end();y++){
               int flag=0;
               if(*y<=0.5*(*x)+7||*y>*x||(*y>100&&*x<100))
               flag=1;
               if(flag==0&&x!=y){
               m.insert(make_pair(*x,*y));
               cout<<*x<<" "<<*y<<endl;
               }
           }
        }
        int sum=0;
        for(auto mm:m){
            sum+=(c[mm.first]);
        }
        for(int i=0;i<120;i++){
            sum+=c[i];
        }
        return sum;
    }
};
int main(){
    vector<int> nums={2,7,11,15};
    string str="ABc";
    Solution s;
    str=s.toLowerCase(str);
    cout<<str<<endl;
    return 0;
}