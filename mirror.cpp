//
// Created by xuyou on 19-2-27.
//
#include <stdlib.h>
#include <stack>
#include <stdio.h>
using namespace std;
struct  TreeNode{
    int val;
    struct  TreeNode*left,*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){
    }

};
class Solution{
public:
    void mirror(TreeNode*pRoot){

        auto temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        if(pRoot->left){
            mirror(pRoot->left);
        }
        if(pRoot->right)
            mirror(pRoot->right);
    }
};
TreeNode *build_tree(int vals[],int len){
    auto h=new TreeNode(vals[0]);
    stack<TreeNode*>nodes;
    stack<int>indexs;
    nodes.push(h);
    int cur_index=1,l,r;
    TreeNode *curnode;
    indexs.push(cur_index-1);
    while(!indexs.empty()){
        cur_index=indexs.top();
        curnode=nodes.top();
        indexs.pop();
        nodes.pop();
        l=(cur_index+1)*2-1;
        if(l<len&&vals[l]!=0){
            auto lnode=new TreeNode(vals[l]);
            curnode->left=lnode;
            indexs.push(l);
            nodes.push(lnode);
        }
        r=(cur_index+1)*2;
        if(r<len&&vals[r]!=0){
            auto rnode=new TreeNode(vals[r]);
            curnode->right=rnode;
            indexs.push(r);
            nodes.push(rnode);
        }
    }
    return h;
}
void preorder(TreeNode*r){
    if(r)
        printf("%d",r->val);
    else
        return;
    preorder(r->left);
    preorder(r->right);
}
int main(){
    int avals[]={8,8,7,9,2,1,1};
    TreeNode*a=build_tree(avals,7);
    preorder(a);
    printf("\n");
    Solution s;
    s.mirror(a);
    preorder(a);
    return 0;
}

