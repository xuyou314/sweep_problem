//
// Created by xuyou on 19-4-2.
//
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
    TreeNode*left,*right;
    int val;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
int widthOfBinaryTree(TreeNode* root) {
    queue<long long>indexq;
    queue<TreeNode*>nodeq;
    if(root==NULL)
        return 0;
    indexq.push(1);
    nodeq.push(root);
    long long len=1,newlen=0,ret=1;
    while (!indexq.empty()){
        long long min = 99999999, max = -9999;
        while(len>0) {
            len--;
            TreeNode *temp = nodeq.front();
            long long index = indexq.front();
            indexq.pop();
            nodeq.pop();
            if (temp->left) {
                indexq.push(index*2);
                nodeq.push(temp->left);
                newlen++;
                min=min>index*2?index*2:min;
                max=max>index*2?max:index*2;

            }
            if(temp->right){
                indexq.push(index*2+1);
                nodeq.push(temp->right);
                newlen++;
                min=min>index*2+1?index*2+1:min;
                max=max>index*2+1?max:index*2+1;
            }
            ret=ret>max-min+1?ret:max-min+1;

        }
        len=newlen;
        if(newlen==1){
            indexq.pop();
            indexq.push(1);
        }

        newlen=0;
    }
    return ret;
}
int main(){
  TreeNode a(4);
  TreeNode b(5);
  TreeNode c(5);
  TreeNode d(7);
  TreeNode e(3);TreeNode f(3);
  a.right=&b;
  a.left=&c;
  b.left=&d;
  c.left=&e;
  c.right=&f;
  int res=widthOfBinaryTree(&a);
    return 0;
}