#include <bits/stdc++.h>
using namespace std;

void worst_fit(int processes[], int blocks[], int n, int m){
	int allocated[n];
	for(int i = 0; i < n; i++)
		allocated[i] = -1;
	for(int i = 0; i < n; i++){
		int max_diff = 0;
		int index = i;
		for(int j = 0; j < m; j++){
			if(blocks[j] >= processes[i]){
				if(max_diff < blocks[j] - processes[i]){
					max_diff = blocks[j] - processes[i];
					index = j;
				}
			}
		}
		if(max_diff != 0){
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
	worst_fit(processSize, blockSize, n, m);
	return 0;
}
