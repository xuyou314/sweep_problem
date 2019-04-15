//
// Created by xuyou on 19-2-26.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
class Solution{
public:
    bool match(char *str,char*pattern){
        int m=strlen(str);
        int n=strlen(pattern);
        int **dp=new int*[m+1];
        for(int i=0;i<m+1;i++){
            dp[i]=new int[n+1]();
        }
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            if(pattern[i-1]=='*')
                dp[0][i]=dp[0][i-2];
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(pattern[j-1]=='*'){
                    if(pattern[j-2]=='.'||pattern[j-2]==str[i-1]) {
                        dp[i][j] = dp[i][j - 1]+dp[i][j-2]+dp[i-1][j-1];
                    } else{
                        dp[i][j]=dp[i][j-2];
                    }
                }
                else{
                    if(pattern[j-1]=='.'||pattern[j-1]==str[i-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
    void pri(char*str,char*pat){
        int m=strlen(str);
        int n=strlen(pat);
        //int **dp=(int**)malloc((m+1)*sizeof(int*));
        int **dp=new int*[m+1];
        for(int i=0;i<m+1;i++){
            dp[i]=new int[n]();
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                printf("%d",dp[i][j]);

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                dp[i][j]=1;

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                printf("%d",dp[i][j]);

        }
    }
};
int main(){
    char str[]="aaa";
    char pattern[]=".*";
    Solution s;
    printf("%d",s.match(str,pattern));
}
