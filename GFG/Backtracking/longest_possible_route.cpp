#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<vector<int>> & grid, int i, int j, int n, int m){
 	return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
}



int row[4] = {0, 1, 0, -1};
int col[4] = {1, 0, -1, 0};


void longest_path(vector<vector<int>>& grid, int i, int j, int n, int m, int curr_length, int &max_len, int di, int dj){
	if(i == di && j == dj){
		if(curr_length > max_len){
			max_len = curr_length;
		}
	}
	for(int h = 0; h < 4; h++){
		int ni = i + row[h];
		int nj = j + col[h];
		if(is_valid(grid, ni, nj, n, m)){
			grid[ni][nj] = 2;
			longest_path(grid, ni, nj, n, m, curr_length + 1, max_len, di, dj);
			grid[ni][nj] = 1;
		}
	}
}


int main(){
	vector<vector<int>> mat = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } 
	};
	int n = mat.size();
	int m = mat[0].size();
	int max = 1;
	int di = 1, dj = 7;
	longest_path(mat, 0, 0, n, m, 0, max, di, dj);
	cout << max << endl;
	return 0;
}
