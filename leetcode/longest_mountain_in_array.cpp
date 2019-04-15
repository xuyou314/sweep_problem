//
// Created by xuyou on 19-3-18.
//
#include <iostream>
using namespace std;
int longestMountain(int* A, int ASize) {
    int start=0,high,low;
    int maxsize=0;
    while(start<ASize-1&&A[start+1]<=A[start]){
        start++;
    }
    high=start;
    while (start!=ASize-1&&start!=ASize) {
        while (high+1<ASize &&A[high] < A[high + 1]) {
            high++;
        }
        low = high;

        while (low+1<ASize&&A[low + 1] < A[low]) {
            low++;
        }

        if(high>start&&low>high){
            maxsize=maxsize>low-start+1?maxsize:low-start+1;
        }
        if(start==low)
            low++;
        start = low;
        high=start;
    }
    return maxsize;
}
int main(){
    int A[7]={2,1,4,7,3,2,5};
    int B[3]={2,3};
    cout<<longestMountain(B,2)<<endl;

    return 0;
}
