//
// Created by xuyou on 19-4-20.
//
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    int row=n;
    int sc=0,sr=0;
    vector<vector<int>>res(n,vector<int>(n));
    int loop_num=(1+row)/2,cur=1;
    for(int i=0;i<loop_num;i++){
        if(row==1) {
            res[sc][sr] = cur;
            return res;
        }
        for(int i=0;i<row;i++)
            res[sr][sc+i]=cur++;
        for(int i=0;i<row-2;i++)
            res[sr+1+i][sc+row-1]=cur++;
        for(int i=0;i<row;i++)
            res[sr+row-1][sc+row-1-i]=cur++;
        for(int i=0;i<row-2;i++)
            res[sr+row-2-i][sc]=cur++;
        row-=2;
        sc++;
        sr++;
    }
    return  res;
}


class Solution {
public:
    int R1,C1;
    bool legal(int row,int col){
        if(row>=0&&row<R1&&col>=0&&col<C1)
            return true;
        else
            return false;
    }
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        R1=R;
        C1=C;
        vector<vector<int>> res(0,vector<int>(2));
        int nr=r0,nc=c0;
        res.push_back({r0,c0});
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int curd=0,curstep=1;
        int cycle=1;
        while(res.size()<R*C){
             for(int i=0;i<2;i++) {
                for(int j=0;j<curstep;j++) {
                    nr = nr + dir[curd][0];
                    nc = nc + dir[curd][1];
                    if (legal(nr, nc))
                        res.push_back({nr, nc});
                }
                 curd = (curd + 1) % 4;
             }
             curstep++;
        }
        return res;
    }
};
int main(){
    //vector<vector<int>>res=generateMatrix(4);
    Solution S;
    vector<vector<int>>res2=S.spiralMatrixIII(5,6,1,4);
    return 0;
}
