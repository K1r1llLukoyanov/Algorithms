#include <bits/stdc++.h>
using namespace std;

bool subset(int sum, int set[], int n){
	int dp[n+1][sum+1];
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < sum+1; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(set[i-1] == j)
				dp[i][j] = 1;
			else if(set[i-1] < j)
				dp[i][j] = dp[i-1][j - set[i-1]] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][sum] > 0;
}


int main(){
	int sum = 30;
	int set[] = {3, 34, 4, 12, 5, 2};
	int n = sizeof(set)/sizeof(set[0]);
	cout << subset(sum, set, n) << endl;
	return 0;
}
