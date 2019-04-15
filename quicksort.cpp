//
// Created by xuyou on 19-3-8.
//
#include<stdio.h>
#include<iostream>
using namespace std;
void quicksort(int a[],int left,int right){
    int pivot,high,low;
    pivot=a[left];
    high=right;
    low=left;
    while(low<high){
    while(high>low&&a[high]>=pivot)
        high--;
    a[low]=a[high];
    while(low<high&&a[low]<=pivot)
        low++;
    a[high]=a[low];
    }
    a[low]=pivot;
    if(low-1>left)
        quicksort(a,left,low-1);
    if(right>low+1)
        quicksort(a,low+1,right);
}
int main(){
    int m;
    cin>>m;
    int *a=new int[m];
    for(int i=0;i<m;i++)
        cin>>a[i];
    quicksort(a,0,m-1);
    int gap=a[1]-a[0];
    for(int i=1;i<m-1;i++)
        if((a[i+1]-a[i])!=gap){
            cout<<"Impossible"<<endl;
            return 0;
        }
    cout<<"Possible"<<endl;
    return 0;
}
