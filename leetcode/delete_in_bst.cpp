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
TreeNode*find(TreeNode*root,int key){
    if(root->val==key)
        return root;
    else if(root->val<key)
        return find(root->right,key);
    else
        return find(root->left,key);

}
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode *temp = root;
    TreeNode *parent = NULL, *next = NULL;
    int flag = 1;
    if (!root)
        return root;
    while (temp->val != key) {
        if (temp->val > key) {
            parent = temp;
            if (temp->left)
                temp = temp->left;
            else {
                flag = 0;
                break;
            }
        } else {
            parent = temp;
            if (temp->right)
                temp = temp->right;
            else {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0)
        return root;
    if (temp->right) {
        next = temp->right;
        while (next->left)
            next = next->left;
    }
    if (temp == root) {
        if (!next) {
            temp = root->left;
            root = NULL;
            return temp;
        } else {
            next->left = root->left;
            temp = root->right;
            root = NULL;
            return temp;
        }
    }
    if (!next) {
        if (temp == parent->left)
            parent->left = temp->left;
        else
            parent->right = temp->left;
        temp = NULL;
        return root;
    } else {
        next->left = temp->left;
        if (temp == parent->left)
            parent->left = temp->right;
        else
            parent->right = temp->right;
        temp = NULL;
        return root;
    }
}

int main(){
    TreeNode*a=new TreeNode(5);
    TreeNode*b=new TreeNode(4);
    TreeNode*c=new TreeNode(1);
    TreeNode*d=new TreeNode(2);
    a->right=c;
    a->left=b;
    c->right=d;
    a=deleteNode(c,2);
    return 0;
}