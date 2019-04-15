//
// Created by xuyou on 19-3-16.
//
#include <iostream>
#include <string.h>
using  namespace std;
int main(){
    int n;
    cin>>n;
    char str[1000];
    for(int i=0;i<n;i++){
        cin>>str;
        int lens=strlen(str);
        if(lens<=2) {
            cout << str << endl;
            break;
        }
        int prepre=1,pre=1;
        char prechar=str[1],preprechar=str[0];
        if(str[0]==str[1]){
            pre=2;
            prepre=-1;
        }
        for(int j=2;j<lens;j++){
            if(pre==2&&str[j]==prechar) {
                str[j] = '#';
                continue;
            }
            if(pre==1&&prepre==2){
                str[j]='#';
                continue;
            }
            if(pre==2&&prepre==-1){
                pre=1;
                prepre=2;
                preprechar=prechar;
                prechar=str[j];
                continue;
            }
            prepre=pre;
            if(str[j]==prechar)
                pre+=1;

            prechar=str[j];
        }
        for(int j=0;j<lens;j++)
            if(str[j]!='#')
            cout<<str[j];
        cout<<endl;
    }
    return 0;
}