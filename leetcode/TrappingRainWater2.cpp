//
// Created by xuyou on 19-3-25.
//
#include <iostream>
#include <queue>
using namespace std;
struct coord{
    int x,y,height;
    coord(int x,int y,int h):x(x),y(y),height(h){}
};
struct cmp {
    bool operator()(coord a, coord b) {
        return a.height>b.height;
    }
};

int trapRainWater(vector<vector<int>>& heightMap) {
    priority_queue<coord,vector<coord>,cmp>q;
    int row=heightMap.size();
    if(row==0)
        return 0;
    int col=heightMap[0].size();
    int curmin=9999999,res=0;
    vector<vector<int>>visited(row,vector<int>(col));
    for(int i=0;i<row;i++){
        if(visited[i][0]==0){
            curmin=curmin>heightMap[i][0]?heightMap[i][0]:curmin;
            q.push(coord(i,0,heightMap[i][0]));
            visited[i][0]=1;
        }
        if(visited[i][col-1]==0){
            curmin=curmin>heightMap[i][col-1]?heightMap[i][col-1]:curmin;
            q.push(coord(i,col-1,heightMap[i][col-1]));
            visited[i][col-1]=1;
        }
    }
    for(int i=0;i<col;i++){
        if(visited[0][i]==0){
            curmin=curmin>heightMap[0][i]?heightMap[0][i]:curmin;
            q.push(coord(0,i,heightMap[0][i]));
            visited[0][i]=1;
        }
        if(visited[row-1][i]==0){
            curmin=curmin>heightMap[row-1][i]?heightMap[row-1][i]:curmin;
            q.push(coord(row-1,i,heightMap[row-1][i]));
            visited[row-1][i]=1;
        }
    }
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    while (!q.empty()) {
        coord temp = q.top();
        int cx=temp.x;
        int cy=temp.y;
        q.pop();
        curmin=temp.height>curmin?temp.height:curmin;
        for (int i = 0; i < 4; i++) {
            int nx=cx+dir[i][0];
            int ny=cy+dir[i][1];
            if(nx<0||nx>=row||ny<0||ny>=col||visited[nx][ny]==1)
                continue;
            visited[nx][ny]=1;
            int height=heightMap[nx][ny];
            if (height >= curmin) {
                q.push(coord(nx,ny,height));
                continue;
            }
            else{
                res=res+curmin-height;
                q.push(coord(nx,ny,height));
            }
        }
    }
    return  res;
}

int main(){
    priority_queue<coord,vector<coord>,cmp>q;
    coord z(1,2,1);
    coord x(1,2,3);
    coord y(1,2,2);
    q.push(z);
    q.push(x);
    q.push(y);
    while (!q.empty()){
        coord temp=q.top();
        q.pop();
        cout<<temp.height<<endl;
    }
    vector<vector<int>>heigh={{1,4,3,1,3,2}, {3,2,1,3,2,4}, {2,3,3,2,3,1}};
    vector<vector<int>>heigh2={{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
    int res=trapRainWater(heigh2);
    return 0;
}