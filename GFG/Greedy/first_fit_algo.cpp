#include <bits/stdc++.h>
using namespace std;

void first_fit(int blocks[], int process[], int n, int m){
	int allocated[m];
	for(int i = 0; i < m; i++)
		allocated[i] = -1;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(blocks[j] >= process[i]){
				allocated[i] = j+1;
				blocks[j] -= process[i];
				break;
			}
		}
	}	

	for(int i = 0; i < m; i++){
		cout << i+1 << "\t" << process[i] << "\t" <<  allocated[i] << endl;
	}
}


int main(){
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	int n = sizeof(blockSize)/sizeof(blockSize[0]);
	int m = sizeof(processSize)/sizeof(processSize[0]);
	first_fit(blockSize, processSize, n, m);
	return 0;
}
