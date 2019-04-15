//
// Created by xuyou on 19-3-22.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarraySum1(vector<int>& nums, int k) {
    int start=0,end=0;
    int sum=nums[start],length=nums.size(),res=0;
    while(start<length&&end<length){
        if(sum==k){
            res++;
            sum-=nums[start];
            start++;
        }
        else if(sum<k){
            end++;
            if(end<length)
                sum+=nums[end];
        }
        else{
            sum-=nums[start];
            start++;
        }
    }
    return res;
}
int subarraySum2(vector<int>& nums, int k) {
    int start=0,end=0;
    int sum=nums[start],length=nums.size(),res=0;
    while(start<length){
        end=start;
        sum=nums[start];
        while (end<length){
            if(sum==k)
                res++;
            end++;
            if(end<length)
                sum+=nums[end];
        }
        start++;
    }
    return res;
}
int subarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=1;
        int length=nums.size();
        int sum=0;
        int res=0;
        for(int i=0;i<length;i++){
            sum+=nums[i];
//            map<int,int>::iterator it=m.find(sum-k);
//            if(it!=m.end())
//                res+=it->second;
            res+=m[sum-k];
            m[sum]++;
        }
    return res;
}
int main(){
    vector<int>a={1,2,1,2,1};
    map<int,int>m;
    //m[50]++;
    //auto re= m.find(1);
    //cout<<(re==m.end())<<endl;
    //cout<<m[1]<<endl;
    int res=subarraySum(a,3);
    return 0;
}
