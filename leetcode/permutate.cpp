//
// Created by xuyou on 19-4-2.
//
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>>&res,
         vector<int>nums,vector<int>cur,vector<int>&vis){
    if(cur.size()==nums.size()){
        res.push_back(cur);
        return ;
    }
    for(int j=0;j<nums.size();j++){
        if(vis[j]==0){
            vis[j]=1;
            cur.push_back(nums[j]);
            dfs(res,nums,cur,vis);
            cur.pop_back();
            vis[j]=0;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>res;
    vector<int>cur;
    vector<int>vis(nums.size(),0);
    dfs(res,nums,cur,vis);
    return res;
}
void dfs2(vector<int>cur,vector<vector<int>>&res,vector<int>&vis,int k,int n){
    int last=0;
    if(cur.size()==k){
        res.push_back(cur);
        return ;
    }
    if(!cur.empty())
        last=cur.back();
    for(int i=last+1;i<=n;i++){
        if(vis[i-1]==0){
            vis[i-1]=1;
            cur.push_back(i);
            dfs2(cur,res,vis,k,n);
            cur.pop_back();
            vis[i-1]=0;
        }

    }

}
vector<vector<int>> combine(int n, int k) {
    vector<int>vis(n,0);
    vector<vector<int>>res;
    vector<int>cur;
    dfs2(cur,res,vis,k,n);
    return res;
}
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
    if(nums.size()<=1)
        return;
    int first=nums.size()-1;
    int second=nums.size()-2;
    while(second>=0&&nums[second]>=nums[first]){
        if(first>second+1)
            first--;
        else{
            second--;
            first=nums.size()-1;
        }
    }
    if(second==-1)
        sort(nums.begin(),nums.end());
    else{
        int temp=nums[first];
        nums[first]=nums[second];
        nums[second]=temp;
        sort(nums.begin()+second+1,nums.end());
    }
}
int main(){
    vector<vector<int>>res;
    vector<int>a={4,2,0,2,3,2,0};
    nextPermutation(a);
    res=combine(4,2);
    return 0;
}