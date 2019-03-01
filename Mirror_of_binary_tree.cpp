#include <iostream>
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
void Mirror(TreeNode *pRoot) {
while(pRoot!=NULL){
    auto x=pRoot->left;
    pRoot->left=pRoot->right;
    pRoot->right=x;
}
}
int main(){
    int i=1,j=2;
    int *p=&i;
    auto x=p;
    p=&j;
    cout<<*x<<endl;
}
