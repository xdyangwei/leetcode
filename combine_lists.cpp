#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    //两个有序链表合并
    //两个for循环遍历两个链表，然后再从大到小新建一个新的合并后的列表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3;
        if(l1->val>=l2->val){
            l3->val=l2->val;
            l2=l2->next;
        }else{
            l3->val=l1->val;;
           l1=l1->next; 
        }
        while(l1!=NULL){
            while(l2!=NULL){
                if(l1->val<=l2->val){
                    l3->next=l1;
                    l1=l1->next;
                }else{
                    l3->next=l2;
                    l2=l2->next;
                }
            }
        }
    }
//去除一个数组中的重复的数值
//思路一：使用std中的unique函数，然后再把重复的部分erase掉
    int removeDuplicates(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
    //思路二：使用sort排序后，遍历整个数组，使用find和count函数找到第一次和此数出现的此数，把
    //第一次出现的迭代器加1，再把两者之间的数都erase掉即可
    int removeDuplicates2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto i=nums.begin();
        //cout<<*i<<endl;
        while(i!=nums.end()){
            auto x=find(nums.begin(),nums.end(),*i);
            cout<<*x<<endl;
            auto y=count(nums.begin(),nums.end(),*i);
            cout<<y<<endl;
            nums.erase(x,x+y-1);
            
            i++;
        }
        return nums.size();
    }
};
int main(){
    Solution s;
    vector<int> v1={1,1,2};
    cout<<s.removeDuplicates2(v1)<<endl;
    return 0;
}