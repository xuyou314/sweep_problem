//
// Created by xuyou on 19-3-22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MyCalendar {
public:
    vector<vector<int>>sch;
    vector<vector<int>>a={{-1,3},{1,1}};
public:

    MyCalendar() {

    }

    static bool cmp(vector<int>a,vector<int>b){
        if(a[1]<b[1])
            return true;
        else
            return false;
    }
    bool book(int start, int end) {
        vector<int>temp;
        temp.push_back(start);
        temp.push_back(end);
        if(sch.size()==0){
           sort(a.begin(),a.end());

           sch.push_back(temp);
           return true;
       }
       int flag=0,length=sch.size();
       for(int i=0;i<length;i++)
           if(end<=sch[i][0]||start>=sch[i][1])
               continue;
           else {
               flag = 1;
               break;
           }
        if(flag==0)   {
            sch.push_back(temp);
            return true;
        } else
            return false;
    }
};
int main(){
    MyCalendar *obj=new MyCalendar();
    vector<vector<int>>a={{2,3},{1,1}};
    sort(a.begin(),a.end());
    obj->book(1,2);
    return 0;
}
