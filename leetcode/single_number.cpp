//
// Created by xuyou on 19-4-1.
//
#include <vector>
#include <iostream>
using namespace std;
vector<int> singleNumber3(vector<int>& nums) {
    int num1=0,num2=0,res=0;
    for(int i=0;i<nums.size();i++)
        res=res^nums[i];
    int index=0;
    for(;index<32;index++)
        if(res&(1<<index))
            break;
    for(int i=0;i<nums.size();i++)
        if(nums[i]&(1<<index))
            num1^=nums[i];
        else
            num2^=nums[i];
    vector<int>ret={num1,num2};
    return ret;
}
int main(){

    return 0;
}