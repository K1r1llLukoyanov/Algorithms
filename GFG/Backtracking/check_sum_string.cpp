#include <bits/stdc++.h>
using namespace std;

string string_sum(string str1, string str2){
	if(str1.length() < str2.length())
		swap(str1, str2);
	int n = str2.length();
	int m = str1.length();
	
	int sum = 0;
	int carry = 0;
	int base = 1;
	int i;
	for(i = 0; i < n; i++){
		int dd = (str1[m-1-i]-'0') + (str2[n-1-i]-'0') + carry;
		sum += (dd%10)*base;
		carry = dd/10;
		base *= 10;
	}
	for(int j = n; j < m; j++){
		int dd = (str1[m-1-j]-'0') + carry;
		sum += (dd%10)*base;
		carry = dd/10;
		base *= 10;
	}
	if(carry){
		sum += carry * base;
	}
	string new_str = "";
	while(sum > 0){
		new_str.push_back((sum%10)+'0');
		sum/=10;
	}
	reverse(new_str.begin(), new_str.end());
	return new_str;
}

bool still(string str1, string str2, string str, int index, int n){
	if(str1.length() > n-index || str2.length() > n-index)
		return false;
	string sum = string_sum(str1, str2);
	for(int i = index; i < n; i++){
		string sub = str.substr(index, i - index + 1);
		cout << str1 << " " << str2 << " " << sub << " ";
		bool a = false;
		if(sum == sub){
			a = (i == (n-1)) || still(str2, sub, str, i+1, n);
		}
		if(a){
			cout << "true" << endl;
			return true;
		}
		else
			cout << "false" << endl;
	}
	return false;
}


bool sum_string(string str){
	int n = str.length();
	for(int i = 0; i < n-2; i++){
		string str1 = str.substr(0, i+1);
		for(int j = i + 1; j < n - 1; j++){
			if(j-i > n-j || i+1 > n-j)
				continue;
			string str2 = str.substr(i+1, j-i);
			bool a = still(str1, str2, str, j+1, n);
			if(a)
				return true;
		}
	}
	return false;
}


int main(){
	string str = "12243660";
	cout << str << endl;
	if(sum_string(str))
		cout << "YEEEEEEES\n";
	else
		cout << "NO\n";
	return 0;
}
