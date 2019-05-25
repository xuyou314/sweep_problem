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
         TreeNode(void) : val(-1), left(NULL), right(NULL) {}
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode*build(vector<int>&nums){
    TreeNode*T=new TreeNode[5];
    for(int i=0;i<nums.size();i++) {
            T[i].val = nums[i];
    }
    int start=0;
    while((start+1)*2-1<nums.size()){
        if(nums[start]==-1){
            start++;
            continue;
        }
        if(nums[2*start+1]!=-1)
            T[start].left=&T[(start+1)*2-1];
        if(2*start+2<nums.size()&&nums[2*start+2]!=-1)
            T[start].right=&T[2*start+2];
        start++;
    }
    return &T[0];
}
TreeNode*first=NULL,*last=NULL,*pre=NULL;

TreeNode*convert2doubly(TreeNode*root){
    if(!root)
        return NULL;
    if(root->left)
        convert2doubly(root->left);
    if(pre!=NULL) {
        root->left = pre;
        pre->right=root;
        pre=root;
    }
    else{
        first=root;
        pre=root;
    }
    last=root;
    if(root->right)
        convert2doubly(root->right);
    first->left=last;
    last->right=first;
    return first;
};
int main(){
    vector<int>nums={4,2,5,1,3};
    TreeNode*r=build(nums);
    TreeNode*b=convert2doubly(r);

    return 0;
}
