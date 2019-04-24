//
// Created by xuyou on 19-4-15.
//
#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>& nums) {
    if(nums.size()==1)
        return nums[0];
    int low=0,high=nums.size()-1;
    while (low<high){
        int mid=(low+high)/2;
        if(nums[low]>nums[high]) {
            if (nums[mid] >= nums[low])
                low = mid + 1;
            else
                high = mid;
        }
        else
            break;
    }
    return nums[low];
}
int findMin2(vector<int>& nums) {
    if(nums.size()==1)
        return nums[0];
    int low=0,high=nums.size()-1;
    while (low<high){
        int mid=(low+high)/2;
        if(nums[low]<nums[high])
            return nums[low];
        if(nums[mid]>nums[low]||nums[mid]>nums[high])
            low=mid+1;
        else if(nums[mid]<nums[low]||nums[mid]<nums[high])
            high=mid;
        else{
            for(int i=low+1;i<=high;i++)
                if(nums[i]>nums[low])
                    return nums[low];
                else if(nums[i]<nums[low])
                    return nums[i];
            return nums[low];
        }
    }
    return nums[low];

}
int main(){
    vector<int>a={1,3,5};
    int min=findMin2(a);
    return 0;
}
