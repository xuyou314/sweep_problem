//
// Created by xuyou on 19-4-21.
//
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>>visited(numCourses,vector<int>(numCourses,0));

    for (int i = 0; i < prerequisites.size(); i++) {
        visited[prerequisites[i].first][prerequisites[i].second]=1;
    }
    for(int i=0;i<numCourses;i++) {
        if (visited[i][i] == 1)
            return false;
    }
    vector<int>allzeros(numCourses,0);
    vector<int>changed(numCourses,0);
    int flag,change,ct=0;
    for(int t=0;t<numCourses;t++) {
        change=0;
        for (int i = 0; i < numCourses; i++) {
            if(allzeros[i])
                continue;
            flag=0;
            for (int j = 0; j < numCourses; j++) {
                if (visited[i][j] == 1) {
                    flag=1;
                    break;
                }
            }
            if(flag)
                continue;
            for (int j = 0; j < numCourses; j++){
                visited[j][i] = 0;
            }
            allzeros[i]=1;
            ct++;
            if(ct==numCourses)
                return true;
            change=1;
        }
        if(change==0)
            return false;
    }
    return true;
}
bool canFinish2(int numCourses, vector<pair<int, int>>& prerequisites) {
    map<int,list<int>>need;
    map<int,vector<int>>isneededby;
    for(int i=0;i<prerequisites.size();i++){
        need[prerequisites[i].first].push_back(prerequisites[i].second);
        isneededby[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    int ct=0;
    vector<int>visited(numCourses,0);
    for(int t=0;t<numCourses;t++) {
        int prect=ct;
        for (int i = 0; i < numCourses; i++) {
            if(visited[i])
                continue;
            if (need.count(i) == 0 || need[i].size() == 0) {
                for (int j = 0; j < isneededby[i].size(); j++) {
                        need[isneededby[i][j]].remove(i);
                }
                visited[i]=1;
                ct++;
                if(ct==numCourses)
                    return true;
            }
        }
        if(prect==ct)
            return false;
    }
    int flag=0;
    for(int i=0;i<numCourses;i++){
        if(need.count(i)==0||need[i].size()==0)
            continue;
        else
            return false;
    }
    return true;
}
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>>graph(numCourses);
    vector<int>indegree(numCourses,0);
    vector<int>order;
    for(int i=0;i<prerequisites.size();i++){
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
        indegree[prerequisites[i].first]++;
    }
    for (int i = 0; i < numCourses; i++) {
        int j=0;
        for (; j < numCourses; j++) {
            if(!indegree[j])
                break;
        }
        if(j==numCourses){
            order.clear();
            return order;
        }
        order.push_back(j);
        indegree[j]--;
        for(int k=0;k<graph[j].size();k++)
            indegree[graph[j][k]]--;
    }
    return order;
}
class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if ((a[1] - a[0])!= (b[1] - b[0])) {

            return (a[1] - a[0]) > (b[1] - b[0]);
        } else
            return a[0]>b[0];

    }
    static bool comp2(vector<int>&a,vector<int>&b){

        return a[0]>b[0];
    }
    static bool comp3(vector<int>&a,vector<int>&b){
        return a[1]<b[1];

    }
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<vector<int>>d(10001,vector<int>(courses.size()+1,0));
        sort(courses.begin(),courses.end(),comp);
        int cur=0;
        int incre;
        for(int i=9999;i>=0;i--){
            incre=0;
            while(cur<courses.size()&&i==courses[cur][1]-courses[cur][0]) {
                cur++;
                incre=1;
            }
            if(incre)
            for(int j=1;j<=cur;j++) {
                d[i][j]=d[i+1][j];
                if (i + courses[j - 1][0] <= 10000) {
                    d[i][j] = d[i + courses[j - 1][0]][j - 1] + 1 > d[i][j] ? d[i + courses[j - 1][0]][j - 1] + 1
                                                                          : d[i][j];
                }
            }
            if(d[i][cur]!=d[i+1][cur])
                for(int j=1;j<=cur;j++)
                    cout<<i<<j<<" "<<d[i][j]<<endl;
        }
        int ret=0;
        for(int i=0;i<=cur;i++)
            ret=ret>d[0][i]?ret:d[0][i];
        return ret;
    }
    int scheduleCourse2(vector<vector<int>>& courses) {
        vector<vector<int>>d(10001,vector<int>(courses.size()+1,0));
        vector<int>avail(10001,0);
        sort(courses.begin(),courses.end(),comp);
        int cur=0,incre;
        for(int i=9999;i>=0;i--){
            incre=0;
            while(cur<courses.size()&&i==courses[cur][1]-courses[cur][0]) {
                cur++;
                incre=1;
            }
            if(incre)
                sort(courses.begin(),courses.begin()+cur,comp2);
            avail[i]=cur;
            for(int j=1;j<=cur;j++) {
                d[i][j]=d[i+1][j];
                d[i][j]=d[i][j-1]>d[i][j]?d[i][j-1]:d[i][j];
                if (i + courses[j - 1][0] <= 10000) {
//                    int pre=avail[i+courses[j-1][0]];
//                    pre=pre>j-1?j-1:pre;
                    d[i][j] = d[i + courses[j - 1][0]][j-1] + 1 > d[i][j] ? d[i + courses[j - 1][0]][j-1] + 1 : d[i][j];
                }
            }
            if(d[i][cur]!=d[i+1][cur])
                for(int j=1;j<=cur;j++)
                    cout<<i<<j<<" "<<d[i][j]<<endl;
        }
        return d[0][cur];
    }
    int scheduleCourse3(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp3);
        vector<int>taken;
        int currenttotal=0;
        for (int i = 0; i < courses.size(); i++) {
            if(currenttotal+courses[i][0]<=courses[i][1]){
                taken.push_back(i);
                currenttotal+=courses[i][0];
            } else{
                if(taken.size()==0)
                    continue;
                int max=0;
                for(int j=0;j<taken.size();j++){
                       if(courses[taken[j]][0]>courses[taken[max]][0])
                            max=j;
                }
                if(courses[taken[max]][0]>courses[i][0]){
                    currenttotal=currenttotal+courses[i][0]-courses[taken[max]][0];
                    taken.erase(taken.begin()+max);
                    taken.push_back(i);
                }
            }
        }
        return taken.size();
    }
};
int main(){
    map<int,vector<int>>pre;
    vector<pair<int, int>>in;
    in.push_back(pair<int,int>(0,1));
    in.push_back(pair<int,int>(1,0));
    vector<int> res=findOrder(2,in);
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.remove(3);
    cout<<pre.count(0)<<endl;
    vector<vector<int>>curs={{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    vector<vector<int>>curs2={{1,2},{2,3}};
    vector<vector<int>>curs3={{5,5},{4,6},{2,6}};
    vector<vector<int>>curs4={{7,16},{2,3},{3,12},{3,14},{10,19},{10,16},{6,8},{6,11},{3,13},{6,16}};
    vector<vector<int>>curs5={{9,14},{7,12},{1,11},{4,7}};
    vector<vector<int>>curs6={{100,2},{32,50}};
    Solution s;
    int ret=s.scheduleCourse3(curs6);
    return 0;
}
