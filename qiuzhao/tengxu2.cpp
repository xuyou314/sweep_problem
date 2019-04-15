//
// Created by xuyou on 19-4-7.
//
#include <iostream>
using namespace std;
int num[300000];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>num[i];
    long res=0,send=0,receice=0;
    while(send<n&&num[send]<=0)
        send++;
    while(receice<n&&num[receice]>=0)
        receice++;
    while(send<n&&receice<n){
        if(num[send]>-num[receice]) {
            int dis=send-receice>0?send-receice:receice-send;
            res=res-dis*num[receice];
            num[send]=num[send]+num[receice];
            num[receice]=0;
            receice++;
        } else{
            int dis=send-receice>0?send-receice:receice-send;
            res=res+dis*num[send];
            num[receice]=num[send]+num[receice];
            num[send]=0;
            send++;
        }
        while(receice<n&&num[receice]>=0)
            receice++;
        while(send<n&&num[send]<=0)
            send++;
    }
    cout<<res<<endl;
    return 0;
}
