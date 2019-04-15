//
// Created by xuyou on 19-3-29.
//
#include <vector>
#include <string>
using namespace std;
void dfs(vector<string>cur,string leftstring,vector<vector<string>>&res){
    if(leftstring.size()==0){
        res.push_back(cur);
        return;
    }
    for(int i=0;i<leftstring.size();i++){
        if(leftstring[i]==leftstring[0]){
           int flag=0;
            for(int j=1;j<=i/2;j++){
               if(leftstring[j]!=leftstring[i-j]) {
                   flag = 1;
                   break;
               }
           }
           if(flag==0){
               string temp(leftstring.begin(),leftstring.begin()+i+1);
               cur.push_back(temp);
               dfs(cur,string(leftstring.begin()+i+1,leftstring.end()),res);
               cur.pop_back();
           }
        }
    }

}
void dfs2(int index,vector<string>&cur,string &leftstring,vector<vector<string>>&res){
    if(index==leftstring.size()){
        res.push_back(cur);
        return;
    }
    for(int i=index;i<leftstring.size();i++){
        if(leftstring[i]==leftstring[index]){
            int flag=0;
            for(int j=1;j<=(i-index)/2;j++){
                if(leftstring[index+j]!=leftstring[i-j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                cur.push_back(leftstring.substr(index,i-index+1));
                dfs2(i+1,cur,leftstring,res);
                cur.pop_back();
            }
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>>res;
    vector<string>cur;
    dfs2(0,cur,s,res);
    return res;
}
int main(){
    vector<vector<string>>res=partition("aab");
    return 0;
}