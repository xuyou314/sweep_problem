//
// Created by xuyou on 19-3-14.
//
#include<iostream>
#include <string>
using namespace std;

int main(){
    int t;
    long n,k,d1,d2;
    cin>>t;
//    double pos[4];
//    for(int i=0;i<t;i++){
//        cin>>n>>k>>d1>>d2;
//        int temp;
//        if(d1>d2)
//            pos[0]=2*d1-d2;
//        else
//            pos[0]=2*d2-d1;
//        pos[1]=d1+d2;
//        pos[2]=2*d1+d2;
//        pos[3]=d1+2*d2;
//        int j=0;
//        if(d1>n/3||d2>n/3){
//            cout<<"no"<<endl;
//            continue;
//        }
//        for(;j<4;j++){
//            double left=n-k-pos[j];
//            if(left>=0&&left%3==0){
//                cout<<"yes"<<endl;
//                break;
//            }
//        }
//        if(j==4)
//            cout<<"no"<<endl;
//    }
    for(int i=0;i<t;i++){
        cin>>n>>k>>d1>>d2;
        int sum=0;
        long temp=n;
        long pos[4];
        long left[4];
        pos[0]=d1+d2;
        pos[1]=2*d1+d2;
        pos[2]=d1+2*d2;

        if(d1>d2) {
            left[0] = 2 * d1 - d2;
            pos[3]=2*d1-d2;
        }
        else {
            left[0] = 2 * d2 - d1;
            pos[3]=2*d2-d1;
        }
        left[1]=d1+2*d2;
        left[2]=2*d1+d2;
        left[3]=d1+d2;
        while(temp!=0){
            sum+=temp%10;
            temp/=10;
        }
        temp=d1>d2?d1:d2;
        if(sum%3==0&&n/3>temp) {
            int j=0;
            for(;j<4;j++) {
                if(k-pos[j]>=0&&(k-pos[j])%3==0&&left[j]<=n-k) {
                    cout << "yes" << endl;
                    break;
                }
            }
            if(j==4)
                cout<<"no"<<endl;
        }
        else
            cout<<"no"<<endl;

    }
    return 0;
}