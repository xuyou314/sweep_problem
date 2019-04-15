//
// Created by xuyou on 19-4-7.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k,min;
    int d[100001]={0};
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    sort(d,d+n+1);
    int i=0;
    for(int t=0;t<k;t++) {
        while(i+1<=n&&d[i+1]==d[i])
            i++;
        if(i+1>n){
            cout<<0<<endl;
            continue;
        }
        cout << d[i + 1] - d[i] << endl;
        i++;
    }
    return 0;
}
