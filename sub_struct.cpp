//
// Created by xuyou on 19-2-27.
#include <stdlib.h>
#include <stdio.h>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    int equal(TreeNode*a,TreeNode*b){
        if (b == NULL&&a==NULL)
            return true;
        if(!a||!b||(a->val!=b->val))
            return 0;
        return equal(a->left,b->left)&&equal(a->right,b->right);
    }
    bool subequal(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;

        // 递归判断子结构是否相同
        if (pRoot1->val == pRoot2->val)
            return equal(pRoot1->left, pRoot2->left)
                   && equal(pRoot1->right, pRoot2->right);
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(pRoot1==NULL||pRoot2==NULL)
            return 0;
        if (equal(pRoot1, pRoot2))
            return 1;

        return  HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);


//        else {
//            int l = 0, r = 0;
//            if (pRoot1->left)
//                l = equal(pRoot1->left, pRoot2);
//            if (pRoot1->right)
//                r = equal(pRoot1->right, pRoot2);
//            return  l||r;
//        }
    }
};
TreeNode *build_tree(int vals[],int len){
    TreeNode *h=new TreeNode(vals[0]);
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
            TreeNode *lnode=new TreeNode(vals[l]);
            curnode->left=lnode;
            indexs.push(l);
            nodes.push(lnode);
        }
        r=(cur_index+1)*2;
        if(r<len&&vals[r]!=0){
            TreeNode*rnode=new TreeNode(vals[r]);
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

    int bvals[]={7,1,1};
    int cvals[]={7};
    TreeNode*a=build_tree(avals,7);
    TreeNode*b=build_tree(bvals,3);
    TreeNode*c=build_tree(cvals,1);
    //preorder(a);
    Solution s;
    printf("%d,%d",s.HasSubtree(a,b),s.HasSubtree(c,b));
    return 0;
}