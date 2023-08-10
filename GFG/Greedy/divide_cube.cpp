#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(a < b)
		swap(a, b);
	if(a % b == 0)
		return b;
	return gcd(b, a%b);
}

pair<int, int> solution(int l, int b, int h){
	int a = gcd(b, l);
	int c = gcd(h, b);
	if(a == c)
		return make_pair(a, l*b*h/(a*a*a));
	int d = gcd(a, c);
	return make_pair(d, l*b*h/(d*d*d));
}

int main(){
	int l = 3, b = 1, h = 2;
	pair<int, int> sol = solution(l, b, h);
	cout << sol.first << " " << sol.second << endl;
	return 0;
}
