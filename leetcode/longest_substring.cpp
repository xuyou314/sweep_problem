//
// Created by xuyou on 19-3-22.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int lengthOfLongestSubstring1(string s) {
  vector<int>d(s.size());
  if(s.size()>=1)
    d[0]=1;
  int longest=1;
  for(int i=1;i<s.size();i++) {
      d[i] = d[i - 1] + 1;
      for (int dis = 1; dis <=d[i - 1]; dis++)
          if (s[i - dis] == s[i]) {
              d[i] = dis;
              break;
          }
      longest=longest>d[i]?longest:d[i];
  }
    return longest;
}
int lengthOfLongestSubstring(string s) {
    vector<int>a(256,-1);
    //vector<int>d(s.size());
    if(s.size()==0)
        return 0;
    int start=-1,maxlen=1;
    for(int i=0;i<s.size();i++){
        if(a[s[i]]!=-1)
            start=start>a[s[i]]?start:a[s[i]];
        maxlen=maxlen>i-start?maxlen:i-start;
        a[s[i]]=i;
    }
    return maxlen;
}
int main(){
    string s="abcabcbb";
    lengthOfLongestSubstring(s);
    return 0;
}
