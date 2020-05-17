#include <iostream> 
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int removeCoveredIntervals(vector<vector<int>> &intervals){
	int len = intervals.size();
	vector<int>vis(len, 0);
	for(int i = 0;i<len;i++){
		for(int j = 0;j<len;j++){
			if(i==j||vis[j]) continue;
			if(intervals[i][0]>=intervals[j][0]&&intervals[i][1]<=intervals[j][1]){
				vis[i] = 1;
			}
		}
	}
	int sum = 0;
	for(auto v:vis){
		if(!v) sum++;
	}
	return sum;
}
struct cmp{
	bool operator()(vector<int> int1, vector<int> int2) const{
		if(int1[0]!=int2[0]) return int1[0] < int2[0];
		return int1[1] < int2[1];
	}
};
int removeCoveredIntervals2(vector<vector<int>> &intervals){
	int len = intervals.size();
	vector<vector<int>>ins,outs;
	vector<vector<int>>events;
	set<vector<int>, cmp>st;
	for(auto v:intervals){
		events.push_back({v[0], 1, v[1]});	
		events.push_back({v[1], -1, -v[0]});	
	}
	sort(events.begin(), events.end());
	for(auto v:events){
		if(v[1] == 1){
			st.insert({v[0], v[2]});
		}
		else{
			st.erase({-v[2],v[0]});
			if(!st.empty()){
				int low = (*st.begin())[0];
				if(low<=-v[2]) len--;
			}
		}
	}
	return len;
}
int main(){
	vector<vector<int>>input= {{1,4},{3,6},{2,8}};
	
	vector<vector<int>>input2= {{3,10},{4,10},{5,11}, {8,9},{9,11},{1,2}};
	for(int i=0;i<10000;i++) removeCoveredIntervals2(input2);
	return 0;	
}

