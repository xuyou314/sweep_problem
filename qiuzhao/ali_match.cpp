//
// Created by xuyou on 19-4-9.
//
#include <iostream>
using namespace std;
bool isdigit(string s){
    int i=0;
    for(;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0')
            continue;
        else
            return false;
    }
    return true;
}
bool isNumber(string s) {
    int pointindex=-1,expindex=-1,startindex=0,startindex2;
    int starti=0,endi=0;
    if(s.size()==0)
        return false;
    while(starti<s.size()&&s[starti]==' ')
        starti++;
    while(s.size()-endi>=1&&s[s.size()-endi-1]==' ')
        endi++;
    if(starti+endi>=s.size())
        return false;
    s=string(s.begin()+starti,s.end()-endi);
    for(int i=0;i<s.size();i++) {
        if (s[i] == '.')
            pointindex = i;
        if(s[i]=='e')
            expindex=i;
    }
    if(s[0]=='-')
        startindex=1;
    if(s==".")
        return false;
    if(pointindex==expindex-1)
        return false;
    if(pointindex!=-1&&pointindex!=0){
        if(!isdigit(string(s.begin()+startindex,s.begin()+pointindex)))
            return false;
    }
    if(pointindex==-1) {
        if (s[0] == '-')
            pointindex += 1;
    }
    if(expindex==s.size()-1||expindex==0)
        return false;
    if(expindex==-1)
        return isdigit(string(s.begin()+pointindex+1,s.end()));
    else{
        if(!isdigit(string(s.begin()+pointindex+1,s.begin()+expindex)))
            return false;
        if(s[expindex+1]=='-')
            startindex2=expindex+1;
        else
            startindex2=expindex;
        return isdigit(string(s.begin()+startindex2+1,s.end()));
    }

}

int main(){
    string t="0.1";
    string t2="0";
    string t3="abc";
    string t4="1 a";
    string t5="2e10";
    string t6="-90e3";
    string t7="1e";
    string t8[7]={"e3","6e-1","99e2.5","  53.5e93  ","--6","++3","95a54e53"};
    int res=isNumber(".e1");
    for(int i=0;i<7;i++)
        cout<<isNumber(t8[i])<<endl;
    return 0;
}
