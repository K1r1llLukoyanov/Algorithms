#include <bits/stdc++.h>
using namespace std;

int min_time_assigning(vector<int> mice, vector<int> holes){
	int n = mice.size();
	sort(mice.begin(), mice.end());
	sort(holes.begin(), holes.end());
	int max_time = 0;
	for(int i = 0; i < n; i++){
		max_time = max(max_time, abs(mice[i] - holes[i]));
	}
	return max_time;
}



int main(){
	vector<int> mice = {-10, -79, -79, 67, 93, -85, -28, -94};
	vector<int> holes = {-2, 9, 69, 25, -31, 23, 50, 78};
	cout << min_time_assigning(mice, holes) << endl;
	return 0;
}
