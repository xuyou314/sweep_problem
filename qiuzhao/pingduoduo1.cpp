//
// Created by xuyou on 19-4-3.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,temp;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    sort(nums.begin(),nums.end());
    int min=300,max=0,res=0,minindex,maxindex;
    for(int i=0;i<n/2;i++){
        if(nums[i]+nums[n-1-i]<=min) {
            minindex = i;
            min=nums[i]+nums[n-1-i];
        }
        if(nums[i]+nums[n-1-i]>max){
            maxindex=i;
            max=nums[i]+nums[n-1-i];
        }
        if(maxindex!=minindex)
            res=res>max-min?res:max-min;

    }
    cout<<res<<endl;
    return 0;
}
