//
// Created by xuyou on 19-3-23.
//
#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    if(n1<n2){
        return findMedianSortedArrays(nums2,nums1);
    }
    if(n2==0)
        return (nums1[(n1-1)/2]+nums1[n1/2])/2.0;
    int cut1,cut2,l1,l2,r1,r2;
    int lo=n1-n2,hi=n1+n2;
    while(lo<=hi) {
        cut1 = (hi + lo) / 2;
        cut2 = n1 + n2 - cut1;
        if(cut1==0)
            l1=-999999;
        else
            l1 = nums1[(cut1 - 1) / 2];
        if(cut1/2>=n1)
            r1=9999999;
        else
            r1 = nums1[cut1 / 2];
        if(cut2==0)
            l2=-999999;
        else
            l2 = nums2[(cut2 - 1) / 2];
        if(cut2/2>=n2)
            r2=999999;
        else
            r2 = nums2[cut2 / 2];
        if (l1 <= r2 && l2 <= r1) {
            int maxl = l1 > l2 ? l1 : l2;
            int minr = r1 < r2 ? r1 : r2;
            return (maxl + minr) / 2.0;
        } else if (l1 > r2) {
            hi = cut1-1;
        } else {
            lo = cut1+1;
        }
    }
    return 0;
}
int main(){
    vector<int>a={1};
    vector<int>b={2,3,4};
    double  res=findMedianSortedArrays(a,b);
    return 0;
}