#include <bits/stdc++.h>
using namespace std;

#define N 8

void display(vector<int>& board){
	int arr[N][N] {0};
	for(int i = 0; i < N; i++)
		arr[i][board[i]] = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

bool can_place(vector<int>& board, int k, int i){
	for(int j = 0; j < k; j++){
		if(board[j] == i || abs(board[j] - i) == abs(k-j))
			return false;
	}
	return true;
}

void n_queen(vector<int>& board, int k){
	for(int i = 0; i < N; i++){
		if(can_place(board, k, i)){
			board[k] = i;
			if(k == N-1){
				display(board);
			}
			else{
				n_queen(board, k+1);
			}
			board[k] = -1;
		}
	}
}

int main(){
	vector<int> board;
	for(int i = 0; i < N; i++){
		board.push_back(-1);
	}
	n_queen(board, 0);
	return 0;
}
