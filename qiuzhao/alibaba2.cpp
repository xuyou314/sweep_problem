#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/


int ballAllocate(int m, int n, int k) {
    //vector<vector<int>>d1(m+1,vector<int>(k+1,0));
    int mm=m>n?m:n;
    vector<vector<int>>d1(k+1,vector<int>(mm+1,0));
    for(int i=1;i<=mm;i++)
        d1[1][i]=1;
    for(int i=1;i<=k;i++)
        d1[i][1]=1;
    for(int i=0;i<=k;i++)
        d1[i][0]=1;
    for(int i=2;i<=k;i++)
        for(int j=2;j<=mm;j++){
            d1[i][j]=d1[i-1][j-1]+d1[i][j-i];
        }
    int res=0;
    for(int i=1;i<k&&i<=m;i++){
        for(int j=1;j<=k-i&&j<=n;j++)
        res=res+d1[i][m]*d1[j][n];
    }
    return  res;
}

int main() {
    int res;

//    int _m;
//    cin >> _m;
//    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
//
//
//    int _n;
//    cin >> _n;
//    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
//
//
//    int _k;
//    cin >> _k;
//    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



    res = ballAllocate(1, 1, 3);
    cout << res << endl;

    return 0;

}