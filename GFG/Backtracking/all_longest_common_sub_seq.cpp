#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int dp[MAX][MAX];
int lcslen = 0;

int lcs(string str1, string str2, int len1, int len2, int i, int j){
	int &ret = dp[i][j];
	if(i == len1 || j == len2)
		return ret = 0;
	
	if(ret != -1)
		return ret;
	
	ret = 0;
	if(str1[i] == str2[j])
		ret = 1 + lcs(str1, str2, len1, len2, i+1, j+1);
	else
		ret = max(lcs(str1, str2, len1, len2, i+1, j), lcs(str1, str2, len1, len2, i, j+1));
	
	return ret;
}


void printAll(string str1, string str2, int len1, int len2, char data[], int indx1, int indx2, int currlcs){
	if(currlcs == lcslen){
		data[currlcs] = '\0';
		puts(data);
		return;
	}
	if(len1 == indx1 || len2 == indx2)
		return;
	
	for(char ch = 'a'; ch <= 'z'; ch++){
		bool done = false;
		for(int i = indx1; i < len1; i++){
			if(str1[i] == ch){
				for(int j = indx2; j < len2; j++){
					if(str2[j] == ch && dp[i][j] == lcslen - currlcs){
						data[currlcs] = ch;
						printAll(str1, str2, len1, len2, data, i+1, j+1, currlcs+1);
						done = true;
						break;
					}
				}
			}
			if(done)
				break;
		}
	}
}


int main(){
	string str1 = "abcabcaa";
	string str2 = "acbacba";
	int len1 = str1.length(), len2 = str2.length();
	memset(dp, -1, sizeof(dp));
	lcslen = lcs(str1, str2, len1, len2, 0, 0);
	
	char data[MAX];
	printAll(str1, str2, len1, len2, data, 0, 0, 0);
	return 0;
}
