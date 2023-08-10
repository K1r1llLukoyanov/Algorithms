#include <bits/stdc++.h>
using namespace std;

int max_profit(vector<int>& stocks, int money){
	int n = stocks.size();
	vector<pair<int, int>> pairs;
	for(int i = 0; i < n; i++)
		pairs.push_back(make_pair(stocks[i], i+1));
	sort(pairs.begin(), pairs.end());

	int profit = 0;
	int stonks = 0;
	for(int i = 0; i < n; i++){
		int count = min(money/pairs[i].first, pairs[i].second);
		int paid = count*pairs[i].first;
		stonks += count;
		money -= paid;
		profit += paid;
	}
	return stonks;
}


int main(){
	vector<int> stocks = {7, 10, 4};
	int money = 100;
	cout << "Stonks purchased: " << max_profit(stocks, money) << endl;
	return 0;
}
