//
// Created by xuyou on 19-3-15.
//
#include <iostream>
#include <queue>
#include <vector>
using  namespace std;
int st[50][50][50][50]={0};
int legal(char map[50][50],int row,int col,int n,int m){
    if(map[row][col]!='#'&&row<n&&row>=0&&col<m&&col>=0)
        return 1;
    return 0;
}
int main(){
    queue<vector<int>> que;
    char map[50][50]={0};
    int n,m;
    cin>>n>>m;
    int startr,startc,boxr,boxc,endr,endc;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]=='S'){
                startr=i;
                startc=j;
            }
            if(map[i][j]=='E'){
                endr=i;
                endc=j;
            }
            if(map[i][j]=='0'){
                boxr=i;
                boxc=j;
            }
        }
    st[startr][startc][boxr][boxc]=1;
    que.push({startr,startc,boxr,boxc});
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int res=0;
    while(!que.empty()&&res==0){
        vector<int>coordin=que.front();
        que.pop();
        for(int i=0;i<4;i++){
           int hr=coordin[0];
           int hc=coordin[1];
           int boxr=coordin[2];
           int boxc=coordin[3];
           int nhr=dir[i][0]+hr;
           int nhc=dir[i][1]+hc;
           int nnhr=nhr+dir[i][0];
           int nnhc=nhc+dir[i][1];
           if(legal(map,nhr,nhc,n,m)&&(nhr!=boxr||nhc!=boxc)&&st[nhr][nhc][boxr][boxc]==0){
               st[nhr][nhc][boxr][boxc]=st[hr][hc][boxr][boxc]+1;
               que.push({nhr,nhc,boxr,boxc});
           }
           else if(nhr==boxr&&nhc==boxc&&legal(map,nnhr,nnhc,n,m)){
               if(nnhr==endr&&nnhc==endc){
                    res=st[hr][hc][boxr][boxc]+1;
                   break;
               }
               else if(st[nhr][nhc][nnhr][nnhc]==0){
                   st[nhr][nhc][nnhr][nnhc]=st[hr][hc][boxr][boxc]+1;
                   que.push({nhr,nhc,nnhr,nnhc});
               }

           }

        }
    }
    cout<<res-1<<endl;
    return 0;
}
