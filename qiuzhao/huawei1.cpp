//
// Created by xuyou on 19-4-10.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    vector<string>out;
    string temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        int t=temp.size()/8+1;
        if(temp.size()%8==0)
            t--;
        for(int j=0;j<t;j++){
            if(j==t-1){
                string in(temp.begin()+j*8,temp.end());
                int zeros=8-temp.size()%8;
                if(zeros==8)
                    zeros=0;
                in=in+string(zeros,'0');
                out.push_back(in);
            } else{
                string in(temp.begin()+j*8,temp.begin()+(j+1)*8);
                out.push_back(in);
            }

        }
    }
    sort(out.begin(),out.end());
    cout<<out[0];
    for(int i=1;i<out.size();i++) {
        cout << " " << out[i];
    }
    return 0;
}
