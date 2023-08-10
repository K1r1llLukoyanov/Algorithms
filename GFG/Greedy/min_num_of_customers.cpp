#include<bits/stdc++.h>
using namespace std;

long long a = 9999, b = 10000;

struct sort_pred {
	bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return (long long)(left.first*a + left.second*b) < (long long)(right.first*a + right.second*b);
	}
};


int solve(vector<pair<int, int>> &clients, long long n, long long d){
	sort(clients.begin(), clients.end(), sort_pred());
	int count = 0;
	for(int i = 0; i < n; i++){
		if((long long)(clients[i].first*a + clients[i].second*b) < d){
			count++;
			d -= (long long)(clients[i].first*a + clients[i].second*b);
		}
		else
			break;
	}
	return count;
}



int main(){
	long long n = 6, d = 1000000000;
	vector<pair<int, int>> clients = {{10000, 9998}, {10000, 10000}, {10000, 10000}, {70000, 70000}, {10000, 10000}, {10000, 10000}};
	cout << "Clients satisfied: " << solve(clients, n, d) << endl;
	return 0;
}
