#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &solution){
	int n = solution.size();
	for(int i = 0; i < n; i++){
		cout << "[ ";
		int m = solution[i].size();
		for(int j = 0; j < m; j++)
			cout << solution[i][j] << " ";
		cout << "] ";
	}
	cout << endl;
}


void partition(vector<int>& nums, vector<vector<int>>& solution, vector<int>& sums, int left, int pos){
	int n = nums.size();
	int m = solution.size();
	
	if(pos == n){
		int first = sums[0];
		for(int i = 1; i < m; i++){
			if(first != sums[i])
				return;
		}
		display(solution);
		return;
	}

	for(int i = pos; i < n; i++){
		for(int j = 0; j < m; j++){
			solution[j].push_back(nums[i]);
			sums[j] += nums[i];
			partition(nums, solution, sums, left-nums[i], i+1);
			solution[j].pop_back();
			sums[j] -= nums[i];
		}
	}
}


int main(){
	vector<int> nums = {2, 1, 4, 5, 6};
	int k = 3;
	vector<vector<int>> solution;
	vector<int> sums;
	for(int i = 0; i < k; i++){
		solution.push_back({});
		sums.push_back(0);
	}
	partition(nums, solution, sums, 18, 0);
	return 0;
}
