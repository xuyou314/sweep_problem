//
// Created by xuyou on 19-4-9.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,op,lens;
    cin>>n;
    vector<int>bar;
    for(int i=0;i<n;i++){
        cin>>op>>lens;
        if(op==1){
            bar.push_back(lens);
        }
        else {
            for (vector<int>::iterator iter = bar.begin(); iter != bar.end(); iter++) {
                if (*iter == lens) {
                    bar.erase(iter);
                    break;
                }
            }
        }
        if(bar.size()<3) {
            cout << "No" << endl;
            continue;
        }
        else{
            int max=-1;
            int sum=0;
            for(int i=0;i<bar.size();i++){
                if(bar[i]>max)
                    max=bar[i];
                sum+=bar[i];
            }
            if(sum>2*max)
                cout<<"Yes"<<endl;
            else
                cout << "No" << endl;
        }


    }
    return 0;
}
