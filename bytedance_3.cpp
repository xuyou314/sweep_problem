//
// Created by xuyou on 19-3-16.
//

#include <iostream>
int a[100000];
int d[100000];
using  namespace std;
int main() {
    int t,n;
    cin >>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++) {
            cin >> a[j];
            d[j]=1;
        }
        for(int j=0;j<n;j++){
            int left_less=0;

                for (int left = 1; left < n; left++) {
                    if (a[(j + n - left)%n] < a[(j + n - left + 1) % n]) {
                        left_less += 1;
                    } else if (a[(j + n - left)%n] == a[(j + n - left + 1) % n]) {
                        continue;
                    } else {
                        break;

                    }
                }

//            else if(a[j]>a[j-1]){
//                left_less=d[j];
//
//            }
//            else if(a[j]==a[j-1]){
//                left_less=d[j]-1;
//            }
            int right_less=0;
            for(int right=1;right<n;right++){
                if(a[(j+right)%n]<a[(j+right-1)%n]){
                    right_less+=1;
                }
                else if(a[(j+right)%n]==a[(j+right-1)%n]){
                    continue;
                } else{

                    break;
                }
            }

            if(a[j]>a[(j+1)%n])
                d[j]=right_less+1;
            if(a[j]>a[(j+n-1)%n]&&left_less>=d[j]-1)
                d[j]=left_less+1;
        }
        int sum=0;
        for(int j=0;j<n;j++)
            sum+=d[j];
        cout<<sum<<endl;
    }
    return 0;
}