#include <bits/stdc++.h>
using namespace std;

int maximum(int arr[], int n, int k){
	sort(arr, arr+n);
	int sum1 = 0;
	int sum2 = 0;
	if(k > n-k){
		for(int i = n-1; i > n-1-k; i--)
			sum1 += arr[i];
		for(int i = n-1-k; i >= 0; i--)
			sum2 += arr[i];
	}
	else{
		for(int i = 0; i < k; i++)
			sum2 += arr[i];
		for(int i = k; i < n; i++)
			sum1 += arr[i];
	}
	return sum1 - sum2;
}


int main(){
	int arr[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << maximum(arr, n, k) << endl;
	return 0;
}
