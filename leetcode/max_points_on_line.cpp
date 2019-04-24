//
// Created by xuyou on 19-4-22.
//
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int maxPoints(vector<vector<int>>& points) {
    map<pair<double,double>,int>ratect;
    map<int,int>vectical;
    if(points.size()==0)
        return 0;
    vector<int>weight(points.size(),1);
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            if(points[i][0]==points[j][0]&&points[i][1]==points[j][1]) {
                points.erase(points.begin() + j);
                weight.erase(weight.begin()+j);
                weight[i]++;
            }
        }
    }

    int res=0,vect=0,intercept;
    double rate;
    if(points.size()==1)
        return weight[0];
    vector<int>vis(weight.size(),1);
    map<pair<double,double>,int>line_to_index;
    vector<int>vis2(weight.size(),1);
    for (int i = 0; i < points.size(); i++) {
        for(int j=i+1;j<points.size();j++){
            if (points[i][0] - points[j][0] == 0) {
                vectical[points[i][0]] = vectical[points[i][0]] + weight[i] * weight[j] +vis[i]* weight[i] * (weight[i] - 1) / 2 +
                           vis[j]* weight[j] * (weight[j] - 1) / 2;
                if(weight[i]>1)
                    vis[i]=0;
                if(weight[j]>1)
                    vis[j]=0;
                res=vectical[points[i][0]]>res?vectical[points[i][0]]:res;
            } else {
                rate = (points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                intercept=points[i][1]-rate*points[i][0];
                pair<double,double>p(rate,intercept);
                ratect[p]=ratect[p]+weight[i]*weight[j]+weight[i]*(weight[i]-1)/2+weight[j]*(weight[j]-1)/2;
                res=ratect[p]>res?ratect[p]:res;
            }
        }
    }
    double delta=1+8*res;
    res= int((1 + sqrt(delta)) / 2);
    return res;

}
int gcd(int a,int b){

    if(b==0)
        return a;
    return gcd(b,a%b);

}
int maxPoints2(vector<vector<int>>& points) {
    int res=0;

    for(int i=0;i<points.size();i++){
        map<pair<int,int>,int>rate2ct;
        for(int j=i+1;j<points.size();j++){
            int dx=points[i][0]-points[j][0];
            int dy=points[i][1]-points[j][1];
            int g=gcd(dx,dy);
            if(g!=0) {
                dx = dx / g;
                dy = dy / g;
            }
            pair<int,int>p(dx,dy);
            rate2ct[p]++;
        }
        pair<int,int>same(0,0);
        res=res>rate2ct[same]+1?res:rate2ct[same]+1;
        for(auto v:rate2ct){
            if(v.first.first||v.first.second){
                res=res<v.second+rate2ct[same]+1?v.second+rate2ct[same]+1:res;
            }
        }
    }
    return res;

}
int main(){
    vector<vector<int>>res={{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<vector<int>>res2={{1,1},{2,2},{3,3}};
    vector<vector<int>>res3={{1,1},{1,1},{2,3}};
    vector<vector<int>>res4={{0,0},{0,0}};
    vector<vector<int>>res5={{0,-1},{0,3},{0,-4},{0,-2},{0,-4},{0,0},{0,0},{0,1},{0,-2},{0,4}};
    vector<vector<int>>res6= {{-230,324},{-291,141},{34,-2},{80,22},{-28,-134},{40,-23},{-72,-149},{0,-17},{32,-32},{-207,288},{7,32},{-5,0},{-161,216},{-48,-122},{-3,39},{-40,-113},{115,-216},{-112,-464},
                              {-72,-149},{-32,-104},{12,42},{-22,19},{-6,-21},{-48,-122},{161,-288},{16,11},{39,23},{39,30},{873,-111}};

    int ret=maxPoints2(res6);
    return 0;
}