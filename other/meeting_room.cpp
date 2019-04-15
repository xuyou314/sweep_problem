//
// Created by xuyou on 19-3-20.
//
#include <iostream>
using namespace std;
//struct times{
//    int start,end;
//}T;
int n;

int main(){
    int start[100];
    int finish[100];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>start[i]>>finish[i];
    int max=0,startindex=0,finishindex=1,nextstartindex=0;
    while(startindex<n) {
        while (finishindex < n && start[finishindex] < finish[startindex]) {
            finishindex++;
        }
        max = max > finishindex - startindex ? max : finishindex - startindex;
        startindex=finishindex;
        finishindex+=1;
    }
    cout<<max<<endl;
   return 0;
}
