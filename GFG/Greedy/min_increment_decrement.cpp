#include <bits/stdc++.h>
using namespace std;

int min_incr_decr(int a[], int n){
	int sum = 0, dif = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++){
		if(!pq.empty() && pq.top() < a[i]){
			dif = a[i] - pq.top();
			sum += dif;
			pq.pop();
			pq.push(a[i]);
		}
		pq.push(a[i]);
	}
	return sum;
}


int  main(){
	int a[] = {3, 1, 2, 1};
	int n = sizeof(a)/sizeof(a[0]);
	cout << min_incr_decr(a, n) << endl;
	return 0;
}
