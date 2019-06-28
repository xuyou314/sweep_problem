//
// Created by xuyou on 19-6-8.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>>d(K+1,vector<int>(N+1,0));
        for(int k=1;k<=K;k++){
            for(int n=1;n<=N;n++){
                if(n==1){
                    d[k][n]=1;
                    continue;
                }
                if(k==1){
                    d[k][n]=n;
                }
                else{
                    int temp=9999;
                    int low=1,high=n;
                    while(low<high){
                        int p=(low+high)/2;
                        if(d[k-1][p-1]==d[k][n-p])
                            break;
                        if(d[k-1][p-1]==d[k][n-p]-1&&d[k-1][p]==d[k][n-p-1]+1)
                            break;
                        if(d[k-1][p-1]==d[k][n-p]+1&&d[k-1][p-2]==d[k][n-p+1]-1)
                            break;
                        if(d[k-1][p-1]>d[k][n-p])
                            high=p;
                        else if(d[k-1][p-1]<d[k][n-p])
                            low=p;
                    }
                    int p=(low+high)/2;
                    d[k][n]=d[k-1][p-1]>d[k][n-p]?d[k-1][p-1]+1:d[k][n-p]+1;
                }
            }
        }
        return d[K][N];
    }
};
class Solution2 {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>>d(K+1,vector<int>(N+1,0));
        int ret=-1;
        for(int k=1;k<=K;k++){
            for(int n=1;n<=N;n++){
                if(k==1){
                    d[k][n]=n;
                }
                else{
                    d[k][n]=d[k-1][n-1]+d[k][n-1]+1;
                    if(k<K&&d[k][n]>=N)
                        break;
                }
                if(k==K&&d[k][n]>=N){
                    ret=n;
                    break;
                }
            }
            if(ret!=-1)
                break;
        }
        return ret;
    }
};
int a[10];
int main(){
    vector<vector<int>>d(5,vector<int>(6,0));
    return 0;
}