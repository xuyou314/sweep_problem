//
// Created by xuyou on 19-3-18.
//
#include <iostream>
#include <vector>
using namespace std;
int candy(vector<int>&ratings) {
    int ratingsSize= ratings.size();
    //int *ct=new int[ratingsSize];
    vector<int> ct(ratingsSize,1);
    for(int i=0;i<ratingsSize;i++)
        ct[i]=1;
    for(int i=0;i<ratingsSize-1;i++){
        if(ratings[i+1]>ratings[i])
            ct[i+1]=ct[i]+1;
    }
    for(int i=ratingsSize-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]&&ct[i]<ct[i+1]+1)
            ct[i]=ct[i+1]+1;
    }
    int sum=0;
    for(int i=0;i<ratingsSize;i++)
        sum+=ct[i];
    return sum;
}
int main(){
    vector<int>A={1,2,2};
    cout<<candy(A)<<endl;
    return 0;
}
