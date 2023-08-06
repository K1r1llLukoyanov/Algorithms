#include <bits/stdc++.h>
using namespace std;

void display(vector<string>& sentance){
	cout << "Sentance: ";
	for(auto word: sentance)
		cout << word << " ";
	cout << "\n";
}


void word_break(string str, int i, vector<string>& dict, vector<string>& sentance){
	int n = str.length();
	if(i == n){
		display(sentance);
		return;
	}
	for(int j = i; j < n; j++){
		string substring = str.substr(i, j-i+1);
		if(find(dict.begin(), dict.end(), substring) != dict.end()){
			sentance.push_back(substring);
			word_break(str, j+1, dict, sentance);
			sentance.pop_back();
		}
	}
}



int main(){
	string str = "ilovesamsungmobile";
	vector<string> dict = {"mobile","samsung","sam","sung", "man","mango", "icecream","and", "go","i","love","ice","cream"};
	vector<string> sentance;
	word_break(str, 0, dict, sentance);
	word_break("iloveicecreamandmango", 0, dict, sentance);
	return 0;
}
