//
// Created by xuyou on 19-3-28.
//
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void sum_recursive(TreeNode*root,int val,int &res){
    if(!root)
        return;
    int curval;
    curval=val*10+root->val;
    if(!root->left&&!root->right) {
        res += curval;
        return;
    }
    if(root->left)
        sum_recursive(root->left,curval,res);
    if(root->right)
        sum_recursive(root->right,curval,res);
}
int sumNumbers(TreeNode* root) {
    int res=0;
    sum_recursive(root,0,res);
    return res;
}
int main(){
    TreeNode *a=new TreeNode(1);
    TreeNode *b=new TreeNode(5);
    TreeNode *c=new TreeNode(4);
    TreeNode *d=new TreeNode(3);
    a->left=b;a->right=c,c->right=d;
    int res=sumNumbers(a);
    return 0;
}
