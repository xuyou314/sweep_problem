//
// Created by xuyou on 19-4-15.
//
#include <iostream>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if(!root||(!root->left&&!root->right))
        return;
    if(root->left)
        flatten(root->left);
    if(root->right)
        flatten(root->right);
    TreeNode*tail=NULL;
    if(root->left){
        tail=root->left;
        while(tail->right)
            tail=tail->right;
    }
    if(tail) {
        tail->right=root->right;
        root->right = root->left;
        root->left=NULL;
    }
}
void flatten1(TreeNode* root,TreeNode*&pre) {
    if(pre!=root){
        pre->left=NULL;
        pre->right=root;
        pre=root;
    }
    if(root->left)
    flatten1(root->left,pre);
    if(root->right)
    flatten1(root->right,pre);
    return;
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
    return 0;
}