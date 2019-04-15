//
// Created by xuyou on 19-3-10.
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using  namespace std;

void simple_mult(char *a,int b,char*res){
    char c[2001];
    int lensa=strlen(a);
    int ct=0,temp,cindex=0;
    for(int i=0;i<lensa;i++){
        temp=(a[lensa-i-1]-'0')*b+ct;
        c[i]=temp%10+'0';
        ct=temp/10;

    }
    if(ct!=0){
        c[lensa]='0'+ct;
        lensa+=1;
    }
    res[lensa]=0;
    for(int i=0;i<lensa;i++){
        res[i]=c[lensa-i-1];
    }
}
void add(char *a,char*b,char*sum){
    int lena=strlen(a);
    int lenb=strlen(b);
    char c[2001];
    int ct=0,i=0,tempsum;
    while(i<lena&&i<lenb){
        tempsum=a[lena-i-1]-'0'+b[lenb-i-1]-'0'+ct;
        c[i]= tempsum % 10 + '0';
        ct=tempsum/10;
        i++;
    }
    while (i<lena){
        tempsum=a[lena-i-1]+ct-'0';
        c[i]=tempsum%10+'0';
        ct=tempsum/10;
        i++;

    }
    while (i<lenb){
        tempsum=b[lenb-i-1]+ct-'0';
        c[i]=tempsum%10+'0';
        ct=tempsum/10;
        i++;
    }
    if(ct>0){
        c[i]=ct+'0';
        i++;
    }
    sum[i]=0;
    for(int j=0;j<i;j++)
        sum[j]=c[i-j-1];

}
int main(){
    char a[2001];
    char b[2001];
    char s[2001]="0",temp[2001];
    cin>>a>>b;
    int lena=strlen(a),templen;
    //add(a,b,s);
    //cout<<s<<endl;
    //72724265794384512986367221541249349587164894332307462464657722693758861902455673677472937
    //653451007744809376392212931345812219613865483767182118420188
    for(int i=0;i<lena;i++) {
        simple_mult(b, a[lena-i-1] - '0', temp);
        for(int j=0;j<i;j++) {
            templen=strlen(temp);
            temp[templen] = '0';
            temp[templen+1]=0;
        }
        add(s,temp,s);
    }
    cout<<s<<endl;
    return  0;
}