#include <iostream> 
#include <vector>
using namespace std;
//0-8 row 9-17 col 18-27 box
class Solution {

    public:
        // vector<vector<int>> vis(27, vector<int>(9, 0));
    int ret = 0;
void dfs(vector<vector<char>>&board, int cur_i, vector<vector<int>>pos, vector<vector<int>>&vis){
        if(ret) return;
        if(cur_i == pos.size()){
                ret = 1;
                return;
        }
	int x =pos[cur_i][0], y = pos[cur_i][1];
        int boxnum = x/3*3+y/3;
        for(int i =0;i<9;i++){
                if(vis[x][i]||vis[y+9][i]||vis[boxnum+18][i]){
                        continue;
                }
                board[x][y] = '1'+i;
                vis[x][i]=1;
                vis[y+9][i]=1;
                vis[boxnum+18][i]=1;
                dfs(board, cur_i+1,pos, vis);
                vis[x][i]=0;
                vis[y+9][i]=0;
                vis[boxnum+18][i]=0;
                if(ret) return;
        }
        return ;
}

    void solveSudoku(vector<vector<char>>& board) {
                vector<vector<int>> pos;
 	vector<vector<int>>vis(27, vector<int>(9, 0));
        for(int i = 0;i<9;i++){
                for(int j = 0;j<9;j++){
                        if(board[i][j] == '.'){
                                pos.push_back({i,j});
                                continue;
                        }
                        int num = board[i][j]-'1';
                        vis[i][num] = 1;
                        vis[j+9][num] = 1;
                        int boxnum = i/3*3+j/3;
                        vis[boxnum+18][num] = 1;
                }
        }
        dfs(board,0,pos, vis);

    }
};
int main(){
	Solution s;
	vector<vector<char>>map = 
	{
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};
	s.solveSudoku(map);
	for(auto v:map){
		for(auto j:v){
			cout<<j<<" ";		
		}
		cout<<endl;
	}
	return 0;	
}

