//
// Created by xuyou on 19-4-6.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:

    int minCut(string s) {
        if(s.size()<=1)
            return 0;
        vector<int>mins(s.size()+1,9999);
        mins[s.size()-1]=1;
        mins[s.size()]=0;
        for(int i=s.size()-2;i>=0;i--){
            mins[i]=mins[i+1]+1;
            for(int j=i+1;j<s.size();j++){
                int flag=1;
                if(s[i]==s[j]){
                    for(int dis=0;dis<(j-i+1)/2;dis++){
                        if(s[i+dis]!=s[j-dis]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag==1){
                        mins[i]=mins[i]>1+mins[j+1]?1+mins[j+1]:mins[i];
                    }
                }

            }
        }
        return mins[0]-1;
    }
};
int main(){

    Solution s;
    string ss="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
    cout<<ss.size()<<endl;
    int res=s.minCut(ss);
    return 0;
}