//
// Created by xuyou on 19-3-18.
//
#include <iostream>
#include <queue>
using  namespace std;
int st[1024]={0};
//runtime error
//int control[10][100];
int control[100][10];
int main(){
    int n,m;
    cin>>n>>m;
    int light[10]={0};
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>control[i][j];
    int prestate=0;
    st[prestate]=1;
    queue<int>states;
    states.push(prestate);
    while (!states.empty()) {
        int currentstate=states.front();

        states.pop();
        for (int i = 0; i < m; i++) {
            int temp=currentstate;
            for(int j=0;j<n;j++){
                light[j]=temp%2;
                temp/=2;
            }
            for (int j = 0; j < n; j++) {
                if (control[i][j] == 1 && light[j] == 0)
                    light[j] = 1;
                else if (control[i][j] == -1 && light[j] == 1)
                    light[j] = 0;
            }
            //compute state
            int base = 1, nextstate=0;
            for (int j = 0; j < n; j++) {
                nextstate = nextstate + base * light[j];
                base *= 2;
            }
            if(st[nextstate]==0){
                st[nextstate]=st[currentstate]+1;
                states.push(nextstate);
            }
        }
    }
    int finalstate=0,base=1;
    for(int i=0;i<n;i++) {
        finalstate += base;
        base*=2;
    }
    cout<<st[finalstate]-1<<endl;
}
