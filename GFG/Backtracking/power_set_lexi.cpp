#include <bits/stdc++.h>
using namespace std;

void solve(string str, string cur_str, vector<string>& solution, int i){
	if(i == str.length())
		return;
	for(int j = 0; j < 2; j++){
		if(j % 2 == 0){
			solution.push_back(cur_str + str[i]);
			solve(str, cur_str + str[i], solution, i+1);
		}
		else{
			solve(str, cur_str, solution, i+1);
		}
	}
}


int main(){
	string str = "abc";
	vector<string> strs;
	solve(str, "", strs, 0);
	for(auto &str: strs)
		cout << str << endl;
	return 0;
}
