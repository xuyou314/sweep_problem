//
// Created by xuyou on 19-4-13.
//
#include <iostream>
#include <map>
using namespace std;
int edges[100000][2];
int main() {
    int n,res=0;
    cin>>n;
    map<int,int>pre;
    map<int,int>precount;
    for(int i=0;i<n-1;i++) {
        cin >> edges[i][0] >> edges[i][1];
        if(pre.count(edges[i][0])==0)
            pre[edges[i][0]]=edges[i][0];
        if(pre.count(edges[i][1])==0)
            pre[edges[i][1]]=edges[i][1];
        precount[edges[i][0]]=1;
        precount[edges[i][1]]=1;
    }

    for(int i=0;i<n-1;i++) {
        if(edges[i][1]!=1&&pre[edges[i][0]]!=pre[edges[i][1]]){
            precount[pre[edges[i][1]]]+=precount[pre[edges[i][0]]];
            pre[edges[i][0]]=pre[edges[i][1]];
            res=res>precount[pre[edges[i][1]]]?res:precount[pre[edges[i][1]]];
        }
    }
    cout<<res<<endl;
}
