#include <bits/stdc++.h>
using namespace std;


vector<string> all_possible(string str){
	int n = str.length() - 1;
	vector<string> ans;
	for(int counter = 0; counter < (1 << n); counter++){
		string temp = "";
		for(int i = 0; i < n+1; i++){
			temp += str[i];
			if(counter & (1 << i))
				temp += ' ';
		}
		ans.push_back(temp);
	}
	return ans;
}


int main(){
	string str = "ABCD";
	vector<string> ans = all_possible(str);
	for(auto &str: ans)
		cout << str << endl;
	return 0;
}
