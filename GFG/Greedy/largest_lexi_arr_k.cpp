#include <bits/stdc++.h>
using namespace std;

void largest(int arr[], int n, int k){
	for(int i = 0; i < n && k > 0; i++){
		int value = arr[i];
		int largest_after_value = arr[i];
		int largest_index = i;
		for(int j = i + 1; j < n && (j-i) <= k; j++){
			if(arr[j] > largest_after_value){
				largest_after_value = arr[j];
				largest_index = j;
			}
		}
		swap(arr[i], arr[largest_index]);
		k -= (largest_index - i);
	}
}


int main(){
	int arr[] = {3, 5, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	largest(arr, n, k);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
