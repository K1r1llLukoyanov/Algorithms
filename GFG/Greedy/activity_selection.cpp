#include <bits/stdc++.h>
using namespace std;

vector<int> maximum_activities(vector<int> start, vector<int> end){
	int n = start.size();
	vector<int> executed;
	if(n == 0)
		return executed;
	executed.push_back(0);
	int i = 1;
	int prev = 0;
	while(i < n){
		if(start[i] >= end[prev]){
			executed.push_back(i);
			prev = i;
		}
		i++;
	}
	return executed;
}


int main(){
	vector<int> start = {1, 3, 0, 5, 8, 5};
	vector<int> end = {2, 4, 6, 7, 9, 9};
	vector<int> solution = maximum_activities(start, end);
	for(auto a: solution)
		cout << a << " ";
	cout << endl;
	return 0;
}
