#include <bits/stdc++.h>
using namespace std;


void find_all_distinct(vector<int>& array, vector<vector<int>>& res){
	int n = array.size();
	vector<string> list;
	for(int counter = 0; counter < (1 << n); counter++){
		vector<int> subset;
		string temp = "";
		
		for(int j = 0; j < n; j++){
			if(counter & (1 << j)){
				subset.push_back(array[j]);
				temp += to_string(array[j])+'$';
			}
		}
		
		if(find(list.begin(), list.end(), temp) == list.end()){
			res.push_back(subset);
			list.push_back(temp);
		}
	}
}


int main(){
	vector<int> array = {1,2,2};
	vector<vector<int>> res;
	find_all_distinct(array, res);
	for(auto &sub: res){
		for(auto &item: sub)
			cout << item << " ";
		cout << endl;
	}
	return 0;
}
