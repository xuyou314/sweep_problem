//
// Created by xuyou on 19-4-9.
//
#include <iostream>
#include <vector>
using namespace std;
int reversePairs1(vector<int>& nums,int low,int high) {
    if(high-low<1)
        return 0;
    if(high-low==1){
        int ret=0;
        if(nums[low]/2.0>nums[high])
            ret=1;
        if(nums[low]>nums[high])
            swap(nums[low],nums[high]);
        return ret;
    }
    int mid=(high+low)/2;
    int l=reversePairs1(nums,low,mid-1);
    int r=reversePairs1(nums,mid,high);
    int left=mid-1;
    int right=high,ret=0;
    vector<int>temp;
    while(left>=low&&right>=mid){
        if(nums[left]/2.0>nums[right]){
            ret=ret+right-mid+1;
            left--;
        }
        else
            right--;
    }
    left=low;
    right=mid;
    while(left<mid&&right<=high){
        if(nums[left]<nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
        nums[i]=temp[i-low];
    return l+r+ret;
}
int reversePairs(vector<int>& nums) {
    int res=reversePairs1(nums,0,nums.size()-1);
    return res;
}
int main(){
    vector<int>in={1,3,2,3,1};
    int res=reversePairs(in);
    return 0;
}