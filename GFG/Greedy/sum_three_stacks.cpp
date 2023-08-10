#include<bits/stdc++.h>
using namespace std;

int equal_sum(vector<vector<int>> &stacks){
	vector<int> sums;
	int n = stacks.size();
	for(int i = 0; i < n; i++){
		int m = stacks[i].size();
		int sum = 0;
		for(int j = 0; j < m; j++)
			sum += stacks[i][j];
		sums.push_back(sum);
	}

	while(1){
		for(int i = 0; i < n; i++)
			if(sums[i] == 0)
				return 0;
		int max = sums[0];
		int max_id = 0;
		for(int i = 1; i < n; i++)
			if(max < sums[i]){
				max = sums[i];
				max_id = i;
			}
		int popped = stacks[max_id][stacks[max_id].size()-1];
		stacks[max_id].pop_back();
		sums[max_id] -= popped;
		int a = sums[0];
		bool equal = true;
		for(int j = 1; j < n; j++)
			if(a != sums[j]){
				equal = false;
				break;
			}
		if(equal)
			return sums[0];
	}
	return 0;
}


int main(){
	vector<vector<int>> stacks = {{ 1,1,1,2,3}, { 2,3,4 }, { 1,4,5,2 }};
	cout << equal_sum(stacks) << endl;
	return 0;
}
