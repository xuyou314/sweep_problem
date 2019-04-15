//
// Created by xuyou on 19-4-12.
//
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<double>pros(n,0);
    for(int i=0;i<n;i++)
        cin>>pros[i];
    double res=0,unfinish=1;
    for(int i=1;i<=100;i++){
        if(i%2==1)
            res+=unfinish*pros[(i-1)%n];
        unfinish=unfinish*(1-pros[(i-1)%n]);
    }
    printf("%.4lf",res);


    return 0;
}
