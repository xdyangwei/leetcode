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
    //一个while循环遍历两个链表，然后再从大到小新建一个新的合并后的列表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         int min;
        if(l1==NULL&&l2==NULL){
            return NULL;
        }else if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }else{
        if(l1->val>=l2->val){
            min=l2->val;
            l2=l2->next;
        }else{
            min=l1->val;;
            l1=l1->next; 
        }
        ListNode* l3=new ListNode(min);
        auto l4=l3;
        while(l1!=NULL&&l2!=NULL){
                if(l1->val<=l2->val){  
                    l3->next=l1;
                    l1=l1->next;
                }else{
                    l3->next=l2;
                    l2=l2->next;
                }  
                l3=l3->next;  
                }
            if(l1==NULL){
                l3->next=l2;
            }else{
                l3->next=l1;
            }
        
        return l4;
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
    //数组中移除给定的元素值
    //思路：排序完后使用find找到这个值的第一个位置，count找到有多少个，然后全部erase掉
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(),nums.end());
    auto x=find(nums.begin(),nums.end(),val);
    auto y=count(x,nums.end(),val);
    nums.erase(x,x+y);
    return nums.size();
    }
    //返回一个字符串在另一个字符串中第一次出现的位置
    //思路：当needle为空字符时，返回0，else直接使用STL中的find方法
    int strStr(string haystack, string needle) {
        if(needle==""){
            return 0;
        }else{
        auto x=haystack.find(needle);
        if(x==string::npos){
            return -1;
        }else{
            return x;
        }
        }
    }
    //查询有序数组中的一个数值，若存在返回其索引，若不存在将其按顺序插入并返回索引
    //思路：find方法查询数值，若迭代器不为end，则用当前迭代器减去begin即为下标
    //若迭代器为end，则插入，使用for循环方法找到第一个比target大的值，然后插入起前面
    bool compare(int a,int target){
        return a>target?true:false;
    }
    int searchInsert(vector<int>& nums, int target) {
        auto x=find(nums.begin(),nums.end(),target);
        if(x!=nums.end()){
            return x-nums.begin();
        }else{
            //auto y=0;
            // for(y=0;y<nums.size();y++){
            //     if(nums[y]>target)
            //     break;
            // }
            // nums.insert(nums.begin()+y,target);
            auto y=find_if(nums.begin(),nums.end(),bind2nd(compare,target));
            
            return y;
        }
    }
};
int main(){
    ListNode *l1=new ListNode(1);ListNode *l2=new ListNode(2);ListNode *l3=new ListNode(3);ListNode *l4=new ListNode(1);ListNode *l5=new ListNode(5);ListNode *l6=new ListNode(6);
    l1->next=l2;l2->next=l3;
    l4->next=l5;;l5->next=l6;
    Solution s;
    ListNode* ll=s.mergeTwoLists(l1,l4);
    while(ll!=NULL){
        cout<<ll->val<<endl;
        ll=ll->next;
    }
}
 
