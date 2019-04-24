//
// Created by xuyou on 19-4-23.
//
#include <iostream>
#include <vector>
using namespace std;
int quicksort(vector<int>&nums,int left,int right,int k){
    int low=left,high=right;
    int pivot=nums[left];
    while(low<high){
        while(low<high&&nums[high]<=pivot)
            high--;
        nums[low]=nums[high];
        while(low<high&&nums[low]>pivot)
            low++;
        nums[high]=nums[low];
    }
    nums[low]=pivot;
    if(low-left==k-1)
        return nums[low];
    else if(low-left>k-1)
        return quicksort(nums,left,low-1,k);
    else
        return quicksort(nums,low+1,right,k-(low-left+1));
}
int findKthLargest(vector<int>& nums, int k) {
    int res=quicksort(nums,0,nums.size()-1,k);
    return res;
}
int main(){
    vector <int>case1={3,2,1,5,6,4};
    vector<int >case2={3,2,3,1,2,4,5,5,6};
    int res=findKthLargest(case2,4);
    return 0;
}
