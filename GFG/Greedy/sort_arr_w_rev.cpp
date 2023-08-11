#include <bits/stdc++.h>
using namespace std;

bool can_be_sorted(int arr[], int n){
	int copy[n];
	for(int i = 0; i < n; i++)
		copy[i] = arr[i];
	sort(copy, copy+n);
	int i = n/2-1;
	while(i >= 0){
		if(!((copy[i] == arr[i] && copy[n-i-1] == arr[n-i-1]) || (copy[i] == arr[n-1-i] && copy[n-i-1] == arr[i])))
			return false;
		i--;
	}
	return true;
}


int main(){
	int arr[] = {1, 6, 3, 4, 5, 7, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(can_be_sorted(arr, n))
		cout << "YES" << endl;
	else
		cout << "No" << endl;
	return 0;
}
