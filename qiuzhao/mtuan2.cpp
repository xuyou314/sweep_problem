//
// Created by xuyou on 19-4-23.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int grid[2000][2000]={0};
int main() {
    int n,x1,y1,x2,y2;
    cin>>n;
    int ret=0;
    for(int i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        x1+=1000;
        x2+=1000;
        y1+=1000;
        y2+=1000;
        if(x1==x2){

            if(y1>y2){
                int temp=y1;
                y1=y2;
                y2=temp;

            }
            if(y2>=2000||y1<0) {
                ret = ret + y2 - y1;
                continue;
            }
            for(int j=y1;j<=y2;j++)
                if(grid[x1][j]==0){
                    ret++;
                    grid[x1][j]=1;
                }
        } else{
            if(x1>x2){
                int temp=x1;
                x1=x2;
                x2=temp;
            }
            if(x2>=2000||x1<0){
                ret = ret + x2 - x1;
                continue;
            }
            for(int j=x1;j<=x2;j++){
                if(grid[j][y2]==0){
                    ret++;
                    grid[j][y2]=1;
                }
            }

        }
    }
    cout<<ret<<endl;
    return 0;
}
