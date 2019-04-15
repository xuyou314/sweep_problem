//
// Created by xuyou on 19-4-10.
//
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    string in,out;
    cin>>in;
    //stack<char>sta;
    for(int i=0;i<in.size();i++){
        if(in[i]!=')'&&in[i]!=']'&&in[i]!='}')
            out.push_back(in[i]);
        else if(in[i]==')'){
            string temp;
            while(out.back()!='('){
                temp.push_back(out.back());
                out.pop_back();
            }
            reverse(temp.begin(),temp.end());
            out.pop_back();
            int t=out.back()-'0';
            out.pop_back();
            for(int j=0;j<t;j++)
                out+=temp;
        }
        else if(in[i]==']'){
            string temp;
            while(out.back()!='['){
                temp.push_back(out.back());
                out.pop_back();
            }
            reverse(temp.begin(),temp.end());
            out.pop_back();
            int t=out.back()-'0';
            out.pop_back();
            for(int j=0;j<t;j++)
                out+=temp;
        }
        else if(in[i]=='}'){
            string temp;
            while(out.back()!='{'){
                temp.push_back(out.back());
                out.pop_back();
            }
            reverse(temp.begin(),temp.end());
            out.pop_back();
            int t=out.back()-'0';
            out.pop_back();
            for(int j=0;j<t;j++)
                out+=temp;
        }
    }
    cout<<out<<endl;
    reverse(out.begin(),out.end());
    //out.reserve();
    cout<<out<<endl;
    return 0;
}
