#include<iostream>
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
    return 0;
}