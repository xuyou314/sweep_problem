//
// Created by xuyou on 19-4-17.
//

#include <iostream>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int mostdeep(TreeNode*root,int &max){
    int l=-1,r=-1;
    if(!root||(!root->left&&!root->right))
        return 0;
    if(root->left)
        l=mostdeep(root->left,max);
    if(root->right)
        r=mostdeep(root->right,max);
    if(max<l+r+2)
        max=l+r+2;
     if(l>r)
         return l+1;
     else
         return r+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int res=0;
    mostdeep(root,res);
    return res;
}
TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return root;
    TreeNode*temp=root->right;
    if(root->left)
        root->right=invertTree(root->left);
    else{
        root->right=NULL;
    }
    if(temp)
        root->left=invertTree(temp);
    else{
        root->left=NULL;
    }
    return root;
}
int main(){
    TreeNode*a=new TreeNode(5);
    TreeNode*b=new TreeNode(4);
    TreeNode*c=new TreeNode(3);
    TreeNode*d=new TreeNode(6);
    a->right=c;
    a->left=b;
    c->left=d;
    TreeNode *res=invertTree(c);
    return 0;
}