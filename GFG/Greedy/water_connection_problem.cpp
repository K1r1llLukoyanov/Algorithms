#include <bits/stdc++.h>
using namespace std;


struct ListNode{
	int num;
	struct ListNode* next = 0;
	ListNode(int num){
		this->num = num;
	}
};


struct List{
	struct ListNode* head = 0;
	struct ListNode* tail = 0;
	int min_diam = INT_MAX;
	List(struct ListNode* head, struct ListNode* tail, int min_diam){
		this->head = head;
		this->tail = tail;
		this->min_diam = min_diam;
	}
};

// 2 -> 8 (22)
// 5 -> 9 -> 7 -> 4 -> 6 (10)
// 3 -> 1 (66)


void print_list(struct List* list){
	struct ListNode* head = list->head;
	while(head != 0){
		cout << head->num << " -> ";
		head = head->next;
	}
	cout << endl;
}

void solve(vector<vector<int>>& input){
	vector<List*> lists;
	int n = input.size();
	for(int i = 0; i < n; i++){
		int m = lists.size();
		int k = m;
		int g = m;
		for(int j = 0; j < m; j++){
			if(lists[j]->tail->num == input[i][0])
				k = j;
			else if(lists[j]->head->num == input[i][1]){
				g = j;
			}
		}
		if(k == m && g == m){
			struct ListNode* begin = new ListNode(input[i][0]);
			struct ListNode* end = new ListNode(input[i][1]);
			begin->next = end;
			struct List* new_list = new List(begin, end, input[i][2]);
			print_list(new_list);
			lists.push_back(new_list);
		}
		else if(g == m){
			struct ListNode* new_tail = new ListNode(input[i][1]);
			lists[k]->tail->next = new_tail;
			lists[k]->tail = new_tail;
			lists[k]->min_diam = min(lists[k]->min_diam, input[i][2]);
			print_list(lists[k]);
		}
		else if(k == m){
			struct ListNode* new_head = new ListNode(input[i][0]);
			new_head->next = lists[g]->head;
			lists[g]->head = new_head;
			lists[g]->min_diam = min(lists[g]->min_diam, input[i][2]);
			print_list(lists[g]);
		}
		else{
			lists[k]->tail->next = lists[g]->head;
			int m = min(lists[k]->min_diam, lists[g]->min_diam);
			lists[k]->min_diam = min(m, input[i][2]);
			lists.erase(lists.begin() + g);
		}
	}
	
	int m = lists.size();
	for(int i = 0; i < m; i++){
		cout << lists[i]->head->num << " " << lists[i]->tail->num << " " << lists[i]->min_diam << endl;
	}
}


int main(){
	vector<vector<int>> arr = { { 7, 4, 98 }, { 5, 9, 72 }, { 4, 6, 10 }, { 2, 8, 22 }, { 9, 7, 17 }, { 3, 1, 66 } };
	solve(arr);
	return 0;
}
