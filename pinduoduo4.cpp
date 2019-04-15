//
// Created by xuyou on 19-3-10.
//
#include <iostream>
#include<string.h>
#include <string>
using namespace std;
int way=0;
int legal(string a,int start,int end){
    if(end-start+1==0)
        return 1;
    if(end-start+1==1)
        return 0;

    char left=a[start];
    char right=a[end];
    if(end-start==1){
        if(left=='('&&right==')')
            return 1;
        else
            return 0;
    }
    if(left=='('&&right==')'&&legal(a,start+1,end-1))
        return 1;
    for(int i=start;i<end;i++)
        if(legal(a,start,i)&&legal(a,i+1,end))
            return 1;
    return 0;
}
void dfs(string str,int aindex,int bindex,char *a,char *b){
    if(aindex==strlen(a)&&bindex==strlen(b)){
        cout<<str<<endl;
        if(legal(str,0,str.size()-1))
            way++;
        return;
    }

    if(aindex<strlen(a)) {
        str.push_back(a[aindex]);
        dfs(str,aindex+1,bindex,a,b);
        str.pop_back();
    }
    if(bindex<strlen(b)){
        str.push_back(b[bindex]);
        dfs(str,aindex,bindex+1,a,b);
        str.pop_back();
    }

}
void test(string s){
    s.push_back('c');
}
void dfs2(int left,int right,string a,string b,int&num){
    if(right>left)
        return;
    if(a.size()==0&&b.size()==0&&left==right){
        num++;
        return;
    }
    if(a[0]=='(')
        dfs2(left+1,right,string(a.begin()+1,a.end()),b,num);
    if(a[0]==')')
        dfs2(left,right+1,string(a.begin()+1,a.end()),b,num);
    if(b[0]=='(')
        dfs2(left+1,right,a,string(b.begin()+1,b.end()),num);
    if(b[0]==')')
        dfs2(left,right+1,a,string(b.begin()+1,b.end()),num);
}
int num(string a,string b){
    int num=0;
    dfs2(0,0,a,b,num);
    return num;
}
int main() {
    char a[1000]="((())",b[1000]="())";
    string str;
    //test(str);
    //cout<<legal("(())()",0,5)<<endl;
    //legal("()",0,1);
    dfs(str,0,0,a,b);
    int res=num("(()","())");
    return 0;
}