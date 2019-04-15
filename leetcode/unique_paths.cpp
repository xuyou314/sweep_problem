//
// Created by xuyou on 19-4-10.
//
#include <iostream>
#include <vector>
using namespace std;
int uniquePaths(int m, int n) {
    vector<vector<int>>d(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        d[i][0]=1;
    for (int i = 0; i < m; ++i) {
        d[0][i]=1;
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            d[i][j]=d[i-1][j]+d[i][j-1];
    return d[n-1][m-1];
}
long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=obstacleGrid.size();
    int m=obstacleGrid[0].size(),flag=0;
    vector<vector<long>>d(n,vector<long>(m,0));
    for(int i=0;i<n;i++) {
        if(flag==0&&obstacleGrid[i][0]==0)
            d[i][0] = 1;
        else{
            d[i][0]=0;
            flag=1;
        }
    }
    flag=0;
    for(int i=0;i<m;i++) {
        if(flag==0&&obstacleGrid[0][i]==0)
            d[0][i] = 1;
        else{
            d[0][i]=0;
            flag=1;
        }
    }
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(obstacleGrid[i][j])
                continue;
            else
                 d[i][j]=(1-obstacleGrid[i-1][j])*d[i-1][j]+(1-obstacleGrid[i][j-1])*d[i][j-1];
    return d[n-1][m-1];
}
int main(){
    vector<vector<int>>grid={{0,0,0},{0,1,0},{0,0,0}};

    long res=uniquePathsWithObstacles(grid);
    return 0;
}
