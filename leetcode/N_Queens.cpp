//
// Created by xuyou on 19-3-26.
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<string>>&res,vector<vector<int>>visited, int n,vector<int>index){
    if(index.size()==n){
        vector<string>ns(n,string(n,'.'));
        for(int i=0;i<n;i++)
            ns[i][index[i]]='Q';
        res.push_back(ns);
        return;
    }
    int currow=index.size();
    for(int i=0;i<n;i++){
        if(visited[currow][i]==0){
            visited[currow][i]=1;
            int dir[2][2]={{1,1},{1,-1}};
            vector<vector<int>>change;
            for(int s=0;s<2;s++) {
                for (int j = 1; j <= n - currow - 1; j++) {
                    int nx = currow +dir[s][0]*j;
                    int ny=i+dir[s][1]*j;
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&visited[nx][ny]==0)
                        change.push_back({nx,ny});
                }
            }
            for(int j=0;j<n-currow-1;j++)
                if(visited[currow+j+1][i]==0)
                    change.push_back({currow+j+1,i});
            for(int j=0;j<change.size();j++)
                visited[change[j][0]][change[j][1]]=1;
            index.push_back(i);
            dfs(res,visited,n,index);
            index.pop_back();
//          may affect the original visited  change to
//            for(int j=0;j<n-currow-1;j++)
//                visited[currow+j+1][i]=0;
//            for(int s=0;s<2;s++) {
//                for (int j = 1; j <= n - currow - 1; j++) {
//                    int nx = currow +dir[s][0]*j;
//                    int ny=i+dir[s][1]*j;
//                    if(nx>=0&&nx<n&&ny>=0&&ny<n)
//                        visited[nx][ny]=0;
//                }
//            }
            for(int j=0;j<change.size();j++)
                visited[change[j][0]][change[j][1]]=0;
        }
    }
    return;
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>>visited(n,vector<int>(n,0));
    vector<vector<string>>res;
    vector<int>index;
    dfs(res,visited,n,index);
    return res;
}
using namespace std;
int main(){
    vector<string>vs(3,string(3,','));
    string s(3,'.');
    s[0]='Q';
    //cout<<s<<endl;
    vector<vector<string>>res=solveNQueens(5);
    cout<<res.size()<<endl;
    for(int j=0;j<res.size();j++)
        for(int i=0;i<res[j].size();i++)
            cout<<res[j][i]<<endl;
    return 0;
}
