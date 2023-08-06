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


bool prove(vector<int>& nums, vector<int> used, vector<int> subsum, int sum, int curr, int n){
	int k = subsum.size();
	if(subsum[curr] == sum){
		if(curr == k-2)
			return true;
		return prove(nums, used, subsum, sum, curr+1, n-1);
	}
	for(int i = n; i >= 0; i--){
		if(used[i])
			continue;
		int temp = subsum[curr] + nums[i];
		if(temp <= sum){
			used[i] = 1;
			subsum[curr] = temp;
			if(prove(nums, used, subsum, sum, curr, i-1))
				return true;
			used[i] = 0;
			subsum[curr] -= nums[i];
		}
	}
	return false;
}


bool is_possible(vector<int>& nums, int k){
	int n = nums.size();
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += nums[i];
	if(sum % k)
		return false;
	int subsetSum = sum / k;
	vector<int> subset;
	for(int i = 0; i < k; i++)
		subset.push_back(0);
	vector<int> used;
	for(int i = 0; i < n; i++)
		used.push_back(0);
	return prove(nums, used, subset, subsetSum, 0, n-1);
}

int main(){
	vector<int> nums = {2, 1, 4, 5, 6};
	int k = 3;
	if(is_possible(nums, k))
		cout << "It's possible\n";
	else
		cout << "It's not possible\n";
	return 0;
}
