//
// Created by xuyou on 19-4-10.
//
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int vis[600][600]={0};
int map[600][600]={0};
long long int flag[600][600]={0};
long long int flag2[600][600]={0};
int n,m,sr,sc,er,ec;
long long int res=0;
void dfs(int row,int col,vector<vector<int>>&f2){
    int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    if(row==er&&col==ec) {
        res++;
        return;
    }
    if(flag[row][col]==-1)
        return;
    if(flag[row][col]>0){
        res=res+flag[row][col]+f2[row][col];
        return;
    }
    long long int curres=res;
    for(int t=0;t<4;t++){
        int nx=row+next[t][0];
        int ny=col+next[t][1];
        if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]==1)
            continue;
        if(map[nx][ny]<=map[row][col])
            continue;
        f2[nx][ny]++;
        vis[nx][ny]=1;
        dfs(nx,ny,f2);
        vis[nx][ny]=0;
    }
    if(curres==res)
        flag[row][col]=-1;
    if(curres!=res)
        flag[row][col]=res-curres;
    return;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>map[i][j];
    cin>>sr>>sc>>er>>ec;
    vector<vector<int>>f(n,vector<int>(m,0));
    vis[sr][sc]=1;
    dfs(sr,sc,f);
    printf("%lld",res%1000000000);
    cout<<endl;
    return 0;
}
