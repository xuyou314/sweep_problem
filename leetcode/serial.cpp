//
// Created by xuyou on 19-4-25.
//
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

    // Encodes a tree to a single string.

    string int2str(int num){
        string ret;
        if(num==0){
            ret.push_back('0');
            return ret;
        }
        while(num){
            ret.push_back(num%10+'0');
            num/=10;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    void inorder(TreeNode*root, string&s){
        if(root==NULL)
            return;
        if(root->left)
            inorder(root->left,s);
        s=s+int2str(root->val);
        s.push_back('#');
        if(root->right)
            inorder(root->right,s);
    }
    void preorder(TreeNode*root,string&s){
        if(root==NULL)
            return;
        s=s+int2str(root->val);
        s.push_back('#');
        if(root->left)
            preorder(root->left,s);
        if(root->right)
            preorder(root->right,s);

    }
    string serialize(TreeNode* root) {
        string s;
        preorder(root,s);
        return s;
    }
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
// Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>pre;
        int cur=0;
        for(int i=0;i<data.size();i++){
            if(data[i]=='#') {
                pre.push_back(cur);
                cur = 0;
            }
            else{
                cur=cur*10+data[i]-'0';

            }
        }
        vector<int>in(pre.begin(),pre.end());
        sort(in.begin(),in.end());
        TreeNode*root=buildTree(pre,in);
        return root;
    }
};
int main() {
    TreeNode*a=new TreeNode(595959);
    TreeNode*b=new TreeNode(4);
    TreeNode*c=new TreeNode(1);
    TreeNode*d=new TreeNode(2);
    a->right=c;
    a->left=b;
    c->right=d;
    Codec codec;
    char buf[4];
    memcpy(buf, &(a->val), sizeof(int));
    string s=codec.serialize(a);
    TreeNode *R=codec.deserialize(s);
    return 0;
}
