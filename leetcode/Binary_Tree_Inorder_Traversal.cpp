//
// Created by xuyou on 19-4-15.
//
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
vector<int> inorderTraversal(TreeNode* root) {
    vector<TreeNode*>unvisited;
    TreeNode*temp=root;
    unvisited.push_back(temp);
    vector<int>res;
    if(!root)
        return res;
    while(!unvisited.empty()) {
        temp=unvisited.back();
        while (temp->left) {
            temp = temp->left;
            unvisited.push_back(temp);
        }
        temp=unvisited.back();
        res.push_back(temp->val);
        unvisited.pop_back();
        while(!unvisited.empty()&&!temp->right){
            temp=unvisited.back();
            unvisited.pop_back();
            res.push_back(temp->val);
        }
        if(temp->right)
            unvisited.push_back(temp->right);
    }
    return res;
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<TreeNode*>unvisited;
    vector<int>res;
    TreeNode*temp,*pre;
    if(!root)
        return res;
    unvisited.push_back(root);
    int flag=0; //2 from right 1 from left
    while(!unvisited.empty()){
        temp=unvisited.back();
        if(flag==2){
            if(pre==NULL||pre==temp->right) {
                res.push_back(temp->val);
                pre = temp;
                unvisited.pop_back();
            }
            else{
                flag=1;
                pre=NULL;
            }
        }
        else if(flag==0){
            while(temp->left){
                unvisited.push_back(temp->left);
                temp=temp->left;
            }
            flag=1;
        }
        else{
            if(temp->right){
                unvisited.push_back(temp->right);
                flag=0;
                continue;
            }
            else
                flag=2;
        }
    }
    return res;
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int>res;
    if(!root)
        return res;
    vector<TreeNode*>unvisited;
    TreeNode*temp;
    unvisited.push_back(root);
    while (!unvisited.empty()){
        temp=unvisited.back();
        res.push_back(temp->val);
        unvisited.pop_back();
        if(temp->right)
            unvisited.push_back(temp->right);
        if(temp->left)
            unvisited.push_back(temp->left);
    }
    return res;
}
int main(){
    TreeNode*a=new TreeNode(5);
    TreeNode*b=new TreeNode(4);
    TreeNode*c=new TreeNode(3);
    TreeNode*d=new TreeNode(6);
    a->right=c;
    a->left=b;
    b->left=d;
    vector<int>res=preorderTraversal(a);
    return 0;
}
