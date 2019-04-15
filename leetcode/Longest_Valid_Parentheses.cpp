//
// Created by xuyou on 19-4-2.
//
#include <iostream>
#include <vector>
using namespace std;
int longestValidParentheses1(string s) {
    int res=0;
    int left=0,right=0,pre=0,out=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            left++;
        else
            right++;
        if(left>=right&&right>0) {
            res = res > 2+pre ? res : 2+pre;
            left--;
            right--;
            if(out==1)
                pre=2+pre;
            out=1;
            continue;
        }
        if(left<right) {
            left = right = 0;
            pre=0;
        }
        out=0;
    }
    res=res>right*2?res:right*2;
    return res;
}
int longestValidParentheses(string s) {
    vector<int>d(s.size()+1,0);
    int res=0;
    for(int i=2;i<=s.size();i++) {
        if (s[i - 1] == '(')
            d[i] = 0;
        else {
            int right = 1, left = 0, j = i - 2;
            while (j >= 0) {
                if (s[j] == '(')
                    left++;
                else
                    right++;
                if (left == right)
                    break;
                j--;
            }
            if (j >= 0)
                d[i] = d[j] + right * 2;
        }
        res=res>d[i]?res:d[i];
    }
    return  res;
}
int main(){
    string test="(()(((()";
    int res=longestValidParentheses("(()(((()");
    return 0;
}
