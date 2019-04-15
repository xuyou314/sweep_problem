//
// Created by xuyou on 19-2-27.
//
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using  namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows=matrix.size();
        vector<int>firstrow=matrix.front();
        int cols=firstrow.size();

    }
};
void create(){
    vector<vector<int>>mat;
    vector<int>row;
    for(int i=0;i<3;i++){
        row.clear();
        for(int j=0;j<4;j++)
            row.push_back(i*j);
        mat.push_back(row);
    }
    row=mat.front();
    printf("%d %d",mat.size(),mat[2][3]);

}
int main(){
    Solution s;

    create();
    return 0;
}
