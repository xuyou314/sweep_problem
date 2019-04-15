//
// Created by xuyou on 19-3-10.
//

#include <iostream>
#include<string.h>
using namespace std;

int main() {
    char s[50];
    int ct[52]={0};
    char output;
    cin>>s;
    for(int i=0;i<strlen(s);i++)
        if(s[i]>='a'&&s[i]<='z')
            ct[s[i]-'a']+=1;
        else
            ct[s[i]-'A'+26]+=1;
//    for(int i=0;i<26;i++){
//        if(ct[i]>0||ct[i+26]>0){
//            output=i+'a';
//            cout<<output<<endl;
//            return 0;
//        }
        int min=30;
        for(int i=0;i<strlen(s);i++) {
            int index;
            int big=0;
            if(s[i]>='a'&&s[i]<='z')
                index=s[i]-'a';
            else {
                index = s[i] - 'A';
                big=1;
            }
            if(index<min)
                min=index;
            if(ct[index]==0||ct[index+26]==0)
                break;
            else
                ct[big*26+index]=0;

        }
        output='a'+min;
        cout<<output<<endl;

    return 0;
}