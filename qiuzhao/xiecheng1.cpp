//
// Created by xuyou on 19-4-8.
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d[10000][6]={0};
    int t[5];
    for(int i=0;i<n;i++)
        cin>>d[i][5];
    vector<int>mins(3,999);
    vector<int>maxs(3,-999);
    for(int i=0;i<n;i++) {
        for (int j = 0; j < 5; j++) {
            cin>>d[i][j];
            if(j>1){
                mins[j-2]=mins[j-2]<d[i][j]?mins[j-2]:d[i][j];
                maxs[j-2]=maxs[j-2]>d[i][j]?maxs[j-2]:d[i][j];
            }
        }
    }
    for(int i=0;i<n;i++) {
        for (int j = 0; j < 3; j++) {
            //cout<<(d[i][j + 2] - mins[j]) /((maxs[j] - mins[j]) / 3.0)<<endl;
            d[i][j + 2] = int((d[i][j + 2] - mins[j]) / ((maxs[j] - mins[j]) / 3.0));
            if(d[i][j+2]==3)
                d[i][j+2]--;
        }
    }
    int x2y[2][2][2]={0};
    int x3y[3][3][2]={0};
    int y[2]={0};
    for(int i=0;i<n;i++)
        y[d[i][5]]++;
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            x2y[j][d[i][j]][d[i][5]]++;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            x3y[j][d[i][j+2]][d[i][5]]++;
    for(int i=0;i<5;i++) {
        cin >> t[i];
        if(i>1) {
            t[i] = int((t[i] - mins[i - 2]) / ((maxs[i - 2] - mins[i - 2]) / 3.0));
            if(t[i]==3)
                t[i]--;
        }
    }
    double fengzi0=double(y[0])/n;
    for(int i=0;i<5;i++)
        if(i<2)
            fengzi0*=double(x2y[i][t[i]][0])/y[0];
        else
            fengzi0*=double(x3y[i-2][t[i]][0])/y[0];
    double fengzi1=double(y[1])/n;
    for(int i=0;i<5;i++) {
        if (i < 2)
            fengzi1 *= double(x2y[i][t[i]][1]) / y[1];
        else
            fengzi1 *= double(x3y[i - 2][t[i]][1]) / y[1];
    }
    printf("%.3lf",fengzi1/fengzi0);
    return 0;
}
