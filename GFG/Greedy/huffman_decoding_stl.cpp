
#include <bits/stdc++.h>
using namespace std;

map<char, string> codes;
map<char, int> freq;

struct MinHeapNode{
	char data;
	unsigned freq;
	MinHeapNode* left, *right;
	MinHeapNode(char data, unsigned freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


struct compare{
	bool operator()(struct MinHeapNode* l, struct MinHeapNode* r){
		return l->freq > r->freq;
	}
};


void printCodes(struct MinHeapNode* root, string str){
	if(!root)
		return;
	if(root->data != '$')
		cout << root->data << ": " << str << endl;
	printCodes(root->left, str + '0');
	printCodes(root->right, str + '1');
}

struct MinHeapNode* HuffmanCodes(string str){
	struct MinHeapNode *left, *right, *top;
	priority_queue<struct MinHeapNode*, vector<struct MinHeapNode*>, compare> minHeap;
	int size = str.length();
	for(int i = 0; i < size; i++){
		minHeap.push(new MinHeapNode(str[i], freq[str[i]]));
	}

	while(minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	
	return minHeap.top();
}

void count_freq(string str){
	for(int i = 0; i < str.length(); i++)
		freq[str[i]]++;
}

void store_data(struct MinHeapNode* root, string str){
	if(!root)
		return;
	if(root->data != '$')
		codes[root->data] = str;
	store_data(root->left, str + '0');
	store_data(root->right, str + '1');
}

string encodeString(string str){
	string encoded = "";
	for(int i = 0; i < str.length(); i++)
		encoded += codes[str[i]];
	return encoded;
}


string decode_data(struct MinHeapNode* root, string encoded){
	struct MinHeapNode* curr = root;
	int n = encoded.size();
	string decoded = "";
	for(int i = 0; i < n; i++){
		if(encoded[i] == '0')
			curr = curr->left;
		else
			curr = curr->right;
		if(curr->left == NULL and curr->right == NULL){
			decoded += curr->data;
			curr = root;
		}
	}
	return decoded + '\0';
}

int main(){
	string str = "geeksforgeeks";
	count_freq(str);
	struct MinHeapNode* top = HuffmanCodes(str);
	store_data(top, "");
	string encoded_string = encodeString(str);
	string decoded_string = decode_data(top, encoded_string);
	cout << "Encoded: " << encoded_string << endl;
	cout << "Decoded: " << decoded_string << endl;
	return 0;
}
