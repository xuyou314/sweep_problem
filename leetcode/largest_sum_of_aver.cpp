//
// Created by xuyou on 19-6-26.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int len=A.size();
        vector<vector<double>>d(len+1,vector<double>(K+1,0));
        vector<double>dsum(len+1,0);
        for(int i=1;i<=len;i++)
            dsum[i]=dsum[i-1]+A[i-1];
        for(int starti=len-1;starti>=0;starti--){
            for(int k=1;k<=K;k++){
                int dis=len-starti;
                if(k>dis) {
                    break;
                }
                if(starti!=0&&k==K)
                    continue;
                if(k==1) {
                    d[starti][k] = (dsum[len] - dsum[starti])/dis;
                    continue;
                }
                for(int jlen=1;jlen<=dis;jlen++) {
                    double mean=(dsum[starti+jlen]-dsum[starti])/jlen;
                    if(mean+d[starti+jlen][k-1]>d[starti][k])
                        d[starti][k]=mean+d[starti+jlen][k-1];
                }
            }
        }
        return d[0][K];
    }
};
int main(){
    Solution s;
    vector<int>a={9,1,2,3,9};
    vector<vector<double>>d(5,vector<double>(5,0));

    cout<<s.largestSumOfAverages(a,3);
    while (1){;}
    return 0;
}