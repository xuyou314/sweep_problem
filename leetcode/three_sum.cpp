//
// Created by xuyou on 19-3-20.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void dfs(int i,vector<int>&nums,int *visited,vector<int>res,vector<vector<int>>&reses){
    visited[i]=1;
    res.push_back(nums[i]);
    if(res.size()==3){
        sort(res.begin(),res.end());
        int sum=0;
        for(int i=0;i<3;i++)
            sum+=res[i];
        if(sum==0) {
            int flag=0;
            for(int j=0;j<reses.size();j++)
                if(reses[j][0]==res[0]&&reses[j][1]==res[1])
                    flag=1;
            if(flag==0)
                reses.push_back(res);
        }
        return;
    }
    int length=nums.size();

    for(int j=i;j<length;j++) {
         if(visited[j] == 0){
             visited[j]=1;
             dfs(j,nums,visited,res,reses);
             visited[j]=0;
         }
    }

}

vector<vector<int>> threeSum1(vector<int>& nums) {
    int length=nums.size();
    int *visited=new int[length];
    for(int i=0;i<length;i++)
        visited[i]=0;
    vector<int>res;
    vector<vector<int>>ress;
    for(int i=0;i<length-2;i++)
        dfs(i,nums,visited,res,ress);
//    queue<int>q;
//    for(int i=0;i<length;i++){
//        visited[i]=1;
//        q.push(nums[i]);
//        while (q.size()<=3){
//            if(q.size()==3)
//
//        }
//        visited[i]=0;
//    }
    return ress;
}
void test1(vector<int>&res){
    res.push_back(1);
    return;
}
vector<vector<int>> threeSum2(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int length=nums.size();
    int start=0,mid=1,end=2;
    vector<vector<int>>res;
    while (start<length-2&&nums[start]+nums[start+1]+nums[start+2]<=0){
        mid=start+1;
        while (mid<length-1&&nums[start]+nums[mid]+nums[mid+1]<=0) {
            end=mid+1;
            while (end < length&&nums[start] + nums[mid] + nums[end] <= 0  ) {
                if (nums[start] + nums[mid] + nums[end] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[start]);
                    temp.push_back(nums[mid]);
                    temp.push_back(nums[end]);
//                    int flag=0;
//                    for(int i=0;i<res.size();i++){
//                        if(res[i][0]==temp[0]&&res[i][1]==temp[1])
//                            flag=1;
//                    }
//                    if(flag==0)
                        res.push_back(temp);
                    break;
                }
                end++;
            }
            mid++;
            while(mid<length&&nums[mid]==nums[mid-1])
                mid++;
        }
        start++;
        while (start<length&&nums[start]==nums[start-1])
            start++;
    }
    return res;
}
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int length=nums.size();
    int start=0,mid=1,end=2;
    vector<vector<int>>res;
    while (start<length-2&&nums[start]+nums[start+1]+nums[start+2]<=0){
        mid=start+1;
        end=length-1;
        while (mid<end){
            if(nums[start]+nums[mid]+nums[end]>0)
                end--;
            else if(nums[start]+nums[mid]+nums[end]<0)
                mid++;
            else{
                vector<int>temp;
                temp.push_back(nums[start]);
                temp.push_back(nums[mid]);
                temp.push_back(nums[end]);
                res.push_back(temp);
                mid++;
                while (mid<end&&mid+1<length&&nums[mid-1]==nums[mid])
                    mid++;
            }
        }
        start++;
        while (start<length-2&&nums[start-1]==nums[start])
            start++;
    }
    return res;
}
int main(){
    vector<int>test={0,0,0};
    vector<vector<int>>ress;
    ress=threeSum(test);

    for(int i=0;i<ress.size();i++)
        for(int j=0;j<ress[i].size();j++)
            cout<<ress[i][j]<<endl;
    return 0;
}
