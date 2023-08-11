#include <bits/stdc++.h>
using namespace std;

void best_fit(int processes[], int blocks[], int n, int m){
	int allocated[n];
	for(int i = 0; i < n; i++)
		allocated[i] = -1;
	for(int i = 0; i < n; i++){
		int min_diff = INT_MAX;
		int index = i;
		for(int j = 0; j < m; j++){
			if(blocks[j] >= processes[i]){
				if(min_diff > blocks[j] - processes[i]){
					min_diff = blocks[j] - processes[i];
					index = j;
				}
			}
		}
		if(min_diff != INT_MAX){
			allocated[i] = index+1;
			blocks[index] -= processes[i];
		}
	}
	for(int i = 0; i < n; i++)
		cout << i+1 << "\t" << processes[i] << "\t" << allocated[i] << endl;
}


int main(){
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {212, 417, 112, 426};
	int n = sizeof(processSize)/sizeof(processSize[0]);
	int m = sizeof(blockSize)/sizeof(blockSize[0]);
	best_fit(processSize, blockSize, n, m);
	return 0;
}
