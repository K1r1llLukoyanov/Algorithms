#include <bits/stdc++.h>
using namespace std;

void fitting(int wall, int m, int n){
	int p = wall/n;
	int num_p = p;
	int num_q = 0;
	int min_empty = wall - p*n;
	int rem = min_empty;
	int q = 0;
	while(wall >= m){
		q++;
		wall -= m;
		p = wall/n;
		rem = wall%n;
		if(rem < min_empty){
			min_empty = rem;
			num_p = p;
			num_q = q;
		}
	}
	cout << num_q << " " << num_p << " " << min_empty << endl;
}

int main(){
	fitting(24, 4, 7);
	return 0;
}
