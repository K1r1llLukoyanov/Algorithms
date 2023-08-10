#include <bits/stdc++.h>
using namespace std;

int max_cought(char arr[], int k, int n){
	if(n <= 1 || k == 0)
		return 0;
	vector<int> thi;
	vector<int> pol;
	for(int i = 0; i < n; i++){
		if(arr[i] == 'P')
			pol.push_back(i);
		else
			thi.push_back(i);
	}
	int i = 0, j = 0;
	int pn = pol.size(), tn = thi.size();
	int count = 0;
	while(i < pn && j < tn){
		if(abs(pol[i] - thi[j]) <= k){
			count++;
			i++;
			j++;
		}
		else if(thi[j] < pol[i]){
			j++;
		}
		else{
			i++;
		}
	}
	return count;
}


int main(){
	char arr[] = {'P', 'T', 'P', 'T', 'T', 'P'};
	int k = 3;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Cought: " << max_cought(arr, k, n) << endl;
	return 0;
}
