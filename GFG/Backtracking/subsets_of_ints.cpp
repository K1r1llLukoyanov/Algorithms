#include <bits/stdc++.h>
using namespace std;



void print_subsets(vector<vector<int>>& subsets){
	for(auto &sub: subsets){
		for(auto item: sub){
			cout << item << " ";
		}
		cout << endl;
	}
}


// brute-force solution

void all_subsets(vector<int>& array, vector<int>& subset, vector<vector<int>>& res, int current_pos){
	int n = array.size();
	res.push_back(subset);
	for(int i = current_pos; i < n; i++){
		subset.push_back(array[i]);
		all_subsets(array, subset, res, i+1);
		subset.pop_back();
	}
}

// bit solution
void print_all_subsets(vector<int>& array, int n){
	for(int i = 1; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				cout << array[j] << " ";
			}
		}
		cout << endl;
	}
}

int main(int args, char** argv){
	vector<int> array;
	for(int i = 1; i < args; i++){
		array.push_back(atoi(argv[i]));
	}
	print_all_subsets(array, array.size());
	return 0;
}
