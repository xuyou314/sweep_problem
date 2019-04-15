//
// Created by xuyou on 19-2-27.
//
#include<vector>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
using namespace std;
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int  lenl=0,lenr=0,len=pre.size();
        int root=pre[0];
        for(int i=0;i<len;i++)
            if(vin[i]==root) {
                lenl = i;
                break;
            }
            lenr=len-1-lenl;
//        vector<int>prel,prer,vinl,vinr;
//        for(int i=0;i<len;i++){
//            if(i<index)
//                vinl.push_back(vin[i]);
//            if(i>index)
//                vinr.push_back(vin[i]);
//        }
//        for(int i=1;i<len;i++){
//            if(i<index+1)
//                prel.push_back(pre[i]);
//            else
//                prer.push_back(pre[i]);
//
//        }
//
        //vector<int>prel(pre.begin()+1,pre.begin()+1+lenl);
        vector<int>inl(vin.begin(),vin.begin()+lenl);
        vector<int>prer(pre.begin()+lenl+1,pre.end());
        vector<int>inr(vin.begin()+lenl+1,vin.end());
        TreeNode*rt=new TreeNode(root);
        if(lenl>0)
            rt->left = reConstructBinaryTree(vector<int>(pre.begin()+1,pre.begin()+1+lenl),inl);
        if(lenr>0)
            rt->right=reConstructBinaryTree(prer,inr);
        return rt;
    }
    void prit(int a[],int num){
        for(int i=0;i<num;i++)
            cout<<a[i];

    }
};
int main(){
    vector<int>pre={1,2,4,7,3,5,6,8};
    vector<int>in={4,7,2,1,5,3,8,6};
    vector<int> test(pre.begin(),pre.begin());
    Solution s;
    TreeNode*rt=s.reConstructBinaryTree(pre,in);
    return 0;
}