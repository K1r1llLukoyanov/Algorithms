#include <bits/stdc++.h>
using namespace std;

int min_cost(vector<int> &array){
	int n = array.size();
	int min = array[0];
	for(int i = 1; i < n; i++)
		if(min > array[i])
			min = array[i];
	return min*(n-1);
}


int main(){
	vector<int> array = {4,3,2};
	cout << min_cost(array) << endl;
	return 0;
}
