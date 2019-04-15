//
// Created by xuyou on 19-3-24.
//
#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    int length=height.size();
    int res=0;
    int left=0,right=length-1;
    while (left<right){
        int lh=height[left];
        int rh=height[right];
        int minh=lh>rh?rh:lh;
        int shape=minh*(right-left);
        res=res>shape?res:shape;
        if(lh<rh)
            left++;
        else
            right--;
    }
    return res;
}
int main(){
    vector<int>test={1,8,6,2,5,4,8,3,7};
    int res=maxArea(test);
    return 0;
}
