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
void max_to_end_sum(TreeNode *root,int &max,int curval){
    if(root==NULL)
        return;
    int nval=root->val+curval;
    max=max>nval?max:nval;
    if(root->left)
        max_to_end_sum(root->left,max,nval);
    if(root->right)
        max_to_end_sum(root->right,max,nval);
}

int max_to_two_end(TreeNode* root) {
    if(!root)
        return 0;
    int val=root->val;
    int leftval=0,rightval=0;
    max_to_end_sum(root->left,leftval,0);
    max_to_end_sum(root->right,rightval,0);
    return val+leftval+rightval;
}
void max_to_two_end_recursive(TreeNode*root,int &max){
    int curval=max_to_two_end(root);
    max=max>curval?max:curval;
    if(root->left)
        max_to_two_end_recursive(root->left,max);
    if(root->right)
        max_to_two_end_recursive(root->right,max);
}
int maximum_to_edge(TreeNode*root,int &max){
    int val=root->val,l=0,r=0,res=root->val;
    if(root->left)
        l=maximum_to_edge(root->left,max);
    if(root->right)
        r=maximum_to_edge(root->right,max);
    if(l>0)
        val+=l;
    if(r>0)
        val+=r;
    max=max>val?max:val;
    if(l>0&&l>r)
        return l+res;
    if(r>0&&r>l)
        return r+res;
    return res;
}
int maxPathSum(TreeNode* root) {
    int res=-9999;
    maximum_to_edge(root,res);
    return res;
}
void test(int *a){
    *a=5;
}
int main(){
    TreeNode *a=new TreeNode(10);
    TreeNode *b=new TreeNode(9);
    TreeNode *c=new TreeNode(20);
    TreeNode *d=new TreeNode(15);
    TreeNode *e=new TreeNode(7);
    a->left=b;a->right=c;c->left=d;c->right=e;
    int t,max=-999;
    //maximum_to_edge(a,max);
    //test(&t);
    //cout<<t<<endl;
    //int res=max_to_two_end(a);
    int res=maxPathSum(a);
    return 0;

}
