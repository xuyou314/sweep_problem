//
// Created by xuyou on 19-2-26.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 999999
int adj[1002][1002]={0};
int cost[1002][1002]={};
int dist[1002];
int costdist[1002];
int visited[1002]={0};
int min(int left,int right){
    if(left<right)
        return left;
    return right;
}
void dij(int source,int n){
    int pre;
    pre = source - 1;
    visited[pre] = 1;
    dist[pre] = 0;
    costdist[pre]=0;

    for(int i=0;i<n-1;i++){
        int cur_min_node=-1,min_dist=MAX;
        for(int j=0;j<n;j++){
            if(adj[pre][j]>0&&visited[j]==0&&dist[j]>=dist[pre]+adj[pre][j]) {

                if(dist[j]>dist[pre]+adj[pre][j]) {
                    costdist[j] = costdist[pre] + cost[pre][j];
                }
                else {
                    costdist[j]=min(costdist[j],costdist[pre]+cost[pre][j]);
                }
                dist[j] = dist[pre] + adj[pre][j];
            }

        }
        for(int j=0;j<n;j++) {
            if (dist[j] < min_dist && visited[j] != 1) {
                min_dist = dist[j];
                cur_min_node = j;
            }

        }
        //printf("%d\n",dist[target-1]);
        if(min_dist==MAX){
            break;
        }
        pre=cur_min_node;
        visited[pre]=1;
    }


}
int main(){
    int n,m,col,row,distance,source,target,costitem;


//
    FILE *fd=freopen("input","r",stdin);
    if(!fd){
        printf("read error exit");
        return 0;
    }
    while (true) {
        scanf("%d %d\n", &n, &m);
        if(n==0)
            break;
//        memset(visited,0,n*sizeof(int));
        for (int i = 0; i < n; i++) {
            costdist[i]=dist[i] = 99999;
            visited[i]=0;
            for(int j=0;j<n;j++){
                adj[i][j]=cost[i][j]=0;
            }
//            memset(adj[i],0,n* sizeof(int));
//            memset(cost[i],0,n* sizeof(int));
        }
        for (int i = 0; i < m; i++) {
            //cin >> row >> col >> distance>>costitem;
            scanf("%d %d %d %d",&row,&col,&distance,&costitem);
            if(adj[row-1][col-1]==0||distance<=adj[row-1][col-1]) {

                if(distance==adj[row-1][col-1]&&cost[col-1][row-1]!=0)
                    cost[row-1][col-1]=cost[col-1][row-1]=min(cost[col-1][row-1],costitem);
                else
                    cost[row-1][col-1]=cost[col-1][row-1]=costitem;
                adj[row - 1][col - 1] = adj[col - 1][row - 1] = distance;
            }

        }
        cin >> source >> target;
        dij(source,n);
        cout<<dist[target-1]<<" "<<costdist[target-1]<<endl;

    }
    return 0;


}
