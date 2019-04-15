//
// Created by xuyou on 19-3-21.
//
#include<iostream>
using namespace std;
long a[200001];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[n-1];
    int i=n-2;
    for(;i>=1;i-=2)
        cout<<" "<<a[i-1];
    if(i==-1)
        i=1;
    for(;i<n;i+=2)
        cout<<" "<<a[i];
    return 0;
}
