#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
// Read only region start
void dfs(int cur,int maxlen,int curlen,int n,int end,int&res){
    if(curlen>maxlen+1)
        return;
    if(cur==end&&curlen>1)
        res++;
    for(int i=1;i<=n;i++){
        if(i==cur)
            continue;
        if(cur%i==0||i%cur==0){
            dfs(i,maxlen,curlen+1,n,end,res);
        }
    }

}
int maxCircles(int input1,int input2,int input3)
{
    int res=0;
    dfs(input2,input3,1,input1,input2,res);
    return res;
}
int main(){

    int res=maxCircles(3,2,4);
    return 0;
}