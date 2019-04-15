//
// Created by xuyou on 19-3-20.
//
class Solution {
public:
    int integerBreak(int n) {
        int d[59];
        d[1]=1;
        for(int i=2;i<=n;i++){
            int tempmax=0;
            for(int j=1;j<=i/2;j++){
                tempmax=tempmax>d[j]*d[i-j]?tempmax:d[j]*d[i-j];
                tempmax=tempmax>j*d[i-j]?tempmax:j*d[i-j];
                tempmax=tempmax>d[j]*(i-j)?tempmax:d[j]*(i-j);
                tempmax=tempmax>j*(i-j)?tempmax:j*(i-j);
            }
            d[i]=tempmax;
        }
        return d[n];
    }
};
