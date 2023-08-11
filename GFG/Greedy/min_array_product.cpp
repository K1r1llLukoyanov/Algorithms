#include <bits/stdc++.h>
using namespace std;

int min_array_product(int arr[], int n){
	sort(arr, arr+n);
	int min_product = arr[0];
	int count_neg;
	for(count_neg = 0; count_neg < n && arr[count_neg] < 0; count_neg++){}
	if(count_neg % 2 == 1){
		for(int i = 1; i < n; i++){
			if(arr[i] != 0)
				min_product*=arr[i];
		}	
	}
	if(count_neg % 2 == 0 && count_neg != 0){
		for(int i = 1; i < count_neg-1; i++){
			min_product *= arr[i];
		}
		for(int i = count_neg; i < n; i++){
			if(arr[i] != 0)
				min_product *= arr[i];
		}
	}
	return min_product;
}


int main(){
	int arr[] = {0,0,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << min_array_product(arr, n) << endl;
	return 0;
}
