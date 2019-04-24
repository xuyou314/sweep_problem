//
// Created by xuyou on 19-4-16.
//
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void preorder(TreeNode*root,int &sum){
    if(!root)
        return;
    if(root->left){
        if(!(root->left->right)&&!(root->left->left)){
            sum+=root->left->val;
        } else
            preorder(root->left,sum);
    }
    if(root->right){
        preorder(root->right,sum);
    }
}

int main(){
    TreeNode*a=new TreeNode(5);
    TreeNode*b=new TreeNode(4);
    TreeNode*c=new TreeNode(3);
    TreeNode*d=new TreeNode(6);
    a->right=c;
    a->left=b;
    c->left=d;
    int sum=0;
    preorder(a,sum);
    return 0;
}