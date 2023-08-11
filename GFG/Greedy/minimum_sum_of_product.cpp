#include <bits/stdc++.h>
using namespace std;

int min_sum_of_product(int arr1[], int arr2[], int n, int k){
	int arr3[n];
	int max_diff = 0;
	int max_diff_index = 0;
	int value = 0;
	for(int i = 0; i < n; i++)
		arr3[i] = arr1[i]*arr2[i];

	for(int i = 0; i < n; i++){
		int a3 = arr3[i];
		if(arr1[i] > arr2[i])
			swap(arr1[i], arr2[i]);
		if(arr1[i]*arr2[i] < 0){
			int a1 = (arr1[i]-k*2)*arr2[i];
			int a2 = arr1[i]*(arr2[i]+k*2);
			a3 = min(a3, min(a1, a2));
		}
		else{
			if(arr1[i] <= 0){
				int a1 = arr1[i]*(arr2[i] + 2*k);
				a3 = min(a3, a1);
			}
			else{
				int a1 = (arr1[i] - 2*k)*arr2[i];
				a3 = min(a3, a1);
			}
		}
		
		if(max_diff < abs(a3 - arr3[i])){
			max_diff_index = i;
			max_diff = abs(a3 - arr3[i]);
			value = a3;
		}
	}
	int sum = 0;
	cout << max_diff_index << endl;
	cout << value << endl;
	for(int i = 0; i < n; i++){
		if(i == max_diff_index)
			sum += value;
		else
			sum += arr3[i];
	}
	return sum;
}


int main(){
	int arr1[] = {2, 3, 4, 5, 4};
	int arr2[] = {3, 4, 2, 3, 2};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int k = 3;
	cout << min_sum_of_product(arr1, arr2, n, k) << endl;
	return 0;
}
