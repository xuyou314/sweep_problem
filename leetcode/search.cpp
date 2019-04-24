//
// Created by xuyou on 19-4-19.
//
#include <vector>
#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    if(row==0)
        return false;
    int col=matrix[0].size();
    if(col==0)
        return false;
    int low=0,high=row-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(matrix[mid][0]>target)
            high=mid-1;
        else if(matrix[mid][0]<target)
            low=mid+1;
        else
            return true;
    }
    if(low<row&&row>=0) {
        int clow = 0, chigh = col - 1;
        while (clow <= chigh) {
            int mid = (clow + chigh) / 2;
            if (matrix[low][mid] > target)
                chigh = mid - 1;
            else if (matrix[low][mid] < target)
                clow = mid + 1;
            else
                return true;
        }
    }
    if(high<row&&high>=0){
        int clow=0,chigh=col-1;
        while(clow<=chigh){
            int mid=(clow+chigh)/2;
            if(matrix[high][mid]>target)
                chigh=mid-1;
            else if(matrix[high][mid]<target)
                clow=mid+1;
            else
                return true;
        }
    }
    return false;
}
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int row=matrix.size();
    if(row==0)
        return false;
    int col=matrix[0].size();
    if(col==0)
        return false;
    int startrow=0,startcol=col-1;
    while(startrow<row&&startrow>=0&&startcol<col&&startcol>=0){
        if(matrix[startrow][startcol]<target)
            startrow++;
        else if(matrix[startrow][startcol]>target)
            startcol--;
        else
            return true;
    }
    return false;
}
int main(){
    vector<vector<int>>v={{2}};
    int res=searchMatrix(v,1);
    return 0;
}