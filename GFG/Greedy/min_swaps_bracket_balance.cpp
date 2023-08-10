#include <bits/stdc++.h>
using namespace std;

int min_swaps(string& str){
	int n = str.length();
	int close = 0;
	int open = 0;
	int j = 0;
	int swaps = 0;
	char base[n];
	for(int i = j; i < n; i++){
		if(str[i] == '[')
			open++;
		else if(str[i] == ']')
			close++;
		
		if(close > open){
			int k = i+1;
			while(k < n && str[k] != '[')
				k++;

			swaps+=(k - i);
		
			str[k] = ']';
			str[i] = '[';
			j = j+2;
			i++;
		}
	}
	
	return swaps;
}


int main(){
	string str = "]]][[[";
	cout << min_swaps(str) << endl;
	cout << str << endl;
	return 0;
}
