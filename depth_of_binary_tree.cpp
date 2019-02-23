#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    if(!pRoot) return 0 ;
            return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
    }
};
int main(){
    TreeNode n1(1);TreeNode n2(2);TreeNode n3(3);TreeNode n4(4);
    TreeNode* s1=&n1;
    s1->left=&n2;s1->right=&n3;
   // s1->left->right=&n4;
    Solution s;
    cout<<s.TreeDepth(s1)<<endl;
}