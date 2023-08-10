#include <bits/stdc++.h>
using namespace std;


int values[9] = {2000, 500, 200, 100, 50, 20, 10, 5, 1};


vector<pair<int, int>> min_num(int value){
	vector<pair<int, int>> ans;
	int i = 0;
	while(value){
		for(int j = i; j < 9; j++){
			if(value/values[j]){
				ans.push_back(make_pair(values[j], value/values[j]));
				value %= values[j];
				i = j + 1;
			}
		}
	}
	return ans;
}


int main(){
	int input = 2456;
	vector<pair<int, int>> ans = min_num(input);
	for(auto &p: ans){
		cout << p.first << " : " << p.second << endl;
	}
	return 0;
}
