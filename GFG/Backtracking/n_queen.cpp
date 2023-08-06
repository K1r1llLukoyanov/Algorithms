#include <bits/stdc++.h>
using namespace std;

void n_queen(vector<vector<int>>& board, int row, int cols, int rows, int &count){
	if(row == rows){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		count++;
		return;
	}

	for(int i = 0; i < cols; i++){
		bool good = true;
		for(int j = row; j >= 0; j--)
			if(board[j][i]){
				good = false;
				break;
			}
		if(!good)
			continue;
		for(int j = row, k = i; j >= 0 && k >= 0; j--, k--)
			if(board[j][k]){
				good = false;
				break;
			}
		if(!good)
			continue;
		for(int j = row, k = i; j >= 0 && k < cols; j--, k++)
			if(board[j][k]){
				good = false;
				break;
			}
		if(!good)
			continue;
		
		board[row][i] = 1;
		n_queen(board, row+1, cols, rows, count);
		board[row][i] = 0;
	}
}


int main(){
	vector<vector<int>> board;
	int rows = 8;
	int cols = 8;
	for(int i = 0; i < rows; i++){
		board.push_back({});
		for(int j = 0; j < cols; j++){
			board[i].push_back(0);
		}
	}
	int count = 0;
	n_queen(board, 0, cols, rows, count);
	cout << count << endl;
	return 0;
}
