#include <bits/stdc++.h>
using namespace std;

#define N 4

bool is_valid(int maze[N][N], pair<int, int> *point){
	return point->first < N && point->second < N && maze[point->first][point->second] != 0;
}

void print_path(vector<pair<int,int>> &path){
	int n = path.size();
	for(int i = 0; i < n-1; i++)
		cout << "(" << path[i].first << ", " << path[i].second << ") -> ";
	cout << "(" << path[n-1].first << ", " << path[n-1].second << ")\n";
}

int row[2] = {0, 1};
int col[2] = {1, 0};

void find_path(int maze[N][N], vector<pair<int, int>> path, int i, int j){
	if(i == N-1 && j == N-1){
		print_path(path);
		return;
	}

	for(int h = 1; h <= maze[i][j]; h++){
		for(int k = 0; k < 2; k++){
			int ni = i + h*row[k];
			int nj = j + h*col[k];
			
			pair<int, int> next = make_pair(ni, nj);
			if(is_valid(maze, &next)){
				path.push_back(next);
				find_path(maze, path, ni, nj);
				path.pop_back();
			}
		}
	}
}


int main(){
	int maze[N][N] = {
		{ 2, 1, 0, 0 },
	    { 3, 0, 0, 1 },
		{ 0, 1, 0, 1 },
		{ 0, 0, 0, 1 }
	};
	vector<pair<int, int>> path = {{0, 0}};
	find_path(maze, path, 0, 0);
	return 0;
}
