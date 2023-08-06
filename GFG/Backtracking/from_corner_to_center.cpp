#include <bits/stdc++.h>
using namespace std;

#define N 9


bool is_valid(vector<vector<int>>& visited, pair<int, int> *point){
	return point->first >= 0 && point->second >= 0 && point->first < N && point->second < N && visited[point->first][point->second] == 0;
}


void print_path(vector<pair<int, int>>& path){
	int n = path.size();
	for(int i = 0; i < n-1; i++){
		cout << "(" << path[i].first << ", " << path[i].second << ") -> ";
	}
	cout << "(" << path[n-1].first << ", " << path[n-1].second << ")\n";
}




int row[4] = {0, 1, 0, -1};
int col[4] = {1, 0, -1, 0};
int _row[4] = {0, 0, N-1, N-1};
int _col[4] = {0, N-1, N-1, 0};

void find_paths_from_corners(int grid[N][N], vector<pair<int, int>> path, vector<vector<int>>& visited, int i, int j){
	if(i == N/2 && j == N/2){
		print_path(path);
		return;
	}
	for(int h = 0; h < 4; h++){
		int ni = i + row[h]*grid[i][j];
		int nj = j + col[h]*grid[i][j];
		pair<int, int> next = make_pair(ni, nj);
		if(is_valid(visited, &next)){
			path.push_back(next);
			visited[ni][nj] = 1;
			find_paths_from_corners(grid, path, visited, ni, nj);
			path.pop_back();
			visited[i][j] = 0;
		}
	}
}

void find_paths(int grid[N][N]){
	vector<vector<int>> visited;
	for(int i = 0; i < N; i++){
		visited.push_back({});
		for(int j = 0; j < N; j++)
			visited[i].push_back(0);
	}
	for(int i = 0; i < 4; i++){
		vector<pair<int, int>> path;
		find_paths_from_corners(grid, path, visited, _row[i], _col[i]);
	}
}


int main(){
	int maze[N][N] = {
			{ 3, 5, 4, 4, 7, 3, 4, 6, 3 },
			{ 6, 7, 5, 6, 6, 2, 6, 6, 2 },
			{ 3, 3, 4, 3, 2, 5, 4, 7, 2 },
			{ 6, 5, 5, 1, 2, 3, 6, 5, 6 },
			{ 3, 3, 4, 3, 0, 1, 4, 3, 4 },
			{ 3, 5, 4, 3, 2, 2, 3, 3, 5 },
			{ 3, 5, 4, 3, 2, 6, 4, 4, 3 },
			{ 3, 5, 1, 3, 7, 5, 3, 6, 4 },
			{ 6, 2, 4, 3, 4, 5, 4, 5, 1 }
	};
	find_paths(maze);
	return 0;
}
