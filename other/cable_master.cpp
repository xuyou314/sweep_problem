//
// Created by xuyou on 19-3-20.
//
#include <iostream>
#include <stdio.h>
using  namespace std;
float rope[10000];
int main(){
    int n,k;
    cin>>n>>k;
    float max=0;
    for(int i=0;i<n;i++) {
        cin >> rope[i];
        max=max>rope[i]?max:rope[i];
    }
    float left=0,right=max;
    while(right-left>0.005){
        int len=0;
        for(int i=0;i<n;i++)
            len+=int(rope[i]/(right+left)*2);
        if(len>=k)
            left=(right+left)/2;
        else
            right=(right+left)/2;
    }
    printf("%.2f",int(left*100)/100.0);
    return 0;
}
