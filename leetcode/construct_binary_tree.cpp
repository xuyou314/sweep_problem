//
// Created by xuyou on 19-4-25.
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
TreeNode* build(vector<int>& preorder, int low1,int high1,int low2,int high2,vector<int>& inorder) {
    if(low1>high1)
        return NULL;
    TreeNode*root=new TreeNode(preorder[low1]);
    int id2=low2;
    while(inorder[id2]!=preorder[low1])
        id2++;
    root->left=build(preorder,low1+1,low1+id2-low2,low2,id2-1,inorder);
    root->right=build(preorder,low1+id2-low2+1,high1,id2+1,high2,inorder);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size()==0)
        return NULL;
    TreeNode*root=build(preorder,0,preorder.size()-1,0,inorder.size()-1,inorder);
    return root;
}
TreeNode* build2(vector<int>& inorder, int low1,int high1,int low2,int high2,vector<int>& postorder) {
    if(low1>high1)
        return NULL;
    TreeNode*root=new TreeNode(postorder[high2]);
    int id2=low1;
    while(inorder[id2]!=postorder[high2])
        id2++;
    root->left=build2(inorder,low1,id2-1,low2,low2+id2-1-low1,postorder);
    root->right=build2(inorder,id2+1,high1,high2-high1+id2,high2-1,postorder);
    return root;
}
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
    int len=inorder.size();
    if(len==0)
        return NULL;

    TreeNode*root=build2(inorder,0,len-1,0,len-1,postorder);
    return root;
}
int main(){

    return 0;
}
