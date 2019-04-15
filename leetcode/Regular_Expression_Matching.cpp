//
// Created by xuyou on 19-3-28.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isMatch(string s, string p) {
    int len1=s.size();
    int len2=p.size();
    vector<vector<int>>d(len1+1,vector<int>(len2+1,0));
    d[0][0]=1;
    for(int i=2;i<=len2;i+=2)
        if(p[i-1]=='*')
            d[0][i]=d[0][i-2];
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++){
            int op1=0,op2=0,op3=0,op4=0;
            if(p[j-1]=='*'){
                op1=d[i][j-2];
                int dis=0;
                while(i-1-dis>=0&&(p[j-2]==s[i-1-dis]||p[j-2]=='.')){
                    op2+=d[i-1-dis][j-2];
                    dis++;
                }
            }
            else if(p[j-1]=='.')
                op3=d[i-1][j-1];
            else if(p[j-1]==s[i-1])
                op4=d[i-1][j-1];
            if(op1||op2||op3||op4)
                d[i][j]=1;
        }
    return d[len1][len2];
}
int main(){
    int res=isMatch("ab","c*a*b");
    char s[3][2]={{'(',')'},{'[',']'},{'{','}'}};
    return 0;
}