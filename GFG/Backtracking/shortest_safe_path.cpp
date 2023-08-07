#include <bits/stdc++.h>
using namespace std;

int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };


bool is_valid(int i, int j, int n, int m){
	return i >= 0 && i < n && j >= 0 && j < m;
}


void util(vector<vector<int>> &grid, int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 0){
				for(int k = 0; k < 4; k++){
					if(is_valid(i + rowNum[k], j + colNum[k], n ,m)){
						grid[i + rowNum[k]][j + colNum[k]] = -1;
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(grid[i][j] == -1)
				grid[i][j] = 0;
}


int bfs(vector<vector<int>>& grid, int n, int m){
	util(grid, n, m);

	for(int i = 0; i < n; i++){
		for(int j = 1; j < m; j++){
			if(grid[i][j] == 0)
				continue;
			else if(i == 0 && j == 0)
				continue;
			else if(i == 0){
				if(grid[i][j-1] != 0)
					grid[i][j] += grid[i][j-1];
				else
					grid[i][j] = 3000;
			}
			else if(j == 0)
				grid[i][j] += grid[i-1][j];
			else{
				if(grid[i-1][j] == 0 && grid[i][j-1] == 0)
					grid[i][j] = 3000;
				else if(grid[i-1][j] == 0)
					grid[i][j] += grid[i][j-1];
				else if(grid[i][j-1] == 0)
					grid[i][j] += grid[i-1][j];
				else{
					grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
				}
			}
		}
	}
	int min = INT_MAX;
	for(int j = 0; j < n; j++){
		if(grid[j][m-1] < min && grid[j][m-1] != 0)
			min = grid[j][m-1];
	}
	return min;
}


int main(){
	vector<vector<int>> mat = {
		        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
				        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
						        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
								        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
										        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
												        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
														        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
																        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
																		        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
																				        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
																						        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
																								        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
			   };
	int n = mat.size(), m = mat[0].size();
	cout << bfs(mat, n, m)-1 << endl;
	return 0;
}
