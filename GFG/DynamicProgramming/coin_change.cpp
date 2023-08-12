#include <bits/stdc++.h>
using namespace std;

int coin_change(int sum, int coins[], int n){
	int dp[n+1][sum+1];
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < sum + 1; j++){
			if(i == 0)
				dp[i][j] = 0;
			else if(j == 0)
				dp[i][j] = 1;
			else if(coins[i-1] <= j)
				dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[n][sum];
}


int main(){
	int sum = 4;
	int coins[] = {1,2,3};
	int n = 3;
	cout << coin_change(sum, coins, n) << endl;
	return 0;
}
