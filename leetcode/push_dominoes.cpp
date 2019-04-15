//
// Created by xuyou on 19-3-22.
//
#include <iostream>
#include <string>
using namespace std;
string pushDominoes(string dominoes) {
    int start=0,next=0,predir=0;//1 for right
    int length=dominoes.size();
    string res(dominoes.size(),'.');
    while(start<length){
        while(next<length&&dominoes[next]=='.')
            next++;
        if(next>=length)
            break;
        if(dominoes[next]=='R'){
            if(predir==1){
                for(int i=start;i<=next;i++)
                    res[i]='R';
            }
            res[next]='R';
            predir=1;
        }
        else{
            if(predir==0)
                for(int i=start;i<=next;i++)
                    res[i]='L';
            else{
                int mid=(next-start-1)/2+1;
                int i=start;
                while(i<start+mid) {
                    res[i] = 'R';
                    i++;
                }
                if((start+next)%2==0) {
                    res[(start + next) / 2] = '.';
                    i++;
                }
                while(i<=next) {
                    res[i] = 'L';
                    i++;
                }
            }
            predir=0;
        }
        start=next;
        next++;
    }
    if(next==length&&predir==1)
            for(int i=start;i<next;i++)
                res[i]='R';
    return res;

}


int main(){
    string res(".L.R...LR..L..");
    cout<<pushDominoes(res)<<endl;
    return 0;
}
