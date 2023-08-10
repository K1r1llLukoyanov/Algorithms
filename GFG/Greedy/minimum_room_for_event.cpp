#include <bits/stdc++.h>
using namespace std;

int min_number_of_rooms(int n, int m, vector<string>& slots){
	int book[m] {0};
	int rooms_needed = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(slots[i][j]-'0'){
				book[j]+=1;
				rooms_needed = max(book[j], rooms_needed);
			}
		}
	}
	return rooms_needed;
}


int main(){
	int n = 3;
	int m = 7;
	vector<string> slots = {"0101011", "0011001", "0110111"} ;
	cout << "Rooms needed: " << min_number_of_rooms(n, m, slots) << endl;
	return 0;
}
