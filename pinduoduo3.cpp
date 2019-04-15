#include <iostream>
#include<string.h>
using namespace std;

int main() {
    int n,d;
    int a[200000],b[200000];
    cin>>n>>d;
    int max=-1;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);

    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(a[i]-a[j]>=d||a[j]-a[i]>=d){
                if(max<b[i]+b[j])
                    max=b[i]+b[j];

            }

    }
    cout<<max<<endl;
    return 0;
}