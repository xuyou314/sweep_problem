//
// Created by xuyou on 19-3-28.
//
#include <string>
#include <vector>
using namespace std;
void dfs(vector<string>&s,int left,int right,string curs,string sta,int n){
    if(left==n&&right==n)
        s.push_back(curs);
    if(left<n){
      curs.push_back('(');
      sta.push_back('(');
      dfs(s,left+1,right,curs,sta,n);
      sta.pop_back();
      curs.pop_back();
    }
    if(!sta.empty()){
        sta.pop_back();
        curs.push_back(')');
        dfs(s,left,right+1,curs,sta,n);
        sta.push_back('(');
    }

}
vector<string> generateParenthesis(int n) {
    vector<string>res;
    string str,sta;
    dfs(res,0,0,str,sta,n);
    return  res;
}
int main(){
    vector<string>res=generateParenthesis(4);
    return 0;
}
