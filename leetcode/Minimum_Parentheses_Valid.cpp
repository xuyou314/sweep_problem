//
// Created by xuyou on 19-4-2.
//
#include <string>
using namespace std;
int minAddToMakeValid(string S) {
    int left=0,right=0;
    int leftadd=0;
    for(int i=0;i<S.size();i++){
        if(S[i]=='(')
            left++;
        else{
            if(left>0)
                left--;
            else
                leftadd++;
        }
    }
    return leftadd+left;
}
