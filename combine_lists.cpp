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
};