#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
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

//根据一棵树的中序遍历与后序遍历构造二叉树。
//假设树中没有重复的元素
//先由后序遍历得到根节点的值，然后得到左子树和右子树范围，使用递归返回根节点的左子节点和右子节点
TreeNode *buildTree(vector<int> inorder, vector<int> postorder)
{
    if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
        return nullptr;
    auto root = new TreeNode(postorder[postorder.size() - 1]);
    auto it = find(inorder.begin(), inorder.end(), root->val);
    if (it != inorder.begin() && it != inorder.end() - 1)
    {
        vector<int> vv(inorder.begin(), it);
        auto it1 = find(postorder.begin(), postorder.end(), *(it - 1));
        for (auto xx : vv)
        {
            auto it2 = find(postorder.begin(), postorder.end(), xx);
            if (it2 > it1)
                it1 = it2;
        }
        root->left = buildTree(vector<int>(inorder.begin(), it), vector<int>(postorder.begin(), it1 + 1));
        root->right = buildTree(vector<int>(it + 1, inorder.end()), vector<int>(it1 + 1, postorder.end() - 1));
    }
    else if (it == inorder.begin())
    {
        root->left = nullptr;
        root->right = buildTree(vector<int>(it + 1, inorder.end()), vector<int>(postorder.begin(), postorder.end() - 1));
    }
    else
    {
        root->right = nullptr;
        root->left = buildTree(vector<int>(inorder.begin(), inorder.end() - 1), vector<int>(postorder.begin(), postorder.end() - 1));
    }
    return root;
}

//求根到叶子节点数字之和
//使用DFS递归求解
int DFS(TreeNode *root, int sum)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 10 * sum + root->val;
    else
        return DFS(root->left, 10 * sum + root->val) + DFS(root->right, 10 * sum + root->val);
}

int sumNumbers(TreeNode *root)
{
    return DFS(root, 0);
}

//二叉树的最大深度
//使用递归
int Dfs_height(TreeNode *root)
{
    if (!root)
        return 0;
    return max(Dfs_height(root->left), Dfs_height(root->right)) + 1;
}

int maxDepth(TreeNode *root)
{
    return Dfs_height(root);
}

//二叉树展开为链表
//首先进行前序遍历将节点放入一个数组中，然后令前一个节点的右节点指向下一个节点
vector<TreeNode *> results1;
void preorder_traversal(TreeNode *root)
{
    results1.push_back(root);
    if (root->left)
        preorder_traversal(root->left);
    if (root->right)
        preorder_traversal(root->right);
}

void flatten(TreeNode *root)
{
    preorder_traversal(root);
    for (int i = 0; i < results1.size() - 1; i++)
    {
        auto xx = results1[i];
        xx->left = nullptr;
        xx->right = results1[i + 1];
    }
    results1[results1.size() - 1]->right = nullptr;
}

//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，
//这条路径上所有节点值相加等于目标和。
//使用递归判断
bool hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
    {
        if (sum == root->val)
            return true;
        else
            return false;
    }
    else
    {
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
}

//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
//使用DFS找出所有路径，然后筛选出满足条件的即可
vector<vector<int>> v2;
void path(vector<int> &v, TreeNode *root)
{
    if (!root)
    {
        v.pop_back();
        return;
    }
    if (!root->left && !root->right)
    {
        v.push_back(root->val);
        v2.push_back(v);
        return;
    }
    if (root->left || root->right)
    {
        v.push_back(root->val);
        if (root->left)
        {
            path(v, root->left);
            if (!v.empty())
                v.pop_back();
        }
        if (root->right)
        {
            path(v, root->right);
            v.pop_back();
        }
    }
}
vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    if (!root)
        return vector<vector<int>>();
    vector<int> v;
    path(v, root);
    vector<vector<int>> vv;
    for (auto xx : v2)
    {
        if (accumulate(xx.begin(), xx.end(), 0) == sum)
            vv.push_back(xx);
    }
    return vv;
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