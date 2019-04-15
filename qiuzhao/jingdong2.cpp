//
// Created by xuyou on 19-4-13.
//
#include <iostream>
#include <vector>
using namespace std;
int res=0;
void dfs(vector<int>&nums,vector<int>&indexs,int curindex){
    if(curindex==indexs.size()) {
        res++;
        return;
    }
    int id=indexs[curindex];
    if(id==0) {
        int max=200;
        if(nums[1]!=0)
            max=max>nums[1]?max:nums[1];
        for (int i = 1; i <max; i++) {
            nums[id]=i;
            dfs(nums,indexs,curindex+1);
            nums[id]=0;
        }
    }
    else if(id==nums.size()-1){
        for (int i = nums[id-1]; i>=1; i--) {
            nums[id]=i;
            dfs(nums,indexs,curindex+1);
            nums[id]=0;
        }
    }
    else{
        int max=nums[id-1];
        if(nums[id+1]!=0)
            max=max>nums[id+1]?max:nums[id+1];
        int min=1;
        if(id-1==0)
            min=min<nums[0]?nums[0]:min;
        if(id+1==nums.size())
            min=min>nums[nums.size()-1]?min:nums[nums.size()-1];
        for(int i=min;i<=max;i++){
            nums[id]=i;
            dfs(nums,indexs,curindex+1);
            nums[id]=0;
        }

    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    vector<int>miss;
    for(int i=0;i<n;i++) {
        cin >> nums[i];
        if(nums[i]==0)
            miss.push_back(i);
    }
    dfs(nums,miss,0);
    cout<<res<<endl;
    return 0;
}