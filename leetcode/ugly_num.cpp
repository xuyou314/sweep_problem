//
// Created by xuyou on 19-4-23.
//
#include <iostream>
#include <vector>
using namespace std;
int nthUglyNumber(int n) {
    int d[5000000]={0};
    d[1]=1;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            for(int k=0;k<20;k++){
                int cur=1,flag=0;
                int t1=i,t2=j,t3=k;
                while(t1>0){
                    cur*=2;
                    t1--;
                }
                while(t2>0){
                    cur*=3;
                    if(cur>5000000){
                        break;
                    }
                    t2--;
                }
                if(t2)
                    continue;
                while(t3>0){
                    cur*=5;
                    if(cur>5000000)
                        break;
                    t3--;
                }
                if(cur>=5000000)
                    continue;
                if(t3!=0)
                    continue;
                d[cur]=1;
            }
        }
    }
    int ret=0,index=0;
    while(ret!=n){
        index++;
        if(d[index])
            ret++;
    }
    return index;
}
int nthUglyNumber2(int n) {
    int pre2=1,pre3=1,pre5=1;
    vector<int>d(n+1,0);
    d[1]=1;

    for(int i=2;i<=n;i++){
        int nxcur2=d[pre2]*2;
        int nxcur3=d[pre3]*3;
        int nxcur5=d[pre5]*5;
        int min=nxcur2>nxcur3?nxcur3:nxcur2;
        min=min>nxcur5?nxcur5:min;
        d[i]=min;
        if(min==nxcur2)
            pre2++;
        if(min==nxcur3)
            pre3++;
        if(min==nxcur5)
            pre5++;
    }
    return d[n];
}
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int>pre(primes.size(),1);
    vector<int>d(n+1,0);
    d[1]=1;
    for(int i=2;i<=n;i++ ){
        int min=d[pre[0]]*primes[0];
        for(int k=1;k<primes.size();k++){
            min=min<d[pre[k]]*primes[k]?min:d[pre[k]]*primes[k];
        }
        d[i]=min;
        for(int k=0;k<primes.size();k++){
            if(min==d[pre[k]]*primes[k])
                pre[k]++;
        }
    }
    return d[n];
}
int main(){

    return 0;
}