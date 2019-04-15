//
// Created by xuyou on 19-3-20.
//
#include <iostream>
using namespace std;

int main(){
    int a[1001]={0};
    int d[1001]={0};
    int preindex[1001]={0};
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    d[1]=1;
    preindex[1]=0;
    int output_index=0;
    for(int i=2;i<=n;i++){
        d[i]=1;
        for(int j=1;j<i;j++){
            if(a[i]>a[j])
                if(d[i]<d[j]+1){
                    d[i]=d[j]+1;
                    if(d[output_index]<d[i])
                        output_index=i;
                    preindex[i]=j;
                }
        }
    }

    cout<<d[output_index]<<endl;
    while (preindex[output_index]!=0){
        cout<<a[output_index]<<endl;
        output_index=preindex[output_index];
    }
    cout<<a[output_index]<<endl;
    return 0;
}
