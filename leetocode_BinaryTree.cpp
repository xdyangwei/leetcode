#include <iostream>
#include <vector>
#include <stack>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> results;

//递归中序遍历二叉树

void inorderTraversal_recursive(TreeNode *root)
{
    if (!root)
        return;
    if (root->left)
    {
        inorderTraversal_recursive(root->left);
    }
    results.push_back(root->val);
    if (root->right)
    {
        inorderTraversal_recursive(root->right);
    }
}

//非递归中序遍历二叉树版本1
vector<int> inorderTraversal_1(TreeNode *root)
{
    if (!root)
        return vector<int>();
    stack<TreeNode *> s1;
    s1.push(root);
    vector<int> v;
    while (!s1.empty())
    {
        auto p = s1.top();
        while (p)
        {
            s1.push(p->left);
            p = p->left;
        }
        s1.pop();
        //cout<<p->val<<" "<<s1.size()<<endl;
        if (!s1.empty())
        {
            auto p = s1.top();
            s1.pop();
            v.push_back(p->val);
            s1.push(p->right);
        }
    }
    return v;
}

//非递归中序遍历版本2
vector<int> inorderTraversal_2(TreeNode *root)
{
    if (!root)
        return vector<int>();
    stack<TreeNode *> s;
    vector<int> v;
    while (root)
    {
        s.push(root);
        root = root->left;
    }
    while (!s.empty())
    {
        auto p = s.top();
        v.push_back(p->val);
        s.pop();
        auto p1 = p->right;
        while (p1)
        {
            s.push(p1);
            p1 = p1->left;
        }
    }
    return v;
}

//递归版本的前序遍历
void preorderTraversal_recursive(TreeNode *root)
{
    if (!root)
        return;
    results.push_back(root->val);
    if (root->left)
        preorderTraversal_recursive(root->left);
    if (root->right)
        preorderTraversal_recursive(root->right);
}

//非递归版本的前序遍历，使用栈
//出栈，然后将右节点和左节点依次入栈，出栈即为先左后右
vector<int> preorderTraversal(TreeNode *root)
{
    if (!root)
        return vector<int>();
    stack<TreeNode *> s;
    vector<int> v;
    s.push(root);
    while (!s.empty())
    {
        auto p = s.top();
        s.pop();
        v.push_back(p->val);
        if (p->right)
            s.push(p->right);
        if (p->left)
            s.push(p->left);
    }
    return v;
}

//重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.empty() || vin.empty() || pre.size() != vin.size())
        return nullptr;
    auto head = new TreeNode(pre[0]);
    auto it = find(vin.begin(), vin.end(), pre[0]);
    int size1 = it - vin.begin();
    vector<int> vin1(vin.begin(), it);
    vector<int> pre1(pre.begin() + 1, pre.begin() + size1 + 1);
    head->left = reConstructBinaryTree(pre1, vin1);
    head->right = reConstructBinaryTree(vector<int>(pre.begin() + size1 + 1, pre.end()), vector<int>(it + 1, vin.end()));
    return head;
}

//求根到叶子节点数字之和
//使用DFS递归求解
int DFS(TreeNode* root,int sum){
    if(!root)
    return 0;
    if(!root->left&&!root->right)
    return 10*sum+root->val;
    else
    return DFS(root->left,10*sum+root->val)+DFS(root->right,10*sum+root->val);
}

int sumNumbers(TreeNode *root)
{
    return DFS(root,0);
}

//二叉树的最大深度
//使用递归
int Dfs_height(TreeNode* root){
    if(!root)
    return 0;
    return max(Dfs_height(root->left),Dfs_height(root->right))+1;
}

int maxDepth(TreeNode* root) {
    return  Dfs_height(root);     
}

//二叉树展开为链表
//首先进行前序遍历将节点放入一个数组中，然后令前一个节点的右节点指向下一个节点
vector<TreeNode*> results1;
void preorder_traversal(TreeNode* root){
    results1.push_back(root);
    if(root->left)
    preorder_traversal(root->left);
    if(root->right)
    preorder_traversal(root->right);
}

void flatten(TreeNode* root) {
    preorder_traversal(root);
    for(int i=0;i<results1.size()-1;i++){
        auto xx=results1[i];
        xx->left=nullptr;xx->right=results1[i+1];
    }
    results1[results1.size()-1]->right=nullptr;
}

int main()
{
    auto x = new TreeNode(1);
    x->left = nullptr;
    x->right = new TreeNode(2);
    x->right->left = new TreeNode(3);
    auto result = preorderTraversal(x);
    for (auto xx : result)
        cout << xx << endl;
}