#include<bits/stdc++.h>
using namespace std;

pair<int, int> solution(vector<int> prices, int k){
	int n = prices.size();
	sort(prices.begin(), prices.end());
	int paid1 = 0, paid2 = 0;
	int i = 0;
	int j = n-1;
	while(i <= j){
		paid1 += prices[i];
		j-=k;
		i+=1;
	}
	i = n-1;
	j = 0;
	while(i >= j){
		paid2 += prices[i];
		i--;
		j+=k;
	}
	return make_pair(paid1, paid2);
}


int main(){
	vector<int> a = {3,2,1,4};
	int k = 2;
	pair<int, int> sol = solution(a, k);
	cout << "Minimum amount of money we have to spend to buy all the N different candies: " << sol.first << endl;
	cout << "Maximum amount of money we have to spend to buy all the N different candies: " << sol.second << endl;
	return 0;
}
