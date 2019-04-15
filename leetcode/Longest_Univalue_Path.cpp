//
// Created by xuyou on 19-3-28.
//

//
// Created by xuyou on 19-3-27.
//
#include<iostream>
using namespace std;
struct TreeNode{
    TreeNode*left,*right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL) {};
};
int oneside_longest(TreeNode *root,int &max){
    if(root==NULL)
        return 0;
    int l=0,r=0;
    if(root->left){
        l=oneside_longest(root->left,max);
    }
    if(root->left&&root->left->val!=root->val)
        l=0;
    if(root->right){
        r=oneside_longest(root->right,max);
    }
    if(root->right&&root->right->val!=root->val)
        r=0;
    max=l+r+1>max?l+r+1:max;
    if(l>r)
        return l+1;
    else
        return r+1;
}
int longestUnivaluePath(TreeNode* root) {
    int max=1;
    oneside_longest(root,max);
    return max-1;
}
int main(){
    TreeNode *a=new TreeNode(1);
    TreeNode *b=new TreeNode(4);
    TreeNode *c=new TreeNode(5);
    TreeNode *d=new TreeNode(5);
    TreeNode *e=new TreeNode(5);
    a->left=b;a->right=c;c->left=d;c->right=e;
    int t,max=-999;
    int res=longestUnivaluePath(a);
    return 0;

}
