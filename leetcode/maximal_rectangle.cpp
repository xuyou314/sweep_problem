//
// Created by xuyou on 19-3-24.
//
#include <iostream>
#include <vector>
using namespace std;
int maximalRectangle(vector<vector<char>>& matrix) {
      int row=matrix.size(),res=0;
      if(row==0)
          return 0;
      int col=matrix[0].size();
      vector<int>d(col+1,0);
      vector<int>index;
      for(int i=0;i<row;i++) {
          index.clear();
          if(matrix[i][0]=='1')
              d[0]=d[0]+1;
          else
              d[0]=0;
          index.push_back(0);
          for (int j = 1; j <= col; j++) {
              if(j==col||matrix[i][j]=='0')
                  d[j]=0;
              else
                  d[j]=d[j]+1;
              while (!index.empty()&&d[index.back()]>d[j]){
                  int value=d[index.back()];
                  int preid=-1;
                  index.pop_back();
                  if(!index.empty())
                      preid=index.back();
                  int shape=value*(j-preid-1);
                  res=res>shape?res:shape;
              }
              index.push_back(j);
          }
      }
    return res;
}
int main(){
    vector<vector<char>>test={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>>test2={{'0'}};
    int res=maximalRectangle(test2);
    return 0;
}