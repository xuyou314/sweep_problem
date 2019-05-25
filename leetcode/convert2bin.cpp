//
// Created by xuyou on 19-4-24.
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
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};
TreeNode*insert(TreeNode*root,int val){
    TreeNode*in=root;
    while (true) {
        if (val < in->val) {
            if (!in->left) {
                TreeNode *node = new TreeNode(val);
                in->left = node;
                break;
            } else {
                in = in->left;

            }
        }
        else if(val>in->val) {
            if (!in->right) {
                TreeNode *node = new TreeNode(val);
                in->right = node;
                break;
            } else{
                in=in->right;
            }
        }
        }

    return root;
}
TreeNode*sort(vector<int>&nums,int low,int high){


    int mid=(low+high)/2;
    TreeNode*root=new TreeNode(nums[mid]);
    if(high-mid>=1){
        TreeNode*rchild=sort(nums,mid+1,high);
        root->right=rchild;

    }
    if(mid-low>=1){
        TreeNode*lchild=sort(nums,low,mid-1);
        root->left=lchild;
    }
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size()==0)
        return NULL;
    TreeNode*root=sort(nums,0,nums.size()-1);

    return root;
}
TreeNode* l2tree(ListNode*head){
    if(!head){
        return  NULL;
    }
    ListNode*slow=head,*fast=head,*pre;
    while(fast&&fast->next){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    TreeNode *root=new TreeNode(slow->val);
    pre->next=NULL;
    root->left=l2tree(head);
    root->right=l2tree(slow->next);
    return root;
}
TreeNode* sortedListToBST(ListNode* head) {
    if(!head){
        return  NULL;
    }
    ListNode*slow=head,*fast=head,*pre=NULL;
    while(fast&&fast->next){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    TreeNode *root=new TreeNode(slow->val);
    if(pre)
        pre->next=NULL;
    if(slow!=head)
        root->left=sortedListToBST(head);
    root->right=sortedListToBST(slow->next);
    return root;
}
int main(){
    vector<int>nums={-10,-3,0,5,9,10};
    TreeNode*r=sortedArrayToBST(nums);
    return 0;
}