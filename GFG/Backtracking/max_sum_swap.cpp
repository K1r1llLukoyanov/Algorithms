#include <bits/stdc++.h>
using namespace std;

void max_through_swaps(int number[], int k, int n, int &max_number){
	if(k == 0)
		return;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(number[j] > number[i]){
				swap(number[j], number[i]);
				int num = 0;
				for(int h = 0; h < n; h++){
					num *= 10;
					num += number[h];
				}
				if(num > max_number)
					max_number = num;
				max_through_swaps(number, k-1, n, max_number);
				swap(number[j], number[i]);
			}
		}
	}
}

int max_right(int number[], int start, int n){
	int max = number[start];
	int id_max = start;
	for(int i = start+1; i < n; i++)
		if(number[i] > max){
			max = number[i];
			id_max = i;
		}
	return id_max;
}


void find_max_swapping(int number[], int k, int n, int &max_number, int curr){
	if(k == 0)
		return;
	int right_max = max_right(number, curr, n);
	if(number[right_max] != number[curr])
		k--;
	for(int j = n-1; j >= curr; j--){
		if(number[right_max] == number[j]){
			int max = 0;
			for(int i = 0; i < n; i++){
				max *= 10;
				max += number[i];
			}
			if(max > max_number)
				max_number = max;

			swap(number[curr], number[j]);
			find_max_swapping(number, k, n, max_number, curr+1);
			swap(number[curr], number[j]);
		}
	}
}


int main(){
	int M = 129814999;
	int swap = 4;
	int n = 0;
	int temp = M;
	while(temp > 0){
		n++;
		temp /= 10;
	}
	int number[n];
	int m = n-1;
	temp = M;
	while(temp > 0){
		number[m--] = temp%10;
		temp /= 10;
	}
	find_max_swapping(number, swap, n, M, 0);
	cout << M << endl;
	return 0;
};
