#include <bits/stdc++.h>
using namespace std;

int count(int n){
	if(n < 4)
		return -1;
	if(n % 4 == 0)
		return n / 4;
	
	int a = n % 4;
	int b = 1;
	if(a == 1){
		n -= 9;
	}
	else if(a == 2){
		n -= 6;
	}
	else if(a == 3){
		n -= 15;
		b += 1;
	}
	if(n < 0 || n % 4 != 0)
		return -1;
	return n/4 + b;
}



int main(){
	int n = 143;
	cout << count(n) << endl;
	return 0;
}
