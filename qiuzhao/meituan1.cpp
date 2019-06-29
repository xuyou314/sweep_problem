//
// Created by xuyou on 19-4-23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int innum;
    vector<int>black;
    vector<int>white;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin >> innum;
            if((i+j)%2==0)
                black.push_back(innum);
            else
                white.push_back(innum);
        }
    }
    int blackmode1=0,blackmode2=0,whitemode1=0,whitemode2=0;
    int bmode1,bmode2,wmode1,wmode2;
    sort(black.begin(),black.end());
    sort(white.begin(),white.end());
    int pre=0,cur=0;
    while(cur<black.size()){
         while(cur<black.size()&&black[cur]==black[pre])
            cur++;
         if(cur-pre>blackmode1) {
             blackmode2=blackmode1;
             blackmode1 = cur - pre;
             if(blackmode2!=0)
                 bmode2=bmode1;
             bmode1=black[pre];
             pre=cur;
         }
         else if(cur-pre>blackmode2) {
             blackmode2 = cur - pre;
             bmode2=black[pre];
             pre=cur;
         }
         pre=cur;
    }
    pre=0,cur=0;
    while(cur<white.size()){
        while(cur<white.size()&&white[cur]==white[pre])
            cur++;
        if(cur-pre>whitemode1) {
            whitemode2=whitemode1;
            whitemode1 = cur - pre;
            if(whitemode2!=0)
                wmode2=wmode1;
            wmode1=white[pre];
            pre=cur;
        }
        else if(cur-pre>whitemode2) {
            whitemode2 = cur - pre;
            wmode2=white[pre];
            pre=cur;
        }
        pre=cur;
    }
    int  res,op1,op2;
    if(bmode1!=wmode1)
        res=n*m-blackmode1-whitemode1;
    else{
        op1=n*m-blackmode1-whitemode2;
        op2=n*m-blackmode2-whitemode1;
        res=op1<op2?op1:op2;
    }
    cout<<res<<endl;
    return 0;
}