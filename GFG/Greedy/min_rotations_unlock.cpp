#include <bits/stdc++.h>
using namespace std;

int min_rotations(int input, int unlock_code){
	int rotations = 0;
	while(input || unlock_code){
		int current_input = input%10;
		int current_unlock = unlock_code%10;
		rotations += min(abs(current_input-current_unlock), min(current_input + 10 - current_unlock, current_unlock + 10 - current_input));
		input/=10;
		unlock_code/=10;
	}
	return rotations;
}


int main(){
	int code = 28756;
	int unlock_code = 98234;
	cout << "Rotations required: " << min_rotations(code, unlock_code) << endl;
	return 0;
}
