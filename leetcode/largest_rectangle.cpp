//
// Created by xuyou on 19-3-23.
//
#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int largestRectangleArea2(vector<int>& heights) {
    int length=heights.size(),curheight;
    //map<int,int>m;
    int m[10000]={0};
    int preheight=heights[0];
    for(int i=1;i<=heights[0];i++)
        m[i]=1;
    int res=0,shape;
    for(int i=1;i<length;i++){
        curheight=heights[i];
        for(int i=curheight;i<=preheight;i++)
            m[i]=0;
        for(int j=1;j<=curheight;j++) {
            m[j] += 1;
            shape=j*m[j];
            res=res>shape?res:shape;
        }
        preheight=curheight;
    }
    return res;
}
int largestRectangleArea3(vector<int>& heights) {
    int length=heights.size(),curheight;
    map<int,int>m;
    if(length==0)
        return 0;
    //int m[10000]={0};
    int preheight=heights[0];
    m[preheight]=1;
    int res=heights[0],shape;
    for(int i=1;i<length;i++){
        curheight=heights[i];
        int flag=0;
        if(m.count(curheight)==0)
            flag=1;
        auto it=m.begin();
        while (it!=m.end()) {
            if (it->first > curheight) {
                if(flag==1)
                    m[curheight]=m[curheight]>it->second+1?m[curheight]:it->second+1;
                auto re = it;
                it++;
                m.erase(re->first);
            } else {
                m[it->first]++;
                it++;
            }
        }
        m[curheight]=m[curheight]>1?m[curheight]:1;
        for(auto i:m) {
          shape=i.first*i.second;
          res=res>shape?res:shape;
        }

    }
    return res;
}
int largestRectangleArea4(vector<int>& heights) {
    int length=heights.size(),curheight,res=0,index=0,preindex;
    if(length==0)
        return 0;
    heights.push_back(-1);
    stack<int>elestack,indexstack;
    elestack.push(heights[0]);
    indexstack.push(0);
    index++;
    for(;index<=length;index++){
        while (!elestack.empty()&&elestack.top()>heights[index]){
         int value=elestack.top();
         elestack.pop();
         indexstack.pop();
         preindex=-1;
         if(!indexstack.empty())
            preindex=indexstack.top();
         int shape=value*(index-preindex-1);
         res=res>shape?res:shape;
        }
        elestack.push(heights[index]);
        indexstack.push(index);
    }
    return res;
}
int largestRectangleArea(vector<int>& heights) {
    int length=heights.size(),res=0,index=0,preindex;
    if(length==0)
        return 0;
    heights.push_back(-1);
    stack<int>indexstack;
    indexstack.push(0);
    index++;
    for(;index<=length;index++){
        while (!indexstack.empty()&&heights[indexstack.top()]>heights[index]){
            int value=heights[indexstack.top()];
            indexstack.pop();
            preindex=-1;
            if(!indexstack.empty())
                preindex=indexstack.top();
            int shape=value*(index-preindex-1);
            res=res>shape?res:shape;
        }
        indexstack.push(index);
    }
    return res;
}
int main(){
    vector<int>a={2,1,5,6,2,3};
    vector<int>a2={0,0,0,0,0,0,0,0,2147483647};
    vector<int>a3={1,1};
    vector<int>a4={2,1,4,5,1,3,3};
    vector<int>a5={3,6,5,7,4,8,1,0};
//    map<int,int>m;
//    m[1]=2;
//    m[2]=3;
//    auto it=m.begin();
//    auto remove=it;
//    it++;
//    m.erase(remove->first);
    int res=largestRectangleArea(a);
    return 0;
}
