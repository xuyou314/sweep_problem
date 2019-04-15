//
// Created by xuyou on 19-2-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Solution {
public:
    int numDecodings(char* s) {
        int len = strlen(s);
        int *d = new int[len]();
        d[1]=d[0] = 1;
        if (s[1] < '7' && s[0] < '3'&&s[0]>'0')
            d[1]=2;
        for (int i = 2; i < len; i++) {
            d[i]=d[i-1];
            if (s[i]>'0'&&s[i] < '7' && s[i - 1] < '3'&&s[i-1]>'0')
                d[i] = d[i - 1] + d[i - 2];
            else if(s[i]=='0')
                d[i] = d[i - 2];

        }
        return d[len - 1];
    }
};
int main(){
    Solution s;
    cout<<s.numDecodings("120");

    return 0;
}