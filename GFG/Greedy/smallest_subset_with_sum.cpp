#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	int sum1 = 0, sum2 = arr[n-1];
	for(int i = 0; i < n-1; i++)
		sum1 += arr[i];
	int k = n-2;
	while(sum1 > sum2){
		sum1 -= arr[k];
		sum2 += arr[k];
		k-=1;
	}
	return n-k-1;
}


int main(){
	vector<int> arr = {3 , 1 , 7, 1};
	cout << solve(arr) << endl;
	return 0;
}
