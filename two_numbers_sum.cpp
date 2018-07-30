#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
思路：遍历数组，使用目标值减去当前遍历值，再使用std中的find方法找到即可
find方法找到的是iterator，此时利用*取出此值，然后再一次for循环找出下标值
*/
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
};
int main(){
    vector<int> nums={2,7,11,15};
    Solution s;
    s.twoSum(nums,9);
    return 0;
}