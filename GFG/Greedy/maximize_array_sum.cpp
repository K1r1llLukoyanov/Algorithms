#include <bits/stdc++.h>
using namespace std;

int maximize(int arr[], int n, int k){
	sort(arr, arr+n);
	int i;
	for(i = 0; i < n && i < k && arr[i] < 0; i++){
		arr[i] = -arr[i];
	}
	if(i != k && arr[i] != 0 && (k-i)%2 == 1){
		arr[i] = -arr[i];
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}


int main(){
	int arr[] = {9, 8, 8, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << maximize(arr, n, k) << endl;
	return 0;
}
