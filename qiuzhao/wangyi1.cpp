//
// Created by xuyou on 19-4-7.
//
#include <iostream>

using namespace std;
int main(){
    long n;
    int ct=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<30;j++)
            if((i&(1<<j))&&(i&1<<(j+1))){
                ct++;
                break;
            }
    }
    cout<<n+1-ct<<endl;
    return 0;
}
