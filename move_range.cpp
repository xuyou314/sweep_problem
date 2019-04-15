//
// Created by xuyou on 19-2-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {   int res=0;
        int **flag = new int*[rows];
        int **visited=new int *[rows];
        for(int i=0;i<rows;i++ ) {
            flag[i] = new int[cols]();
            visited[i]=new int[cols]();
        }
        for(int i=0;i<rows;i++ )
            for(int j=0;j<cols;j++)
                if(sum(i)+sum(j)<=threshold)
                    flag[i][j]=1;
                dfs(0,0,flag,visited,rows,cols);
        for(int i=0;i<rows;i++ )
            for(int j=0;j<cols;j++)
                res+=visited[i][j];
        return res;
    }
    int sum(int num){
        int t=0;
        while(num){
            t+=num%10;
            num/=10;
        }
        return  t;
    }
    void dfs(int i,int j,int**flag,int **visited,int row,int col){
        int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
        if(flag[i][j]==1&&visited[i][j]==0){
            visited[i][j]=1;
            int ni,nj;
            for(int step=0;step<4;step++){
                ni=i+dir[step][0];
                nj=j+dir[step][1];
                if(ni>=0&&ni<row&&nj>=0&&nj<col)
                    dfs(ni,nj,flag,visited,row,col);
            }
        }

    }
};
int main(){
    Solution s;
    cout<<s.movingCount(10,1,100);
    return 0;
}
