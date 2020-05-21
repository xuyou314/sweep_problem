#include <iostream> 
#include <map>
#include <vector>
#include <string>
using namespace std;
int min_dis(int i, int j, int len){
	int dis = i - j;
	if(i <  j) dis = j - i;
	return min(dis, len-dis);

}
int findRoteSteps(string ring, string key){
	int len = ring.size();
	//shortest_index[i][j] shortest index from i of char 'a'+j
	vector<vector<int>> shortest_index(len, vector<int>(26, -1));
	map<char, vector<int>>indexs;
	for(int i = 0;i < len;i++){
		//a b 'c' 'd' e
		//a b 'c' d
		indexs[ring[i]].push_back(i);
//		for(int j = 0; j<len;j++){
//			char current_char = ring[j];
//			if (i == j||shortest_index[i][current_char-'a'] == -1){
//				shortest_index[i][current_char-'a'] = j;
//				continue;
//			}
//			int dis = min_dis(i, j, len);
//			int current_min = min_dis(i, shortest_index[i][current_char-'a'], len);
//			if(dis < current_min) shortest_index[i][current_char-'a'] = j;
//		}
	}
	cout<<"here"<<endl;
	int klen = key.size();
	//d[i][j] the minimum total cost of searching from key[i] to the end from the position of index j
	vector<vector<int>> d(klen, vector<int>(len, 0x7fffffff)); 
	for(int i = klen-1;i>=0;i--){
		for(int j = 0;j<len;j++){
		//	if(i == klen-1){
		//		int min_index = shortest_index[j][key[i]-'a'];
		//		int cost = min_dis(min_index, j, len);
		//		d[i][j] = cost;
		//	}
			
			for(auto index:indexs[key[i]]){
				int cost = min_dis(j, index, len);
				if(i != klen-1){
					d[i][j] = min(cost+d[i+1][index], d[i][j]);
				}
				else{
					if(d[i][j] == 0x7fffffff){
						d[i][j] = cost;
					}
					else{
						d[i][j] = min(d[i][j], cost);
					}
				}
			}
			cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
		}
	}
	return d[0][0]+klen;
}
int main(){
	map<char, vector<int>>ct;
	string a = "godding", key = "gd";
	ct['a'].push_back(1);
	cout<<findRoteSteps(a,key)<<endl;
	vector<vector<int>> t = {{2,3}, {2}};
	return 0;	
}

