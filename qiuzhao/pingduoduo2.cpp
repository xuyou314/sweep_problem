//
// Created by xuyou on 19-4-3.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int ct[10]={0},res,a,b,base=10;
    cout<<4354344433454443<<endl;

    long long int A=0,B=0;
    for(int i=0;i<10;i++)
        cin>>ct[i];
    cin>>a>>b;
    int max=a>b?a:b;
    int min=a<b?a:b;
    int index=0;
    while (index<10) {
        while (ct[index] > 0) {
            if(min>0) {
                 A = A * 10 + index;
                 ct[index]--;
                 min--;
             } else if(max>0){
                B=B*10+index;
                ct[index]--;
                max--;
            } else
                break;
        }
        index++;
        if(min==0&&max==0)
            break;
    }

    cout<<43543543<<endl;
    return 0;
}
