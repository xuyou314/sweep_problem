#include <iostream> 
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
struct cmp{
	bool operator()(const vector<int> &a, const vector<int> &b) const{ 
		if(a[2] != b[2]) return a[2] < b[2];
		if(a[0] != b[0]) return a[0] < b[0];
		if(a[1] != b[1]) return a[1] < b[1];
	}
};

vector<vector<int>> getSkyline(vector<vector<int>> &buildings){
	set<vector<int>, cmp>st;
	vector<vector<int>> events;
	vector<vector<int>> ret;
	for(auto v:buildings){
		events.push_back({v[0], 1, v[1], v[2]});
		events.push_back({v[1], -1, v[0], v[2]});
	}
	sort(events.begin(), events.end());
	for(auto v:events){
		if(v[1] == 1){
			int max_height = 0;
			if(!st.empty()) max_height = (*st.rbegin())[2];
			st.insert({v[0], v[2], v[3]});
			if(max_height < v[3]){
				ret.push_back({v[0], v[3]});
			}
		}
		else{
			
			if(st.empty()) continue;
			int cur_height = (*st.rbegin())[2],max_height = 0;
			st.erase({v[2], v[0], v[3]});
			if(!st.empty()) max_height = (*st.rbegin())[2];
			if(max_height !=cur_height){
				ret.push_back({v[0], max_height});
			}
		}
	
	}
	vector<vector<int>> points;
	int start = 0, len = ret.size();
	while(start<len){
		int maxh = ret[start][1];
		while(start<len-1&&ret[start+1][0]==ret[start][0]){
			start++;
			maxh = max(maxh, ret[start][1]);
		}
		if(points.empty()||points.back()[1]!=maxh){
			points.push_back({ret[start][0], maxh});
		}
		start++;	
	}
	return points;
}
int main(){
	set<vector<int>, cmp>st;
	vector<int> s1 = {2, 9, 10};
	vector<int> s2 = {2, 9, 9};
	vector<int> s3 = {3, 7, 15};
	
	vector<vector<int>> input = {{2, 9, 10},{3, 7, 15}, {5, 12, 12},
	{15, 20,10}, {19,24,8}};
	//vector<vector<int>> input2 = {{0, 2, 3},{2, 5, 3}};
	vector<vector<int>> input2 = {{1, 5, 3},{1, 5, 3}};
	vector<vector<int>>ret = getSkyline(input2);
	for(auto v:ret){
		cout<<v[0]<<" "<<v[1]<<endl;
	}
	vector<vector<int>>ret2 = getSkyline(input);
	for(auto v:ret2){
		cout<<v[0]<<" "<<v[1]<<endl;
	}
	st.erase(s1);
	//st.insert(s1);
	//st.insert(s2);
	//st.insert(s3);
//	cout<<(*st.begin())[2]<<endl;
//	cout<<(*st.rbegin())[2]<<endl;
	return 0;
}

