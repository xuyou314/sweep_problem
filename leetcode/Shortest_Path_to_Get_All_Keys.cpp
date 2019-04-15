//
// Created by xuyou on 19-3-25.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int shortestPathAllKeys(vector<string>& grid) {
    int row=grid.size();
    if(row==0)
        return -1;
    int col=grid[0].size(),shortest=999;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int startrow,startcol,keycout=0;
    int state[30][30][64]={0};
    for(int i=0;i<row;i++)
        for (int j = 0; j < col; j++){
            if (grid[i][j] == '@') {
                startrow = i;
                startcol = j;
            }
            else if(grid[i][j]!='.'&&grid[i][j]!='#')
                keycout++;
        }
    keycout/=2;
    int finalstate=0,base=1;
    for(int i=0;i<keycout;i++){
        finalstate+=base;
        base*=2;
    }
    queue<vector<int>>q;
    q.push({startrow,startcol,0});
    state[startrow][startcol][0]=1;
    while(!q.empty()){
        vector<int>curstate=q.front();
        q.pop();
        int x=curstate[0],y=curstate[1],keystate=curstate[2];
        for(int i=0;i<4;i++){
            int nx=dir[i][0]+x;
            int ny=dir[i][1]+y;
            if(nx<0||nx>=row||ny<0||ny>=col||grid[nx][ny]=='#')
                continue;
            if(grid[nx][ny]<='f'&&grid[nx][ny]>='a'){
                int nextstate=keystate|(1<<(grid[nx][ny]-'a'));
                if(state[nx][ny][nextstate]!=0)
                    continue;
                if(nextstate==finalstate)
                    return state[x][y][keystate];
                else {
                    q.push({nx, ny, nextstate});
                    state[nx][ny][nextstate]=state[x][y][keystate]+1;
                }
            }
            else if(grid[nx][ny]<='F'&&grid[nx][ny]>='A'){
                if((keystate&(1<<grid[nx][ny]-'A'))==0)
                    continue;
                else{
                    if(state[nx][ny][keystate]!=0)
                        continue;
                    q.push({nx,ny,keystate});
                    state[nx][ny][keystate]=state[x][y][keystate]+1;
                }

            }
            else{
                if(state[nx][ny][keystate]!=0)
                    continue;
                q.push({nx,ny,keystate});
                state[nx][ny][keystate]=state[x][y][keystate]+1;
            }

        }
    }
    return -1;
}
int main(){
    vector<string>s={"@.a.#","###.#","b.A.B"};
    vector<string>s2={"@..aA","..B#.","....b"};
    vector<string>s3={"@abcdeABCDEFf"};
    vector<string>s4={".@aA"};
    //cout<<(31&(1<<('F'-'A')));
    int res=shortestPathAllKeys(s);
    //cout<<(0|(1<<4));
    return 0;
}
