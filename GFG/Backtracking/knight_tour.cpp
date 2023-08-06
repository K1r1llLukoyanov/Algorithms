#include <bits/stdc++.h>
using namespace std;

void tour_problem(vector<vector<int>>& board, int rows, int cols, int visited, int i, int j){
	board[i][j] = visited;
	if(rows*cols-1 == visited){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++)
				cout << board[i][j] << " ";
			cout << endl;
		}
		exit(1);
	}
	if(i+1 < rows && j-2 >= 0 && board[i+1][j-2] == 0)
		tour_problem(board, rows, cols, visited+1, i+1, j-2);
	if(i+1 < rows && j+2 < cols && board[i+1][j+2] == 0)
		tour_problem(board, rows, cols, visited+1, i+1, j+2);
	if(i-1 >= 0 && j-2 >= 0 && board[i-1][j-2] == 0)
		tour_problem(board, rows, cols, visited+1, i-1, j-2);
	if(i-1 >= 0 && j+2 < cols && board[i-1][j+2] == 0)
		tour_problem(board, rows, cols, visited+1, i-1, j+2);
	if(i-2 >= 0 && j - 1 >= 0 && board[i-2][j-1] == 0)
		tour_problem(board, rows, cols, visited+1, i-2, j-1);
	if(i-2 >= 0 && j + 1 < cols && board[i-2][j+1] == 0)
		tour_problem(board, rows, cols, visited+1, i-2, j+1);
	if(i+2 < rows && j - 1 >= 0 && board[i+2][j-1] == 0)
		tour_problem(board, rows, cols, visited+1, i+2, j-1);
	if(i+2 < rows && j + 1 < cols && board[i+2][j+1] == 0)
		tour_problem(board, rows, cols, visited+1, i+2, j+1);
	board[i][j] = 0;
}


int main(){
	vector<vector<int>> board;
	int N = 8;
	for(int i = 0; i < N; i++){
		board.push_back({});
		for(int j = 0; j < N; j++)
			board[i].push_back(0);
	}
	tour_problem(board, N, N, 0, 0, 0);
	return 0;
}
