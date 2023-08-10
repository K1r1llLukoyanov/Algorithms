#include <bits/stdc++.h>
using namespace std;

int min_increments(vector<int>& arr, int k){
	int n = arr.size();
	int carry = arr[0]%k;
	int min = arr[0];
	int min_id = 0;
	for(int i = 1; i < n; i++){
		if(arr[i]%k != carry)
			return -1;
		if(arr[i] < min){
			min = arr[i];
			min_id = i;
		}
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(i == min_id)
			continue;
		count += (arr[i] - min)/k;
	}
	return count;
}


int main(){
	vector<int> arr = {4, 7, 19, 16};
	int k = 3;
	cout << min_increments(arr, k) << endl;
	return 0;
}
