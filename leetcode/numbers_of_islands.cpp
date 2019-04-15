//
// Created by xuyou on 19-3-22.
//
//
// Created by xuyou on 19-3-18.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int numIslands(vector<vector<char>>& grid) {

    int row=grid.size();
    if(row==0)
        return 0;
    int col=grid[0].size();
    vector<vector<int>>visited(row,vector<int>(col));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            visited[i][j]=0;
    queue<vector<int>>que;
    int ct=0;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++){
            if(visited[i][j]==0&&grid[i][j]=='1'){
                que.push({i,j});
                visited[i][j]=1;
                while(!que.empty()){
                    vector<int>loc=que.front();
                    que.pop();
                    for(int move=0;move<4;move++){
                        int nx=loc[0]+dirs[move][0];
                        int ny=loc[1]+dirs[move][1];
                        if(nx<row&&nx>=0&&ny<col&&ny>=0&&visited[nx][ny]==0&&grid[nx][ny]=='1'){
                            visited[nx][ny]=1;
                            que.push({nx,ny});
                        }

                    }
                }
                ct++;
            }

        }
    return ct;
}
int main(){
    queue<vector<int>>que;
    que.push({1,2});
    vector<vector<char>>A={{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    int re=numIslands(A);
    return 0;
}

