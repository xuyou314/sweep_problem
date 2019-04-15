//
// Created by xuyou on 19-3-10.
//
#include <iostream>
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
void quicksort2(int a[],int left,int right){
    int pivot,high,low;
    pivot=a[left];
    high=right;
    low=left;
    while(low<high){
        while(high>low&&a[high]<=pivot)
            high--;
        a[low]=a[high];
        while(low<high&&a[low]>=pivot)
            low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    if(low-1>left)
        quicksort2(a,left,low-1);
    if(right>low+1)
        quicksort2(a,low+1,right);
}
int main() {
    int n;
    int a[50],b[50],sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    quicksort(a,0,n-1);
    quicksort2(b,0,n-1);
    for(int i=0;i<n;i++){
        sum+=a[i]*b[i];
    }
    cout<<sum<<endl;
    return 0;
}
