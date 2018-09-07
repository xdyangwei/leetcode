#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
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
    //思路：遍历所给数组，使用关联容器存储值和值的个数
    //然后使用两次for循环遍历关联容器判断key是否满足条件，如果满足的话就将两者的个数相乘，如果二者key相同，则相乘的时候减去1即可
    int numFriendRequests(vector<int>& ages) {
          unordered_map<int,int>m;
        for(auto i: ages)
            m[i]++;
        int res = 0;
        for(auto i1: m){
            for(auto i2: m){
                if((i2.first <= i1.first && i2.first>i1.first*0.5 + 7)){
                    res += i2.second*(i1.second - (i1.first == i2.first ? 1:0));
                }
            }
        }
        return res;
    }
};
int main(){
    vector<int> nums={56,117,42,55,100,27,97,113,56,57,117,13,42,119,67};
    string str="ABc";
    Solution s;
    int a=s.numFriendRequests(nums);
    cout<<a<<endl;
    return 0;
}