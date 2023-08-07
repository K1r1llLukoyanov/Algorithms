#include <bits/stdc++.h>
using namespace std;

bool is_palindromic(string str){
	int n = str.length();
	int i = 0, j = n-1;
	while(i < j && str[i] == str[j]){
		i++;
		j--;
	}
	return i >= j;
}


void find_all_palindromic(string str, vector<vector<string>>& ans){
	int n = str.length() - 1;
	for(int i = 0; i < (1 << n); i++){
		bool palindromic = true;
		vector<string> subans;
		string temp = "";
		temp += str[0];
		for(int j = n-1; j >= 0; j--){
			if(i & (1 << j)){
				if(!is_palindromic(temp)){
					palindromic = false;
					break;
				}
				else
					subans.push_back(temp);
				temp = "";
			}
			temp += str[n-j];
		}
		if(!is_palindromic(temp))
			palindromic = false;
		else
			subans.push_back(temp);

		if(!palindromic)
			continue;
		
		ans.push_back(subans);
	}
}


int main(){
	string str = "nitin";
	vector<vector<string>> ans;
	find_all_palindromic(str, ans);
	for(auto &vec: ans){
		for(auto word: vec)
			cout << word << " ";
		cout << endl;
	}
	return 0;
}
