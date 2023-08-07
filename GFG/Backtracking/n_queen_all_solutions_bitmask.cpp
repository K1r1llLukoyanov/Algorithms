#include <bits/stdc++.h>
using namespace std;

#define N 4


vector<vector<int>> result;

void solve(vector<vector<char>>& board, int row, int rowmask, int ldmask, int rdmask, int &ways){
	
	int all_row_filled = (1 << N) - 1;

	if(all_row_filled == rowmask){
		vector<int> solution;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(board[i][j] == 'Q')
					solution.push_back(j);
		result.push_back(solution);
		ways++;
	}
	
	int safe = all_row_filled & (~(rowmask | ldmask | rdmask));
	
	while(safe){
		int p = safe & (-safe);
		int col = (int)log2(p);
		board[row][col] = 'Q';
		solve(board, row+1, rowmask | p, (ldmask | p) << 1, (rdmask | p) >> 1, ways);
		board[row][col] = ' ';
		safe = safe & (safe - 1);
	}
}


int main(){
	vector<vector<char>> board;
	for(int i = 0; i < N; i++){
		board.push_back({});
		for(int j = 0; j < N; j++)
			board[i].push_back(' ');
	}
	int ways = 0;
	solve(board, 0, 0, 0, 0, ways);
	cout << ways << endl;
	return 0;
}
