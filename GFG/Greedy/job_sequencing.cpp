#include <bits/stdc++.h>
using namespace std;

struct Job{
	char id;
	int deadline;
	int profit;
};

bool profit_comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}


// O(N^2)
void max_profit(Job jobs[], int n){
	sort(jobs, jobs + n, profit_comparison);
	int result[n];
	bool slots[n];
	
	for(int i = 0; i < n; i++)
		slots[i] = false;

	for(int i = 0; i < n; i++){
		for(int j = min(n, jobs[i].deadline)-1; j >= 0; j--){
			if(slots[j] == false){
				result[j] = i;
				slots[j] = true;
				break;
			}
		}	
	}
	for(int i = 0; i < n; i++)
		if(slots[i])
			cout << jobs[result[i]].id << " ";
	cout << endl;
}

bool deadline_comparison(Job a, Job b){
	return a.deadline < b.deadline;
}

struct jobProfit {
	bool operator()(Job const& a, Job const& b)
	{
		return (a.profit < b.profit);
	}
};

// O(NlogN)
void job_sequencing(Job jobs[], int n){
	vector<Job> result;
	sort(jobs, jobs+n, deadline_comparison);
	priority_queue<Job, vector<Job>, jobProfit> pq;
	for(int i = n-1; i >= 0; i--){
		int slot_available;
		if(i == 0)
			slot_available = jobs[i].deadline;
		else
			slot_available = jobs[i].deadline - jobs[i-1].deadline;

		pq.push(jobs[i]);
		while(slot_available && pq.size()){
			Job top_job = pq.top();
			pq.pop();
			slot_available--;
			result.push_back(top_job);
		}
	}
	
	sort(result.begin(), result.end(), [](Job &a, Job &b){
		return a.deadline < b.deadline;
	});
	
	for(int i = 0; i < result.size(); i++)
		cout << result[i].id << " ";
	cout << endl;
}


int main(){
	Job arr[] = { 
		{ 'a', 2, 100 },
		{ 'b', 1, 19 },
		{ 'c', 2, 27 },
		{ 'd', 1, 25 },
		{ 'e', 3, 15 } 
	};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs: \n";
	max_profit(arr, n);
	job_sequencing(arr, n);
	return 0;
}
