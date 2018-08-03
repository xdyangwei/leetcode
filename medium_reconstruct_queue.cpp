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
    };

int main(){
    Solution s;
    vector<int> v={-2147483647,2147483647};
    cout<<s.containsNearbyAlmostDuplicate(v,1,2147483647);
    return 0;
}