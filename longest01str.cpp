//
// Created by xuyou on 19-3-14.
//
#include<iostream>
#include<string.h>
using namespace std;
int main() {
    int n, m, maxlen = 1;
    char str[50000];
    cin >> n >> m;
    cin >> str;
    //0 for a and 1 for b
//    int maxnum=1;
//    for(int i=1;i<strlen(str);i++){
//        int j=i;
//        int changea=0,changeb=0;
//        //end with a
//        while(j>=0&&(changea<m||str[j]=='a')){
//            if(str[j]=='b'){
//                changea++;
//            }
//            j--;
//        }
//        maxnum=maxnum>i-j?maxnum:i-j;
//        j=i;
//        while(j>=0&&(changeb<m||str[j]=='b')){
//            if(str[j]=='a'){
//                changeb++;
//            }
//            j--;
//        }
//        maxnum=maxnum>(i-j)?maxnum:(i-j);
//    }
//    cout<<maxnum<<endl;
    int length[2][50000] = {0};
    int changetime[2][50000] = {0};
    //0 for a and 1 for b
    length[0][0] = length[1][0] = 1;
    if (str[0] == 'a')
        changetime[1][0] = 1;
    else
        changetime[0][0] = 1;
    for (int i = 1; i < strlen(str); i++){
        if (str[i] == 'a') {
            length[0][i] = length[0][i - 1] + 1;
            changetime[0][i] = changetime[0][i - 1];
            if (changetime[1][i - 1] < m) {
                length[1][i] = length[1][i - 1] + 1;
                changetime[1][i] = changetime[1][i - 1] + 1;
            } else {
                int temp = i;
                int change = 0;
                while (change < m || str[temp] == 'b') {
                    if (str[temp] == 'a')
                        change++;
                    temp--;
                }
                length[1][i] = i - temp;
                changetime[1][i] = m;
            }
        } else {
            length[1][i] = length[1][i - 1] + 1;
            changetime[1][i] = changetime[1][i - 1];
            if (changetime[0][i - 1] < m) {
                length[0][i] = length[0][i - 1] + 1;
                changetime[0][i] = changetime[0][i - 1] + 1;
            } else {
                int temp = i;
                int change = 0;
                while (change < m || str[temp] == 'a') {
                    if (str[temp] == 'b')
                        change++;
                    temp--;
                }
                length[0][i] = i - temp;
                changetime[0][i] = m;
            }
        }
        int tempmaxlen=length[0][i]>length[1][i]?length[0][i]:length[1][i];
        maxlen=maxlen>tempmaxlen?maxlen:tempmaxlen;
}

    cout<<maxlen<<endl;
    return 0;
}
