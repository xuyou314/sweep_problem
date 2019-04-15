//
// Created by xuyou on 19-4-9.
//
#include <iostream>
using namespace std;
int findIntegers(int num) {
    int d[32]={2,3,0};
    for(int i=2;i<32;i++)
        d[i]=d[i-1]+d[i-2];
    int res=0,i=30;
    while(i>=0&&(num&(1<<i))==0)
        i--;
    while(i>=0){
        if(i==0) {
            res += 2;
            return res;
        }
        if(num&(1<<i)) {
            res += d[i - 1];
            i--;
            if(num&(1<<i)) {
                if (i == 0)
                    res += 1;
                else
                    res += d[i - 1];
                return res;
            }
            while(i>=0&&(num&(1<<i))==0)
                i--;
            if(i==-1) {
                res += 1;
                return res;
            }
        }
    }
    return res;
}
int findIntegers2(int num) {
    int d[32]={1,2,3,0};
    for(int i=2;i<32;i++)
        d[i]=d[i-1]+d[i-2];
    int res=0,i=30;
    while(i>=0&&(num&(1<<i))==0)
        i--;
    while(i>=0){
        if(num&(1<<i)) {
            res += d[i];
            i--;
            if(i>=0&&num&(1<<i)) {
                res += d[i];
                return res;
            }
            while(i>=0&&(num&(1<<i))==0)
                i--;
        }
    }
    return res+1;
}
int main(){
    int mins=1<<31;
    int max=mins-1;
    int res=findIntegers2(11);

    return 0;
}
