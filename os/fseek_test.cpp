//
// Created by xuyou on 19-4-3.
//
#include <stdio.h>
#include <unistd.h>
int main(){
    FILE*fp=fopen("input","r+");
    FILE*fp2=fopen("input","r+");
    char c;
    fputc('d',fp2);
    fclose(fp2);
    c=fgetc(fp);
    fclose(fp2);
    if(fp==NULL) {
        printf("%s", "fail");
        return 1;
    }
    //fseek(fp,0,2);
    //char buf[50]={"file description"};
    //write(fp->_fileno,buf,50);
    //int len=ftell(fp);
    //printf("%d",len);
    return 0;
}