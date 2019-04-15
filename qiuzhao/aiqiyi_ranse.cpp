//
// Created by xuyou on 19-3-21.
//
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s[50];
    cin>>s;
    int length=strlen(s);
    int countR[50]={0},count=0;
    for(int i=0;i<length;i++){
        if(s[i]=='R')
            count++;
        countR[i]=count;
    }
    int min=countR[length-1];
    for(int i=0;i<length;i++){
        int leftR=countR[i];
        int leftG=i+1-leftR;
        int rightR=countR[length-1]-leftR;
        min=leftG+rightR>min?min:leftG+rightR;
    }
    cout<<min<<endl;
    return 0;
}
