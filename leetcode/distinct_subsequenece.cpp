//
// Created by xuyou on 19-3-28.
//
#include <string>
#include <vector>
using namespace std;
int numDistinct(string s, string t) {
    int len1=s.size(),len2=t.size();
    vector<vector<long>>d(len2+1,vector<long>(len1+1,0));
    for(int i=0;i<=len1;i++)
        d[0][i]=1;

    for(int i=1;i<=len2;i++)
        for(int j=i;j<=len1;j++){
            long op1=0,op2=0;
            if(s[j-1]==t[i-1]){
                op2=d[i][j-1]+d[i - 1][j - 1];
            }
            else
                d[i][j]=d[i][j-1];
            d[i][j]=d[i][j]>op2?d[i][j]:op2;
        }
    return d[len2][len1];
}
int main(){
    string s1="jletqjoxcrncoxdxvmjaeepydrcchfyftjighntqzoo";
    string s2="rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    int res=numDistinct(s1,s2);
    return 0;
}