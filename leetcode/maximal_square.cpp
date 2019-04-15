//
// Created by xuyou on 19-3-24.
//
#include <iostream>
#include <vector>
using namespace std;
int maximalSquare(vector<vector<char>>& matrix) {
    int row=matrix.size();
    if(row==0)
        return 0;
    int col=matrix[0].size(),res=0;
    vector<vector<int>>d(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]=='0'){
                d[i][j]=0;
                continue;
            }
            if(i==0||j==0){
                d[i][j]=1;
                res=res>d[i][j]?res:d[i][j];
                continue;
            }
            int len=d[i-1][j-1];
            d[i][j]=1;
            res=res>d[i][j]?res:d[i][j];
            for(int k=1;k<=len;k++){
                if(matrix[i][j-k]=='1'&&matrix[i-k][j]=='1'){
                    d[i][j]++;
                    res=res>d[i][j]*d[i][j]?res:d[i][j]*d[i][j];
                }
                else
                    break;
            }
        }
    }
    return res;
}
int main(){
    vector<vector<char>>a={{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    int res=maximalSquare(a);
    return 0;
}