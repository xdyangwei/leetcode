#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

//递归中序遍历二叉树
vector<int> results;
void inorderTraversal_recursive(TreeNode* root) {
        if(!root)
            return ;
        if(root->left){
            inorderTraversal_recursive(root->left);
        }
        results.push_back(root->val);
        if(root->right){
            inorderTraversal_recursive(root->right);
        }
    }

//非递归中序遍历二叉树版本1
vector<int> inorderTraversal_1(TreeNode* root) {
    if(!root)
        return vector<int>();
    stack<TreeNode*> s1;
    s1.push(root);
    vector<int> v;
    while(!s1.empty()){
        auto p=s1.top();
        while(p){
            s1.push(p->left);
            p=p->left;
        }
        s1.pop();
        //cout<<p->val<<" "<<s1.size()<<endl;
        if(!s1.empty()){
        auto p=s1.top();s1.pop();
        v.push_back(p->val);
        s1.push(p->right);
        }
    }
    return v;
    }

//非递归中序遍历版本2
vector<int> inorderTraversal_2(TreeNode* root){
    if(!root)
    return vector<int>();
    stack<TreeNode*> s;
    vector<int> v;
    while(root){
    s.push(root);
    root=root->left;
    }
    while(!s.empty()){
        auto p=s.top();
        v.push_back(p->val);
        s.pop();
        auto p1=p->right;
        while(p1){
        s.push(p1);
        p1=p1->left;
        }
    }
    return v;
}



int main(){
    auto x=new TreeNode(1);
    x->left=nullptr;x->right=new TreeNode(2);x->right->left=new TreeNode(3);
    auto result=inorderTraversal_2(x);
    for(auto xx:result)
    cout<<xx<<endl;
}