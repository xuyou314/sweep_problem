#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
	vector<vector<int>> capitals;
	for(int i = 0;i < Capital.size();i++){
		capitals.push_back({Capital[i], Profits[i]});
	}
	sort(capitals.begin(), capitals.end());
	//priority_queue<int, vector<int>, less<int>>current_profits;
	priority_queue<int, vector<int>>current_profits;
	int current_capital = W, start_i = 0, len = capitals.size();
	while(k){
		while(start_i < len&&capitals[start_i][0]<=current_capital){
			current_profits.push(capitals[start_i][1]);
			start_i++;
		}
		if(!current_profits.empty()){
			current_capital+=current_profits.top();
			current_profits.pop();
			k--;
		}
		else break;
	}
	return current_capital;
}
int main(){
	vector<int>p = {1,2,3},c = {0,1,1};
	cout<<findMaximizedCapital(2, 0, p, c)<<endl;
	return 0;	
}

