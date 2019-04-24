//
// Created by xuyou on 19-4-16.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*>q;
    if(!root)
        return 0;
    q.push(root);
    int curlen=1,nextlen=0;
    int res;
    while(!q.empty()){
        nextlen=0;
        res=-1;
        for(int i=0;i<curlen;i++){
            TreeNode*temp=q.front();
            if(res==-1)
                res=temp->val;
            q.pop();
            if(temp->left){
                q.push(temp->left);
                nextlen++;
            }
            if(temp->right){
                q.push(temp->right);
                nextlen++;
            }
        }
        curlen=nextlen;
    }
    return res;
}
void pre(TreeNode*root,int&maxdepth,int depth,int&ret){
    if(depth>maxdepth) {
        ret = root->val;
        maxdepth=depth;
    }
    if(root->left)
        pre(root->left,maxdepth,depth+1,ret);
    if(root->right)
        pre(root->right,maxdepth,depth+1,ret);

}
int findBottomLeftValue2(TreeNode* root) {
    int ret,maxd=-1;
    pre(root,maxd,0,ret);
    return ret;
}

int main(){
    TreeNode*a=new TreeNode(5);
    TreeNode*b=new TreeNode(4);
    TreeNode*c=new TreeNode(1);
    TreeNode*d=new TreeNode(2);
    a->right=c;
    a->left=b;
    c->right=d;
    int res=findBottomLeftValue2(a);
    return 0;
}