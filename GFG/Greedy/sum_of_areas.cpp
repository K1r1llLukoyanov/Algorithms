#include <bits/stdc++.h>
using namespace std;

int max_area(int arr[], int n){
	if(n < 4)
		return 0;
	sort(arr, arr+n);
	int i = n-1;
	int sum = 0;
	while(i >= 3){
		int d1 = arr[i] - arr[i-1];
		int d2 = arr[i-2] - arr[i-3];
		if(d1 < 2 && d2 < 2){
			sum += (arr[i] - d1)*(arr[i-2] - d2);
		}
		i -= 4;
	}
	return sum;
}


int main(){
	int arr[] = {10, 10, 10, 10, 11, 10, 11, 10, 9, 9, 8, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << max_area(arr, n) << endl;
	return 0;
}
