//
// Created by xuyou on 19-3-16.
//

#include <iostream>
using  namespace std;
int min_coin=1024;
int coin[4]={64,16,4,1};
//void dfs(int left,int deep){
//    if(left==0){
//        min_coin=min_coin>deep?deep:min_coin;
//        return;
//    }
//    if(deep>min_coin||left<0)
//        return;
//    for(int i=0;i<4;i++)
//        dfs(left-coin[i],deep+1);
//}
int main(){
    int n;
    cin>>n;
    int left=1024-n;
    int receive[1024]={0};
    receive[1]=1;
    for(int i=2;i<=left;i++) {
        int tempmin=1024;
        for (int j=0;j<4;j++){
            if(i-coin[j]>=0){
                tempmin=tempmin>receive[i-coin[j]]+1?receive[i-coin[j]]+1:tempmin;
            }
        }
        receive[i]=tempmin;
    }

    cout<<receive[left]<<endl;
    return 0;
}