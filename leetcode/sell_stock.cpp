//
// Created by xuyou on 19-4-1.
//
#include <iostream>
#include <vector>
using namespace std;
int maxProfit1(vector<int> prices) {
    int min=9999,max=0;
    for(int i=0;i<prices.size();i++){
        min=min>prices[i]?prices[i]:min;
        max=max<prices[i]-min>0?prices[i]-min:max;
    }
    return max;
}
int maxProfit2(vector<int>& prices) {
    int lens=prices.size(),buy=0,sell=0,max=0;
    while(buy<lens){
        while(buy+1<lens&&prices[buy+1]<=prices[buy])
            buy++;
        sell=buy+1;
        while(sell+1<lens&&prices[sell+1]>=prices[sell])
            sell++;
        if(sell>lens-1)
            break;
        max+=prices[sell]-prices[buy];
        buy=sell+1;
    }
    return max;
}
int maxProfit3(vector<int>& prices) {
    int len=prices.size();
    int lmax=0,rmax=0,max=0;
    int buy=0,sell=0;
    vector<int>temp;
    while(buy<len) {
        while (buy + 1 < len && prices[buy + 1] <= prices[buy])
            buy++;
        sell = buy + 1;
        while (sell + 1 < len && prices[sell + 1] >= prices[sell])
            sell++;
        if (sell > len - 1)
            break;
        temp.push_back(prices[buy]);
        temp.push_back(prices[sell]);
        buy=sell+1;
    }
    if(temp.size()<2)
        return 0;
    for(int i=0;i<=temp.size()-2;i++) {
        lmax = maxProfit1(vector<int>(temp.begin(), temp.begin() + i));
        rmax=maxProfit1(vector<int>(temp.begin()+i,temp.end()));
        if(max<lmax+rmax)
            max=lmax+rmax;
    }
    return max;
}
int maxProfit4(vector<int>& prices) {
    int len=prices.size(),lmin=9999,rmax=-9999,res=0;
    if(len<=1)
        return 0;
    vector<int>leftmost(len,0),rightmost(len,0);
    for(int i=0;i<len;i++){
        lmin=lmin>prices[i]?prices[i]:lmin;
        leftmost[i]=prices[i]-lmin;
        if(i>0)
            leftmost[i]=leftmost[i-1]>leftmost[i]?leftmost[i-1]:leftmost[i];
        rmax=rmax>prices[len-1-i]?rmax:prices[len-1-i];

        rightmost[len-1-i]=rmax-prices[len-1-i];
        if(i>0)
            rightmost[len-1-i]=rightmost[len-i]>rightmost[len-i-1]?rightmost[len-i]:rightmost[len-i-1];
    }
    res=rightmost[0];
    for(int i=0;i<len-1;i++){
        int temp=leftmost[i]+rightmost[i+1];
        res=temp>res?temp:res;

    }
    return res;
}
int maxProfit5(int k, vector<int>& prices) {
    int len=prices.size();
    if(len<2)
        return 0;
    int buy=0,sell=0;
    vector<int>temp;
    if(k>len/2)
        return maxProfit2(prices);
    while(buy<len) {
        while (buy + 1 < len && prices[buy + 1] <= prices[buy])
            buy++;
        sell = buy + 1;
        while (sell + 1 < len && prices[sell + 1] >= prices[sell])
            sell++;
        if (sell > len - 1)
            break;
        temp.push_back(prices[buy]);
        temp.push_back(prices[sell]);
        buy=sell+1;
    }
    if(temp.size()<2)
        return 0;
    len=temp.size();
    k=len/2>k?k:len/2;
    vector<vector<int>>d(k+1,vector<int>(len+1,0));
    int ret=0;
    for(int t=1;t<=k;t++) {
        for (int i = 2; i <=len; i++) {
            int max=0;
            for(int j=1;j<i;j++){
                max=d[t-1][j-1]+temp[i-1]-temp[j-1]>max?d[t-1][j-1]+temp[i-1]-temp[j-1]:max;
            }
            max=max>d[t][i-1]?max:d[t][i-1];
            d[t][i]=max;

            ret=max>ret?max:ret;
        }
    }
    return ret;
}
int main(){
    vector<int>test={3,3,5,0,0,3,1,4};
    int res=maxProfit5(2,test);
    return 0;
}
