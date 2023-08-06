#include <bits/stdc++.h>
using namespace std;

void TOW(vector<int>& set, int sum, int& min_diff, int curr_position, int left_size, int n, bool *elements, bool* sol){
	if(left_size == n/2){
		int summ = 0;
		for(int i = 0; i < n; i++){
			if(!elements[i])
				summ += set[i];
		}
		if(abs(sum - summ) < min_diff){
			for(int i = 0; i < n; i++)
				sol[i] = 0;
			for(int i = 0; i < n; i++)
				if(elements[i])
					sol[i] = 1;
			min_diff = abs(sum - summ);
		}
		return;
	}
	for(int i = curr_position; i < n; i++){
		elements[i] = 1;
		TOW(set, sum + set[i], min_diff, i+1, left_size+1, n, elements, sol);
		elements[i] = 0;
	}
}


int main(){
	vector<int> set = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n = set.size();
	int min_diff = INT_MAX;
	bool elements[n] {0};
	bool solution[n] {0};
	TOW(set, 0, min_diff, 0, 0, n, elements, solution);
	cout << min_diff << endl;
	for(int i = 0; i < n; i++)
		if(solution[i])
			cout << set[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		if(!solution[i])
			cout << set[i] << " ";
	cout << endl;
}
