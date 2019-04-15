//
// Created by xuyou on 19-4-7.
//
#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int temp=n,t=k;
    while(temp>1&&t>0){
        temp=(temp+1)/2;
        t--;
    }
    cout<<k-t+temp<<endl;
    return 0;
}
