//
// Created by xuyou on 19-4-4.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int longestPalindromeSubseq(string s) {
    int lens=s.size();
    if(lens<=1)
        return lens;
    vector<vector<int>>d(lens+1,vector<int>(lens+1,0));
    for(int i=1;i<=lens;i++)
        d[i][i]=1;
    int dis=1;
    while(dis<lens){
        for(int i=1;i<=lens-dis;i++){
                if(s[i-1]==s[i+dis-1])
                    d[i][i+dis]=d[i+1][i+dis-1]+2;
                else
                    d[i][i+dis]=d[i+1][i+dis]>d[i][i+dis-1]?d[i+1][i+dis]:d[i][i+dis-1];
        }
        dis++;
    }
    return d[1][lens];
}
string longestPalindrome(string s) {
    int lens=s.size();
    if(lens<=1)
        return s;
    vector<vector<int>>d(lens+1,vector<int>(lens+1,0));
    for(int i=1;i<=lens;i++)
        d[i][i]=1;
    for(int i=2;i<=lens;i++)
        d[i][i-1]=1;
    int dis=1,start=1,maxdis=0;
    while(dis<lens){
        for(int i=1;i<=lens-dis;i++){
            if(s[i-1]==s[i+dis-1])
                d[i][i+dis]=d[i+1][i+dis-1]*1;
            else
                d[i][i+dis]=0;
            if(d[i][i+dis]==1) {
                start = i;
                maxdis=dis;
            }
        }
        dis++;
    }
    string res(s.begin()+start-1,s.begin()+start+maxdis);
    return res;
}
int main(){
    string res=longestPalindrome("cbbd");
    return 0;
}