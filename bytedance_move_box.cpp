//
// Created by xuyou on 19-3-15.
//

#include<iostream>
#include<vector>
#include <string.h>
using namespace std;
int min_dis=9999;
int legal(char map[50][50],int sr,int sc,int n,int m){
    if(sr<n&&sr>=0&&sc<m&&sc>=0&&map[sr][sc]!='0'&&map[sr][sc]!='#')
        return 1;
    return 0;

}
int shortest(char map[50][50],int visited[50][50],int sr,int sc,
             int er,int ec,int n,int m){
    //   visited[sr][sc]=1;
    if(sr==er&&sc==ec){
        return 0;
    }
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int min=9999;
    for(int i=0;i<4;i++){
        int nextr=sr+dir[i][0];
        int nextc=sc+dir[i][1];
        if(nextr<n&&nextr>=0&&nextc<m&&nextc>=0&&visited[nextr][nextc]==0&&map[nextr][nextc]!='0'&&map[nextr][nextc]!='#'){
            visited[nextr][nextc]=1;
            int temp=shortest(map,visited,nextr,nextc,er,ec,n,m);
            if(temp!=-1)
                min=min>temp+1?temp+1:min;
            visited[nextr][nextc]=0;
        }

    }
    if(min==9999)
        return -1;
    else
        return min;
}
void dfs_find_step(char map[50][50],int visited[4][50][50],int boxr,
                   int boxc,int predir,
                   int er,int ec,int cur_dis,int n,int m){
    if(cur_dis>min_dis)
        return;
    if(boxr==er&&boxc==ec){
        min_dis=min_dis>cur_dis?cur_dis:min_dis;
        return ;
    }
    visited[predir][boxr][boxc]=1;
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int humanr=boxr-dir[predir][0];
    int humanc=boxc-dir[predir][1];
    for(int i=0;i<4;i++){
        int nextboxr=boxr+dir[i][0];
        int nextboxc=boxc+dir[i][1];
        int nexthumanr=boxr-dir[i][0];
        int nexthumanc=boxc-dir[i][1];
        if(map[nextboxr][nextboxc]!='#'&&visited[i][nextboxr][nextboxc]==0
           &&legal(map,nexthumanr,nexthumanc,n,m)){
            map[nextboxr][nextboxc]='0';
            map[boxr][boxc]='.';
            int tempvisited[50][50]={0};
            int tempdis=shortest(map,tempvisited,humanr,
                                 humanc,nexthumanr,nexthumanc,n,m);
            if(tempdis!=-1){
                visited[i][nextboxr][nextboxc]=1;
                dfs_find_step(map,visited,nextboxr,nextboxc,i,er,
                              ec,cur_dis+tempdis+1,n,m);
                visited[i][nextboxr][nextboxc]=0;
            }
            map[nextboxr][nextboxc]='.';
            map[boxr][boxc]='0';
        }
    }


}
int main(){
    int n,m;
    char map[50][50]={0};
    int visited[50][50]={0};
    int findvisited[4][50][50]={0};

    cin>>n>>m;
//    vector<int*>step;
//    vector<int*>final;
//    int test[2]={3,4};
//    step.push_back(test);
//    final=step;
//    step.pop_back();
    int boxr=-1,boxc=-1,humanr=-1,humanc=-1,endr,endc;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            if(map[i][j]=='0'){
                boxr=i;
                boxc=j;
            }
            if(map[i][j]=='S'){
                humanr=i;
                humanc=j;
            }
            if(map[i][j]=='E'){
                endr=i;
                endc=j;

            }
        }
    //cout<<shortest(map,visited,0,1,2,3,3,6)<<endl;
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    int  res_min=9999,tempdis;
    for(int i=0;i<4;i++) {
        int starthumanr = boxr - dir[i][0];
        int starthumanc = boxc - dir[i][1];
        min_dis=9999;
        if(legal(map,starthumanr,starthumanc,n,m)){

            tempdis=shortest(map,visited,humanr,humanc,starthumanr,starthumanc,n,m);
            if(tempdis!=-1){
                dfs_find_step(map,findvisited,boxr,boxc,i,endr,endc,tempdis,n,m);
                //cout<<min_dis<<endl;
                if(min_dis<res_min)
                    res_min=min_dis;
            }

        }
    }
    //cout<<shortest(map,visited,0,1,0,5,3,6)<<endl;
    if(res_min==9999)
        cout<<-1<<endl;
    else
        cout<<res_min<<endl;
    return 0;
}