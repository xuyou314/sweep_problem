//
// Created by xuyou on 19-3-8.
//
#include<stdio.h>
#include<iostream>
using namespace std;
int mindis=99999;
void find_min(char map[100][100],int visited[100][100],int startrow,int startcol,int endrow,int endcol,int m,int n,int deep){
    if(deep>1000)
        return;
    if(startrow==endrow&&startcol==endcol)
        if(mindis>deep) {
            cout<<deep<<endl;
            mindis = deep;
            return;
        }
    int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    visited[startrow][startcol]=1;
    for(int i=0;i<4;i++){
        int nextrol=startrow+dir[i][0];
        int nextcol=startcol+dir[i][1];
        char nextchar;
        if(nextrol<0||nextrol>m-1||nextcol<0||nextcol>n-1)
            continue;
        nextchar=map[nextrol][nextcol];
        if(nextchar=='0'||visited[nextrol][nextcol]==1)
            continue;
        if(nextchar>='A'&&nextchar<='Z')
            continue;

        int doorrow,doorcol;
        if(nextchar>='a'&&nextchar<='z'){

            for(int r=0;r<m;r++)
                for(int c=0;c<n;c++) {
                    if (map[r][c] == 'A' - 'a' + nextchar) {
                        doorrow = r;
                        doorcol = c;

                    }
                    if(map[r][c]<='z'&&map[r][c]>='a'&&visited[r][c]==1)
                        visited[r][c] = 1;
                    else
                        visited[r][c]=0;
                }
            map[doorrow][doorcol]='1';

            visited[nextrol][nextcol]=1;
            find_min(map ,visited,nextrol,nextcol,endrow,endcol,m,n,deep+1);

            map[doorrow][doorcol]=nextchar+'A'-'a';
            visited[nextrol][nextcol]=0;
        } else{
            visited[nextrol][nextcol]=1;
            find_min(map ,visited,nextrol,nextcol,endrow,endcol,m,n,deep+1);
            visited[nextrol][nextcol]=0;
        }
    }

}
void pri(char c[100][100]){
    cout<<c[0][0];
}
int main(){
    int m,n,sr,sc,er,ec;
    cin>>m>>n;
    char map[100][100];

    int visited[100][100]={0};
    for(int i=0;i<m;i++ )
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            if(map[i][j]=='2'){
                sr=i;
                sc=j;
            }
            if(map[i][j]=='3'){
                er=i;
                ec=j;
            }
        }

    find_min(map,visited,sr,sc,er,ec,m,n,0);
    cout<<mindis<<endl;
    return 0;
}
