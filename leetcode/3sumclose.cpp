//
// Created by xuyou on 19-4-19.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int low=0,high=nums.size()-1,hlimit=high;
    int min=9999,res=0;
    for(low=0;low<=hlimit-2;low++)
        for(high=hlimit;high>=low+2;high--)
    {
        int left=target-nums[low]-nums[high];
        int lmid = low + 1, hmid = high - 1;
        while (lmid <= hmid) {
            int mid = (lmid + hmid) / 2;
            int templeft = left - nums[mid];
            if (templeft > 0) {
                if(templeft < min) {
                    min=templeft;
                    res = target-templeft;
                }
                lmid++;
            } else if (templeft < 0) {
              if(-templeft<min) {
                  min=-templeft;
                  res = target-templeft;
              }
                hmid--;
            } else {
                return target;
            }
        }
        if (lmid == high) {
            break;
        }
        if (hmid == low) {
            hlimit--;
            continue;
        }
    }
    return res;
}
int main(){
    vector<int>v={1,1,1,0};
    int res=threeSumClosest(v,-100);
    return 0;
}