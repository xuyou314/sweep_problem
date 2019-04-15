//
// Created by xuyou on 19-3-21.
//
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char s[51];
    int d[51];
    cin>>s;
    int length=strlen(s);
    d[0]=1;
    int max=1;
    for(int i=1;i<length;i++){
        if(s[i]!=s[i-1])
            d[i]=d[i-1]+1;
        else
            d[i]=1;
        max=max>d[i]?max:d[i];
    }
    cout<<max<<endl;
    return 0;
}
