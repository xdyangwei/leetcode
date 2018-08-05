#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<cmath>
using namespace std;
class Solution {
public:
   //重建身高队列，vector里元素为pair类型，由身高和排在他前面身高不低于它的人数组成
   //思路：找出身高最高的，然后根据排在他前面的人数就可知它的位置，接着再使用insert插入后续身高低的
   //之前已插入元素会自动往后移
    static bool mycompare(pair<int,int>p1,pair<int,int>p2){
        if(p1.first==p2.first)return p1.second<p2.second;
        return p1.first>p2.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),mycompare);
        for(auto s:people)
        cout<<s.first<<" "<<s.second<<endl;
        vector<pair<int,int>>ans;
        //insert in the apt position in another vector
	//If k=2 this means that you should insert at second position
        for(int i=0;i<people.size();i++) ans.insert(ans.begin()+people[i].second,people[i]);
	// vector.insert(poition of iterator,value)
        return ans;
    }

    //存在重复元素，给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，
    //使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。
    //思路：遍历整个数组，每个遍历值与他相邻k个位置之间的值求差的绝对值，若存在则为true
    static bool notfu(int x){
        return x<0?true:false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        bool flag=false;
        if(nums.size()<=1){
            return flag;
        }else{
            if(nums.size()<=k){
                for(int i=0;i<nums.size();i++){
                    for(int j=0;j<nums.size();j++){
                        if(abs(nums[i]-nums[j])<=t&&i!=j){
                            flag=true;
                        }
                    }
                }
                }else{
                   for(int i=0;i<nums.size();i++){
                       for(int j=1;j<=k;j++){
                           if((i+j)<nums.size()){
                               if(find(nums.begin(),nums.end(),2147483647)!=nums.end()){
                                if(find_if(nums.begin(),nums.end(),notfu)!=nums.end()){
                                    flag=false;
                                }else{
                                    flag=true;
                                }
                               }else{
                               if(abs(nums[i]-nums[j+i])<=t){
                                   cout<<abs(nums[i]-nums[j+i])<<endl;
                               flag=true;}
                           }
                           }
                       }
                   } 
                }
            }
            return flag;
        }
        //实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
        //如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
        //必须原地修改，只允许使用额外常数空间。
        //思路1：使用STL中的next_permutation函数找出数组的下个排列，若函数返回值为false表示已为最大排列
        //因此，此时直接使用sort函数即可
        //思路2：从后往前遍历数组找到第一个比后面一个数小的数，如果不存在这说明已是最大排列，sort一下即可。如果下标
        //大于0，则再次从后往前遍历数组找到第一个比当前值大的值，将其交换，然后再将当前值以后的数组部分sort即可   
        void nextPermutation(vector<int>& nums) {
        bool x=next_permutation(nums.begin(),nums.end());
        if(x==false)
        sort(nums.begin(),nums.end());
    }
    };

int main(){
    Solution s;
    vector<int> v={-2147483647,2147483647};
    cout<<s.containsNearbyAlmostDuplicate(v,1,2147483647);
    return 0;
}