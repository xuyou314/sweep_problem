//
// Created by xuyou on 19-4-9.
//
#include <iostream>
#include <vector>
using namespace std;
int find_pre(int i,vector<int>&pre){
    while(pre[i]!=i){
     i=pre[i];
    }
    return i;
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int max=-1;
    for(int i=0;i<edges.size();i++){
        max=max>edges[i][0]?max:edges[i][0];
        max=max>edges[i][1]?max:edges[i][1];
    }
    vector<int>d(max+1,0);
    vector<int>pred(max+1,0);
    for(int i=0;i<max+1;i++)
        pred[i]=i;
    vector<int>res;
    for(int i=0;i<edges.size();i++){
        if(find_pre(edges[i][0],pred)!=find_pre(edges[i][1],pred)){
             pred[find_pre(edges[i][0],pred)]=find_pre(edges[i][1],pred);
        } else{
            res.clear();
            if(edges[i][0]>edges[i][1])
                swap(edges[i][0],edges[i][1]);
            res.push_back(edges[i][0]);
            res.push_back(edges[i][1]);
        }
    }
    return res;
}
int main(){
    vector<vector<int>>inpt={{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>>inpt2={{9,10},{5,8},{2,6},{1,5},{3,8},{4,9},{8,10},{4,10},{6,8},{7,9}};
    vector<int>res;
    res=findRedundantConnection(inpt2);
    return 0;
}
