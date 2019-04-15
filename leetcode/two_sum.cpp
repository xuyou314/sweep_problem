//
// Created by xuyou on 19-3-21.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int left=0,right=nums.size()-1;
    while(left<right){
        if(nums[left]+nums[right]>target)
            right--;
        else if(nums[left]+nums[right]<target)
            left++;
        else
            break;
    }
    vector<int>res;
    res.push_back(left);
    res.push_back(right);
    return res;
}
int main(){
    vector<int>test={2, 7, 11, 15};
    vector<int>ress;
    ress=twoSum(test,9);
    return 0;
}