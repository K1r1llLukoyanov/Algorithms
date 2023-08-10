#include <bits/stdc++.h>
using namespace std;

int min_cost(vector<int>& coins, int k){
	sort(coins.begin(), coins.end());
	int i = 0;;
	int j = coins.size()-1;
	int sum = 0;
	while(i <= j){
		sum += coins[i];
		i++;
		j-=k;
	}
	return sum;
}


int main(){
	vector<int> coins = {100, 20, 50, 10, 2, 5};
	int k = 3;
	cout << min_cost(coins, k) << endl;
	return 0;
}
