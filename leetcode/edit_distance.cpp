//
// Created by xuyou on 19-3-25.
//
#include <iostream>
#include <vector>
using namespace std;
int minDistance(string word1, string word2) {
    int len1=word1.size();
    int len2=word2.size();
    if(len1==0)
        return len2;
    if(len2==0)
        return len1;
    vector<vector<int>>d(len1+1,vector<int>(len2+1,0));
    for(int i=0;i<=len2;i++)
        d[0][i]=i;
    for(int i=0;i<=len1;i++)
        d[i][0]=i;
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++){
           int op1,op2,op3;
           op1=d[i][j-1]+1;
           op2=d[i-1][j]+1;
           if(word1[i-1]==word2[j-1])
               op3=d[i-1][j-1];
           else
               op3=d[i-1][j-1]+1;
           op1=op1<op2?op1:op2;
           op3=op1<op3?op1:op3;
           d[i][j]=op3;
        }
    return d[len1][len2];
}
int main(){
    string s1="horse",s2="ros",s3="intention",s4="execution";
    string s5="sea",s6="eat";
    string s7="pneumonoultramicroscopicsilicovolcanoconiosis";
    string s8="ultramicroscopically";

    int res=minDistance(s1,s2);
    cout<<res<<endl;
    return 0;
}
