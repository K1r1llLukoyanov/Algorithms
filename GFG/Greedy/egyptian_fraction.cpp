#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
	if(a < b)
		swap(a, b);
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}


void egyptianFraction(int numerator, int denominator){
	while(numerator){
		int a = ceil(denominator/float(numerator));
		cout << "1/" << a << " ";
		numerator -= 1;
	}
}


int main(){
	int numerator = 6, denominator = 14;
	cout << "Egyptian Fraction representation of " << numerator << "/" << denominator << " is ";
	egyptianFraction(numerator, denominator);
	cout << endl;
	return 0;
}
