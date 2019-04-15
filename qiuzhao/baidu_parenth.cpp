//
// Created by xuyou on 19-4-2.
//
//牛牛现在给出一个括号序列s,牛牛允许你执行的操作是:在s的开始和结尾处添加一定
//数量的左括号('[')或者右括号(']')使其变为一个合法的
//括号匹配序列。牛牛希望你能求出添加最少的括号之后的合法的括号匹配序列是什么。
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string s;
    stack<char>str;
    int left=0,right=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[')
            str.push('[');
        else {
            if(!str.empty()&&str.top()=='[')
                str.pop();
            else {
                str.push(']');
            }
        }
    }
    while(!str.empty()){
        if(str.top()=='[')
            left++;
        else
            right++;
        str.pop();
    }
    cout<<string(right,'[')+ s+string(left,']')<<endl;
    return 0;
}
