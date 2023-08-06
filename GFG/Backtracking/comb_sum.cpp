#include <bits/stdc++.h>
using namespace std;

void all_unique(vector<int>& set, vector<vector<int>>& unique, int sum, vector<string>& list, vector<int>& subset, string temp, int curr_sum, int curr_pos){
	if(curr_sum > sum)
		return;
	if(curr_sum == sum){
		if(find(list.begin(), list.end(), temp) == list.end()){
			unique.push_back(subset);
			list.push_back(temp);
		}
		return;
	}
	int n = set.size();
	for(int i = curr_pos; i < n; i++){
		subset.push_back(set[i]);
		all_unique(set, unique, sum, list, subset, temp + to_string(set[i]) + '$', curr_sum + set[i], i);
		subset.pop_back();
	}
}


int main(){
	vector<int> arr = {2,4,6,8};
	int sum = 10;
	vector<vector<int>> ans;
	vector<int> subset;
	vector<string> list;
	all_unique(arr, ans, sum, list, subset, "", 0, 0);
	for(auto &set: ans){
		for(auto elem: set)
			cout << elem << " ";
		cout << endl;
	}
	return 0;
}
