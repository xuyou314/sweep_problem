//
// Created by xuyou on 19-3-21.
//
#include<iostream>
#include<string.h>
using namespace std;
void quicksort(int *a,int left,int right){
    if(left>=right)
        return;
    int pivot=a[left];
    int low=left,high=right;
    while(left<right){
        while(right>left&&a[right]>=pivot)
            right--;
        a[left]=a[right];
        while(left<right&&a[left]<=pivot)
            left++;
        a[right]=a[left];
    }
    a[left]=pivot;
    quicksort(a,low,left-1);
    quicksort(a,left+1,high);
}
int main(){
    int n,a[50],b[50];
//    int test[5]={2,3,2,1,4};
//    quicksort(test,0,3);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    int res=0;
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            res++;
        cout<<res<<endl;
    return 0;
}
