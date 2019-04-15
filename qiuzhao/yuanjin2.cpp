//
// Created by xuyou on 19-4-9.
//
#include <iostream>
#include <vector>
using namespace std;
int count(vector<int> A, int n) {
    int ct=0;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++)
            if(A[i]>A[j])
                ct++;
    }
    return ct;
}
int main(){


    return 0;
}
